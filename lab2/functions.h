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
#include <map>
#include <iomanip>

#define EPS 0.1

class Teacher {
private:
    int exampleCount;
    std::vector<std::pair<std::string, int>> results;
public:
    Teacher(int exampleCount) : exampleCount(exampleCount) {};
    const std::vector<std::pair<long double, long double>> solveExamTeacher(const std::string& filename);
    void evaluateWorks(const std::string name,const std::vector<std::pair<long double, long double>>& studentAns,const std::vector<std::pair<long double, long double>>& ans);
    void publishResults();
};

class Student {
private:
    const std::string type;
    int solveChance;
public:
    const std::string name;
    Student(const std::string& name, const std::string& type) : name(name), type(type), solveChance(0) {
        if (type == "diligent") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(30, 100);
            solveChance = dist(gen);
        }
    }
    std::pair<long double, long double> solveQuadEquatStudent(std::vector<long double>& const coefficients,const std::string type, int solveChance);
    const std::vector<std::pair<long double, long double>> solveExamStudent(const std::string& filename);
};

std::vector<long double> getCoefficients(std::string& const str);
bool isCorrectQuadraticEquation(std::vector<long double>& const coefficients);
std::pair<long double, long double> solveQuadraticEquation(std::vector<long double>& const coefficients);