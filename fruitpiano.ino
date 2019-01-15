#include "Arduino.h" 
#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h" 

#define s1 6 
#define s2 7 
#define s3 8 
#define s4 9 
#define s5 10 
#define s6 11 
#define s7 12 
SoftwareSerial mySoftwareSerial(2, 3); // RX, TX 

DFRobotDFPlayerMini myDFPlayer; 
//void printDetail(uint8_t type, int value); 

void setup() 
{ 
mySoftwareSerial.begin(9600); 
if (!myDFPlayer.begin(mySoftwareSerial, false)) { //Use softwareSerial to communicate with mp3. 
// while (true) { 
// delay(0); // Code to compatible with ESP8266 watch dog. 
//} 
 Serial.begin(115200); 
//Serial.print("hey"); 
} 

myDFPlayer.volume(30); //Set volume value. From 0 to 30 
myDFPlayer.EQ(DFPLAYER_EQ_BASS);
// myDFPlayer.play(1); //Play the first mp3 
pinMode(s1, INPUT); 
pinMode(s2, INPUT); 
pinMode(s3, INPUT); 
pinMode(s4, INPUT); 
pinMode(s5, INPUT); 
pinMode(s6, INPUT); 
pinMode(s7, INPUT); 

//// 
myDFPlayer.play(7); 
delay(1000); 
//// 
} 
int whichButton() { 
int num = 0; 
int num2 = 0; 
for (int i = 1; i < 8; i++) { 
int count1 = 0; 
for (int z = 0; z < 5; z++) { 
if (!digitalRead(i + 5)) { 
count1 = count1 + 1; 
} 
} 
//
if (count1 > 0) { 
num = i; 
}
// 
} 

//here renumber for correct playing
Serial.println(num); 
return num; 
} 
int lastPressed = 0; 


#define n0 1 
#define n1 2 
#define n2 6 
#define n3 4 
#define n4 3 
#define n5 3 
void loop() 
{ 
static unsigned long timer = millis(); 
if (millis() - timer > 400) { 
timer = millis(); 
int button = whichButton(); 

if (button != 0) { 
myDFPlayer.play(button);//////////////////////////////////////////////////
button = 0; 
}

} 


}
