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
    qInfo()<< beforPCname << localHostname;
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

/* 菜单栏业务相关定义 */
/*打开文档页*/
void home::action_help_wiki_triggered(){
    qInfo()<<"已触发action_help_wiki_triggered";
    QUrl wikiurl("https://armyknife.ne0w0r1d.top");//使用QUrl定义*Wiki URL*
    QDesktopServices::openUrl(wikiurl);//用Qt桌面服务打开*Wiki URL*
    qDebug() << "Wiki 信号已发出，请检查浏览器";
    /*以下菜单栏相关代码同理 QUrl & Desktup Services*/
}
/*打开CNB*/
void home::action_help_cnb_triggered(){
    QUrl cnb_repo("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(cnb_repo);
    qDebug() << "打开CNB信号已发出，请检查浏览器";
}
/*打开github*/
void home::action_help_github_triggered(){
    QUrl wikiurl("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(wikiurl);
    qDebug() << "打开Github信号已发出，请检查浏览器";
}
/*打开关于窗口*/
void home::action_help_about_triggered(){
    about *aboutWidget = new about(this);//打开about组件
    aboutWidget->setAttribute(Qt::WA_DeleteOnClose);//
    aboutWidget->show();//exec为模态，show为非模态，改为非模态显示避免影响操作
    qDebug()<<aboutWidget<<"aboutWidget 已打开，请检查窗口状态";
}
/*打开更新日志*/
void home::action_help_updatelog_triggered(){
    QUrl updateurl("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife/-/releases");
    QDesktopServices::openUrl(updateurl);
    qDebug() << "打开更新日志信号已发出，请检查浏览器";
}
/*IssueCNB*/
void home::action_help_issuecnb_triggered(){
    QUrl issuecnb("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife/-/issues");
    QDesktopServices::openUrl(issuecnb);
    qDebug() << "打开CNB议题 信号已发出，请检查浏览器";
}
/*IssueGithub*/
void home::action_help_issuegithub_triggered(){
    QUrl issuegithub("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife/issues");
    QDesktopServices::openUrl(issuegithub);
    qDebug() << "打开Github议题已发出，请检查浏览器";
}



/* 刷新按键、首次获取 */
void home::action_homeinfo_refresh(){
    qInfo()<<"信息获取/刷新信号已收到，初始化UI并获取信息中";
    ui -> v4add -> setText("Loading......"); // v4地址ui: 初始化
    ui -> v6add -> setText("Loading......"); // v6地址ui: 初始化
    ui -> ispinfo -> setText("Loading......"); // isp UI: 初始化
    ui -> localv4add -> setText("Loading......"); // 局域网V4: UI初始化
    ui -> localv6add -> setText("Loading......"); // 局域网V6: UI初始化
    home::getlan();
    home::getwanv4();
    home::getwanv6();
    home::getisp();
    home::getpriority();
}

// 远程IP、ISP获取

void home::getwanv4() // V4
{
    QNetworkAccessManager *v4manager = new QNetworkAccessManager(this); // 设置新的QNAM
    QNetworkRequest request(QUrl("https://4.ipw.cn")); // 设置Request API为ipw.cn（TODO LIST - 支持多API，并研究出口API）
    QNetworkReply *v4reply = v4manager->get(request); // 设置Manager操作为request
    qDebug()<<v4reply; // 为v4reply设置Debug
    connect(v4reply, &QNetworkReply::finished, this, [this, v4reply]() { // 连接V4 Reply
        if (v4reply->error() == QNetworkReply::NoError) { // 判定是否有错误
            QString ipv4 = QString(v4reply->readAll()).trimmed(); // 设置IPV4变量为v4返回信息
            qInfo() << "公网 IPv4:" << ipv4; // Qt调试输出信息
            ui -> v4add -> setText(ipv4); // 显示在UI中
        } else {
            QString ipv4_error = v4reply->errorString();
            qWarning() << "请求失败:" << v4reply->errorString(); // 输出错误信息
            ui -> v4add -> setText("请求失败🐱，请检查日志🐱"); // 输出错误UI
        }
        v4reply->deleteLater(); // 从我的内存滚出去😡
        qDebug()<<v4reply;
    });
}
/*以下代码同理*/

void home::getwanv6()
{
    QNetworkAccessManager *v6manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://6.ipw.cn"));
    QNetworkReply *v6reply = v6manager->get(request);
    qDebug()<<v6reply;
    connect(v6reply, &QNetworkReply::finished, this, [this, v6reply]() {
        if (v6reply->error() == QNetworkReply::NoError) {
            QString ipv6 = QString(v6reply->readAll()).trimmed();
            qInfo() << "公网 IPv6:" << ipv6;
            ui -> v6add -> setText(ipv6);
        } else {
            qWarning() << "请求失败:" << v6reply->errorString();
            ui -> v6add -> setText("查询失败🐱看看右边有没有输出喵，如果没有请检查日志喵");
        }
        v6reply->deleteLater();
        qDebug()<<v6reply;

    });
}

void home::getisp() {
    QNetworkAccessManager *ispget = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://cip.cc"));
    QNetworkReply *ispreply = ispget->get(request);
    connect(ispreply, &QNetworkReply::finished, this, [this, ispreply]() {
        if (ispreply->error() == QNetworkReply::NoError) {
            QString replyText = QString::fromUtf8(ispreply->readAll());
            QString isp;
            static const QRegularExpression regex(R"(数据二\s*:\s*(.*))");// 正则表达式提取
            QRegularExpressionMatch match = regex.match(replyText);
            if (match.hasMatch()) {
                isp = match.captured(1).trimmed();
                qInfo() << "ISP:" << isp;
                ui->ispinfo->setText(isp);
            } else {
                isp = "查询不到喵🐱，请检查日志🐱";
                ui->ispinfo->setText(isp);
                qWarning() << "查询不到喵：" <<ispreply->errorString();
            }
        }else{
            qWarning() << "请求失败喵：" <<ispreply->errorString();
            ui -> ispinfo -> setText("请求失败喵，请检查日志🐱");
        }
        ispreply->deleteLater();
        qDebug()<<ispreply;
    });
}

void home::getpriority(){ // 连接优先级
    QNetworkAccessManager *priorityget = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://test.ipw.cn"));
    QNetworkReply *priorityreply = priorityget->get(request);
    connect(priorityreply, &QNetworkReply::finished, this, [this, priorityreply](){
        if(priorityreply->error() == QNetworkReply::NoError){
            QString res = QString::fromUtf8(priorityreply->readAll()).trimmed(); // 数据转换（原始字节 -> UTF字符串）
            QString pri;
            if(res.contains("ipv6",Qt::CaseInsensitive) || res.contains(":")){ // 设置判断标识符 - V6
                pri="IP优先模式：IPv6优先";
                qInfo()<<pri;
            } else if(res.contains("ipv4",Qt::CaseInsensitive) || res.contains(".")){
                pri="IP优先模式：IPv4优先";
                qInfo()<<pri;
            } else{
                pri="暂时无法查询，请检查网络情况";
                qWarning() << "暂时无法查询，请检查网络情况喵";
            }
            ui -> priority -> setText(pri);
            priorityreply->deleteLater();
            qDebug()<<priorityreply;
        }
    });
}

// 本地网路地址获取相关（计划增加多网卡支持）
void home::getlan(){
    QString lanv4_add, lanv6_add, macadd;
    const QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces(); // 获取所有网卡
    qDebug()<<interfaces;
    for (const QNetworkInterface &iface : interfaces) {
        if (!iface.flags().testFlag(QNetworkInterface::IsUp) || //是否启用
            !iface.flags().testFlag(QNetworkInterface::IsRunning) || // 是否运行
            iface.flags().testFlag(QNetworkInterface::IsLoopBack)) // 是否回环
            continue; // 遍历后继续
        macadd = iface.hardwareAddress();// 设置macadd为MAC地址
        qInfo()<< macadd << iface.humanReadableName();
        ui->Mac->setText(macadd + "（" + iface.humanReadableName() + "）"); // 设置UI: Mac地址为macadd变量
        for (const QNetworkAddressEntry &entry : iface.addressEntries()) { // 遍历接口地址
            QHostAddress ip = entry.ip(); // 获取IP地址
            if (ip.protocol() == QAbstractSocket::IPv4Protocol) {// 检测是否有V4
                lanv4_add = ip.toString(); // 获取V4字符串
                ui -> localv4add -> setText(lanv4_add.isEmpty() ? "查询失败喵🐱！" : lanv4_add);// UI：输出V4字符串
            } else if (ip.protocol() == QAbstractSocket::IPv6Protocol) {//检测是否有V6
                if (!ip.toString().startsWith("fe80"))// 屏蔽本地IP地址
                lanv6_add = ip.toString(); // 获取V6字符串
                ui -> localv6add -> setText(lanv6_add.isEmpty() ? "请求失败喵🐱请把鼠标放在我上面喵" : lanv6_add); // UI：输出V6字符串
                ui -> localv6add -> setToolTip(lanv6_add.isEmpty() ? "请手动检查IP ADDR/IPCONFIG喵🐱是否存在V6地址喵" : lanv6_add);
                }
            }
            qDebug() << "请检查网络配置喵🐱" <<lanv4_add.isEmpty();
            qInfo() << "本地IPv4" << lanv4_add;
            qDebug() << "请手动检查IP ADDR/IPCONFIG喵🐱是否存在V6地址喵" <<lanv6_add.isEmpty();
            qInfo() << "本地IPv6：" << lanv6_add;
            break; // 业务结束
        }
    }


