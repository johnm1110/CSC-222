// rock-paper-scissors.cpp : A program to play rock, paper, scissors against the computer

#include <iostream>
#include <string>
#include <random>
using namespace std;

string promptHuman ();
string promptComputer ();
string winner (string, string);
void score (int &, int &, string);
string tournamentWinner (int, int);

int main ()
{
	int scoreComputer = 0, scoreHuman = 0;
    string roundWinner, choiceComputer, choiceHuman, declaredWinner;

	choiceHuman = promptHuman();
	while (choiceHuman != "quit")
    {
		choiceComputer = promptComputer ();
		roundWinner = winner (choiceHuman, choiceComputer);
		score (scoreComputer, scoreHuman, roundWinner);
		
		// determine the winner of the round
		if (roundWinner == "computer")
			cout << choiceComputer << " beats " << choiceHuman << " , the computer wins.\n";
		else if (roundWinner == "human")
			cout << choiceHuman << " beats " << choiceComputer << " , you win.\n";
		else
			cout << "You both chose " << choiceHuman << " , draw!\n";

		cout << "Current score: Computer " << scoreComputer  << ", you " << scoreHuman << endl;
		choiceHuman = promptHuman();
    }

	// declare a final winner
	declaredWinner = tournamentWinner(scoreComputer, scoreHuman);
	cout << "Final score: Computer " << scoreComputer << ", you " << scoreHuman << endl;
	if (declaredWinner == "draw")
		cout << "The tournament is a draw!";
	else
		cout << "The tournament winner is " << declaredWinner << "!";

	return 0;
}

string promptHuman ()
{
	string inputHuman;

	// get the players input
	cout << "Please choose rock, paper, scissors, or quit: ";
	cin >> inputHuman;
	
	// check that the input is valid, ask again if it is not
	while (inputHuman != "rock" && inputHuman != "paper" && inputHuman != "scissors" && inputHuman != "quit")
	{
		cout << "That is not a correct entry, please try again: ";
		cin >> inputHuman;
	}
	return inputHuman;
}

string promptComputer ()
{

	const int MIN = 1; // minimum value for the computer's choice
	const int MAX = 3; // maximum value for the computer's choice
	int inputComputerNum;
	string inputComputer;

	random_device engine;  // randon number engine
	uniform_int_distribution<int>computerRand(MIN, MAX);  // distribution object

	inputComputerNum = computerRand(engine);
	
	// convert the number to a play
	switch (inputComputerNum)
	{
		case 1: inputComputer = "rock";
			break;
		case 2: inputComputer = "paper";
			break;
		case 3: inputComputer = "scissors";
			break;
	}

	return inputComputer;
}

string winner (string choiceHuman, string choiceComputer)
{
	string whoWins;
	
	//compare the plays to determine who wins the round
	if (choiceComputer == "rock")
	{
		if (choiceHuman == "rock")
			whoWins = "draw";
		else if (choiceHuman == "paper")
			whoWins = "human";
		else 
			whoWins = "computer";
	}

	if (choiceComputer == "paper")
	{
		if (choiceHuman == "rock")
			whoWins = "computer";
		else if (choiceHuman == "paper")
			whoWins = "draw";
		else 
			whoWins = "human";
	}

	if (choiceComputer == "scissors")
	{
		if (choiceHuman == "rock")
			whoWins = "human";
		else if (choiceHuman == "paper")
			whoWins = "computer";
		else 
			whoWins = "draw";
	}
	return whoWins;
}

void score (int &scoreComputer, int &scoreHuman, string winner)
{
	// pass references for the scores becasue these need to stay updated
	if (winner == "computer")
		scoreComputer = scoreComputer + 1;
	else if (winner == "human")
		scoreHuman = scoreHuman + 1;
	return;
}

string tournamentWinner(int scoreComputerFinal, int scoreHumanFinal)
{
	string calculatedWinner;

	// compare scores to determine final winner
	if (scoreComputerFinal > scoreHumanFinal)
		calculatedWinner = "the computer";
	else if (scoreComputerFinal < scoreHumanFinal)
		calculatedWinner = "you";
	else
		calculatedWinner = "draw";
	return calculatedWinner;
}
