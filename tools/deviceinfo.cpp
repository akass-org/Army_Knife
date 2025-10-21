#include "deviceinfo.h"
#include "ui_deviceinfo.h"

DeviceInfo::DeviceInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeviceInfo)
{
    ui->setupUi(this);
}

DeviceInfo::~DeviceInfo()
{
    delete ui;
}
