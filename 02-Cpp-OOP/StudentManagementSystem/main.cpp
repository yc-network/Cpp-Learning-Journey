#include <iostream>
#include "Student.h"
#include "StudentManager.h"
#include "StudentUser.h"
using namespace std;
int main() {
	StudentManager manager;
	StudentUser user(manager);
	while (true) {
		/*int y;
		cout << "如果您是老师请输入工号 如果您是学生请输入您的学号：（退出请输入-1）";
		if (y == ) {}
		else if (y == ) {}*/
		int x;
		cout << "输入1添加学生 输入2删除学生 输入0查看当前所有学生档案：（退出请输入-1）";
		cin >> x;
		if (x == 1) manager.addStudent();
		else if (x == 2) manager.deleteStudent();
		else if (x == 0) manager.print();
		else if (x == -1) break;
	}
	return 0;
}
