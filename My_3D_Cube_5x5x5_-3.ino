#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 10  // data pin
#define POTENTIOMETER_PIN A0 // brightness knob
//int   // set brightness here  0-256 with 10 for easy on eyes
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(potentiometerValue, 0, 1023, 0, 255);
 

  
//#define BUTTON_PIN 7
//int buttonState = 0;  // Holds the readout from the button  
//int counter = 3;      // Holds the number as we cycle through them on the display
//bool offed = true;    // To check if the button has been released after pushing 
                        // (otherwise it will get pushed tens of times a second)   
//int numberOfModes = 6;  






// create instance of neo_matrix configured for this display
Adafruit_NeoMatrix cube = Adafruit_NeoMatrix(5, 5, 5, 1, PIN,
                          NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
                          NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                          NEO_RGB            + NEO_KHZ800);

// Color Management
// these are colors that can be specified by GetColor() routine
// calling this routine from 1 to 42 gives you a 42 step rainbow pallette
#define White 43
#define Black 0
#define Red 1
#define Orange 4
#define Yellow 9
#define Green 15
#define Aqua 20
#define Blue 29
#define Purple 34
uint32_t mycolor;
const byte color [44][3] PROGMEM = {  // the color pallette table
  {0, 0, 0}, //Black
  {7, 0, 0}, {7, 1, 0}, {6, 1, 0}, {6, 2, 0}, {5, 2, 0}, {5, 3, 0}, {4, 3, 0}, {4, 4, 0}, {3, 4, 0}, {3, 5, 0}, {2, 5, 0}, {2, 6, 0}, {1, 6, 0}, {1, 7, 0}, // Red to Green
  {0, 7, 0}, {0, 7, 1}, {0, 6, 1}, {0, 6, 2}, {0, 5, 2}, {0, 5, 3}, {0, 4, 3}, {0, 4, 4}, {0, 3, 4}, {0, 3, 5}, {0, 2, 5}, {0, 2, 6}, {0, 1, 6}, {0, 1, 7}, // Green to Blue
  {0, 0, 7}, {1, 0, 7}, {1, 0, 6}, {2, 0, 6}, {2, 0, 5}, {3, 0, 5}, {3, 0, 4}, {4, 0, 4}, {4, 0, 3}, {5, 0, 3}, {5, 0, 2}, {6, 0, 2}, {6, 0, 1}, {7, 0, 1}, // Blue to Red
  {7, 7, 7}  // White
};

byte myloc[3] = {2, 2, 2};
const byte cubetPath [50][3] PROGMEM = {  // cubet path
  {0, 0, 3}, {0, 1, 3}, {0, 2, 3}, {0, 3, 3}, {1, 3, 3}, {2, 3, 3}, {3, 3, 3}, {3, 2, 3}, {3, 1, 3}, {3, 0, 3}, {2, 0, 3}, {1, 0, 3}, {0, 0, 3},
  {0, 2, 0}, {0, 2, 1}, {0, 2, 2}, {0, 2, 3}, {1, 2, 3}, {2, 2, 3}, {3, 2, 3}, {3, 2, 2}, {3, 2, 1}, {3, 2, 0}, {2, 2, 0}, {1, 2, 0}, {0, 2, 0},
  {0, 0, 2}, {1, 0, 2}, {2, 0, 2}, {3, 0, 2}, {3, 1, 2}, {3, 2, 2}, {3, 3, 2}, {2, 3, 2}, {1, 3, 2}, {0, 3, 2}, {0, 2, 2}, {0, 1, 2}, {0, 0, 2},
  {2, 0, 1}, {1, 0, 1}, {0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}, {3, 1, 1}, {3, 2, 1}, {2, 0, 1}
};

void setup() {
  cube.begin();
//  Serial.begin(9600);
  cube.setTextWrap(false);
  cube.setBrightness(30); 

  // Button stuff
//pinMode(BUTTON_PIN, INPUT_PULLUP);

  

  // TIMER 1 Setup for interrupt frequency 67 Hz = 15 ms refresh rate

  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 67.00167504187604 Hz increments
  OCR1A = 29849; // = 16000000 / (8 * 67.00167504187604) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 8 prescaler
  TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts
  delay(7000);
}
