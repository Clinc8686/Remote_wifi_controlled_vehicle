#!/bin/bash

echo "Bitte Schnelligkeit auswählen (1=langsam, 2=mittel, 3=schnell): "
read speed;

case $speed in
   1)
	echo -e "Starte langsam: \n"
	/home/pi/Fahrzeug/FahrzeugLangsam
	;;
   2)
	echo -e "Starte mittel: \n"
	/home/pi/Fahrzeug/FahrzeugMittel
	;;
   3)
	echo -e "Starte schnell: \n"
	/home/pi/Fahrzeug/FahrzeugSchnell
	;;
   *)
	echo -e "Kappier ich jetzt net lol \n"
	;;
esac
