#include "wakenow.h"
#include "ui_wakenow.h"

WakeNow::WakeNow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WakeNow)
{
    ui->setupUi(this);
}

WakeNow::~WakeNow()
{
    delete ui;
}
