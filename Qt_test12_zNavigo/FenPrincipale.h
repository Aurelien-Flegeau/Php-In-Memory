#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtGui>
#include <QtWebKit>
#include <QtWidgets>
#include <QtWebKitWidgets>
#include <string>
#include <QObject>

using namespace std;

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale();
    private:
        void creerActions();
        void creerBarreEtat();
        QWebView *pageActuelle();
        QWidget *creerOngletPageWeb(QString url = "");

    private slots:
        void precedente();
        void suivante();
        void actualiser();
        void arrete();
        void goHome();
        void allerA();
        void chargementDebut();
        void chargementEnCours(int pourcentage);
        void chargementTermine(bool ok);
        void chargerPage();
        void changementOnglet(int index);
        void changementTitre(const QString & titreComplet);
        void changementUrl(const QUrl & url);
        void nouvelOnglet();
        void fermerOnglet();


    private:
        QTabWidget *onglets;

        QAction *previous;
        QAction *next;
        QAction *refresh;
        QAction *actionQuitter;
        QAction *actionStop;
        QAction *home;
        QAction *go;
        QAction *actionNouvelOnglet;
        QAction *actionFermerOnglet;
        QLineEdit *text;
        QProgressBar *progression;
};


#endif // FENPRINCIPALE_H
