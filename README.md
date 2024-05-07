[![Time](https://wakatime.com/badge/user/018dc353-a556-4a78-9feb-f5414f04187a/project/b7c71912-ed84-4618-a95c-9226fecd3eb5.svg)](https://wakatime.com/badge/user/018dc353-a556-4a78-9feb-f5414f04187a/project/b7c71912-ed84-4618-a95c-9226fecd3eb5)

# Pflanzenwachstum-Tracker

Dieses Projekt nutzt einen Raspberry Pi und eine angeschlossene Webcam, um täglich zur gleichen Zeit Fotos von einer Pflanze zu machen. Das Ziel ist es, die Entwicklung und das Wachstum der Pflanze über die Zeit visuell festzuhalten.

## Projektbeschreibung

Der Raspberry Pi ist mit einer Webcam verbunden, die so positioniert ist, dass sie eine Pflanze aufnehmen kann. Ein C++-Programm steuert die Webcam, um täglich zur festgelegten Zeit ein Foto zu machen. Die Fotos werden mit einem Zeitstempel versehen und in eine Datenbank bzw. in einem zusätlichen "img"-Ordner gespeichert, sodass sie leicht chronologisch sortiert und betrachtet werden können.

Zusätzlich zu dem C++-Programm, wurde eine Webseite in PHP entwickelt, die die Bilder aus der Datenbank abholt und auf der Webseite präsentiert. Diese Webseite ermöglicht es, die Entwicklung und das Wachstum der Pflanze über die Zeit visuell nachzuvollziehen.

Die Website ist inklusive, sie holt die Bilder aus der Datenbank und zeigt sie auf der Seite an.

## Website

Die Website wird auf einem konfigurierten nginx-Server betrieben, der in diesem Projekt nicht enthalten ist. Daher wird auch eine Datenbank verwendet, um die Bilder abzurufen und darzustellen. Obwohl die Datenbank nicht unbedingt erforderlich ist, da die Bilder auch in einem "img"-Ordner gespeichert werden, ermöglicht sie eine einfache Abrufung der Bilder aus dem Ordner.

## Hardware-Anforderungen

-   Raspberry Pi 5 _(Getestet nur auf Raspberry 5)_
-   Kompatible USB-Webcam
-   SD-Karte mit Raspberry Pi OS-64Bit installiert
-   Stromversorgung für den Raspberry Pi

## Software-Anforderungen

-   Raspberry Pi OS oder eine vergleichbare Linux-Distribution
-   C++ Entwicklungsumgebung (g++, Make)
-   OpenCV-Bibliothek zur Bildaufnahme und -verarbeitung

##
