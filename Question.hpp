#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <vector>
#include "json.hpp"

class Question {

private:

    std::string category;
    std::string type;
    std::string difficulty;

    std::string question;

    std::string correct_answer;

    std::vector<std::string> incorrect_answers;

public:

    Question();

    Question(nlohmann::json data);

    void print_question(int questionNumber);

    bool askQuestion(int questionNumber);
};

#endif