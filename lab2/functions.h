#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <regex>
#include <cmath>
#include <random>

class Teacher {
private:
    std::vector<int> results;
    std::vector<std::string> names;
public:
    std::pair<long double, long double> solveQuadEquatTeacher(std::vector<long double>& const coefficients) {
        return isCorrectQuadraticEquation ? solveQuadraticEquation(coefficients) : std::make_pair(-1.0L, -1.0L);
    }
    std::vector<std::pair<long double, long double>> solveExamTeacher(const std::string& filename);
};

class Student {
private:
    std::string name;
    std::string type;
    int solveChance;
public:
    Student(const std::string& name, const std::string& type) : name(name), type(type), solveChance(0) {
        if (type == "diligent") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(0, 100);
            solveChance = dist(gen);
        }
    }
    std::pair<long double, long double> solveQuadEquatStudent(std::vector<long double>& const coefficients, std::string type, int solveChance);
    std::vector<std::pair<long double, long double>> solveExamStudent(const std::string& filename);
};

std::vector<long double> getCoefficients(std::string& const str);
bool isCorrectQuadraticEquation(std::vector<long double>& const coefficients);
std::pair<long double, long double> solveQuadraticEquation(std::vector<long double>& const coefficients);