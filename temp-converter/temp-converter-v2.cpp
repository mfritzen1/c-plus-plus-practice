#include <iostream>
#include <string>
#include <limits>
#include "../utilities/validate-input.h"

// bool validateInput() {
//     if (!std::cin) {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         return false;
//     }

//     return true;
// }

// get input from terminal
bool getUserInput(double* inputTemp, std::string* tempType) {
    std::cout << "Enter a temperature value:";
    std::cin >> *inputTemp;
    if (!validateInput()) {
        return false;
    }
    std::cout << "Enter a temperature unit (C | F | K):";
    std::cin >> *tempType;
    return true;
}

void askToContinue(bool* isActive) {
    std::string userInput{};
    std::cout << "Would you like to convert another temperature? (y/n)";
    std::cin >> userInput;
    if (userInput != "y" && userInput != "Y" && userInput != "yes" && userInput != "Yes") {
        *isActive = false;
    }
}

// converts celsius double to fahrenheit double
double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// converts fahrenheit double to celsius double
double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// converts celsius double to kelvin double
double convertCelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// take a wild guess
double convertKelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// outputs converted temperatures to terminal
void printConvertedTemps(double fahrenheit, double celsius, double kelvin, double inputTemp) {
    bool isF{fahrenheit == inputTemp};
    bool isC{celsius == inputTemp};
    bool isK{kelvin == inputTemp};
    std::string tempTypeName{};

    // determine string of temperature type, used in output
    if (isF) {
        tempTypeName = " degrees fahrenheit";
    } else if (isC) {
        tempTypeName = " degrees celsius";
    } else {
        tempTypeName = " kelvin";
    }

    // print results, skip the one that is equivalent to the input
    if (kelvin < 0) {
        std::cout << "Your input temperature (" << inputTemp << tempTypeName << ") is less than absolute zero, but if it was possible to reach this temperature it would be equivalent to:\n";
    } else {
        std::cout << "Your input temperature (" << inputTemp << tempTypeName << ") is equivalent to:\n";
    }

    if (!isF) {
        std::cout << fahrenheit << " degrees Fahrenheit\n";
    }
    if (!isC) {
        std::cout << celsius << " degrees Celsius\n";
    }
    if (!isK) {
        std::cout << kelvin << " Kelvin\n";
    }
}

int main () {
    // initialize variables for user input
    double inputTemp{};
    std::string tempType{};
    double tempC{};
    double tempF{};
    double tempK{};
    bool isActive{true};

    while (isActive) {
        bool isInputValid{true};

        // get input
        if(!getUserInput(&inputTemp, &tempType)) {
            std::cout << "Invalid input.\n";
            askToContinue(&isActive);
            continue;
        }

        // convert temperatures
        if (tempType == "f" || tempType == "F" || tempType == "fahrenheit" || tempType == "Fahrenheit") {
            tempF = inputTemp;
            tempC = convertFahrenheitToCelsius(tempF);
            tempK = convertCelsiusToKelvin(tempC);
        } else if (tempType == "c" || tempType == "C" || tempType == "celsius" || tempType == "Celsius") {
            tempC = inputTemp;
            tempF = convertCelsiusToFahrenheit(tempC);
            tempK = convertCelsiusToKelvin(tempC);
        } else if (tempType == "k" || tempType == "K" || tempType == "kelvin" || tempType == "Kelvin") {
            tempK = inputTemp;
            tempC = convertKelvinToCelsius(tempK);
            tempF = convertCelsiusToFahrenheit(tempC);
        } else {
            std::cout << "Temperature unit not recognized\n";
            isInputValid = false;
        }

        // print output
        if (isInputValid) {
            printConvertedTemps(tempF, tempC, tempK, inputTemp);
        }

        // ask user if they want to continue
        askToContinue(&isActive);

        std::cout << "Thanks for using this temperature converter!\n";
    }

    return 0;
}
