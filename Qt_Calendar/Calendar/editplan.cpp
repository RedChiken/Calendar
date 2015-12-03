#include "editplan.h"
#include "ui_editplan.h"

EditPlan::EditPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPlan)
{
    ui->setupUi(this);
    ui->EditButton->setEnabled(false);
    connect(ui->EditButton, &QPushButton::released, [&]{
        data.details = ui->Detail->toPlainText();
        data.endTime = ui->dateTimeEnd->dateTime();
        data.startTime = ui->dateTimeStart->dateTime();
        data.title = ui->PlanTitle->text();
        this->close();
    });
    connect(ui->PlanTitle, &QLineEdit::editingFinished, [&]{
        if(ui->PlanTitle->text() == "" ||
                ui->dateTimeEnd->dateTime() <= ui->dateTimeStart->dateTime())
            ui->EditButton->setEnabled(false);
        else
            ui->EditButton->setEnabled(true);
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
