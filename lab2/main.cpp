#include "functions.h"

int main() {
    const std::string& filename = "examination_work.txt";

    Student Ivanov("Ivanov", "diligent");
    Student Petrov("Petrov", "diligent");
    Student Sidorov("Sidorov", "cunning");
    Student Markov("Markov", "diligent");
    Student Rodin("Rodin", "cunning");
    Student Popov("Popov", "diligent");
    Student Zuev("Zuev", "diligent");
    Student Chukanov("Chukanov", "genius");

    std::vector<std::vector<std::pair<long double, long double>>> answers;
    std::vector<std::string> names;
    
    names.push_back(Ivanov.name);
    answers.push_back(Ivanov.solveExamStudent(filename));
    names.push_back(Petrov.name);
    answers.push_back(Petrov.solveExamStudent(filename));
    names.push_back(Sidorov.name);
    answers.push_back(Sidorov.solveExamStudent(filename));
    names.push_back(Markov.name);
    answers.push_back(Markov.solveExamStudent(filename));
    names.push_back(Rodin.name);
    answers.push_back(Rodin.solveExamStudent(filename));
    names.push_back(Popov.name);
    answers.push_back(Popov.solveExamStudent(filename));
    names.push_back(Zuev.name);
    answers.push_back(Zuev.solveExamStudent(filename));
    names.push_back(Chukanov.name);
    answers.push_back(Chukanov.solveExamStudent(filename));

    Teacher teacher(20);
    const std::vector<std::pair<long double, long double>> teacherAnswers = teacher.solveExamTeacher(filename);
    for (int i = 0; i != names.size(); ++i) {
        teacher.evaluateWorks(names[i], answers[i], teacherAnswers);
    }
    teacher.publishResults();

    return 0;
}