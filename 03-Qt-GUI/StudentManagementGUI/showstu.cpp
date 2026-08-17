#include "showstu.h"
#include "ui_showstu.h"
#include <QMessageBox>
#include <QCloseEvent>

ShowStu::ShowStu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShowStu)
{
    ui->setupUi(this);
}

ShowStu::~ShowStu()
{
    delete ui;
}


void ShowStu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}