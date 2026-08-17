#include "studentdata.h"
#include "ui_studentdata.h"
#include <QCloseEvent>
#include <qmessagebox.h>

StudentData::StudentData(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentData)
{
    ui->setupUi(this);
}

StudentData::~StudentData()
{
    delete ui;
}

void StudentData::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}