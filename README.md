[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/Toby-Fm/raspi_dailyPhoto/blob/main/LICENSE)

# 🪴 Pflanzenwachstum-Tracker

Dieses Projekt nutzt einen Raspberry Pi und eine angeschlossene Webcam, um täglich zur gleichen Zeit Fotos von einer Pflanze zu machen. Das Ziel ist es, die Entwicklung und das Wachstum der Pflanze über die Zeit visuell festzuhalten.

## 📔 Projektbeschreibung

Der Raspberry Pi ist mit einer Webcam verbunden, die so positioniert ist, dass sie eine Pflanze aufnehmen kann. Ein C++-Programm steuert die Webcam, um täglich zur festgelegten Zeit ein Foto zu machen. Die Fotos werden mit einem Zeitstempel versehen und in eine Datenbank bzw. in einem zusätlichen "img"-Ordner gespeichert, sodass sie leicht chronologisch sortiert und betrachtet werden können.

Zusätzlich zu dem C++-Programm, wurde eine Webseite in PHP entwickelt, die die Bilder aus der Datenbank abholt und auf der Webseite präsentiert. Diese Webseite ermöglicht es, die Entwicklung und das Wachstum der Pflanze über die Zeit visuell nachzuvollziehen.

Die Website ist inklusive.

## ⌨️  Webseite

Die Website wird auf einem konfigurierten nginx-Server betrieben, `der in diesem Projekt nicht enthalten ist`. Daher wird auch eine Datenbank verwendet, um die Bilder abzurufen und darzustellen. Obwohl die Datenbank nicht unbedingt erforderlich ist, da die Bilder auch in einem "img"-Ordner gespeichert werden, ermöglicht sie eine einfache Abrufung der Bilder aus dem Ordner.

## 💻 Hardware-Anforderungen

-   Raspberry Pi 4 & 5 _(Getestet nur auf Raspberry 4 & 5 x 4gb 64Bit)
-   Kompatible USB-Webcam
-   SD-Karte mit Raspberry Pi OS-64Bit installiert
-   Stromversorgung für den Raspberry Pi

## 💻 Software-Anforderungen

-   Debian / Ubuntu (Getestet nur auf Debian 12)
-   C++ Entwicklungsumgebung (g++, Make usw.)
-   OpenCV-Bibliothek zur Bildaufnahme und -verarbeitung
-   C++ MySQL Bibliotheken für die Verbindung zur Datenbank

## 🔮 Zukunft
Zukünftig steht noch an, den PHP Teil in Go nochmal neu zu machen, um direkt eine Webserver mit bereit zu stellen.
