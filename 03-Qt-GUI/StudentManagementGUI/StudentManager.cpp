#include "Student.h"
#include "StudentManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

StudentManager::StudentManager() {}

void StudentManager::addStudent() {
	while(true) {
		std::string name;
		std::string id;
		std::string sex;
		int age = 0;
		double MathScores = 0.0;
		double ChineseScores = 0.0;
		double EnglishScores = 0.0;
		cout << "请输入学生学号：(退出请输入-1）";
		cin >> id;
		if (id == "-1") {
			break;
		}
		
		if (StudentManager::checkid(id))  continue;

		cout << "请输入学生姓名：";
		cin >> name;
		cout << "请输入学生性别：";
		cin >> sex;
		cout << "请输入学生年龄：";
		cin >> age;
		cout << "请输入学生的数学成绩：";
		cin >> MathScores;
		cout << "请输入学生中文成绩：";
		cin >> ChineseScores;
		cout << "请输入学生英语成绩：";
		cin >> EnglishScores;

		Student student{
			name,id,sex,age,MathScores,ChineseScores,EnglishScores
		};

		students.push_back(student);

		cout << "已成功添加学生" << name << "。当前共有" << students.size() << "名学生。" << endl;
	}
}


bool StudentManager::deleteStudent(const std::string &id) {
    for (std::size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getid() == id)
        {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

void StudentManager::print() {
	if (students.size() == 0) {
		cout << "当前学生数量为0！" << endl;
		return;
	}
	for (std::size_t i = 0; i < students.size(); i++) {
		students[i].printInfo();
	}
}

bool StudentManager::checkid(const string &id) const {
	for (std::size_t i = 0; i < students.size();i++) {
		if (students[i].getid() == id) {
			return true;
		}
	}
	return false;
}

void StudentManager::modifyStudent() {
	while (true) {
		int x = 0;
		cout << "输入1修改学生年龄 输入2修改数学成绩 输入3修改中文成绩 输入4修改英文成绩：（退出请输入-1）";
		cin >> x;
		if (x == -1) break;
		string id_;
		cout << "请输入您想要修改的学生的学号：";
		cin >> id_;
		for (std::size_t i = 0; i < students.size(); i++) {
			if (students[i].getid() == id_){
				if (x == 1) {
					int tage = 0;
					cout << "当前学生年龄为：" << students[i].getAge() << " 将该学生的年龄修改为：";
					cin >> tage;
					students[i].setAge(tage);
				}
				else if (x == 2) {
					double tMS = 0.0;
					cout << "当前学生数学成绩为：" << students[i].getMScores() << " 将该学生的数学成绩修改为：";
					cin >> tMS;
					students[i].setMScore(tMS);
				}
				else if (x == 3) {
					double tCS = 0.0;
					cout << "当前学生中文成绩为：" << students[i].getCScores() << " 将该学生的中文成绩修改为：";
					cin >> tCS;
					students[i].setCScore(tCS);
				}
				else if (x == 4) {
					double tES = 0.0;
					cout << "当前学生英语成绩为：" << students[i].getEScores() << " 将该学生的英语成绩修改为：";
					cin >> tES;
					students[i].setEScore(tES);
				}
				else {
					cout << "请输入正确的数字！" << endl;
					continue;
				}
			}
			else {
				cout << "请输入正确的学号！" << endl;
				continue;
			}
		}

	}
}

Student* StudentManager::findStudent(const std::string id_) {

        for (auto& student : students) {
            if (student.getid() == id_) {
                return &student;
            }
        }

        return nullptr;
}



void StudentManager::save(fstream& f) {
	f.open("Student.txt", ios::out);
	if (!f.is_open()){
		cerr << "打开失败!";
		return;
	}
	for (auto& s : students) {
		s.save(f);
	}
	f.close();
}

void StudentManager::load(std::fstream& f)
{
	f.open("Student.txt", std::ios::in);
	if (!f.is_open())
	{
		std::cerr << "文件不存在，跳过读取。" << std::endl;
		return;
	}
	while (true)
	{

		Student s(
			"",
			"",
			"",
			0,
			0,
			0,
			0
		);
		s.load(f);
		if (f.fail())
		{
			break;
		}
		students.push_back(s);

	}



	f.close();

}


void StudentManager::AddStudent(const Student& s) {
    students.push_back(s);
}

const std::vector<Student>&  StudentManager::getStudents() const{
    return students;
}
/*double StudentManager::getEAverage()
{
	double tE = 0.0;
	for (std::size_t i = 0; i < students.size(); i++) {
		tE += students[i].getCScores();
	}
	return tE / students.size();
}

double StudentManager::getCAverage()
{
	double tC = 0.0;
	for (std::size_t i = 0; i < students.size(); i++) {
		tC += students[i].getCScores();
	}
	return tC / students.size();
}

double StudentManager::getMAverage()
{
	double tM = 0.0;
	for (std::size_t i = 0; i < students.size(); i++) {
		tM += students[i].getMScores();
	}
	return tM / students.size();
}

void StudentManager::getEachLevel()//To get total level of one student in the whole students group.
{
	std::string subject;
	std::string id;
	cout << "请输入想要查询的学生学号：";
	getline(cin, id);
	cout << "请输入想要查询的科目：";
	getline(cin, id);
}*/