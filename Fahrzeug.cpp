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

const int ENA=27;
const int IN1=25;
const int IN2=24;

const int IN3=23;
const int IN4=22;
const int ENB=28;
string eingabe;
int test;

   pinMode(ENA, OUTPUT);
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);
   pinMode(ENB, OUTPUT);
   digitalWrite(IN1, 0);
   digitalWrite(IN2, 0);
   digitalWrite(IN3, 0);
   digitalWrite(IN4, 0);
   digitalWrite(ENA, 0);
   digitalWrite(ENB, 0);
     delay(50);
   digitalWrite(ENA, 1);
   digitalWrite(ENB, 1);

while (eingabe != "x") {
//Für die Benutzereingabe:
eingabe=getch();

	if (eingabe == "8") {
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        digitalWrite(IN3, 1);
        digitalWrite(IN4, 0);
	} else if (eingabe == "2") {
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 1);
        digitalWrite(IN3, 0);
        digitalWrite(IN4, 1);
	} else if (eingabe == "5") {
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 0);
        digitalWrite(IN3, 0);
        digitalWrite(IN4, 0);
	} else if (eingabe == "4") {
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        digitalWrite(IN3, 0);
        digitalWrite(IN4, 0);
	} else if (eingabe == "6") {
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 0);
        digitalWrite(IN3, 1);
        digitalWrite(IN4, 0);
	} else if (eingabe == "7") {
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        digitalWrite(IN3, 0);
        digitalWrite(IN4, 1);
	} else if (eingabe == "9") {
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 1);
        digitalWrite(IN3, 1);
        digitalWrite(IN4, 0);
	}
delay(200);
}
/*
system("pigs p 26 255");
system("pigs p 13 255");
*/
digitalWrite(IN1, 0);
digitalWrite(IN2, 0);
digitalWrite(IN3, 0);
digitalWrite(IN4, 0);
digitalWrite(ENA, 0);
digitalWrite(ENB, 0);
return 0;
}
