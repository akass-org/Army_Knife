#include "Home.h" //
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include "version.h"

// 版本号
QString AK_VERSION = "0.4.rana.alpha.251027";
QString AKT_VERSION = "AKTools.astra.prototype";


// 自定义信息接口
void customMessageHandler(QtMsgType type, const QMessageLogContext &, const QString &msg)
{
    static QFile logFile("ArmyKnife.log"); //日志文件打开、生成

    if (!logFile.isOpen()) {
        if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
            qWarning() << "无法打开日志文件是何意味？：" << logFile.errorString();//返回无法打开日志的报错
            return;
        }
    }

    QTextStream out(&logFile);//输入日志
    QString level;//等级变量

    // 定义输出日志的变量值
    switch (type) {
    case QtDebugMsg:
        level = "DEBUG - 调试";
        break;
    case QtInfoMsg:
        level = "INFO - 信息";
        break;
    case QtWarningMsg:
        level = "WARN - 警告";
        break;
    case QtCriticalMsg:
        level = "CRIT - 关键";
        break;
    case QtFatalMsg:
        level = "FATAL - 寄了";
        break;
    }
    // 日志时间
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ")
        << "[" << level << "] "
        << msg << "\n";
    out.flush();

    // 致命错误则终止程序
    if (type == QtFatalMsg) // 如果出现了 QtFatalMsg 报错
        abort();// 则直接终止

    // 自动清理日志
    if (logFile.size() > 2 * 1024 * 1024) { // 超过 2 MB
        logFile.resize(0); // 清空
    }
}
// Main 自动生成
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(customMessageHandler); // 启用自定义信息 Handler
    home w;
    w.show();
    return a.exec();
}
