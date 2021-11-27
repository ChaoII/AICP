#include "widget.h"

#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qSetMessagePattern( "[%{time yyyy-MM-dd h:mm:ss.zzz} %{if-debug}Debug%{endif}%{if-info}Info%{endif}%{if-warning}Warning%{endif}%{if-critical}Critical%{endif}%{if-fatal}Fatal%{endif}] file:%{file},line:%{line} - %{message}" );
    Widget w;
    w.show();
    return a.exec();
}
