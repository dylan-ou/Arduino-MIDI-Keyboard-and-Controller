// Group 53
//
// Dylan Ou - dou5
// Rohan Verma - rverma26
//
// Project: Arduino MIDI piano and controller
//
// Abstract:
// Our project is a piano that can be plugged into a computer and be able to play 
// notes in music making software. The piano includes several knobs and a joystick to 
// control effects. The LCD screen will display the value of the controller being affected. 
// This device can be used for live performances, recording, etc. 

#include <MIDI.h>

#include "pitches.h"

#define NUM_BUTTONS 12
#define THRESHOLD 5
#define NOTE_LENGTH 50
#define VEL_SENSE_VAL 2

const int buttonPin1 = 52;     // the number of the pushbutton pin
const int buttonPin2 = 51;     // the number of the pushbutton pin
const int buttonPin3 = 48;     // the number of the pushbutton pin
const int buttonPin4 = 46;     // the number of the pushbutton pin
const int buttonPin5 = 44;     // the number of the pushbutton pin
const int buttonPin6 = 42;     // the number of the pushbutton pin
const int buttonPin7 = 40;     // the number of the pushbutton pin
const int buttonPin8 = 38;     // the number of the pushbutton pin
const int buttonPin9 = 36;     // the number of the pushbutton pin
const int buttonPin10 = 34;     // the number of the pushbutton pin
const int buttonPin11 = 32;     // the number of the pushbutton pin
const int buttonPin12 = 30;

int val = 0;
int lastVal = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;

int val5 = 0;
int lastVal5 = 0;
int val6 = 0;
int lastVal6 = 0;

const int buttonDown = 8;
const int buttonUp = 9;

const int buttons[NUM_BUTTONS] = {buttonPin1, buttonPin2, buttonPin3,
                                  buttonPin4, buttonPin5, buttonPin6, buttonPin7, buttonPin8, buttonPin9,
                                  buttonPin10, buttonPin11, buttonPin12
                                 };

int buttonRead[NUM_BUTTONS];

int notes[] = {
  NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2,
  NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3,
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
  NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
  NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
  NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

String noteNames[] = {
  "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "
};

int keyStart = 24;

struct MySettings : public midi::DefaultSettings
{
  static const bool UseRunningStatus = false;
  static const long BaudRate = 115200;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

const int velocity = 127; //Max Velocity (range is 0-127)
const int channel = 1; //MIDI Channel 1 (out of 16)

bool noteIsOn[NUM_BUTTONS] = {false};
int midiNoteTime[NUM_BUTTONS] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
  for (int i = 0; i < NUM_BUTTONS; i++)
    pinMode(buttons[i], INPUT_PULLUP);

  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  MIDI.begin();
}

void loop() {

  // put your main code here, to run repeatedly:
  int buttonStateUp = digitalRead(buttonUp);
  int buttonStateDown = digitalRead(buttonDown);

  val = analogRead(0) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  {
    MIDI.sendControlChange(16, val, 1);
  }         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
  lastVal = val;

  val2 = analogRead(2) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val2 != lastVal2)
  {
    MIDI.sendControlChange(17, val2, 2);
  }         // 176 = CC command, 2 = Which Control, val = value read from Potentionmeter 2
  lastVal2 = val2;

  val3 = analogRead(4) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val3 != lastVal3)
  {
    MIDI.sendControlChange(18, val3, 3);
  }         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
  lastVal3 = val3;

  val4 = analogRead(6) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val4 != lastVal4)
  {
    MIDI.sendControlChange(19, val4, 4);
  }         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
  lastVal4 = val4;

  val5 = analogRead(8) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val5 != lastVal5)
  {
    MIDI.sendControlChange(20, val5, 5);
  }         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
  lastVal5 = val5;

  val6 = analogRead(10) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val6 != lastVal6)
  {
    MIDI.sendControlChange(21, val6, 6);
  }         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
  lastVal6 = val6;
  //delay(15); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.


  if (buttonStateUp == HIGH) {
    keyStart = keyStart + 12;
    if (keyStart > 60) {
      keyStart = 60;
    }
    delay(250);
  }

  if (buttonStateDown == HIGH) {
    keyStart = keyStart - 12;
    if (keyStart < 0) {
      keyStart = 0;
    }
    delay(250);
  }

  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttonRead[i] = digitalRead(buttons[i]);

    if (buttonRead[i] == HIGH && noteIsOn[i] == false) {

      MIDI.sendNoteOn(notes[keyStart + i], velocity, channel);
      noteIsOn[i] = true;
      midiNoteTime[i] = NOTE_LENGTH;
    }

    if (noteIsOn[i] == true) {
      Serial1.print(noteNames[i]);
      Serial1.print("\n");
      if (buttonRead[i] == LOW) {
        MIDI.sendNoteOff(notes[keyStart + i], 0, channel);
        noteIsOn[i] = false;
      }
    }
  }
  
  
  //pause the loop
  delay(5);
}
