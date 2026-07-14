#include "Quiz.hpp"

#include <fstream>
#include<iostream>

#include "json.hpp"

Quiz::Quiz(std::string fileName) {

    std::ifstream in_stream;

    in_stream.open(fileName.c_str());

    nlohmann::json j;

    in_stream >> j;

    for(int i = 0; i < j["results"].size(); i++) {

        Question q(
            j["results"][i]
        );

        questions.push_back(q);
    }
}

void Quiz::print_all_questions() {

    for(int i = 0; i < questions.size(); i++) {

        questions[i].print_question(i + 1);
    }
}

void Quiz::runQuiz() {

    int correct = 0;
    int wrong = 0;

    for(int i = 0; i < questions.size(); i++) {

        //std::cout<<"\n" <<i + 1 << "."; 

        if(questions[i].askQuestion(i + 1)) {
            correct++;
        }
        else {

            wrong++;
        }
    }

    std::cout << std::endl;

    std::cout<< "QUIZ RESULTS" << std::endl;
    std::cout<< "Correct: "<< correct<< std::endl;
    std::cout<< "Wrong: "<< wrong<< std::endl;
    std::cout<< "Total Questions: "<< questions.size()<< std::endl;
}