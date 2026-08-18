#include "delstu.h"
#include "ui_delstu.h"
#include "teacherwindow.h"
#include "StudentManager.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <fstream>

DelStu::DelStu(StudentManager *m,TeacherWindow* t,QWidget *parent)
    : manager(m),teacherWindow(t), QWidget(parent)
    , ui(new Ui::DelStu)
{
    ui->setupUi(this);
}

DelStu::~DelStu()
{
    delete ui;
}


void DelStu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}


void DelStu::on_pushButton_clicked()
{
    auto answer = QMessageBox::question(this,"返回","确认要返回教师页面吗",QMessageBox::Yes|QMessageBox::No);
    if(answer!=QMessageBox::Yes){
        return;
    }
    else{
        teacherWindow->show();
        deleteLater();
    }
}


void DelStu::on_Ensure_clicked()
{
    QString qid=ui->InputeId->text().trimmed();
    if(qid.isEmpty()){
        QMessageBox::warning(this,"警告","学号不能为空!");
        return;
    }
    auto id=qid.toStdString();
    if(!manager->deleteStudent(id)){
        QMessageBox::warning(this,"警告","该学生不存在！");
        return;
    }

    std::fstream file;
    manager->save(file);
    ui->InputeId->clear();
    QMessageBox::information(this,"提示","删除成功");
}

