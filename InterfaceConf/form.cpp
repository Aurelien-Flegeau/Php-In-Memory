#include <form.h>
#include <QUrl>
form::form(): QWidget()
{
    // Création GRID LAYOUT secondaire
    //Instanciation des composants
    maxMemory = new QLineEdit;
    maxMemory->setValidator( new QIntValidator(0, 999, this));
    name = new QLineEdit;
    age = new QLineEdit;
    age->setValidator( new QIntValidator(0, 150, this));
    labelMaxMemory = new QLabel("Max Memory : ");
    labelName = new QLabel("Name : ");
    labelAge = new QLabel("Number : ");

    listTaille = new QComboBox;
    listTaille->addItem("Octets");
    listTaille->addItem("Mo");
    listTaille->addItem("Go");

    //Placement des composant dans la grille
    gridLayout = new QGridLayout;
    gridLayout->addWidget(labelMaxMemory, 0, 0,Qt::AlignRight);
    gridLayout->addWidget(maxMemory, 0, 1);
    gridLayout->addWidget(listTaille, 0, 2);
    gridLayout->addWidget(labelName, 1, 0,Qt::AlignRight);
    gridLayout->addWidget(name, 1, 1);
    gridLayout->addWidget(labelAge, 2, 0,Qt::AlignRight);
    gridLayout->addWidget(age, 2, 1);
    // -------------------------------------------- //

    // Création du LAYOUT PRINCIPAL de la fenêtre (vertical) //
    //Instanciation des composants
    layoutPrincipal = new QVBoxLayout;
    boutonOpenFile = new QPushButton("Ouvir un fichier");
    boutonSave = new QPushButton("Sauver");
    boutonQuitter = new QPushButton("Quitter");

    //Placement des composants
    //layoutPrincipal->addWidget(boutonOpenFile);
    layoutPrincipal->addLayout(gridLayout);
    layoutPrincipal->addWidget(boutonSave);
    layoutPrincipal->addWidget(boutonQuitter);
    // -------------------------------------------- //

    //Connect button
    QObject::connect(boutonSave, SIGNAL(clicked()), this, SLOT(save()));
    QFile fichier("php-in-memory.cnf");
    QString texte;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        while(!flux.atEnd())
        {
            QString temp = flux.readLine();

            QStringList list = temp.split(":");
            QString str1 = list.at(0);

            if(str1.contains("Name"))
                name->setText(list.at(1).trimmed());

            if(str1.contains("Max memory")){
                int value = list.at(1).trimmed().toInt();
                if(value > 999999){
                    value = value/1000000;
                    QString a = QString::number(value);
                    maxMemory->setText(a);

                    listTaille->setCurrentIndex(2);
                }
                else if(value > 999){
                    value = value/1000;
                    QString a = QString::number(value);
                    maxMemory->setText(a);
                    listTaille->setCurrentIndex(1);
                }
                else maxMemory->setText(list.at(1).trimmed());
            }

            if(str1.contains("Number"))
                age->setText(list.at(1).trimmed());
        }
        fichier.close();
    }
    else texte = "Impossible d'ouvrir le fichier !";

    QFile File("style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    this->setStyleSheet(StyleSheet);
    this->setLayout(layoutPrincipal);
}

void form::save()
{
    QFile file("php-in-memory.cnf");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        // erreur ...
    }
    else
    {
        QTextStream stream(&file);
        int index = listTaille->currentIndex();
        if(index == 0)
            stream << "Max memory: " << maxMemory->text() << "\n";
        else if(index == 1)
            stream << "Max memory: " << maxMemory->text()+"000" << "\n";
        else if(index == 2)
            stream << "Max memory: " << maxMemory->text()+"000000" << "\n";

        stream << "Name: " << name->text() << "\n";
        stream << "Number: " << age->text() << "\n";
    }
    file.close();
}
