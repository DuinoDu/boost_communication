#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "opencv2/opencv.hpp"

using boost::asio::ip::tcp;
using namespace std;
using namespace cv;

int main()
{
    boost::array<char, 230400> buf;

    while(true){
        try{

            // socket receive
            boost::asio::io_service io;
            tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3200);
            tcp::socket socket(io);
            socket.connect(endpoint);
            boost::system::error_code ec;
            size_t len = socket.read_some( boost::asio::buffer(buf), ec);

            // opencv show img
            cout << "get data length: "<< len << endl;
            if (len != 230400){
                cout << "lost data" << endl;
                continue;
            }
            vector<uchar> data(buf.begin(), buf.end());
            Mat img(data, true);
            img = img.reshape(3,240);
            imshow("client", img);
            waitKey(20);
        }
        catch(exception& e){
            cerr << e.what() << endl;
        }
    }
    return 0;
}
