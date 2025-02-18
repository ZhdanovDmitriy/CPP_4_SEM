#include "functions.h"

std::vector<long double> getCoefficients(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::vector<long double> coefficients;

    std::smatch match;
    // ���������� ���������:
    // ������ 1: ([+-]?\d*)       � ����������� ��� x^2 (����� ���� ������ �������, ���� �������� ������ "x^2")
    // �����: \*?x\^2             � ���� ���������� x^2 (������������ ���������)
    // (?:([+-](\d*))\*?x)?       � ������������ ������ ��� x: ���� ������������, �� ����������� ����������� (������ 2)
    // (?:([+-]\d+))?             � ������������ ������ ��� ���������� ����� �� ����� ����� (������ 3)
    // =([+-]?\d+)$               � ������ ����� ��������� (������ 4)
    std::regex pattern("^([+-]?\\d*)\\*?x\\^2(?:([+-](\\d*))\\*?x)?(?:([+-]\\d+))?=([+-]?\\d+)$");

    if (std::regex_match(str, match, pattern)) {
        // ������ 1: ����������� a
        std::string a_str = match[1].str();
        long double a = 0;
        if (a_str.empty() || a_str == "+")
            a = 1;
        else if (a_str == "-")
            a = -1;
        else
            a = std::stoi(a_str);

        // ������ 2: ����������� b (�����������)
        long double b = 0;
        if (match[2].matched) {
            std::string b_str = match[2].str();
            if (b_str == "+" || b_str == "")
                b = 1;
            else if (b_str == "-")
                b = -1;
            else
                b = std::stoi(b_str);
        }
        else {
            b = 0;
        }

        // ������ 3: ��������� ���� ����� �� ����� "=" (�����������)
        long double c_left = 0;
        if (match[4].matched) {
            c_left = std::stoi(match[4].str());
        }
        else {
            c_left = 0;
        }

        // ������ 4: �������� ������ ����� ���������
        long double right_side = std::stoi(match[5].str());

        long double c = c_left - right_side;
        coefficients = { a, b, c };

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
    }
    else {
        std::cout << "Incorrect input format!" << std::endl;
    }

    return coefficients;
}

std::pair<long double, long double> solveQuadraticEquation(std::vector<long double> coefficients) {
    if (coefficients[0] == 0){
        std::cout << "Not a quadratic equation" << std::endl;
        return { -1, -1 };
    }
};