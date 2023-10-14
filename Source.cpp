//Chad Huntebrinker
//12567690
//crh92d@umsystem.edu


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Student.h"

vector<Student> sortVector(vector<Student> studentVector);

using namespace std;

int main() {

	Student someStudent;
	vector<Student> studentVector;
	ifstream fin;
	ofstream fout;
	float total;
	bool status;

	fin.open("Program4Data.txt");
	fout.open("OutputFile.txt");

	//While loop and if statement continues so long as the file reads in a line and status is true.
	while (status = someStudent.ReadData(fin)) {
		if (status == true) {
			studentVector.push_back(someStudent);
		}
	}
	//The function that will sort the different students by their last name.
	studentVector = sortVector(studentVector);

	cout << fixed << setprecision(3);

	//These statement will be outputted to the output file.
	fout << "First Name	   Last Name		  Q1  Q2  Q3  Q4  Q5   E1   E2   E3   Final  Grade" << endl;
	fout << setw(90) << setfill('-') << "" << endl;
	fout << setfill(' ');

	//This for loop will take a student from the sorted vector and output it to the screen.
	//After the loop outputs it to the screen, it will then output the information via the
	//class functions to the output file.
	for (int i = 0; i < studentVector.size(); ++i) {
		someStudent = studentVector.at(i);
		total = someStudent.CourseAverage();
		cout << setw(20) << left << someStudent.GetFirstName();
		cout << setw(20) << left << someStudent.GetLastName();
		cout << setw(12) << left << total;
		cout << setw(6) << left << someStudent.LetterGrade() << endl;
		
		status = someStudent.WriteData(fout);
		status = someStudent.DisplayCourseAverage(fout);
		fout << setw(6) << left << someStudent.LetterGrade() << endl;
	}
	
	
	
	return 0;
}


//This function sorts the vector based on the students' last names.
//If two students have the same last name, it will sort it by their first names.
vector<Student> sortVector(vector<Student> studentVector) {
	int i, j;
	Student temp1, temp2, temp;

	for (i = 1; i < studentVector.size(); ++i) {
		j = i;
		while (j > 0 && studentVector.at(j - 1).GetLastName() > studentVector.at(j).GetLastName()) {
			temp = studentVector.at(j);
			studentVector.at(j) = studentVector.at(j - 1);
			studentVector.at(j - 1) = temp;

			if (studentVector.at(j - 1).GetLastName() == studentVector.at(j).GetLastName()) {
				
				if (studentVector.at(j - 1).GetFirstName() > studentVector.at(j).GetFirstName()) {
					temp = studentVector.at(j);
					studentVector.at(j) = studentVector.at(j - 1);
					studentVector.at(j - 1) = temp;
				}

			}
			--j;
		}
	}
	return studentVector;
}