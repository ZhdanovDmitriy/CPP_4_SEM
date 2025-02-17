#include "functions.h"

std::vector<int> getCoefficients(std::string str) {
    // ������� ������� �� ������
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::vector<int> coefficients;

    std::smatch match;
    // ���������� ���������:
    // ������ 1: ([+-]?\d*)      � ����������� ��� x^2 (����� ���� ������ �������, ���� �������� ������ "x^2")
    // �����: \*?x\^2             � ���� ���������� x^2 (������������ ���������)
    // (?:([+-](\d*))\*?x)?      � ������������ ������ ��� x: ���� ������������, �� ����������� ����������� (������ 2)
    // (?:([+-]\d+))?           � ������������ ������ ��� ���������� ����� �� ����� ����� (������ 3)
    // =([+-]?\d+)$            � ������ ����� ��������� (������ 4)
    std::regex pattern("^([+-]?\\d*)\\*?x\\^2(?:([+-](\\d*))\\*?x)?(?:([+-]\\d+))?=([+-]?\\d+)$");

    if (std::regex_match(str, match, pattern)) {
        // ������ 1: ����������� a
        std::string a_str = match[1].str();
        int a = 0;
        if (a_str.empty() || a_str == "+")
            a = 1;
        else if (a_str == "-")
            a = -1;
        else
            a = std::stoi(a_str);

        // ������ 2: ����������� b (�����������)
        int b = 0;
        if (match[2].matched) {
            std::string b_str = match[2].str();
            // ���� ����� ����� ��� �����, �� �������������� ��� 1 ��� -1
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
        int c_left = 0;
        if (match[4].matched) {
            c_left = std::stoi(match[4].str());
        }
        else {
            c_left = 0;
        }

        // ������ 4: �������� ������ ����� ���������
        int right_side = std::stoi(match[5].str());

        // �������� ��������� � ���� ax^2 + bx + c = 0, ������� ������ ����� �� ���������� �����
        int c = c_left - right_side;

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


//std::regex pattern(R"(([+-]?\d*)\*?x\^2([+-]\d*\*?x)?([+-]\d*)?=([+-]?\d+))");

//std::regex pattern(R"(([+-]?\d*)[*]?x^2([+-]?\d*)[*]?x([+-]?\d*)=([+-]?\d+))");

/*
std::vector<int> getCoefficients(std::string str) {
    std::vector<int> coefficients;
    std::regex pattern(R"(\s*([+-]?\d*)x\^2\s*([+-]?\s*\d*)x\s*([+-]?\s*\d*)\s*=\s*([+-]?\d+)\s*)");
    std::smatch match;

    if (std::regex_match(str, match, pattern)) {
        int a = match[1].str().empty() || match[1].str() == "+" ? 1 :
            (match[1].str() == "-" ? -1 : std::stoi(match[1].str()));

        int b = match[2].str().empty() || match[2].str() == "+" ? 1 :
            (match[2].str() == "-" ? -1 : std::stoi(match[2].str()));

        int c = std::stoi(match[3].str());
        int right_side = std::stoi(match[4].str())

        c -= right_side;

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
*/