#include "mainwindow.h"

#include <QApplication>

// Спасибо, разобрался!
// На всякий случай приведу свое немного модернизированное решение(без поиска имени шрифта где-то в файле):
// C++ (Qt)Выделить код:
//    int id = QFontDatabase::addApplicationFont(":/fonts/font.ttf"); //путь к шрифту
//    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
//    QFont f(family);  // QFont c вашим шрифтом

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SmartCalc 1.0");
    w.show();
    return a.exec();
}
