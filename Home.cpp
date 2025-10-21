/*
******** Yumeyo's ARMY KNIFE（NetInfoChecker Qt Edition） ********
******** 2025© Ne0W0r1d
******** 2024-2025© Yumeyo
******** LGPL 2.1 License
******** This file about home ********
*/


#include "Home.h"
#include "About.h"
#include "ui_Home.h"
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
    ui -> ispinfo -> setText("请等待后续版本喵"); // isp UI: 初始化
    ui -> localv4add -> setText("Loading......"); // 局域网V4: UI初始化
    ui -> localv6add -> setText("Loading......"); // 局域网V6: UI初始化
    home::getlan();
    home::getwanv4();
    home::getwanv6();
    // home::getisp();
}

// 远程IP、ISP获取
/* 别急！我懒癌犯了！
void home::getisp(){
    QNetworkAccessManager *ispget = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://cip.cc"));
    QNetworkReply *isprep = ispget->get(request);

}
*/
void home::getwanv4() // V4
{
    QNetworkAccessManager *v4manager = new QNetworkAccessManager(this); // 设置新的QNAM
    QNetworkRequest request(QUrl("https://4.ipw.cn")); // 设置Request API为ipw.cn（TODO LIST - 支持多API，并研究单出口API）
    QNetworkReply *v4reply = v4manager->get(request); // 设置Manager操作为request
    connect(v4reply, &QNetworkReply::finished, this, [this, v4reply]() { // 连接V4 Reply
        if (v4reply->error() == QNetworkReply::NoError) { // 判定是否有错误
            QString ipv4 = QString(v4reply->readAll()).trimmed(); // 设置IPV4变量为v4返回信息
            qDebug() << "公网 IPv4:" << ipv4; // Qt调试输出信息
            ui -> v4add -> setText(ipv4); // 显示在UI中
        } else {
            qDebug() << "请求失败:" << v4reply->errorString(); // 输出错误信息
            ui -> v4add -> setText("请求失败🐱"); // 输出错误UI
        }
        v4reply->deleteLater(); // 从我的内存滚出去😡
    });
}
/*以下V6代码同理*/
void home::getwanv6()
{
    QNetworkAccessManager *v6manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://6.ipw.cn"));
    QNetworkReply *v6reply = v6manager->get(request);
    connect(v6reply, &QNetworkReply::finished, this, [this, v6reply]() {
        if (v6reply->error() == QNetworkReply::NoError) {
            QString ipv6 = QString(v6reply->readAll()).trimmed();
            qDebug() << "公网 IPv6:" << ipv6;
            ui -> v6add -> setText(ipv6);
        } else {
            qDebug() << "请求失败:" << v6reply->errorString();
            ui -> v6add -> setText("查询失败🐱看看我的右边有没有输出喵");
        }
        v6reply->deleteLater();
    });
}

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
        for (const QNetworkAddressEntry &entry : iface.addressEntries()) { // 遍历接口地址
            QHostAddress ip = entry.ip(); // 获取IP地址
            if (ip.protocol() == QAbstractSocket::IPv4Protocol) {// 检测是否有V4
                lanv4_add = ip.toString(); // 获取V4字符串
                ui -> localv4add -> setText(lanv4_add.isEmpty() ? "查询失败🐱！" : lanv4_add);// UI：输出V4字符串
            } else if (ip.protocol() == QAbstractSocket::IPv6Protocol) {//检测是否有V6
                if (!ip.toString().startsWith("fe80"))// 屏蔽本地IP地址
                lanv6_add = ip.toString(); // 获取V6字符串
                ui -> localv6add -> setText(lanv6_add.isEmpty() ? "请求失败🐱请把鼠标放在我上面喵" : lanv6_add); // UI：输出V6字符串
                ui -> localv6add -> setToolTip(lanv6_add.isEmpty() ? "请手动检查IP ADDR/IPCONFIG🐱是否存在V6地址喵" : lanv6_add);
                }
            }
            break; // 业务结束
        }
    }

/* 菜单栏业务相关定义 */
    /*打开文档页*/
void home::action_help_wiki_triggered(){
    QUrl wikiurl("https://armyknife.ne0w0r1d.top");//使用QUrl定义*Wiki URL*
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
