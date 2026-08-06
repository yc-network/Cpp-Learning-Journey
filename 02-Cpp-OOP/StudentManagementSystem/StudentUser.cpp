#include "Student.h"
#include "StudentManager.h"
#include "StudentUser.h"
#include <iostream>
using namespace std;

void StudentUser::getStudent() {
	string id_;
	while (true) {
		cout << "请输入您想要查询的学生学号：（退出请输入-1）" << endl;
		cin >> id_;
		if (id_ == "-1") break;
		Student* s = manager.findStudent(id_);
		if (s) {
			s->printInfo();
		}
	}
}

StudentUser::StudentUser(StudentManager& m) :manager(m) {}
