#include <iostream>
#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[])
{
    try{
        cout << "client start" << endl;

        boost::asio::io_service io;

        tcp::socket sock(io);

        tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 6688);

        sock.connect(ep);

        cout << sock.available() << endl;

        vector<char> str(sock.available()+1, 0);
        sock.receive(boost::asio::buffer(str));

        cout << "receive from" << sock.remote_endpoint().address() << endl;

        cout << &str[0] << endl;
    }
    catch(exception& e){
        cerr << e.what() << endl;
    }
}
