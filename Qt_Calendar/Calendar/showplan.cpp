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
    //QPoint p = parent->pos();
    move(QPoint(0,0));
}

ShowPlan::~ShowPlan()
{
    delete ui;
}

void ShowPlan::setData(QDate date){
    this->date.setDate(date.year(), date.month(), date.day());
    ScheduleManager manager;
    list<JBsSchedule> list = manager.getScheduleList(this->date);
    int index = 1;
    for(std::list<JBsSchedule>::iterator it = list.begin(); it != list.end(); it++, index++){
        string item = to_string(index);
        item = item + ". " + it->getTitle() + " : " + it->getContext();
        ui->listWidget->addItem(item.c_str());
    }
}
