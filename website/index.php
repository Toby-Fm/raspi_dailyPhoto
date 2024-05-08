<?php
include "./src/php/db.config.php";
// Verbindung zur Datenbank
$conn = new mysqli($server, $user, $password, $database);
// Überprüfen der Verbindung
if ($conn->connect_error) {
    die("Verbindung Fehlgeschlagen: " . $conn->connect_error);
}
echo "Verbindung Erfolgreich<br><br>";
?>
