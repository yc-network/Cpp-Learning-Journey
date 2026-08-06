#pragma once
#include <string>
#include <vector>

class StudentUser {

private:

    StudentManager& manager;

public:

    StudentUser(StudentManager& m);

    void getStudent();

};
