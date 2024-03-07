#include "Cable.hpp"
#include <Arduino.h>
#include <string>

using namespace std;

/// @brief The constructor of our Cable class
/// @param fils Represents all the wires in the cable
/// @param cableType Allows to indicate the cable type
Cable::Cable(Fil* fils, string cableType)
{
    c_fils = fils;
    c_cableType = cableType; 
}

/// @brief The destructor of our Cable class
Cable::~Cable(){}

/// @brief This function returns, as a pointer, all the wires contained in the cable.
/// @return Fil* : All wire in a cable 
Fil* Cable::getFils(){return c_fils;}

/// @brief This function returns the cable type
/// @return string : Cable type
string Cable::getCableType(){return c_cableType;}

/// @brief This method modifies the cable type
/// @param cableType Represents the new value of cable type
void Cable::setCableType(string cableType){c_cableType = cableType;}

/// @brief This method checks communication and cable configuration
void Cable::verifyCable()
{
    int taille = 8;
    int filDisposition[taille];

    //We run both ends of the wires to test communication
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++) 
        {
            //communication check
            int read = verifyCommunicationBetweenFil((*(getFils() + i)).getLeftPin(), (*(getFils() + j)).getRightPin());
            if(read == 1)
            {
                // save our cable configuration
                filDisposition[i] = j;
                break;
            }
        }
    }

    /*
        If our cable configuration table is already sorted, it's a straight cable.
        If not, we check the configuration of the crossed cable and if it matches, it's a crossed cable.
        Otherwise, the cable type is unknown 
    */
    if (isSorted(filDisposition, taille))
        setCableType("RJ45 Droit");
    else if(filDisposition[0] == 2 && filDisposition[1] == 5 && filDisposition[2] == 0 && filDisposition[3] == 3 &&
            filDisposition[4] == 4 && filDisposition[5] == 1 && filDisposition[6] == 6 && filDisposition[7] == 7)
        setCableType("RJ45 Croisé");
    else
        setCableType("Undifine");
}

/// @brief This function checks communication between the 
///        two ends of a wire in the cable.
/// @param leftPin Represents the pin to which the left 
///                end of a wire will be connected 
/// @param rightPin Represents the pin to which the straight 
///                 end of a wire will be connected
/// @return int  : 1 if the communication went well (the right-hand end received the 1 sent by the left-hand end) or 
///                0 if the communication went badly (the right-hand end did not receive the 1 sent by the left-hand end).
int Cable::verifyCommunicationBetweenFil(int leftPin, int rightPin)
{
    int result = 0;

    pinMode(leftPin, OUTPUT);
    pinMode(rightPin, INPUT_PULLDOWN);
    
    digitalWrite(leftPin, HIGH);
    delay(100);
    result = digitalRead(rightPin) == HIGH ? 1 : 0;
    digitalWrite(leftPin, LOW);

    return result;
}

/// @brief This function returns a Boolean indicating whether the matching 
///        configuration between the two cable ends is sorted or not.
/// @param tableau Represents the array containing our match configuration
/// @param taille Represents the array size
/// @return bool : true if the array is sorted or false is the isn't sorted
bool Cable::isSorted(int tableau[], int taille) 
{
    for (int i = 0; i < taille - 1; ++i)
        if (tableau[i] > tableau[i + 1])
            return false;

    return true;
}

/// @brief This function returns the cable description
/// @return string : Description of the câble
std::string Cable::cableDescription()
{
    return "Cable : \n\tType : " + c_cableType;
}
