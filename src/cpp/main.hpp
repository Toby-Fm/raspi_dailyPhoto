#pragma once
#include "db.config.hpp"

#include <fstream>
#include <vector>
#include <cstring>

std::string filename;
MYSQL* conn;


void connect() {
    std::cout << "Baue eine Verbindung zur Datenbank auf" << std::endl;
  
    conn = mysql_init(NULL);
    conn = mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
    if (conn) {
        std::cout << "Verbindung erfolgreich\n" << std::endl;
    } else {
        std::cout << "Verbindung Fehlgeschlagen" << std::endl;
    }
}

void upload() {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    // Vector ist der Fehler, Bild ist Größer als 'MAX_SIZE'
    std::cout << "Dateigröße: " << size << std::endl;
    std::vector<char>buffer(size);
    
    if (file.read(buffer.data(), size)) {
        // Bereite den MySQL Befehl vector
        std::string query = "INSERT INTO bilder (bild, bildname) VALUES(?, ?)";
        MYSQL_STMT* stmt = mysql_stmt_init(conn);
        if (stmt) {
            if (mysql_stmt_prepare(stmt, query.c_str(), query.length()) == 0) {
                MYSQL_BIND bind[2];
                memset(bind, 0, sizeof(bind));

                // Bild
                std::cout << "Bild wid vorbereitet\n" << std::endl;
                bind[0].buffer_type = MYSQL_TYPE_BLOB;
                bind[0].buffer = (char*)buffer.data();
                bind[0].buffer_length = buffer.size();

                // Bildname
                std::cout << "Bildname wird vorbereitet\n" << std::endl;
                std::string bildname = filename;
                bind[1].buffer_type = MYSQL_TYPE_STRING;
                bind[1].buffer = (char*)bildname.data();
                bind[1].buffer_length = bildname.size();

                mysql_stmt_bind_param(stmt, bind);
                if (mysql_stmt_execute(stmt) == 0) {
                    std::cout << "Bild erfolgreich hochgeladen.\n" << std::endl;
                } else {
                    std::cerr << "Fehler beim Hochladen des Bildes: " << mysql_stmt_error(stmt) << std::endl;
                }
                mysql_stmt_close(stmt);
            }
        }
    } else {
        std::cerr << "Fehler beim Lesen der Datei." << std::endl;
    }
    mysql_close(conn);
}
