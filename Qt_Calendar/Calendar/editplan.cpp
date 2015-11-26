#include "editplan.h"
#include "ui_editplan.h"

EditPlan::EditPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPlan)
{
    ui->setupUi(this);
}

EditPlan::~EditPlan()
{
    delete ui;
}
