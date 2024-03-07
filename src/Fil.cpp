#include <Arduino.h>
#include "Fil.hpp"
#include <string>

using namespace std;

/// @brief The constructor of our Fil class
/// @param leftPin Represents the pin to which the left 
///                end of a wire will be connected
/// @param rightPin Represents the pin to which the straight 
///                 end of a wire will be connected
Fil::Fil(int leftPin, int rightPin)
{
    f_leftPin = leftPin;
    f_rightPin = rightPin;
}

/// @brief The destructor of our Fil class
Fil::~Fil(){}

/// @brief This function returns an integer representing the pin 
///        to which the left end of the wire is connected.
/// @return int : Pin to which the left end of the wire is connected
int Fil::getLeftPin(){return f_leftPin;}

/// @brief This function returns an integer representing the pin 
///        to which the straight end of the wire is connected
/// @return int : Pin to which the right end of the wire is connected
int Fil::getRightPin(){return f_rightPin;}