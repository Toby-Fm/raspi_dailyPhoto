CREATE DATABASE Pflanzen;

USE Pflanzen;

CREATE TABLE bilder (
	id INT AUTO_INCREMENT PRIMARY KEY,
	bild LONGBLOB,
	bildname VARCHAR(255)
);
