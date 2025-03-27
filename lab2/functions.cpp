#include "functions.h"

std::vector<long double> getCoefficients(std::string& const str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::vector<long double> coefficients;
    std::smatch match;
    std::regex pattern("^([+-]?\\d*)\\*?x\\^2(?:([+-](\\d*))\\*?x)?(?:([+-]\\d+))?=([+-]?\\d+)$");

    if (std::regex_match(str, match, pattern)) {
        std::string a_str = match[1].str();
        long double a = 0;
        if (a_str.empty() || a_str == "+")
            a = 1;
        else if (a_str == "-")
            a = -1;
        else
            a = std::stoi(a_str);

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

        long double c_left = 0;
        if (match[4].matched) {
            c_left = std::stoi(match[4].str());
        }
        else {
            c_left = 0;
        }

        long double right_side = std::stoi(match[5].str());

        long double c = c_left - right_side;
        coefficients = { a, b, c };

    }
    return coefficients;
}

bool isCorrectQuadraticEquation(std::vector<long double>& const coefficients) {
    long double a = coefficients[0];
    long double b = coefficients[1];
    long double c = coefficients[2];
    if (a == 0 && b != 0) {
        return 0;
    }
    else if (a == 0 && b == 0 && c == 0) {
        return 0;
    }
    else if (b == 0 && -(c / a) < 0) {
        return 0;
    }
    else if (b * b - 4 * a * c < 0) {
        return 0;
    }
    else {
        return 1;
    }

}

std::pair<long double, long double> solveQuadraticEquation(std::vector<long double>& const coefficients) {
    long double a = coefficients[0];
    long double b = coefficients[1];
    long double c = coefficients[2];
    if (b == 0) {
        return { std::sqrt(-(c / a)), -std::sqrt(-(c / a)) };
    }
    if (b * b - 4 * a * c >= 0) {
        return { (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a) , (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a) };
    }
};

std::pair<long double, long double> Student::solveQuadEquatStudent(std::vector<long double>& const coefficients, const std::string type, int solveChance) {
    if (type == "cunning") {
        return {-0, 0};
    }
    else if (type == "diligent") {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 100);
        int curr = dist(gen);
        if (curr >= solveChance) {
            return solveQuadraticEquation(coefficients);
        }
        else {
            std::uniform_real_distribution<long double> dist(-100.0, 100.0);
            long double ans1 = dist(gen);
            long double ans2 = dist(gen);
            return {ans1, ans2};
        }
    }
    else if(type == "genius") {
        return solveQuadraticEquation(coefficients);
    }
}


const std::vector<std::pair<long double, long double>> Student::solveExamStudent(const std::string& filename) {
    std::vector<std::pair<long double, long double>> solutions;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Oppening error" << filename << std::endl;
        return solutions;
    }

    std::string equation;
    while (std::getline(file, equation)) {
        std::vector<long double> coefficients = getCoefficients(equation);

        if (isCorrectQuadraticEquation(coefficients)) {
            solutions.push_back(solveQuadEquatStudent(coefficients, type, solveChance));
        }
        else {
            solutions.push_back({ -1, -1 });
        }
    }

    file.close();
    return solutions;
}

const std::vector<std::pair<long double, long double>> Teacher::solveExamTeacher(const std::string& filename) {
    std::vector<std::pair<long double, long double>> solutions;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Oppening error" << filename << std::endl;
        return solutions;
    }

    int cnt = 0;
    std::string equation;
    while (std::getline(file, equation)) {
        cnt++;
        std::vector<long double> coefficients = getCoefficients(equation);

        if (isCorrectQuadraticEquation(coefficients)) {
            solutions.push_back(solveQuadraticEquation(coefficients));
        }
        else {
            solutions.push_back({ -1, -1 });
        }
    }

    exampleCount = cnt;
    file.close();
    return solutions;
}

void Teacher::evaluateWorks(const std::string name, const std::vector<std::pair<long double, long double>>& studentAns, const std::vector<std::pair<long double, long double>>& ans) {
    int cnt = 0;
    for (int i = 0; i != ans.size(); ++i) {
        if (std::fabs(studentAns[i].first - ans[i].first) < EPS && std::fabs(studentAns[i].second - ans[i].second) < EPS) {
            cnt++;
        }
    }
    results.push_back({name, cnt});
}

void Teacher::publishResults() {
    int cnt = 0;
    std::cout << "N |   NAME  |  points  |  grade  |" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (auto& elem : results) {
        int grade;
        double percentage = static_cast<double>(elem.second) / exampleCount;
        if (percentage >= 0.90) {
            grade = 5;
        }
        else if (percentage >= 0.75) {
            grade = 4;
        }
        else if (percentage >= 0.60) {
            grade = 3;
        }
        else {
            grade = 2;
        }
        cnt++;
        std::cout << cnt << ".  " << elem.first << " | " << elem.second << " / " << exampleCount << " | " << grade << std::endl;
    }
}
