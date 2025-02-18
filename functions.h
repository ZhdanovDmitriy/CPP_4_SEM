#pragma once
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <regex>

std::vector<long double> getCoefficients(std::string str);
std::pair<long double, long double> solveQuadraticEquation(std::vector<long double> coefficients);