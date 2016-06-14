#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;

void handle_read(char* buf, boost::system::error_code ec, size_t bytes_transferred)
{
    //cout.write(buf, bytes_transferred);
    cout << buf << endl;
}


int main( int argc, char **argv )
{
    try{
        io_service io;
        serial_port port(io, "/dev/ttyUSB0");
        port.set_option(serial_port::baud_rate(57600));
        port.set_option(serial_port::flow_control(serial_port::flow_control::none));
        port.set_option(serial_port::parity(serial_port::parity::none));
        port.set_option(serial_port::character_size(8));

        cout << "write to serial port..." << endl;
        write(port, buffer("hello world", 12));

        // async read
        char buf[100];
        async_read(port, buffer(buf), boost::bind(handle_read, buf, _1, _2));
        deadline_timer timer(io);
        timer.expires_from_now(boost::posix_time::millisec(1000));
        timer.async_wait(boost::bind(&serial_port::cancel, boost::ref(port)));

        // start event loop in block
        io.run();
    }
    catch(exception& e){
        cerr << e.what() << endl;
    }
    return 0;
}
