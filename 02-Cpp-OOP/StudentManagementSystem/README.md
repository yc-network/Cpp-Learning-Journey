# StudentManagementSystem

这是一个使用 C++ 面向对象思想实现的简单学生管理系统。

这个项目是我第一个较完整的 C++ 多文件项目，主要用于练习类设计、多文件编程以及多个类之间的协作。

---

## 项目功能

目前实现：

### 学生信息管理

可以保存学生：

- 姓名
- 学号
- 性别
- 年龄
- 数学成绩
- 语文成绩
- 英语成绩


### 学生端

支持：

- 根据学号查询学生信息
- 查看个人成绩
- 查看平均分
- 查看成绩等级


### 教师端

支持：

- 添加学生
- 删除学生
- 查看全部学生信息


---

## 项目结构

StudentManagementSystem
├── Student.h
├── Student.cpp
├── StudentManager.h
├── StudentManager.cpp
├── StudentUser.h
├── StudentUser.cpp
├── TeacherUser.h
├── TeacherUser.cpp
└── main.cpp

---

## 类设计

### Student

表示一个学生对象。

负责：

- 保存学生基本信息
- 保存学生成绩
- 输出学生信息
- 计算平均分
- 判断成绩等级


---

### StudentManager

负责管理多个学生对象。

使用：

```cpp
vector<Student>
保存学生数据。
实现：
添加学生
删除学生
查找学生
修改学生信息
输出学生列表
StudentUser
模拟学生端操作。
通过学号查询学生信息。
TeacherUser
模拟教师端操作。
通过 StudentManager 对学生信息进行管理。
使用技术
本项目使用：
C++
面向对象编程
多文件项目结构
vector 容器
涉及知识：
class
private / public
构造函数
初始化列表
getter / setter
引用
指针
当前不足
作为第一个完整项目，目前还有一些不足：
部分类职责划分不够清晰
数据管理和用户交互存在一定耦合
数据无法长期保存
STL 使用还比较基础
这些问题会在之后学习更多 C++ 知识后，通过新的项目进行改进。
后续可能优化
未来学习相关知识后，可以继续完善：
使用 fstream 保存学生数据
使用 sort 实现成绩排名
使用更多 STL 容器
优化类之间的职责划分