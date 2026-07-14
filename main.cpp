#include <iostream>
#include <cstdlib>
#include <string>
#include "Quiz.hpp"

int main() {

    // controls whether the user wants another quiz
    std::string playAgain = "yes";

    // keep running quizzes until user says no
    while (playAgain == "yes") {
        // download 10 random questions from Open Trivia DB
        int result = system("curl -s https://opentdb.com/api.php?amount=10 -o quiz.data");
        // make sure curl worked
        if (result != 0) {
            std::cout << "Curl failed!" << std::endl;

            return 1;
        }

        // create a Quiz object using the downloaded file
        Quiz myQuiz("quiz.data");

        // ask all questions and show score
        myQuiz.runQuiz();
        // ask user if they want another quiz
        std::cout << "\nWould you like to play again? (yes/no): ";
        std::cin >> playAgain;
    }

    std::cout << "\nThanks for playing!" << std::endl;

    return 0;
}

/*

SAMPLE OUTPUT
1. What is the name for a male bee that comes from an unfertilized egg?
    1) Male
    2) Drone
    3) Worker
    4) Soldier

Your answer: 2
Correct!

2. Which Pok&eacute;mon and it&#039;s evolutions were banned from appearing in a main role after the Episode 38 Incident?
    1) The Pikachu Line
    2) The Magby Line
    3) The Porygon Line
    4) The Elekid Line

Your answer: 2
Wrong!
Correct answer: The Porygon Line

3. American rapper Dr. Dre actually has a Ph.D. doctorate.
    1) False
    2) True

Your answer: 2
Wrong!
Correct answer: False

4. &quot;Exile&quot; and &quot;Revelations&quot; were the third and fourth installments of which PC game series?
    1) Doom
    2) Myst
    3) Tropico
    4) Shivers

Your answer: 2
Correct!

5. There are 2 player roles in Trouble in Terrorist Town.
    1) True
    2) False

Your answer:
22
Invalid choice!

6. The &ldquo;fairy&rdquo; type made it&rsquo;s debut in which generation of the Pokemon core series games?
    1) 2nd
    2) 7th
    3) 6th
    4) 4th

Your answer: 2
Wrong!
Correct answer: 6th

7. When did Vesuvius destroy the city of Pompeii?
    1) 79 AD
    2) 54 BC
    3) 62 AD
    4) 31 BC

Your answer: 2
Wrong!
Correct answer: 79 AD

8. What polymer is used to make CDs, safety goggles and riot shields?
    1) Bakelite
    2) Nylon
    3) Polycarbonate
    4) Rubber

Your answer: 2
Wrong!
Correct answer: Polycarbonate

9. In which country is the city of Rio de Janeiro?
    1) Brazil
    2) Venezuela
    3) Peru
    4) Chile

Your answer: 2
Wrong!
Correct answer: Brazil

10. What year did Albrecht D&uuml;rer create the painting &quot;The Young Hare&quot;?
    1) 1702
    2) 1402
    3) 1502
    4) 1602

Your answer: 2
Wrong!
Correct answer: 1502

QUIZ RESULTS
Correct: 2
Wrong: 8
Total Questions: 10

Would you like to play again? (yes/no): no

Thanks for playing!



*/