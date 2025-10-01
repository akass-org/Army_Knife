/*
******** Yumeyo's ARMY KNIFE（NetInfoChecker Qt Edition） ********
******** 2025© Ne0W0r1d
******** 2024-2025© Yumeyo
******** LGPL 2.1 License
******** This file about home ********
*/


#include "home.h"
#include "about.h"
#include "ui_home.h"
home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    sessionNet = new QNetworkAccessManager(this); //调用网络管理器，名为sessionNet
    ui->setupUi(this);//启动UI
    action_homeinfo_refresh();
    setFixedSize(this->width(),this->height()); //固定大小
    // 菜单栏：帮助
    connect(ui -> about, &QAction::triggered, this, &home::action_help_about_triggered); // UI：关于
    connect(ui -> wiki, &QAction::triggered, this, &home::action_help_wiki_triggered); // UI：WIKI
    connect(ui -> CNB, &QAction::triggered, this, &home::action_help_cnb_triggered);// UI：CNB GIT
    connect(ui -> Github, &QAction::triggered, this, &home::action_help_github_triggered);// UI：Github
    connect(ui -> wiki, &QAction::triggered, this, &home::action_help_wiki_triggered); // UI：WIKI
    connect(ui -> updatelog, &QAction::triggered, this, &home::action_help_updatelog_triggered);// UI：更新日志
    connect(ui -> issuecnb, &QAction::triggered, this, &home::action_help_issuecnb_triggered);// UI：IssueCNB
    connect(ui -> issuegithub, &QAction::triggered, this, &home::action_help_issuegithub_triggered);// UI：IssueGH
    connect(ui -> aboutqt, &QAction::triggered, qApp, &QApplication::aboutQt);// UI：关于Qt
    /*主页：主机名*/
    QString localHostname = QHostInfo::localHostName(); // 主机名实现
    QString beforPCname = "主机名：";// setText | hostname 前的信息
    ui->hostname->setAlignment(Qt::AlignLeft);// 文本靠左
    ui->hostname->setText(beforPCname + localHostname);// 输出主机名：Hostname

    /*主页：按钮*/
    connect(ui -> refresh, &QPushButton::clicked, this, &home::action_homeinfo_refresh); // 刷新主页信息

    /*主页：IP地址、MAC地址*/



}

home::~home()
{
    delete ui;
}

/* 刷新按键、首次获取 */
void home::action_homeinfo_refresh(){
    ui -> v4add -> setText("Loading......"); // v4地址ui: 初始化
    ui -> v6add -> setText("Loading......"); // v6地址ui: 初始化
    ui -> ispinfo -> setText("Loading......"); // isp UI: 初始化
    ui -> localv4add -> setText("Loading......"); // 局域网V4: UI初始化
    ui -> localv6add -> setText("Loading......"); // 局域网V6: UI初始化
    home::getlan();
}

// 网络管理器相关（远程IP、ISP获取）

// 本地网路地址获取相关
void home::getlan(){
    QString lanv4_add, lanv6_add, macadd;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces(); // 获取所有网卡
    for (const QNetworkInterface &iface : interfaces) {
        if (!iface.flags().testFlag(QNetworkInterface::IsUp) || //是否启用
            !iface.flags().testFlag(QNetworkInterface::IsRunning) || // 是否运行
            iface.flags().testFlag(QNetworkInterface::IsLoopBack)) // 是否回环
            continue; // 遍历后继续
        macadd = iface.hardwareAddress();// 设置macadd为MAC地址
        ui->Mac->setText(macadd); // 设置UI: Mac地址为macadd变量
        for (const QNetworkAddressEntry &entry : iface.addressEntries()) {
            QHostAddress ip = entry.ip();
            if (ip.protocol() == QAbstractSocket::IPv4Protocol) {
                lanv4_add = ip.toString();
                ui -> localv4add -> setText(lanv4_add.isEmpty() ? "暂时无法查询" : lanv4_add);
            } else if (ip.protocol() == QAbstractSocket::IPv6Protocol) {
                if (!ip.toString().startsWith("fe80"))
                lanv6_add = ip.toString();
                ui -> localv6add -> setText(lanv6_add.isEmpty() ? "暂时无法查询" : lanv6_add);
                }
            }
            break;
        }
    }
//void getlanv4()

/* 菜单栏业务相关定义 */
    /*打开文档页*/
void home::action_help_wiki_triggered(){
    QUrl wikiurl("https://ak.ne0w0r1d.top");//使用QUrl定义*Wiki URL*
    QDesktopServices::openUrl(wikiurl);//用Qt桌面服务打开*Wiki URL*

    /*以下菜单栏相关代码同理 QUrl & Desktup Services*/
}
    /*打开CNB*/
void home::action_help_cnb_triggered(){
    QUrl cnb_repo("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(cnb_repo);
}
    /*打开github*/
void home::action_help_github_triggered(){
    QUrl wikiurl("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(wikiurl);
}
    /*打开关于窗口*/
void home::action_help_about_triggered(){
    about *aboutWidget = new about(this);//打开about组件
    aboutWidget->setAttribute(Qt::WA_DeleteOnClose);//
    aboutWidget->show();//exec为模态，show为非模态，改为非模态显示避免影响操作
}
    /*打开更新日志*/
void home::action_help_updatelog_triggered(){
    QUrl updateurl("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife/-/releases");
    QDesktopServices::openUrl(updateurl);
}
    /*IssueCNB*/
void home::action_help_issuecnb_triggered(){
    QUrl issuecnb("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife/-/issues");
    QDesktopServices::openUrl(issuecnb);
}
    /*IssueGithub*/
void home::action_help_issuegithub_triggered(){
    QUrl issuegithub("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife/issues");
    QDesktopServices::openUrl(issuegithub);
}
