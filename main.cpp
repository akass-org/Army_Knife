#include "Home.h"
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include "version.h"


QString AK_VERSION = "0.4.rana.alpha.251027";
QString AKT_VERSION = "AKTools.astra.prototype";

void customMessageHandler(QtMsgType type, const QMessageLogContext &, const QString &msg)
{
    static QFile logFile("ArmyKnife.log");

    if (!logFile.isOpen()) {
        if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
            qWarning() << "无法打开日志文件是何意味？：" << logFile.errorString();
            return;
        }
    }

    QTextStream out(&logFile);
    QString level;

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

    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ")
        << "[" << level << "] "
        << msg << "\n";
    out.flush();

    // 如果是致命错误，仍然终止程序
    if (type == QtFatalMsg)
        abort();
    if (logFile.size() > 5 * 1024 * 1024) { // 超过 5 MB
        logFile.resize(0); // 清空
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(customMessageHandler);
    QString Version = "Test";
    home w;
    w.show();
    return a.exec();
}
