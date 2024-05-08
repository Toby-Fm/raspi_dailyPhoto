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

<!DOCTYPE html>
<html lang="de">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Pflanzen</title>
        <link rel="stylesheet" href="./src/scss/index.css" >
    </head>
    <body>
        <?php 
        echo $server, "<br>", $user, "<br>", $database, "<br><br>";
        echo "<h1>Willkommen<br></h1>";

        $erg = $conn->query("SELECT id, bild, bildname FROM bilder");
        if ($erg === false) {
            echo "Fehler: " . $conn->error;
        } else {
            while($row = $erg->fetch_assoc()) {
                echo "ID: " . $row['id'] . "<br>";
                if ($row['bild']) {
                    // Die Bilddaten werden in Base64 umgewandelt und direkt im <img>-Tag eingefügt
                    $base64 = 'data:image/png;base64,' . base64_encode($row['bild']);
                    echo "<img src='" . $base64 . "' alt='" . htmlspecialchars($row['bildname']) . "'><br><br>";
                }
                echo "Bildname: " . $row['bildname'] . "<br><br>";
            }
        }
        ?>
    </body>
</html>