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
    ui->EditButton->setEnabled(true);
    connect(ui->EditButton, &QPushButton::released, [&]{
        ScheduleManager *SM = ScheduleManager::getInstance();

        if(ui->dateTimeEnd->dateTime() < ui->dateTimeStart->dateTime())
            ui->EditButton->setEnabled(false);
        else
        {
            TimeManager startTM(ui->dateTimeStart->date().year(),
                                ui->dateTimeStart->date().month(),
                                ui->dateTimeStart->date().day(),
                                ui->dateTimeStart->time().hour(),
                                ui->dateTimeStart->time().minute(),
                                ui->dateTimeStart->time().second());
            TimeManager endTM(ui->dateTimeEnd->date().year(),
                              ui->dateTimeEnd->date().month(),
                              ui->dateTimeEnd->date().day(),
                              ui->dateTimeEnd->time().hour(),
                              ui->dateTimeEnd->time().minute(),
                              ui->dateTimeEnd->time().second());

            JBsSchedule schedule(ui->PlanTitle->text().toStdString(),
                                 startTM,
                                 endTM,
                                 ui->Detail->toPlainText().toStdString());
            if(ui->checkBox->checkState())
            {
                TimeManager cycle(ui->lineEdit->text().toInt(),
                                  ui->lineEdit_2->text().toInt(),
                                  ui->lineEdit_3->text().toInt(),
                                  0,0,0);
                SM->recursiveWrite(schedule,cycle,ui->lineEdit_4->text().toInt());
            }
            else
            {
                SM->addSchedule(schedule);
            }

            ui->EditButton->setEnabled(false);
        }

        //data.details = ui->Detail->toPlainText();
        //data.endTime = ui->dateTimeEnd->dateTime();
        //data.startTime = ui->dateTimeStart->dateTime();
        //data.title = ui->PlanTitle->text();
        this->close();
    });
    connect(ui->PlanTitle, &QLineEdit::editingFinished, [&]{

    });
    connect(ui->dateTimeEnd, &QDateTimeEdit::editingFinished, [&]{
        checkDateError();
        convert2lunar(ui->dateTimeEnd->date());
    });
    connect(ui->dateTimeStart, &QDateTimeEdit::editingFinished, [&]{
        checkDateError();
        convert2lunar(ui->dateTimeStart->date());
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
{}
void EditPlan::setdata(QDate d)
{
    ui->dateTimeStart->setDate(d);
    ui->dateTimeEnd->setDate(d);
    convert2lunar(d);
}

void EditPlan::convert2lunar(QDate d)
{
    TimeManager startsolar(d.year(),d.month(),d.day());
    TimeManager endsolar(d.year(),d.month(),d.day());
    startsolar.toLunar();
    endsolar.toLunar();
    QString lunar = "Lunar: ";
    lunar.append(QString::number(startsolar.getLunarYear()));
    lunar.append("-");
    lunar.append(QString::number(startsolar.getLunarMonth()));
    lunar.append("-");
    lunar.append(QString::number(startsolar.getLunarDay()));
    lunar.append(" ");
    lunar.append(QString::number(startsolar.getHour()));
    lunar.append(":");
    lunar.append(QString::number(startsolar.getMinute()));
    ui->label_9->setText(lunar);
    lunar.clear();
    lunar.append("Lunar: ");
    lunar.append(QString::number(endsolar.getLunarYear()));
    lunar.append("-");
    lunar.append(QString::number(endsolar.getLunarMonth()));
    lunar.append("-");
    lunar.append(QString::number(endsolar.getLunarDay()));
    lunar.append(" ");
    lunar.append(QString::number(endsolar.getHour()));
    lunar.append(":");
    lunar.append(QString::number(endsolar.getMinute()));
    ui->label_10->setText(lunar);
}
