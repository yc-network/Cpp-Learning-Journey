#include "studentwindow.h"
#include "studentdata.h"
#include "ui_studentwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

StudentWindow::StudentWindow(QWidget *parent)
    : QWidget(parent)
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
    QString StuId=ui->InputeAccount->text();
    if(StuId=="1"){
        StudentData* stuD=new StudentData();
        stuD->show();
        this->hide();
    }
    else{
        QMessageBox::warning(this,"警告","请检查学号是否错误");
    }
}

