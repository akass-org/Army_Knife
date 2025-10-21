/*
******** Yumeyo's ARMY KNIFE（NetInfoChecker Qt Edition） ********
******** 2025© Ne0W0r1d
******** 2024-2025© Yumeyo
******** LGPL 2.1 License
******** This file about aboutinterface ********
*/


#include "About.h"
#include "ui_About.h"


about::about(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::about)
{
    setFixedSize(400,300);
    ui->setupUi(this);

    QString systemname = QSysInfo::kernelType();// 获取内核信息
    QString distro = QSysInfo::prettyProductName();// 获取发行版名称
    QString systemver = QSysInfo::productVersion();// 获取系统版本
    ui->softver_info->setText("0.4.rana.alpha.251016");//版本信息
    ui->env->setText(systemname.toUpper() + " (" + distro + ")");// 显示系统环境
}

about::~about()
{
    delete ui;
}
