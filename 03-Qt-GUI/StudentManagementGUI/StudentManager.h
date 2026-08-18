#pragma once
#include <algorithm>
#include <vector>
#include <fstream>
#include "Student.h"
class StudentManager {
private:
	std::vector<Student> students;
public:
	StudentManager();
	void addStudent();
    bool deleteStudent(const std::string &id);
	void print();
    bool checkid(const std::string &id) const ;
	void modifyStudent();
    Student* findStudent(const std::string id_);
	void load(std::fstream& f);
	void save(std::fstream& f);
	bool compare(Student students1, Student students2);
	void compareScores();
    void AddStudent(const Student& s)  ;
    const std::vector<Student>& getStudents() const;
};
