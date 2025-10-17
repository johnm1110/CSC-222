// grade-book.cpp : a program to read student's grades from a file and output a corresponding letter grade  


#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Global constants
const int TESTNUMBER = 5;

// Function prototypes
// Reads student names and their test scores from a file
// takes the file stream, an array for names, and a 2D array for scores as arguments, returns the number of students read
int  getGrades(ifstream &, string [], int [][TESTNUMBER]);

// Calculates the average test score for each student
// takes the number of students, a 2D array of scores, and an array for averages as arguments, returns nothing
void calculateAverage(int, int[][TESTNUMBER], double[]);

// Determines the letter grade based on the average score
// takes the average score as an argument, returns the corresponding letter grade, returns the letter grade
char calculateLetterGrade(double);

// Outputs the student names, their average scores, and letter grades
// takes the number of students, an array of names, and an array of averages as arguments, returns nothing
void report(int, string[], double[]);


int main()
{

	ifstream inputFile;
	
	int numberOfStudents, testScores[20][TESTNUMBER];
	string studentNames[20];
	double testAverages[20];
	
	inputFile.open("StudentGrades.txt");
	if (!inputFile)
	{
		cout << "Error opening input file." << endl;
		return 0;
	}

	numberOfStudents = getGrades(inputFile, studentNames, testScores); // Read student names and scores from the file, returns the number of students read
	inputFile.close(); // Close the file after reading
	calculateAverage(numberOfStudents, testScores, testAverages); // Calculate the average scores for each student
	report(numberOfStudents, studentNames, testAverages); // Output the report of student names, average scores, and letter grades

	return 0;
}

int getGrades(ifstream& inFile, string names[], int scores[][TESTNUMBER])
{
	int numberOfRecords = 0; // Initialize the record counter

	while (!inFile.eof()) // Read until the end of the file
	{
		inFile >> names[numberOfRecords];
		for (int j = 0; j < TESTNUMBER; j++)
		{
			inFile >> scores[numberOfRecords][j]; // Read each test score for the student
		}
		numberOfRecords++; //
	}
	return (numberOfRecords - 1); // Return the total number of records read, adjusting for the extra increment after the last read
	
}

void calculateAverage(int numberOfRecords, int scores[][TESTNUMBER], double averages[])
{
	double sum = 0; // Variable to hold the sum of scores for each student

	for (int i = 0; i < numberOfRecords; i++)
	{
		for (int j = 0; j < TESTNUMBER; j++)
		{
			sum = sum + scores[i][j]; // Sum the scores for the current student
		}
		averages[i] = sum / TESTNUMBER; //
		sum = 0; // Reset sum for the next student

	}
	return;
}

char calculateLetterGrade(double average)
{
	if (average < 60)
		return 'F'; 
	else if (average < 70)
		return 'D';
	else if (average < 80)
		return 'C';
	else if (average < 90)
		return 'B';
	else 
		return 'A';

}

void report(int numberofRecords, string names[], double averages[])
{
	cout << "Student Grade Report" << endl;
	cout <<left << setw(15) << "Student Name  " << setw(15) << "Average  " << "Letter Grade" << endl;

	for (int i = 0; i < numberofRecords; i++)
	{
		cout << left << setw(15) << names[i] << setw(15) << setprecision(0) << fixed << averages[i] << setw(10) << calculateLetterGrade(averages[i]) << endl;
	}

	return;
}