#include <form.h>
#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QCombobox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFileDialog>
#include <QIntValidator>
#include <QtGui>


int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    form f;
    QObject::connect(f.boutonQuitter, SIGNAL(clicked()), &a, SLOT(quit()));
    f.show();
    return a.exec();
}
