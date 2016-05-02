#include "FenPrincipale.h"

//"C:/Users/MonCompte/Desktop/Workspace_Qt/assets/images
//C:/Users/My/Desktop/Workspace_Qt/assets/images

#define myHome "http://www.google.fr/"

FenPrincipale::FenPrincipale()
{
    creerActions();
    creerBarreEtat();

    QWidget *pageOnglet = new QWidget;
    QWebView *view = new QWebView();
    view->load(QUrl(myHome));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(view);
    pageOnglet->setLayout(layout);

    //zoneCentrale->setLayout(&view);

    onglets = new QTabWidget();
    onglets->addTab(pageOnglet, "Google");

    setCentralWidget(onglets);

}
void FenPrincipale::chargerPage()
{
    QString url = text->text();

    // On rajoute le "http://" s'il n'est pas déjà dans l'adresse
    if (url.left(7) != "http://")
    {
        url = "http://" + url;
        text->setText(url);
    }

    pageActuelle()->load(QUrl(url));
}

void FenPrincipale::changementOnglet(int index)
{
    changementTitre(pageActuelle()->title());
    changementUrl(pageActuelle()->url());
}


void FenPrincipale::changementTitre(const QString & titreComplet)
{
    QString titreCourt = titreComplet;

    // On tronque le titre pour éviter des onglets trop larges
    if (titreComplet.size() > 40)
    {
        titreCourt = titreComplet.left(40) + "...";
    }

    setWindowTitle(titreCourt + " - " + tr("zNavigo"));
    onglets->setTabText(onglets->currentIndex(), titreCourt);
}

void FenPrincipale::changementUrl(const QUrl & url)
{
    if (url.toString() != tr("html/page_blanche.html"))
    {
        text->setText(url.toString());
    }
}

void FenPrincipale::chargementDebut()
{
    progression->setVisible(true);
}

void FenPrincipale::chargementEnCours(int pourcentage)
{
    progression->setValue(pourcentage);
}

void FenPrincipale::chargementTermine(bool ok)
{
    progression->setVisible(false);
    statusBar()->showMessage(tr("Prêt"), 2000);
}

void FenPrincipale::creerBarreEtat()
{
    progression = new QProgressBar(this);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression, 1);
}

QWebView *FenPrincipale::pageActuelle()
{
    return onglets->currentWidget()->findChild<QWebView *>();
}

void FenPrincipale::precedente()
{
    pageActuelle()->back();
}

void FenPrincipale::suivante()
{
    pageActuelle()->forward();
}

void FenPrincipale::actualiser()
{
    pageActuelle()->reload();
}

void FenPrincipale::arrete()
{
    pageActuelle()->stop();
}

void FenPrincipale::goHome()
{
    pageActuelle()->load(QUrl(myHome));
}

void FenPrincipale::allerA()
{
    QString lien = text->text();

        // On rajoute le "http://" s'il n'est pas déjà dans l'adresse
        if (lien.left(7) != "http://")
        {
            lien = "http://" + lien;
            text->setText(lien);
        }

    pageActuelle()->load(QUrl(lien));
}

void FenPrincipale::creerActions()
{

    actionNouvelOnglet = new QAction("&Nouvel onglet", this);
    actionNouvelOnglet->setShortcut(QKeySequence("Ctrl+N"));
    connect(actionNouvelOnglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    actionFermerOnglet = new QAction("&Fermer l'onglet", this);
    actionFermerOnglet->setShortcut(QKeySequence("Ctrl+F"));
    connect(actionFermerOnglet, SIGNAL(triggered()), this, SLOT(fermerOnglet()));
    actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *menuFichier = menuBar()->addMenu("Fichier");
    QMenu *menuEdition = menuBar()->addMenu("Navigation");
    QMenu *menuAffichage = menuBar()->addMenu("&?");

    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");

    menuFichier->addAction(actionNouvelOnglet);

    /** Bouton previous ToolBar ***/
                previous = new QAction("&Previous", this);
                //menuFichier->addAction(actionQuitter);

                previous->setShortcut(QKeySequence("Ctrl+P"));
                previous->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/prec.png"));

                connect(previous, SIGNAL(triggered()), this, SLOT(precedente()));

    /** ----------------------- **/

    /** Bouton next ToolBar ***/
                next = new QAction("Next", this);
                //menuFichier->addAction(actionQuitter);

                next->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/suiv.png"));

                connect(next, SIGNAL(triggered()), this, SLOT(suivante()));
    /** ----------------------- **/

    /** Bouton Stop ToolBar ***/
                actionStop = new QAction("&Stop", this);
                //menuFichier->addAction(actionQuitter);

                actionStop->setShortcut(QKeySequence("Ctrl+S"));
                actionStop->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/stop.png"));

                connect(actionStop, SIGNAL(triggered()), this, SLOT(stop()));
    /** ----------------------- **/

    /** Bouton Refresh ToolBar ***/
                refresh = new QAction("&Refresh", this);
                //menuFichier->addAction(actionQuitter);

                refresh->setShortcut(QKeySequence("Ctrl+R"));
                refresh->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/actu.png"));

                connect(refresh, SIGNAL(triggered()), this, SLOT(actualiser()));
    /** ----------------------- **/

    /** Bouton Home ToolBar ***/
                home = new QAction("&Home", this);

                home->setShortcut(QKeySequence("Ctrl+H"));
                home->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/home.png"));

                connect(home, SIGNAL(triggered()), this, SLOT(goHome()));
    /** ----------------------- **/

    /** QTextEdit Text ToolBar ***/

                text = new QLineEdit(myHome, this);

    /** ----------------------- **/

    /** Bouton Go ToolBar ***/
                go = new QAction("&Go", this);
                //menuFichier->addAction(actionQuitter);

                go->setShortcut(QKeySequence("Ctrl+G"));
                go->setIcon(QIcon("C:/Users/My/Desktop/Workspace_Qt/assets/images/go.png"));

                connect(go, SIGNAL(triggered()), this, SLOT(allerA()));
    /** ----------------------- **/


        /*QAction *actionQuitter2 = new QAction("Quitter au Survol", this);
        menuFichier->addAction(actionQuitter2);*/

        QAction *actionGras = new QAction("&Gras", this);
        menuEdition->addAction(actionGras);

        actionGras->setCheckable(true);

    /** ToolBar **/
        QToolBar *toolBarFichier = addToolBar("Fichier");

        toolBarFichier->addAction(previous);
        toolBarFichier->addAction(next);
        toolBarFichier->addAction(actionStop);
        toolBarFichier->addAction(refresh);
        toolBarFichier->addAction(home);
        toolBarFichier->addWidget(text);
        toolBarFichier->addAction(go);

       /* toolBarFichier->addSeparator();

        QFontComboBox *choixPolice = new QFontComboBox;
        toolBarFichier->addWidget(choixPolice);*/

        //connect(actionQuitter2, SIGNAL(hovered()), qApp, SLOT(quit()));

    /** ------- **/
}

QWidget *FenPrincipale::creerOngletPageWeb(QString url)
{
    QWidget *pageOnglet = new QWidget;
    QWebView *pageWeb = new QWebView;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pageWeb);
    pageOnglet->setLayout(layout);

    if (url.isEmpty())
    {
        pageWeb->load(QUrl(tr("html/page_blanche.html")));
    }
    else
    {
        if (url.left(7) != "http://")
        {
            url = "http://" + url;
        }
        pageWeb->load(QUrl(url));
    }

    // Gestion des signaux envoyés par la page web
    connect(pageWeb, SIGNAL(titleChanged(QString)), this, SLOT(changementTitre(QString)));
    connect(pageWeb, SIGNAL(urlChanged(QUrl)), this, SLOT(changementUrl(QUrl)));
    connect(pageWeb, SIGNAL(loadStarted()), this, SLOT(chargementDebut()));
    connect(pageWeb, SIGNAL(loadProgress(int)), this, SLOT(chargementEnCours(int)));
    connect(pageWeb, SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine(bool)));

    return pageOnglet;
}

void FenPrincipale::nouvelOnglet()
{
    int indexNouvelOnglet = onglets->addTab(creerOngletPageWeb(), tr("(Nouvelle page)"));
    onglets->setCurrentIndex(indexNouvelOnglet);

    text->setText("");
    text->setFocus(Qt::OtherFocusReason);
}

void FenPrincipale::fermerOnglet()
{
    // On ne doit pas fermer le dernier onglet, sinon le QTabWidget ne marche plus
    if (onglets->count() > 1)
    {
        onglets->removeTab(onglets->currentIndex());
    }
    else
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Il faut au moins un onglet !"));
    }
}
