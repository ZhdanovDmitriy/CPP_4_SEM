#include "functions.h"

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::vector<int> coefficients = getCoefficients(str);
    std::cout << "�������� ���������� github � VS2022" << std::endl;
    return 0;
}