#include "chanstu.h"
#include "ui_chanstu.h"
#include "teacherwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

ChanStu::ChanStu(TeacherWindow *t,QWidget *parent)
    : teacherWindow(t),QWidget(parent)
    , ui(new Ui::ChanStu)
{
    ui->setupUi(this);
}

ChanStu::~ChanStu()
{
    delete ui;
}


void ChanStu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}
void ChanStu::on_return_2_clicked()
{
    auto answer = QMessageBox::question(this,"提示","确定要返回教师页面吗",QMessageBox::Yes|QMessageBox::No);
    if(answer!=QMessageBox::Yes){
        return;
    }
    teacherWindow->show();
    deleteLater();
}

