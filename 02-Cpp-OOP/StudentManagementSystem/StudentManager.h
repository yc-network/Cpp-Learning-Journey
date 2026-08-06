#pragma once
#include <vector>
#include "Student.h"
class StudentManager {
private:
	std::vector<Student> students;
public:
	StudentManager();
	void addStudent();
	void deleteStudent();
	void print();
	bool checkid(std::string &id) const ;
	void modifyStudent();
	Student* findStudent(std::string id_);
	/*double getEAverage();
	double getMAverage();
	double getCAverage();
	void getEachLevel();*/
};
