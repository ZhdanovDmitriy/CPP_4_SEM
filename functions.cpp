#include "functions.h"

std::vector<long double> getCoefficients(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::vector<long double> coefficients;

    std::smatch match;
    // –егул€рное выражение:
    // √руппа 1: ([+-]?\d*)       Ч коэффициент при x^2 (может быть пустой строкой, если записано просто "x^2")
    // «атем: \*?x\^2             Ч сама переменна€ x^2 (опциональна€ звездочка)
    // (?:([+-](\d*))\*?x)?       Ч опциональна€ группа дл€ x: если присутствует, то захватываем коэффициент (группа 2)
    // (?:([+-]\d+))?             Ч опциональна€ группа дл€ свободного члена на левой части (группа 3)
    // =([+-]?\d+)$               Ч права€ часть уравнени€ (группа 4)
    std::regex pattern("^([+-]?\\d*)\\*?x\\^2(?:([+-](\\d*))\\*?x)?(?:([+-]\\d+))?=([+-]?\\d+)$");

    if (std::regex_match(str, match, pattern)) {
        // √руппа 1: коэффициент a
        std::string a_str = match[1].str();
        long double a = 0;
        if (a_str.empty() || a_str == "+")
            a = 1;
        else if (a_str == "-")
            a = -1;
        else
            a = std::stoi(a_str);

        // √руппа 2: коэффициент b (опционально)
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

        // √руппа 3: свободный член слева от знака "=" (опционально)
        long double c_left = 0;
        if (match[4].matched) {
            c_left = std::stoi(match[4].str());
        }
        else {
            c_left = 0;
        }

        // √руппа 4: значение правой части уравнени€
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