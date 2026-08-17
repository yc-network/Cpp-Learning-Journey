#pragma once
#include <string>
#include <fstream>

class Student {
private:
	std::string name;
	std::string id;
	std::string sex;
	int age = 0;
	double MathScores=0.0;
	double ChineseScores = 0.0;	
	double EnglishScores = 0.0;
public:
	Student(std::string name_, std::string id_, std::string sex_, int age_, double Mscores_, double Cscores_, double Escores_);
	void printInfo();
	void setAge(int age);
	void setMScore(double Mscores);
	void setCScore(double Cscores);
	void setEScore(double Escores);
	double getAverage() const ;//获取学生所有科目的平均分
	char getTotalLevel();//获得学生平均分所处在的等级
	std::string getid() const;
	double getCScores() const;
	double getMScores() const;
	double getEScores() const;
	std::string getSex() const;
	std::string getName() const;
	int  getAge() const;
	void load(std::fstream& f);
	void save(std::fstream& f);
};
