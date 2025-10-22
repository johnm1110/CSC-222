// reverse-array.cpp: This program populates an array with values, 
// then calls a function to dynamically create a new array and populates
// it with the contents of the original array in reverse order. 
// The program deallocates the memory created in the function before it terminates.

#include <iostream>
using namespace std;

// Function prototype
int* ReverseArray(const int arr[], int size); // Function to reverse the array, accepts a constant array and its size, returns a pointer to the new reversed array
void print(int const arr[], int size); // Function to print the contents of an array, accepts a constant array and its size, returns nothing


int main() {
	const int originalArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	// Call the function to reverse the array
	int* ReversedArr = ReverseArray(originalArr, 10);
	
	// Print the orignial and reversed array
	cout << "Original Array: " << endl;
	print(originalArr, 10);
	cout << endl;
	print(ReversedArr, 10);
	cout << "Reversed Array: " << endl;

	// Deallocate the memory used for the reversed array
	delete[] ReversedArr;
	
	return 0;
}

int* ReverseArray(const int arr[], int size) {
	// Dynamically allocate a new array
	int* reversedArr = new int[size];

	// Create the new array with elements from the original array in reverse order
	for (int i = 0; i < size; ++i) {
		reversedArr[i] = arr[size - 1 - i];
	}

	return reversedArr; // Return the pointer to the new array
}

void print(int const arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
