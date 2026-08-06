# C++ Learning Log

## 2026-08-05

## 项目：StudentManagementSystem 初版

### 今日完成

完成第一个 C++ 多文件项目。

项目结构：

StudentManagementSystem

├── Student.h  
├── Student.cpp  
└── main.cpp  

### 今日学习

- 学习 C++ 三文件工程结构：
  - .h 文件负责类声明
  - .cpp 文件负责函数实现
  - main.cpp 负责程序入口

- 理解 include 和 namespace：
  - 使用 `#include` 引入库
  - 理解 `std::string` 与 `using namespace std`

- 完成 Student 类设计：
  - 学生姓名
  - 学号
  - 性别
  - 年龄
  - 各科成绩

实现：

- 构造函数
- 初始化列表
- 信息输出
- 平均分计算
- 成绩等级判断

### 遇到的问题

学号显示错误。

原因：

使用 int 保存学号导致超出范围。

解决：

改为 string 类型。

理解：

学号属于编号，不需要进行数学计算，因此应该使用字符串保存。


### 今日收获

第一次从“让代码运行”转向“理解代码为什么这样运行”。

学习了：

- 类与对象
- 多文件结构
- 构造函数
- this 指针
- 数据类型设计


---

## 2026-08-06

## 项目：StudentManagementSystem 完善

### 今日完成

新增：

- StudentManager 类
- StudentUser 类

实现：

- 添加学生
- 删除学生
- 查询学生
- 修改学生信息
- 检查重复学号


项目结构：

StudentManagementSystem

├── Student.h  
├── Student.cpp  
├── StudentManager.h  
├── StudentManager.cpp  
├── StudentUser.h  
├── StudentUser.cpp  
└── main.cpp  


### 今日学习

- 学习 vector 管理多个对象

理解：

Student 负责描述单个学生。

StudentManager 负责管理多个学生。


- 学习 vector 操作：

  - push_back 添加对象
  - erase 删除对象


- 学习函数返回状态：

通过 bool 判断：

- 是否存在
- 是否成功


- 学习类之间的关系：

StudentUser 不直接保存学生数据。

StudentManager 负责保存数据。

其他类通过接口访问。


- 学习引用传递：

通过：

`StudentManager& manager`

让不同类之间使用同一个对象。


- 学习返回对象指针：

通过：

`Student* findStudent()`

返回找到的学生对象。


### 遇到的问题

StudentUser 查询学生时出现问题。

原因：

错误创建新的 StudentManager 对象，导致查询的是空数据。

解决：

使用已有的 StudentManager 对象。


### 今日收获

开始理解面向对象不仅是写 class。

更重要的是：

- 数据应该由谁管理
- 类之间如何通信
- 不同对象如何协作


### 明日计划

- 完善查询功能
- 学习 STL sort
- 实现学生成绩排序
- 学习文件保存功能
