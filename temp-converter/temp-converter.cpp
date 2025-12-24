#include <iostream>
#include <string>

// get input from terminal
void getUserInput(double* inputTemp, std::string* tempType) {
    std::cout << "Enter a temperature value:";
    std::cin >> *inputTemp;
    std::cout << "Enter a temperature unit (C | F | K):";
    std::cin >> *tempType;
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
void printConvertedTemps(double fahrenheit, double celsius, double kelvin) {
    std::cout << "Your input temperature is equivalent to:\n";
    std::cout << fahrenheit << " degrees Fahrenheit\n";
    std::cout << celsius << " degrees Celsius\n";
    std::cout << kelvin << " Kelvin\n";
}

int main () {
    // initialize variables for user input
    double inputTemp{};
    std::string tempType{};
    double tempC{};
    double tempF{};
    double tempK{};

    // get input
    getUserInput(&inputTemp, &tempType);

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
        return 0;
    }

    // print output
    printConvertedTemps(tempF, tempC, tempK);

    return 0;
}
