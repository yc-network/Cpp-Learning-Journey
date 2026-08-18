#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "addstu.h"
#include "delstu.h"
#include "showstu.h"
#include "chanstu.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <fstream>

TeacherWindow::TeacherWindow(StudentManager* manager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherWindow)
    , manager(manager)
{
    ui->setupUi(this);
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}


void TeacherWindow::closeEvent(QCloseEvent* event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}
void TeacherWindow::on_Addstu_clicked()
{
    AddStu* teA=new AddStu(manager,this);
    teA->show();
    this->hide();
}


void TeacherWindow::on_Delstu_clicked()
{
    DelStu* teD=new DelStu(manager,this);
    teD->show();
    this->hide();
}


void TeacherWindow::on_Showstu_clicked()
{
    ShowStu* teS=new ShowStu(manager,this);
    teS->show();
    this->hide();
}


void TeacherWindow::on_Chanstu_clicked()
{
    ChanStu* teC=new ChanStu(manager,this);
    teC->show();
    this->hide();
}

