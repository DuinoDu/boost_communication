#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try{
        cout << "server start..." << endl;

        boost::asio::io_service io;
        tcp::acceptor 	acceptor(io, tcp::endpoint(tcp::v4(), 6688));
        cout << acceptor.local_endpoint().address() << endl;

        for(;;){
            tcp::socket sock(io);

            // wait in block way
            acceptor.accept(sock);

            cout << "client: " << sock.remote_endpoint().address() << endl;

            sock.send(boost::asio::buffer("hello asio"));
        }
    }
    catch(std::exception& e){
        cerr << e.what() << endl;
    }
}
