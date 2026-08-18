#include "chanstu.h"
#include "ui_chanstu.h"
#include "teacherwindow.h"
#include "stu.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <fstream>

ChanStu::ChanStu(StudentManager *m,TeacherWindow *t,QWidget *parent)
    : manager(m),teacherWindow(t),QWidget(parent)
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



void ChanStu::on_Ensure_clicked()
{
    QString qid=ui->InputeId->text().trimmed();
    if(qid.isEmpty()){
        QMessageBox::warning(this,"警告","学号不能为空！");
        return;
    }
    auto id=qid.toStdString();
    if(!manager->checkid(id)){
        QMessageBox::warning(this,"警告","学号错误 未找到该学生");
        return;
    }
    Student *student=manager->findStudent(id);
    Stu* st=new Stu(student,manager,this);
    this->hide();
    st->show();
    ui->InputeId->clear();
}

