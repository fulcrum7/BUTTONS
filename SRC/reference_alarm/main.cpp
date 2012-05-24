 #include <QtGui>
 #include <QWidget>
#include "polledbuttons.h"







 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     AlarmButtons pb(0);
     pb.show();
     return app.exec();
 }
