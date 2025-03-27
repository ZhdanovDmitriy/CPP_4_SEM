#include "functions.h"

int main() {
    std::string str;
    printHead();
    std::getline(std::cin, str);
    std::vector<long double> coefficients = getCoefficients(str);
    if (isCorrectQuadraticEquation(coefficients)) {
        std::pair<long double, long double> ans = solveQuadraticEquation(coefficients);
        std::cout << "Answers: x = " << ans.first << " and x = " << ans.second << std::endl;
    }
    return 0;
}