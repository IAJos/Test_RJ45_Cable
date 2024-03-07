#ifndef CABLE_H
#define CABLE_H

#include "Fil.hpp"
#include <string>

/// @brief This class is used to determine the configuration of 
///        the cable: whether it's a straight cable or a crossover 
///        cable, or whether it's a bad cable.
class Cable
{
    private:
        /// @brief This property represents all the wires in the cable
        Fil* c_fils;

        /// @brief This property indicates the cable type
        std::string c_cableType;

        /// @brief This function returns a Boolean indicating whether the matching 
        ///        configuration between the two cable ends is sorted or not.
        /// @param tableau Represents the array containing our match configuration
        /// @param taille Represents the array size
        /// @return bool : true if the array is sorted or false is the isn't sorted
        bool isSorted(int tableau[], int taille);

    public:
        /// @brief The constructor of our Cable class
        /// @param fils Represents all the wires in the cable
        /// @param cableType Allows to indicate the cable type
        Cable(Fil* fils, std::string cableType);

        /// @brief The destructor of our Cable class
        ~Cable();

        /// @brief This function returns, as a pointer, all the wires contained in the cable.
        /// @return Fil* : All wire in a cable 
        Fil* getFils();

        /// @brief This function returns the cable type
        /// @return string : Cable type
        std::string getCableType();

        /// @brief This method modifies the cable type
        /// @param cableType Represents the new value of cable type
        void setCableType(std::string cableType);

        /// @brief This method checks communication and cable configuration
        void verifyCable();

        /// @brief This function checks communication between the 
        ///        two ends of a wire in the cable.
        /// @param leftPin Represents the pin to which the left 
        ///                end of a wire will be connected 
        /// @param rightPin Represents the pin to which the straight 
        ///                 end of a wire will be connected
        /// @return int  : 1 if the communication went well (the right-hand end received the 1 sent by the left-hand end) or 
        ///                0 if the communication went badly (the right-hand end did not receive the 1 sent by the left-hand end).
        int verifyCommunicationBetweenFil(int leftPin, int rightPin);

        /// @brief This function returns the cable description
        /// @return string : Description of the câble
        std::string cableDescription();
};

#endif // CABLE_H