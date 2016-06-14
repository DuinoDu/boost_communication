//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at <a href="http://www.boost.org/LICENSE_1_0.txt">http://www.boost.org/LICENSE_1_0.txt</a>)
//

#include &lt;cstdlib&gt;
#include &lt;deque&gt;
#include &lt;iostream&gt;
#include &lt;list&gt;
#include &lt;memory&gt;
#include &lt;set&gt;
#include &lt;utility&gt;
#include &lt;<a href="../../../../../../boost/asio.hpp">boost/asio.hpp</a>&gt;
#include &quot;chat_message.hpp&quot;

using boost::asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque&lt;chat_message&gt; chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message&amp; msg) = 0;
};

typedef std::shared_ptr&lt;chat_participant&gt; chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
  void join(chat_participant_ptr participant)
  {
    participants_.insert(participant);
    for (auto msg: recent_msgs_)
      participant-&gt;deliver(msg);
  }

  void leave(chat_participant_ptr participant)
  {
    participants_.erase(participant);
  }

  void deliver(const chat_message&amp; msg)
  {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() &gt; max_recent_msgs)
      recent_msgs_.pop_front();

    for (auto participant: participants_)
      participant-&gt;deliver(msg);
  }

private:
  std::set&lt;chat_participant_ptr&gt; participants_;
  enum { max_recent_msgs = 100 };
  chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class chat_session
  : public chat_participant,
    public std::enable_shared_from_this&lt;chat_session&gt;
{
public:
  chat_session(tcp::socket socket, chat_room&amp; room)
    : socket_(std::move(socket)),
      room_(room)
  {
  }

  void start()
  {
    room_.join(shared_from_this());
    do_read_header();
  }

  void deliver(const chat_message&amp; msg)
  {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      do_write();
    }
  }

private:
  void do_read_header()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.data(), chat_message::header_length),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec &amp;&amp; read_msg_.decode_header())
          {
            do_read_body();
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  void do_read_body()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            room_.deliver(read_msg_);
            do_read_header();
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  void do_write()
  {
    auto self(shared_from_this());
    boost::asio::async_write(socket_,
        boost::asio::buffer(write_msgs_.front().data(),
          write_msgs_.front().length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
              do_write();
            }
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  tcp::socket socket_;
  chat_room&amp; room_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

//----------------------------------------------------------------------

class chat_server
{
public:
  chat_server(boost::asio::io_service&amp; io_service,
      const tcp::endpoint&amp; endpoint)
    : acceptor_(io_service, endpoint),
      socket_(io_service)
  {
    do_accept();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(socket_,
        [this](boost::system::error_code ec)
        {
          if (!ec)
          {
            std::make_shared&lt;chat_session&gt;(std::move(socket_), room_)-&gt;start();
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  tcp::socket socket_;
  chat_room room_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    if (argc &lt; 2)
    {
      std::cerr &lt;&lt; &quot;Usage: chat_server &lt;port&gt; [&lt;port&gt; ...]\n&quot;;
      return 1;
    }

    boost::asio::io_service io_service;

    std::list&lt;chat_server&gt; servers;
    for (int i = 1; i &lt; argc; ++i)
    {
      tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
      servers.emplace_back(io_service, endpoint);
    }

    io_service.run();
  }
  catch (std::exception&amp; e)
  {
    std::cerr &lt;&lt; &quot;Exception: &quot; &lt;&lt; e.what() &lt;&lt; &quot;\n&quot;;
  }

  return 0;
}
