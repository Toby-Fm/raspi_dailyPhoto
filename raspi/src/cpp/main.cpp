#include "main.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main() {
	connect(); // Baut eine Verbindung zur Datenbank auf
	//std::cout << "Datenbank IP: " << server << std::endl;

	VideoCapture cap(0); //Öffne die erste angeschlossene Kamera

	if (!cap.isOpened()) {
		cerr << "Kamera konnte nicht gefunden werden!" << endl;
		return -1;
	}

	// Countdown für Foto-geschoss
	cout << "Foto wird gemacht in:" << endl;
	for (int i = 5; i > 0; --i) {
		cout << i << endl;
		this_thread::sleep_for (chrono::seconds(1));
	}
	cout << "\nFoto wird gemacht\n" << endl;
    
    Mat frame;
	cap >> frame; // Lese Frame von der Kamera
	if (frame.empty()) {
		cerr << "Leeres Frame erhalten" << endl;
		return -1;
	}
	
	//Erstelle den Pfad, wenn er nicht existiert
	string foldername = "img";
	fs::create_directories(foldername);

	// Hole das aktuelle Datum und die Uhrzeit
    std::cout << "Hole das aktuelle Datum und die Uhrzeit\n" << std::endl;
	auto now = chrono::system_clock::now();
	time_t in_time_t = chrono::system_clock::to_time_t(now);

	// Formatierujng von Datum und Uhrzeit für den Datei namen
    std::cout << "Formatiere Datum und Uhrzeit für Dateiname\n" << std::endl;
    stringstream ss;
	ss << put_time(localtime(&in_time_t), "%d-%m-%Y_%H-%M");
	filename = foldername + "/" + ss.str() + ".png";

	//Speicher das Bild als PNG
    std::cout << "Speichere das Bild\n" << std::endl;
    bool isSaved = imwrite(filename, frame);
	if(!isSaved) {
		cerr << "Fehler beim speichern des Bildes!" << endl;
		return -1;
	}
	
    std::cout << "Bild erfolgreich gespeichert unter: " << filename << endl;
    std::cout << "Filename = Day - Month - Year : Hour - Minute" << endl;
	
    //Ändere Dateiname für die Datenbank
    std::cout << "Ändere Dateiname für die Datenbank\n" << std::endl;
    filename = ss.str() + ".png";
    // Lade das Bild in die Datenbank hoch 
    std::cout << "Bild wird hochgeladen...\n" << std::endl;
    upload();

	cap.release();
	return 0;
}
