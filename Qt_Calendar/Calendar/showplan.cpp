#include "showplan.h"
#include "ui_showplan.h"

#include <QWidget>
#include <QDateTime>

ShowPlan::ShowPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowPlan)
{
    ui->setupUi(this);
    //might be better if list widget is placed next to main window
    move(QPoint(0,0));
    //test
    ScheduleManager manager;
    list<JBsSchedule> list = manager.getScheduleList(date);
    //ui->listWidget->addItem(list.begin()->getTitle().c_str());
    ui->listWidget->addItem(date.toString(true).c_str());
    ui->listWidget->addItem("hello");
}

ShowPlan::~ShowPlan()
{
    delete ui;
}

void ShowPlan::setData(QDate date){
    this->date.setDate(date.year(), date.month(), date.day());
}
