#include "formgpio.h"
#include "ui_formgpio.h"

FormGpio::FormGpio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGpio)
{
    ui->setupUi(this);
}

FormGpio::~FormGpio()
{
    delete ui;
}
