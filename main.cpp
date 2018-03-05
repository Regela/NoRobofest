#include <QCoreApplication>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat frame;

    while (1){
        cap>>frame;

        if (frame.empty()){
            break;
        }
        imshow("Frame", frame);


        char c=waitKey(1);
        if(c==27) break;
    }

    cap.release();
    destroyWindow("Frame");

    return a.exec();
}
