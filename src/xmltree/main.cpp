#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QTextCodec>

QTextStream result(QString ln){

}

QString parse (QRegExp rx, QString line, int i){
    rx.setMinimal(true);
    int pos = 0;
    QString s = 0;
    while ((pos = rx.indexIn(line,pos)) != -1){
    s.append(rx.cap(i));
    s.append("\n");
    pos += rx.matchedLength();
    }
return s;
}

QString newstr (QRegExp rx, QString line, int i){
    rx.setMinimal(true);
    int pos = 0;
    QString s = 0;
    while ((pos = rx.indexIn(line,pos)) != -1){
        s.append("  |        " + rx.cap(i) + "\n");
    pos += rx.matchedLength();
    }
return s;
}


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    MainWindow w;
    QFile xml("/home/student/git/db2013/xml/mephi.xml");
    QString resstr;
    xml.open(QIODevice::ReadOnly);
    QTextStream in (&xml);
    QString str = 0;
    while (!in.atEnd()){
        QString line = in.readLine();
        str.append(line);
        str = str.simplified();
    }
        QRegExp rxu ("<university name=\"([^<]*)\">(.*)</university>");
        resstr.append(parse (rxu, str,1));
        resstr += "  |-";
        str = parse(rxu,str,2);
        QRegExp rxf ("<faculty name=\"([^<]*)\">(.*)</faculty>");

        resstr.append(parse (rxf, str,1));
        QRegExp rxkib ("<faculty name=\"...\"> <department group_prefix=\"([^<]*)\"(.*)name=\"([^<]*)\">(.*)</department> </faculty>");
        resstr.insert(17,"\n  |  |-");
        resstr.insert(25,parse (rxkib,str,3));
        str = parse(rxkib,str,4);
        QRegExp rxgr ("<group number=\"([^<]*)\" (.*)> (.*) </group>");
        resstr.insert(resstr.length()- 7,"  |     |-K06-36" + parse (rxgr,str,1));
        QRegExp rx ("<student name=\"([^<]*)\"\/>");

        resstr.insert(resstr.length()- 7,  newstr (rx, str,1));
        resstr.remove(resstr.length()-7,1);
        resstr.insert(resstr.length()-6,"  |-");
        resstr.insert(resstr.length()-4,"  |-");
        resstr.insert(resstr.length()-2,"  |-");

        qDebug() << resstr;
    xml.close();
    return a.exec();
}

