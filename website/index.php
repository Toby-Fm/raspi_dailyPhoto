<?php
include "./src/php/db.config.php";
// Verbindung zur Datenbank
$conn = new mysqli($server, $user, $password, $database);
// Überprüfen der Verbindung
if ($conn->connect_error) {
    die("Verbindung Fehlgeschlagen: " . $conn->connect_error);
}
//echo "Verbindung Erfolgreich<br><br>";
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
        <header class="header">
            <h1>Pflanzen</h1>
        </header>
        <div class='gallery'>
            <?php 
                //echo $server, "<br>", $user, "<br>", $database, "<br><br>";
                
                // SQL Abfrage, um Daten aus der Tabelle "Bilder" zu holen
                $erg = $conn->query("SELECT id, bild, bildname FROM bilder");
                while($row = $erg->fetch_assoc()) { // Schleife über jedes Ergebnis der Abfrage
                    // Ausgabe der ID des Bildes
                    //echo "ID: " . $row['id'] . "<br>";
                    if ($row['bild']) {
                        // Die Bilddaten werden in Base64 umgewandelt und direkt im <img>-Tag eingefügt
                        $base64 = 'data:image/png;base64,' . base64_encode($row['bild']);
                        
                        // Erzeugt immer eine neue "Image-box", wenn es neues Bild in der DB ist. 
                        echo "<div class='image-box'>";
                            // Einfügen des Bildes als <img> Element
                            echo "<img class='img' src='" . $base64 . "' alt='" . htmlspecialchars($row['bildname']) . "'>";
                            // Bildnamen in span element packen
                            echo "<span>" . $row['bildname'] . "</span>"; 
                            // Möglichkeit bild in fullscreen zu öffnen
                            echo "<div class='buttons'>";
                                // Download Image
                                echo "<button class='download'>"
                                        . "<a href='" . $base64 . "' download='" . $row['bildname'] . "'>"
                                            . "<img src='./src/assets/svg/download.svg'>"
                                        . "</a>"
                                    . "</button>";
                                // Öffnet das Bild in fullscreen
                                echo "<button class='open'>"
                                        . "<img src='./src/assets/svg/fullscreen_open.svg'>"
                                   . "</button>";
                            echo "</div>";
                        echo "</div>";
                    }
                } 
            ?>
        </div>
        <div id="blurW">
            <div id="myWindow" class="window">
                <div class="window-content">
                    <img class="window-image" id="img01">
                    <span id="window-bildname"></span>
                    <div class="buttons">
                        <button class='close'>
                            <img src='./src/assets/svg/fullscreen_exit.svg'>
                        </button>
                    </div>
                </div>
            </div>
        </div>
        <script type="text/javascript" src="./src/js/index.js"></script>
    </body>
</html>