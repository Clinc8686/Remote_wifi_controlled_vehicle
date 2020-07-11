#include <termios.h>
#include <string.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int getch() {
   static int ch = -1, fd = 0;
   struct termios neu, alt;
   fd = fileno(stdin);
   tcgetattr(fd, &alt);
   neu = alt;
   neu.c_lflag &= ~(ICANON|ECHO);
   tcsetattr(fd, TCSANOW, &neu);
   ch = getchar();
   tcsetattr(fd, TCSANOW, &alt);
   return ch;
}

int main() {
wiringPiSetup();
string eingabe;

system("pigs p 16 255");
system("pigs p 20 255");

while (eingabe != "x") {
//Für die Benutzereingabe:
eingabe=getch();

system("pigs p 16 255");
system("pigs p 20 255");

	if (eingabe == "8") {
	system("pigs p 26 170");
	system("pigs p 19 0");
	system("pigs p 13 170");
	system("pigs p 6 0");
	} else if (eingabe == "2") {
        system("pigs p 26 0");
        system("pigs p 19 170");
        system("pigs p 13 0");
        system("pigs p 6 170");
	} else if (eingabe == "5") {
        system("pigs p 26 0");
        system("pigs p 19 0");
        system("pigs p 13 0");
        system("pigs p 6 0");
	} else if (eingabe == "4") {
        system("pigs p 26 170");
        system("pigs p 19 0");
        system("pigs p 13 0");
        system("pigs p 6 0");
	} else if (eingabe == "6") {
        system("pigs p 26 0");
        system("pigs p 19 0");
        system("pigs p 13 170");
        system("pigs p 6 0");
	} else if (eingabe == "7") {
        system("pigs p 26 170");
        system("pigs p 19 0");
        system("pigs p 13 0");
        system("pigs p 6 170");
	} else if (eingabe == "9") {
        system("pigs p 26 0");
        system("pigs p 19 170");
        system("pigs p 13 170");
        system("pigs p 6 0");
	}
delay(200);
}
system("pigs p 16 0");
system("pigs p 20 0");
system("pigs p 26 0");
system("pigs p 19 0");
system("pigs p 13 0");
system("pigs p 6 0");

return 0;
}
