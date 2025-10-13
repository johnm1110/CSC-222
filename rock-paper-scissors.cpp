// rock-paper-scissors.cpp : A program to play rock, paper, scissors against the computer

#include <iostream>
#include <string>
#include <random>
using namespace std;

int promptHuman();
int promptComputer();
string winner(int, int);
void score(int, int, string);

int main ()
{
    int scoreComputer, scoreHuman, choiceComputer, choiceHuman = 0;
    string roundWinner;

    while (choiceHuman <> 4)
    {
		choiceHuman = promptHuman();
		choiceComputer = promptComputer();
		roundWinner = winner(choiceHuman, choiceComputer);
		score(scoreComputer, scoreHuman, winner);

		if (winner == "computer")
			cout << choiceComputer << " beats " << choiceHuman << " , the computer wins.";
		else if (winner == "human")
			cout << choiceHuman << " beats " << choiceComputer << " , you win.";
		else
			cout << "You both chose " << choiceHuman << " , draw!"

		cout << "Current score: Computer " << scoreComputer  << ", you << " scoreHuman."
    }
return 0
}

int promptHuman ()
{
	string inputHuman;
	int inputHumanNum = 4;
	while (inputHumanNum < 1 and inputHuman > 4)
	{
		cout << "Please choose rock, paper, scissors, or quit";
		cin >> inputHuman;
		if (inputHuman == "rock")
			inputHumanNum = 1;
		else if (inputHuman == "paper")
			inputHumanNum = 2;
		else if (inputHuman == "scissors")
			inputHumanNum = 3;
		else if (inputHuman == "quit")
			inputHumanNum = 4;
		else
			cout << "That is not a correct entry, please try again";
	}
	return inputHuman;
}

int promptComputer ()
{
	random_device engine
		uniform_int_distribution<int> computerInput(MIN, MAX);
	return computerInput
}

string winner ()
{
	PARAMETER choiceHuman, choiceComputer
		DECLARE string winner
		SWITCH choiceComputer
		if 1
		SWITCH choiceHuman
		else if 1
		winner = draw
		else if 2
		winner = human
		else if 3
		winner = computer
		else if 2
		SWITCH choiceHuman
		else if 1
		winner = computer
		else if 2
		winner = draw
		else if 3
		winner = human
		else if 3
		SWITCH choiceHuman
		else if 1
		winner = human
		else if 2
		winner = computer
		else if 3
		winner = draw
		return winner
}

void score (int &scoreComputer, int &scoreHuman, string winner)
{
	PARAMETER int& scoreComputer, & scoreHuman, winner
		IF winner = computer
		scoreComputer is scoreComputer + 1
	else if winner = human
	scoreHuman is scoreHuman + 1
	return 0
}