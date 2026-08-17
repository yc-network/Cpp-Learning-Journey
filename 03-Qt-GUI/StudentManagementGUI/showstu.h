#ifndef SHOWSTU_H
#define SHOWSTU_H

#include <QWidget>

namespace Ui {
class ShowStu;
}

class ShowStu : public QWidget
{
    Q_OBJECT

public:
    explicit ShowStu(QWidget *parent = nullptr);
    ~ShowStu();

private:
    Ui::ShowStu *ui;
protected:
    void closeEvent(QCloseEvent* event) override;
};

#endif // SHOWSTU_H
