#include <Arduino.h>
#include "Fil.hpp"
#include "Cable.hpp"
#include <vector>

// Definition of left end pin with color name as identifier
#define LEFT_FIL_WHITE_ORANGE 15
#define LEFT_FIL_ORANGE 2
#define LEFT_FIL_WHITE_GREEN 4
#define LEFT_FIL_BLUE 5
#define LEFT_FIL_WHITE_BLUE 18
#define LEFT_FIL_GREEN 19
#define LEFT_FIL_WHITE_BRAIN 21
#define LEFT_FIL_BRAIN 22

// Definition of right end pin with color name as identifier
#define RIGHT_FIL_WHITE_ORANGE 13
#define RIGHT_FIL_ORANGE 14
#define RIGHT_FIL_WHITE_GREEN 27
#define RIGHT_FIL_BLUE 26
#define RIGHT_FIL_WHITE_BLUE 25
#define RIGHT_FIL_GREEN 33
#define RIGHT_FIL_WHITE_BRAIN 32
#define RIGHT_FIL_BRAIN 23

using namespace std;

//Creating our wire objects
Fil filHalfFullOrange(LEFT_FIL_WHITE_ORANGE, RIGHT_FIL_WHITE_ORANGE);
Fil filFullOrange(LEFT_FIL_ORANGE, RIGHT_FIL_ORANGE);
Fil filHalfFullGreen(LEFT_FIL_WHITE_GREEN, RIGHT_FIL_WHITE_GREEN);
Fil filFullBlue(LEFT_FIL_BLUE, RIGHT_FIL_BLUE);
Fil filHalfFullBlue(LEFT_FIL_WHITE_BLUE, RIGHT_FIL_WHITE_BLUE);
Fil filFullGreen(LEFT_FIL_GREEN, RIGHT_FIL_GREEN);
Fil filHalfFullBrain(LEFT_FIL_WHITE_BRAIN, RIGHT_FIL_WHITE_BRAIN);
Fil filFullBrain(LEFT_FIL_BRAIN, RIGHT_FIL_BRAIN);

//Creation of our vector containing our wires
vector<Fil> fils = {filHalfFullOrange, filFullOrange, filHalfFullGreen, filFullBlue, filHalfFullBlue, filFullGreen, filHalfFullBrain, filFullBrain};

//Creating our cable object
Cable cableRJ45(fils.data(), "None");

void setup() {
  Serial.begin(9600);

  Serial.println("\n------------------------ Before RJ45 Test ------------------------\n");
  Serial.println(cableRJ45.cableDescription().c_str());
  
  cableRJ45.verifyCable();

  Serial.println("\n------------------------ After RJ45 Test ------------------------\n");
  Serial.println(cableRJ45.cableDescription().c_str());
}

void loop() {}