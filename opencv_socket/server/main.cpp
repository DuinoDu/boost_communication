#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread/thread.hpp>
#include "opencv2/opencv.hpp"

using boost::asio::ip::tcp;
using namespace std;
using namespace cv;

Mat frame = Mat::zeros( 320, 640, CV_8UC3);

void serverCapture(){

    cout << "serverCapture1" << endl;
    cout << "serverCapture2" << endl;
    cout << "serverCapture3" << endl;

    VideoCapture cap(0);
    if(!cap.isOpened()){
        cerr << "Fail to open camera";
        return;
    }

    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

    while (true){
        // get image
        cap >> frame;
        //imshow("server", frame);
        waitKey(100);
    }
    cap.release();
}

int main(int argc, char *argv[])
{
    boost::thread thrd(&serverCapture);

    try{
        boost::asio::io_service io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 3200));
    
        // main loop
        for(;;){

            // socket
            tcp::socket socket(io);
            acceptor.accept(socket);
            //cout << "client: " << socket.remote_endpoint().address() << endl;
            
            Mat imgSend = Mat::zeros(1, 230400, CV_8U);
            imgSend = (frame.reshape(0,1));

            boost::system::error_code ec;
            string message((char*)imgSend.data, 230400);
            cout << "sending..." << endl;
            socket.write_some(boost::asio::buffer(message), ec);
            cout << "send image finished" << endl;

        }
    }
    catch(exception& e){
        cerr << e.what() << endl;
    }
    
    // block main thread until thrd finish.
    thrd.join();
    
    return 0;
}
