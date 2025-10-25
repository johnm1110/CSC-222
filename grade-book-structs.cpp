// grade-book.cpp : a program to read student's grades from a file and output a corresponding letter grade  


#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Define a structure to hold student records
struct studentRecord
{
	string name;			// Student's name
	int studentID;			// Student's ID
	double* testScores;		// Pointer to dynamically allocated array of test scores
	double testAverage;		// Average test score
};

// Function prototypes
// Reads student names, student ID, and their test scores from a file
// takes the file stream, pointer to the number of students and number of test scores as arguments
// returns a pointer to an array of studentRecord structs
studentRecord* getData(ifstream &, int &, int &);

// Calculates the average test score for each student
// takes an array of studentRecord structs, number of students, and number of test scores as arguments, returns nothing
void calculateAverage(studentRecord[], int, int);

// Determines the letter grade based on the average score
// takes the average score as an argument, returns the corresponding letter grade
char calculateLetterGrade(double);

// Outputs the student names, student ID, their average scores, and letter grades
// takes an array of studentRecord structs and number of students as arguments, returns nothing
void report(studentRecord[], int);

int main()
{
	ifstream file;
	
	int studentCnt, testsCnt;
	studentRecord *students = nullptr; // Pointer to hold the student records
		
	file.open("student_data.txt"); // open the input file

	if (file)
	{
		students = getData(file, studentCnt, testsCnt); // Read data from the file and populate the student records
	}
	else
	{
		cout << "Error opening input file." << endl;
		return 0;
	}

	file.close(); // Close the file after reading

	calculateAverage(students, studentCnt, testsCnt); // Calculate the average scores for each student
	report(students, studentCnt); // Output the report of student names, average scores, and letter grades
	
	for (int i = 0; i < studentCnt; i++)
	{
		delete[] students[i].testScores; // Free the dynamically allocated memory for test scores
	}
	delete[] students; // Free the dynamically allocated memory

	return 0;
}

studentRecord* getData(ifstream &file, int &studentCnt, int &testsCnt)
{
	file >> studentCnt;
	file >> testsCnt;
	studentRecord *students = new studentRecord[studentCnt]; // Dynamically allocate memory for student records
	for (int i = 0; i < studentCnt; i++)
	{
		file >> students[i].name; // Read the student's name
		file >> students[i].studentID; // Read the student's ID
		students[i].testScores = new double[testsCnt]; // Dynamically allocate memory for test scores
		for (int j = 0; j < testsCnt; j++)
		{
			file >> students[i].testScores[j]; // Read each test score for the student
		}
	}
	return (students); // pointer to student records
}

void calculateAverage(studentRecord students[], int studentCnt, int testsCnt)
{
	double sum = 0; // Variable to hold the sum of scores for each student

	for (int i = 0; i < studentCnt; i++)
	{
		for (int j = 0; j < testsCnt; j++)
		{
			sum = sum + students[i].testScores[j]; // Sum the scores for the current student
		}
		students[i].testAverage = sum / testsCnt; // Calculate the average score for the current student
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

void report(studentRecord students[], int studentCnt)
{
	cout << "Student Grade Report" << endl;
	cout << left << setw(15) << "Student Name" << setw(15) << "Student ID" << setw(15) << "Average" << "Letter Grade" << endl;

	for (int i = 0; i < studentCnt; i++)
	{
		cout << left 
			<< setw(15) << students[i].name 
			<< setw(15) << students[i].studentID 
			<< setw(15) << setprecision(1) << fixed << students[i].testAverage 
			<< calculateLetterGrade(students[i].testAverage) 
			<< endl;
	}
}