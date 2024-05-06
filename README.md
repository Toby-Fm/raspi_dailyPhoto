[![Time](https://wakatime.com/badge/user/018dc353-a556-4a78-9feb-f5414f04187a/project/b7c71912-ed84-4618-a95c-9226fecd3eb5.svg)](https://wakatime.com/badge/user/018dc353-a556-4a78-9feb-f5414f04187a/project/b7c71912-ed84-4618-a95c-9226fecd3eb5)
# Pflanzenwachstum-Tracker

Dieses Projekt nutzt einen Raspberry Pi und eine angeschlossene Webcam, um täglich zur gleichen Zeit Fotos von einer Pflanze zu machen. Das Ziel ist es, die Entwicklung und das Wachstum der Pflanze über die Zeit visuell festzuhalten. 

## Projektbeschreibung

Der Raspberry Pi ist mit einer Webcam verbunden, die so positioniert ist, dass sie eine Pflanze aufnehmen kann. Ein C++-Programm steuert die Webcam, um täglich zur festgelegten Zeit ein Foto zu machen. Die Fotos werden mit einem Zeitstempel versehen und in einem zusätlichen "img"-Ordner gespeichert, sodass sie leicht chronologisch sortiert und betrachtet werden können.

## Hardware-Anforderungen

- Raspberry Pi 5 *(Getestet nur auf Raspberry 5)*
- Kompatible USB-Webcam
- SD-Karte mit Raspberry Pi OS-64Bit installiert
- Stromversorgung für den Raspberry Pi

## Software-Anforderungen

- Raspberry Pi OS oder eine vergleichbare Linux-Distribution
- C++ Entwicklungsumgebung (g++, Make)
- OpenCV-Bibliothek zur Bildaufnahme und -verarbeitung
