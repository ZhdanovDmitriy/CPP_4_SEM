#include "functions.h"

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::vector<int> coefficients = getCoefficients(str);
    std::cout << "Проверка сопряжения github с VS2022" << std::endl;
    return 0;
}