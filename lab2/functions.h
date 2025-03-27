#pragma once
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

std::vector<long double> getCoefficients(std::string& const str);
bool isCorrectQuadraticEquation(std::vector<long double>& const coefficients);
std::pair<long double, long double> solveQuadraticEquation(std::vector<long double>& const coefficients);
void printHead();