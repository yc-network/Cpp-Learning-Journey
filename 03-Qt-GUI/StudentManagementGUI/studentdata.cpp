#include "studentdata.h"
#include "ui_studentdata.h"
#include "studentwindow.h"
#include "Student.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QTableWidgetItem>


StudentData::StudentData(Student* student, StudentWindow *s, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentData)
    , student(student)
    , studentwindow(s)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (student != nullptr) {
        ui->tableWidget->setRowCount(1);
        fillStudentRow(0, *student);
    }
}

StudentData::~StudentData()
{
    delete ui;
}

void StudentData::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        studentwindow->show();
        event->accept();
    }
    else{
        event->ignore();
    }
}
void StudentData::on_pushButton_2_clicked()
{
    auto answer = QMessageBox::question(this,"提示","确定要返回学生页面吗",QMessageBox::Yes|QMessageBox::No);
    if(answer!=QMessageBox::Yes){
        return;
    }
    studentwindow->show();
    deleteLater();
}

void StudentData::fillStudentRow(int row, const Student& student)
{
    ui->tableWidget->setItem(
        row, 0,
        new QTableWidgetItem(QString::fromStdString(student.getid()))
        );

    ui->tableWidget->setItem(
        row, 1,
        new QTableWidgetItem(QString::fromStdString(student.getName()))
        );

    ui->tableWidget->setItem(
        row, 2,
        new QTableWidgetItem(QString::fromStdString(student.getSex()))
        );

    ui->tableWidget->setItem(
        row, 3,
        new QTableWidgetItem(QString::number(student.getAge()))
        );

    ui->tableWidget->setItem(
        row, 4,
        new QTableWidgetItem(QString::number(student.getMScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 5,
        new QTableWidgetItem(QString::number(student.getCScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 6,
        new QTableWidgetItem(QString::number(student.getEScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 7,
        new QTableWidgetItem(QString::number(student.getAverage(), 'f', 2))
        );
}

