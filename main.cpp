#include "functions.h"

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::vector<long double> coefficients = getCoefficients(str);
    std::pair<long double, long double> ans = solveQuadraticEquation(coefficients);
    std::cout << "Answer: " << ans.first << " ; " << ans.second << std::endl;
    return 0;
}