#include "QtAudio.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtAudio w;
    w.show();
    return a.exec();
}
