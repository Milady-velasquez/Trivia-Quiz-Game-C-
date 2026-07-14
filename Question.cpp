#include "Question.hpp"

#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>

Question::Question() {

    category = "";
    type = "";
    difficulty = "";
    question = "";
    correct_answer = "";
}

Question::Question(nlohmann::json data) {

    category = data["category"];
    type = data["type"];
    difficulty = data["difficulty"];

    question = data["question"];

    correct_answer = data["correct_answer"];

    for(int i = 0; i < data["incorrect_answers"].size(); i++) {

        incorrect_answers.push_back(
            data["incorrect_answers"][i]
        );
    }
}

void Question::print_question(int questionNumber) {

    std::cout << questionNumber << ". " << question << std::endl;
}

bool Question::askQuestion(int questionNumber) {

    // Create a list containing all possible answers
    std::vector<std::string> answers;

    // Add the correct answer first
    answers.push_back(correct_answer);

    // Add all incorrect answers
    for (const auto& answer : incorrect_answers) {
        answers.push_back(answer);
    }

    // Randomly shuffle the answer choices
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(answers.begin(),answers.end(),gen);

    // Display the question
    std::cout << std::endl;
    std::cout << questionNumber<<". "<<question<< std::endl;

    // Display numbered answer choices
    for (size_t i = 0; i < answers.size(); i++) {

        std::cout<<"    " << i + 1<< ") "<< answers[i]<< '\n';
    }

    // Get the user's choice
    int choice;

    std::cout << "\nYour answer: ";
    std::cin >> choice;

    // Check for invalid input
    if (choice < 1 || choice > static_cast<int>(answers.size())) {

        std::cout << "Invalid choice!" << std::endl;
        return false;
    }

    // Check if the selected answer is correct
    if (answers[choice - 1] == correct_answer) {

        std::cout << "Correct!" << std::endl;
        return true;
    }

    // Otherwise the answer is wrong
    std::cout << "Wrong!" << std::endl;

    std::cout << "Correct answer: " <<correct_answer <<std::endl;

    return false;
}