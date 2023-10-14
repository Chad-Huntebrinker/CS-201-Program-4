#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student();
	bool ReadData(istream& in);
	bool WriteData(ostream& out) const;
	string GetFirstName() const;
	string GetLastName() const;
	float CourseAverage() const;
	bool DisplayCourseAverage(ostream& out);
	string LetterGrade();


public:
	string firstName;
	string lastName;
	int quiz1, quiz2, quiz3, quiz4, quiz5, exam1, exam2, exam3;

};
