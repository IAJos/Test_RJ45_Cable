#ifndef FIL_H
#define FIL_H

/// @brief This class determines the communication of a wire 
///        within a cable between its ends.
class Fil
{
    private:
        /// @brief This property represents the pin to which 
        ///        the left end of a wire will be connected
        int f_leftPin;

        /// @brief This property represents the pin to which 
        ///        the straight end of a wire will be connected
        int f_rightPin;

    public:
        /// @brief The constructor of our Fil class
        /// @param leftPin Represents the pin to which the left 
        ///                end of a wire will be connected
        /// @param rightPin Represents the pin to which the straight 
        ///                 end of a wire will be connected
        Fil(int leftPin, int rightPin);

        /// @brief The destructor of our Fil class
        ~Fil();

        /// @brief This function returns an integer representing the pin 
        ///        to which the left end of the wire is connected.
        /// @return int : Pin to which the left end of the wire is connected
        int getLeftPin();

        /// @brief This function returns an integer representing the pin 
        ///        to which the straight end of the wire is connected
        /// @return int : Pin to which the right end of the wire is connected
        int getRightPin();
};

#endif // FIL_H