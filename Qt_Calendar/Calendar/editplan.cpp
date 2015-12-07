#include "editplan.h"
#include "ui_editplan.h"
#include "TimeManager.h"
#include "JBsSchedule.h"
#include "ScheduleManager.h"

EditPlan::EditPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPlan)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
  //  ui->EditButton->setEnabled(false);
    connect(ui->EditButton, &QPushButton::released, [&]{
        data.details = ui->Detail->toPlainText();
        data.endTime = ui->dateTimeEnd->dateTime();
        data.startTime = ui->dateTimeStart->dateTime();
        data.title = ui->PlanTitle->text();
        this->close();
    });
    connect(ui->PlanTitle, &QLineEdit::editingFinished, [&]{
        ScheduleManager *SM = ScheduleManager::getInstance();

        if(ui->dateTimeEnd->dateTime() <= ui->dateTimeStart->dateTime())
            ui->EditButton->setEnabled(true);
        else
        {
            TimeManager startTM(ui->dateTimeStart->YearSection,
                                ui->dateTimeStart->MonthSection,
                                ui->dateTimeStart->DaySection,
                                ui->dateTimeStart->HourSection,
                                ui->dateTimeStart->MinuteSection,
                                ui->dateTimeStart->SecondSection);
            TimeManager endTM(ui->dateTimeEnd->YearSection,
                              ui->dateTimeEnd->MonthSection,
                              ui->dateTimeEnd->DaySection,
                              ui->dateTimeEnd->HourSection,
                              ui->dateTimeEnd->MinuteSection,
                              ui->dateTimeEnd->SecondSection);
            std::string buf = ui->Detail->toPlainText().toStdString();
            JBsSchedule schedule(ui->PlanTitle->text().toStdString(),
                                 startTM,
                                 endTM,
                                 buf);
            if(ui->checkBox->checkState())
            {
                TimeManager cycle(ui->lineEdit->text().toInt(),
                                  ui->lineEdit_2->text().toInt(),
                                  ui->lineEdit_3->text().toInt(),
                                  0,0,0,true);
                SM->recursiveWrite(schedule,cycle,ui->lineEdit_4->text().toInt());
            }
            else
            {
                SM->addSchedule(schedule);
            }

            ui->EditButton->setEnabled(true);
        }
    });
    connect(ui->dateTimeEnd, &QDateTimeEdit::editingFinished, [&]{
        checkDateError();
    });
    connect(ui->dateTimeStart, &QDateTimeEdit::editingFinished, [&]{
        checkDateError();
    });
}
void EditPlan::checkDateError(){
    if( ui->dateTimeEnd->dateTime() <= ui->dateTimeStart->dateTime())
        ui->EditButton->setEnabled(false);
    else
        ui->EditButton->setEnabled(true);
}

EditPlan::~EditPlan()
{
    delete ui;
}

void EditPlan::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
    }
    else
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
    }
}
void EditPlan::on_checkBox_clicked()
{

}
