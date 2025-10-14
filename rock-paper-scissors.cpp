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
		score(scoreComputer, scoreHuman, roundWinner);

		if (roundWinner == "computer")
			cout << choiceComputer << " beats " << choiceHuman << " , the computer wins.";
		else if (roundWinner == "human")
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

string winner (int choiceHuman, int choiceComputer)
{
	string whoWins;
	if (choiceComputer == 1)
	{
		if (choiceHuman == 1)
			whoWins = draw;
		else if (choiceHuman == 2)
			whoWins = human;
		else (choiceHuman == 3)
			whoWins = computer;
	else if (choiceComputer == 2)
		if (choiceHuman == 1
			whoWins = computer;
		else if (choiceHuman == 2)
			whoWins = draw;
		else (choiceHuman == 3)
			whoWins = human;
	else (choiceComputer == 3)
		else if (choiceHuman == 1)
			whoWins = human;
		else if (choiceHuman == 2)
			whoWins = computer;
		else (choiceHuman == 3)
			whoWins = draw;
	}
	return whoWins;
}

void score (int &scoreComputer, int &scoreHuman, string winner)
{
	if (winner == "computer")
		scoreComputer is scoreComputer + 1;
	else if (winner == "human")
		scoreHuman is scoreHuman + 1;
	return 0;
}