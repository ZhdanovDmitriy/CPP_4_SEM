#include "functions.h"

std::vector<int> getCoefficients(std::string str) {
    // ”дал€ем пробелы из строки
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::vector<int> coefficients;

    std::smatch match;
    // –егул€рное выражение:
    // √руппа 1: ([+-]?\d*)      Ч коэффициент при x^2 (может быть пустой строкой, если записано просто "x^2")
    // «атем: \*?x\^2             Ч сама переменна€ x^2 (опциональна€ звездочка)
    // (?:([+-](\d*))\*?x)?      Ч опциональна€ группа дл€ x: если присутствует, то захватываем коэффициент (группа 2)
    // (?:([+-]\d+))?           Ч опциональна€ группа дл€ свободного члена на левой части (группа 3)
    // =([+-]?\d+)$            Ч права€ часть уравнени€ (группа 4)
    std::regex pattern("^([+-]?\\d*)\\*?x\\^2(?:([+-](\\d*))\\*?x)?(?:([+-]\\d+))?=([+-]?\\d+)$");

    if (std::regex_match(str, match, pattern)) {
        // √руппа 1: коэффициент a
        std::string a_str = match[1].str();
        int a = 0;
        if (a_str.empty() || a_str == "+")
            a = 1;
        else if (a_str == "-")
            a = -1;
        else
            a = std::stoi(a_str);

        // √руппа 2: коэффициент b (опционально)
        int b = 0;
        if (match[2].matched) {
            std::string b_str = match[2].str();
            // ≈сли после знака нет числа, то интерпретируем как 1 или -1
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
        int c_left = 0;
        if (match[4].matched) {
            c_left = std::stoi(match[4].str());
        }
        else {
            c_left = 0;
        }

        // √руппа 4: значение правой части уравнени€
        int right_side = std::stoi(match[5].str());

        // ѕриводим уравнение к виду ax^2 + bx + c = 0, вычита€ правую часть из свободного члена
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