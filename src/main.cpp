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
	cap >> frame; // Lese Frame von der Kamera
	
	if (frame.empty()) {
		cerr << "Leeres Frame erhalten" << endl;
		return -1;
	}
	
	//Speicher das Bild als PNG
	bool isSaved = imwrite("nice.png", frame);
	if(!isSaved) {
		cerr << "Fehler beim speichern des Bildes!" << endl;
		return -1;
	}
	
	cout << "Bild erfolgreich gespeichert" << endl;

	cap.release();
	return 0;
}
