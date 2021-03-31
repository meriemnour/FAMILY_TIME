#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "etat.h"
#include "repas.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QPushButton>
#include <QPdfWriter>
#include <QApplication>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QTextBrowser>
#include <QFileDialog>
#include <QTextBlock>
#include <QTextEdit>
#include <cstdlib>
#include <QRadioButton>
#include "repas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id_3->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id_repas->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_ajouter_3_clicked()
{


    int id_etat=ui->le_id_3->text().toInt();
    QString Etat_sante=ui->sante_3->text();
    QString Etat_psychique=ui->psy_3->text();

    Etat_enfant c(id_etat , Etat_sante, Etat_psychique );

    bool test=c.ajouter();

    if (test)

       {
           ui->tableView->setModel(tmp.afficher());
           QMessageBox::information(nullptr, QObject::tr("okay"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not okay"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }



//void MainWindow::on_pushButton_2_clicked()
//{

//}

void MainWindow::on_b_modifier_3_clicked()
{
    int id_etat=ui->le_id2_3->text().toInt();
    QString Etat_sante=ui->sante2_3->text();
    QString Etat_psychique=ui->psy2_3->text();

      Etat_enfant c(id_etat , Etat_sante, Etat_psychique );

       bool test=c.modifier();

       if (test)

       {
           ui->tableView->setModel(tmp.afficher());
           QMessageBox::information(nullptr, QObject::tr("okay"),
                       QObject::tr("modification effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not okay"),
                       QObject::tr("modification non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_b_sup_3_clicked()
{
    int id_etat=ui->le_id3_3->text().toInt();
    bool test=tmp.supprimer(id_etat);

    if (test)

    {
        ui->tableView->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("okay"),
                    QObject::tr("suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_b_ajouter_repa_clicked()
{

    QString avis_repas=ui->le_avis->text();
    int id_repas=ui->le_id_repas->text().toInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->text();
    QString recette=ui->la_recette->text();
    int nb_calories=ui->le_nbcalo->text().toInt();

    repas r(avis_repas,id_repas,nom,type,recette,nb_calories);
    bool test=r.ajouterr();

    if (test)

       {
           ui->tableView_REPAS->setModel(etmp.afficherr());
           QMessageBox::information(nullptr, QObject::tr("okay"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not okay"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }



void MainWindow::on_b_modifier_repa_clicked()
{
    QString avis_repas=ui->le_avis_2->text();
    int id_repas=ui->le_id_repas_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString type=ui->le_type_2->text();
    QString recette=ui->la_recette_2->text();
    int nb_calories=ui->le_nbcalo_2->text().toInt();
     repas r(avis_repas,id_repas,nom,type,recette,nb_calories);
     bool test=r.modifierr();

     if (test)

        {
            ui->tableView_REPAS->setModel(etmp.afficherr());
            QMessageBox::information(nullptr, QObject::tr("okay"),
                        QObject::tr("ajout effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not okay"),
                        QObject::tr("ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_b_sup_repas_clicked()
{
    int id_repas=ui->le_id3_5->text().toInt();
    bool test=etmp.supprimerr(id_repas);

    if (test)

    {
        ui->tableView_REPAS->setModel(etmp.afficherr());
        QMessageBox::information(nullptr, QObject::tr("okay"),
                    QObject::tr("suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
