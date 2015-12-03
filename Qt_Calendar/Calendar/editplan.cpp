#include "editplan.h"
#include "ui_editplan.h"

EditPlan::EditPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPlan)
{
    ui->setupUi(this);
    connect(ui->EditButton, &QPushButton::released, [&]{
        data.details = ui->Detail->toPlainText();
        data.endTime = ui->dateTimeEnd->dateTime();
        data.startTime = ui->dateTimeStart->dateTime();
        data.title = ui->PlanTitle->text();
        this->close();
    });
}

EditPlan::~EditPlan()
{
    delete ui;
}
