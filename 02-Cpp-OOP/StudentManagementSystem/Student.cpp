#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(std::string name_, std::string id_, std::string sex_, int age_, double Mscores_, double Cscores_, double Escores_) :name(name_), id(id_), sex(sex_), age(age_), MathScores(Mscores_), ChineseScores(Cscores_), EnglishScores(Escores_) {}

void Student::printInfo()
{
	cout << "====================\n\n"
		<< "学生姓名：" << name << '\n'
		<< "学号：" << id << '\n'
		<< "性别：" << sex << '\n'
		<< "年龄：" << age << "\n\n"

		<< "数学成绩：" << MathScores << '\n'
		<< "语文成绩：" << ChineseScores << '\n'
		<< "英语成绩：" << EnglishScores << "\n\n"

		<< "该学生平均分：" << getAverage() << "\n\n"
		<< "该学生平均分等级：" << getTotalLevel() << "\n\n"
		<< "====================" << endl;
}

void Student::setAge(int age) {
	int tage = this->age;
	this->age = age;
	cout << "已成功将学生年龄从" << tage << "修改为" << this->age << endl;
}

void Student::setMScore(double Mscores) {
	double tMSores = this->MathScores;
	this->MathScores = Mscores;
	cout << "已成功将学生数学成绩从" << tMSores << "修改为" << this->MathScores << endl;
}

void Student::setCScore(double Cscores) {
	double tCSores = this->ChineseScores;
	this->ChineseScores = Cscores;
	cout << "已成功将学生中文成绩从" << tCSores << "修改为" << this->ChineseScores << endl;
}

void Student::setEScore(double Escores) {
	double tESores = this->EnglishScores;
	this->EnglishScores = Escores;
	cout << "已成功将学生英语成绩从" << tESores << "修改为" << this->EnglishScores << endl;
}

double Student::getAverage() const {
	return (MathScores + ChineseScores + EnglishScores) / 3 ;
}

char Student::getTotalLevel() {
	if (getAverage() >= 90 && getAverage() <= 100) return 'A';
	else if (getAverage() < 90 && getAverage() >= 80) return 'B';
	else if (getAverage() < 80 && getAverage() >= 70) return 'C';
	else if (getAverage() < 70 && getAverage() >= 60) return 'D';
	else return 'F';
}

std::string Student::getid() const {
	return id;
}

double Student::getMScores() const {
	return MathScores;
}

double Student::getEScores() const {
	return EnglishScores;
}

double Student::getCScores() const {
	return ChineseScores;
}

int Student::getAge() const {
	return age;
}
