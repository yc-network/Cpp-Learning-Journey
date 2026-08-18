#include "studentwindow.h"
#include "studentdata.h"
#include "ui_studentwindow.h"
#include "StudentManager.h"
#include <QMessageBox>
#include <QCloseEvent>

StudentWindow::StudentWindow(StudentManager *m,QWidget *parent)
    : manager(m),QWidget(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}

void StudentWindow::on_Ensure_clicked()
{
    QString qid=ui->InputeAccount->text().trimmed();
    auto id=qid.toStdString();
    if(manager == nullptr){
        QMessageBox::warning(this,"错误","学生数据不可用！");
        return;
    }

    Student* student=manager->findStudent(id);
    if(student == nullptr){
        QMessageBox::warning(this,"警告","请检查学号是否错误");
        return;
    }
    StudentData* stuD=new StudentData(student,this);
    stuD->show();
    this->hide();
}

