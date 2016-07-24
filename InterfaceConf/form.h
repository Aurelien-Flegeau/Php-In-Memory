#ifndef DEF_FORM
#define DEF_FORM

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QTextStream>
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

class form : public QWidget
{
    Q_OBJECT

    public slots:
        void save();
    public:
        form();

        QPushButton *boutonSave;
        QPushButton *boutonQuitter;

    private:
        QLineEdit *maxMemory;
        QLineEdit *name;
        QLineEdit *age;
        QLabel *labelMaxMemory;
        QLabel *labelName;
        QLabel *labelAge;
        QComboBox *listTaille;
        QGridLayout *gridLayout;
        QVBoxLayout *layoutPrincipal;
        QPushButton *boutonOpenFile;

};
#endif
