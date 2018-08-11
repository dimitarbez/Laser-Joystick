// Henry's Bench
// KY-008 Tutorial... On then Off


#include <Servo.h>
Servo servo1;
Servo servo2;
int x_key = A1;
int y_key = A0;
int x_pos;
int y_pos;
int but = 2;

int del = 100;

int servo2_pin = 9;
int initial_position = 90;
int initial_position1 = 90;

int buttonState = 0;
int trig = 0;
int laserPin = 10;

int toggle = 1;
int val;

void setup()
{
	Serial.begin(9600);
	serSetup();
	pinMode(but, INPUT_PULLUP);
	pinMode(laserPin, OUTPUT); // define the digital output interface 13 feet
}
void loop() {

	serLoop();

	buttonState = digitalRead(but);

	if (buttonState == LOW)
	{

		toggle = toggle * -1;

		if (toggle == 1)
		{
			val = LOW;
		}

		else if (toggle == -1)
		{
			val = HIGH;
		}

		digitalWrite(LED_BUILTIN, HIGH);
		digitalWrite(laserPin, val);

	}




}



void serSetup()
{

	servo2.attach(servo2_pin);

	servo2.write(initial_position1);
	pinMode(x_key, INPUT);
	pinMode(y_key, INPUT);
}

void serLoop()
{
	x_pos = analogRead(x_key);
	y_pos = analogRead(y_key);

	if (x_pos < 300) {
		if (initial_position < 10) {}
		else { initial_position1 = initial_position1 - 10; servo2.write(initial_position1); delay(60); }
	} if (x_pos > 700) {
		if (initial_position > 180)
		{
		}
		else {
			initial_position1 = initial_position1 + 10;
			servo2.write(initial_position1);
			delay(60);
		}
	}

	if (y_pos < 300) {
		if (initial_position1 < 10) {}
		else { initial_position1 = initial_position1 - 1; servo2.write(initial_position1); delay(del); }
	} if (y_pos > 700) {
		if (initial_position1 > 180)
		{
		}
		else {
			initial_position1 = initial_position1 + 1;
			servo2.write(initial_position1);
			delay(del);
		}
	}
}