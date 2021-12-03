#include "widget.h"
#include <QFile>
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qSetMessagePattern( "[%{time yyyy-MM-dd h:mm:ss.zzz} %{if-debug}Debug%{endif}%{if-info}Info%{endif}%{if-warning}Warning%{endif}%{if-critical}Critical%{endif}%{if-fatal}Fatal%{endif}] file:%{file},line:%{line} - %{message}" );
    QFile stylesheet_file(":/style/style.qss");
    stylesheet_file.open(QIODevice::ReadOnly);
    a.setStyleSheet(stylesheet_file.readAll());
    Widget w;
    w.show();
    return a.exec();
}
