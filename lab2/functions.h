#pragma once
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

class Teacher {
private:
    std::vector<int> results;
    std::vector<std::string> names;
    bool checkExample(std::string& const str);
    void checkWork();
public:
    std::vector<long double> getCoeffTeacher(std::string& const str) {
        return getCoefficients(str);
    }
    bool isCorrectQuadEquatTecher(std::vector<long double>& const coefficients) {
        return isCorrectQuadraticEquation(coefficients);
    }
    std::pair<long double, long double> solveQuadEquatTeacher(std::vector<long double>& const coefficients) {
        return isCorrectQuadEquatTecher ? solveQuadraticEquation(coefficients) : std::make_pair(-1.0L, -1.0L);
    }
};

std::vector<long double> getCoefficients(std::string& const str);
bool isCorrectQuadraticEquation(std::vector<long double>& const coefficients);
std::pair<long double, long double> solveQuadraticEquation(std::vector<long double>& const coefficients);