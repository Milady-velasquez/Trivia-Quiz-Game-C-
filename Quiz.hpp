#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <vector>
#include <string>

#include "Question.hpp"

class Quiz {

private:

    std::vector<Question> questions;

public:

    Quiz(std::string fileName);

    void print_all_questions();

    void runQuiz();
};

#endif