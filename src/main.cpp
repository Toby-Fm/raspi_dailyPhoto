#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0); //Öffne die erste angeschlossene Kamera

	if (!cap.isOpened()) {
		cerr << "Kamera konnte nicht gefunden werden!" << endl;
		return -1;
	}

	Mat frame;
	while (true) {
		cap >> frame; // Lese neues Frame von der Kamera
		
		if (frame.empty()) {
			cerr << "Leeres Frame erhalten" << endl;
			break;
		}

		imshow("Webcam", frame); // zeige das Frame in einem Fenster an
		
		if (waitKey(1) == 27) break;
	
	}

	cap.release();
	destroyAllWindows();
	return 0;
}
