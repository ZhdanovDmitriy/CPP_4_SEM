#include "functions.h"

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::vector<int> coefficients = getCoefficients(str);
    return 0;
}
