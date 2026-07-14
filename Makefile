all:
	g++ -std=c++17 main.cpp Question.cpp Quiz.cpp -o quizGame

run:
	./quizGame

clean:
	rm -f quizGame