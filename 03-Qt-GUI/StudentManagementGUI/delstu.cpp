#include "delstu.h"
#include "ui_delstu.h"
#include "teacherwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

DelStu::DelStu(TeacherWindow* t,QWidget *parent)
    : teacherWindow(t), QWidget(parent)
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

