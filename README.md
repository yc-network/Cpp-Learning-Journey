# StudentManagementSystem

## 项目简介

这是一个基于 C++ 面向对象思想开发的学生管理系统练习项目。

主要用于学习：

- 类与对象
- C++ 多文件工程结构
- 封装思想
- vector容器管理对象
- 类之间的协作


## 项目结构

StudentManagementSystem

├── Student.h

├── Student.cpp

├── StudentManager.h

├── StudentManager.cpp

├── StudentUser.h

├── StudentUser.cpp

└── main.cpp


## 已实现功能

### Student类

负责保存学生信息：

- 姓名
- 学号
- 性别
- 年龄
- 各科成绩


实现：

- 输出学生信息
- 计算平均分
- 判断成绩等级
- 修改学生信息


### StudentManager类

负责管理学生对象：

- 添加学生
- 删除学生
- 查询学生
- 修改学生信息
- 检查重复学号


### StudentUser类

实现：

- 根据学号查询学生信息


## 后续计划

- 完善查询功能
- 增加学生成绩排序
- 学习STL算法
- 增加文件保存功能
- 完善用户权限系统
