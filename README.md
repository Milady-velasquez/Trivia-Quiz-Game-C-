# Trivia Quiz Game (C++)

## Description

This project is a command-line Trivia Quiz Game written in C++. The program downloads random trivia questions from the Open Trivia Database API, parses the JSON data, and presents an interactive quiz to the user.

Each time the game is played, new questions are retrieved from the internet, making every quiz different. The answer choices are randomized, the program checks the user's responses, displays the correct answer when a mistake is made, keeps track of the score, and allows the user to play multiple rounds.

This project demonstrates object-oriented programming, JSON parsing, file handling, vectors, randomization, and the use of external commands with curl.

## Features
- Downloads random trivia questions from the Open Trivia Database API
- Uses JSON data to create Question objects
- Randomizes the order of answer choices
- Accepts user input through the terminal
- Displays whether each answer is correct or incorrect
- Shows the correct answer after an incorrect response
- Keeps track of correct and incorrect answers
- Allows the user to play multiple rounds
- Uses classes and vectors to organize the program

## Project Structure
- Main.cpp          // Controls the game loop and downloads trivia questions
- Question.hpp      // Declares the Question class
- Question.cpp      // Implements question behavior and answer checking
- Quiz.hpp          // Declares the Quiz class
- Quiz.cpp          // Loads questions, runs the quiz, and tracks scores
- json.hpp          // JSON library used for parsing API responses
- Makefile          // Compiles the project

## How It Works
1. The program uses curl to download trivia questions from the Open Trivia Database API.
2. The JSON response is saved to a local file.
3. The Quiz class reads the JSON file and creates Question objects.
4. Each question is presented with randomized answer choices.
5. The user selects an answer.
6. The program reports whether the answer is correct and displays the correct answer if necessary.
7. After all questions have been answered, the program displays the final score and asks whether the user would like to play again.

## Example Output
1. What is the capital of France?

1) Berlin
2) Paris
3) Madrid
4) Rome

Your answer: 2

Correct

2. Which planet is known as the Red Planet?

1) Earth
2) Venus
3) Mars
4) Jupiter

Your answer: 4

Wrong
Correct answer: Mars

Quiz Results
Correct: 1
Wrong: 1
Total Questions: 2


