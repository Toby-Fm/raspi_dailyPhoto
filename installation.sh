#/bin/bash!

# Abhängigkeiten installieren
sudo apt-get update -y

# shh installieren
echo "Installing ssh..."
sudo apt-get install openssh-server -y
# ssh starten, automatisch starten beim booten
echo "Starting ssh and enabling it on boot..."
sudo systemctl start ssh && sudo systemctl enable ssh

# C++, G++ & Make ready machen
echo "Installing C++, G++ & Make..."
sudo apt-get install g++ make -y
sudo apt-get  install build-essential libssl-dev -y

# weitere Abhängigkeiten installieren
echo "Installing libmysqlcppconn..."
sudo apt-get install libmysqlcppconn-dev -y

echo "Installing libmysqlclient..."
sudo apt-get install default-libmysqlclient-dev -y

echo "Installing default-mysql-client"
sudo apt-get install default-mysql-client -y

# Zugriff auf Seriellen Port
echo "Installing libserial..."
sudo apt-get install libserial-dev -y
# Zugriff auf USB-Webcam
echo "Installing fswebcam..."
sudo apt-get install libopencv-dev -y

# Git installieren
echo "Installing Git..."
sudo apt-get install git -y

# Git-Reposetory clonen
echo "Cloning Repository..."
git clone https://github.com/Toby-Fm/raspi_dailyPhoto.git ~/Desktop/

# daily Script ausführbar machen
chmod +x ~/Desktop/raspi_dailyPhoto/raspi/src/daily.sh

# daily Script in crontab eintragen
(crontab -l 2>/dev/null; echo "0 15 * * * ~/Desktop/raspi_dailyPhoto/raspi/src/daily.sh") | crontab -

echo "Installation abgeschlossen und Cronjob eingetragen!"
