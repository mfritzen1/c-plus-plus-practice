#include <iostream>
#include <limits>
#include "validate-input.h"

bool validateInput() {
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}