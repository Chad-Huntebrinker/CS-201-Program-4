#include <iostream>
#include  <iomanip>
#include <string>
#include "Student.h"

using namespace std;

//Constructor
Student::Student() {
	firstName = "   ";
	lastName = "   ";
	quiz1 = 0, quiz2 = 0, quiz3 = 0, quiz4 = 0, quiz5 = 0;
	exam1 = 0, exam2 = 0, exam3 = 0;
}

//This function of the class will read in the data from the input file.  As
//soon as there is nothing left to read in, it will return false.
bool Student::ReadData(istream& in) {
	
	bool status;

	if (in >> firstName >> lastName >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5
			>> exam1 >> exam2 >> exam3) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

//This function will output the information from the file in a neat and orderly way.
//Once it can't read out a first name, it will return false.
bool Student::WriteData(ostream& out) const {
	bool status;

	if (out << setw(20) << left << firstName) {
		out << setw(20) << left << lastName;
		out << setw(4) << right << quiz1;
		out << setw(4) << right << quiz2;
		out << setw(4) << right << quiz3;
		out << setw(4) << right << quiz4;
		out << setw(4) << right << quiz5;
		out << setw(5) << right << exam1;
		out << setw(5) << right << exam2;
		out << setw(5) << right << exam3;
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

//These functions return the first and last name.
string Student::GetFirstName() const { 
	return firstName; 
}
string Student::GetLastName() const { 
	return lastName; 
}

//This function calculates the average score of the quiz and the test, gets
//the percantage of the average out of their total (20 or 100), and then calculates their weight 
//on the entire course (0.35 or 0.65).  After that, it adds them together and multiplies 
//them with 100 so that it is in percant form.  It then returns the total.
float Student::CourseAverage () const {
	float totalQuiz, totalExam, total;
	
	totalQuiz = (((quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5.0) / 20.0) * 0.35;
	totalExam = (((exam1 + exam2 + exam3) / 3.0) / 100.0) * 0.65;

	total = totalQuiz + totalExam;
	total = total * 100;
	return total;
}

//This function outputs the course average to the output file.  If it doesn't
//output the course average, it will return false.
bool Student::DisplayCourseAverage(ostream& out) {
	bool status;
	float total;
	total = CourseAverage();

	out << fixed << setprecision(3);

	if (out << setw(8) << right << total << "  ") {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

//This function calculates the letter grade based on the course average.
string Student::LetterGrade() {
	string grade;
	float total = CourseAverage();

	if (total >= 93.0) {
		grade = "A+";
	}
	else if (90 <= total && total < 93) {
		grade = "A-";
	}
	else if (88 <= total && total < 90) {
		grade = "B+";
	}
	else if (84 <= total && total < 88) {
		grade = "B";
	}
	else if (80 <= total && total < 84) {
		grade = "B-";
	}
	else if (78 <= total && total < 80) {
		grade = "C+";
	}
	else if (74 <= total && total < 78) {
		grade = "C";
	}
	else if (70 <= total && total < 74) {
		grade = "C-";
	}
	else if (68 <= total && total < 70) {
		grade = "D+";
	}
	else if (64 <= total && total < 68) {
		grade = "D";
	}
	else if (60 <= total && total < 64) {
		grade = "D-";
	}
	else {
		grade = "F";
	}
	return grade;
}
