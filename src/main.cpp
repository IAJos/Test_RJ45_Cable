#include <Arduino.h>
#include "Fil.hpp"
#include "Cable.hpp"
#include <vector>

#define LEFT_FIL_HALF_FULL_ORANGE 15
#define LEFT_FIL_FULL_ORANGE 2
#define LEFT_FIL_HALF_FULL_GREEN 4
#define LEFT_FIL_FULL_BLUE 5
#define LEFT_FIL_HALF_FULL_BLUE 18
#define LEFT_FIL_FULL_GREEN 19
#define LEFT_FIL_HALF_FULL_BRAIN 21
#define LEFT_FIL_FULL_BRAIN 22

#define RIGHT_FIL_HALF_FULL_ORANGE 13
#define RIGHT_FIL_FULL_ORANGE 14
#define RIGHT_FIL_HALF_FULL_GREEN 27
#define RIGHT_FIL_FULL_BLUE 26
#define RIGHT_FIL_HALF_FULL_BLUE 25
#define RIGHT_FIL_FULL_GREEN 33
#define RIGHT_FIL_HALF_FULL_BRAIN 32
#define RIGHT_FIL_FULL_BRAIN 23

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}