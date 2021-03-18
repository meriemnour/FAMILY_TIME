#include "dialog_enfant.h"
#include "ui_dialog_enfant.h"
#include <QDebug>
#include <QIntValidator>
Dialog_enfant::Dialog_enfant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_enfant)
{
    ui->setupUi(this);
     ui->tableView->setModel(tmpenf.afficher());
     QIntValidator *roll = new QIntValidator(100000,999999);
     ui->lineEdit_3->setValidator(roll);

}

Dialog_enfant::~Dialog_enfant()
{
    delete ui;
}

void Dialog_enfant::on_pushButton_clicked()
{

    int id=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit->text();
    QString prenom=ui->lineEdit_2->text();
    QString datenais=ui->dateEdit->text();
    QString sexe=ui->comboBox->currentText();
    float poids=ui->lineEdit_4->text().toFloat();
    float hauteur=ui->lineEdit_5->text().toFloat();
    enfant e(id,nom,prenom,datenais,sexe,poids,hauteur);
    if(!tmpenf.rechercher(id))
    {
   bool test= e.ajouter();

       if(test)
       { ui->tableView->setModel(tmpenf.afficher());
           QMessageBox::information(nullptr, QObject::tr("enfant ajouté"),
                       QObject::tr("successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("enfant non ajouté"),
                       QObject::tr("failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
    else

            QMessageBox::critical(nullptr, QObject::tr("enfant existant"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
void Dialog_enfant::on_pushButton_2_clicked()
{
    int supp=ui->lineEdit_6->text().toInt();
    if(tmpenf.rechercher(supp))
    {
    bool test= tmpenf.supprimer(supp);

        if(test)
        { ui->tableView->setModel(tmpenf.afficher());
            QMessageBox::information(nullptr, QObject::tr("enfant supprimé"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("enfant non supprimé"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else QMessageBox::critical(nullptr, QObject::tr("enfant inexistant"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
    void Dialog_enfant::on_pushButton_3_clicked()
    {
    ui->tableView->setModel(tmpenf.afficher());
}

void Dialog_enfant::on_pushButton_4_clicked()
{
    id=ui->lineEdit_7->text().toInt();
    if(tmpenf.rechercher(id))
    {   ui->groupBox->setEnabled(true);}
        else
        {QMessageBox::critical(nullptr, QObject::tr("identifiant introuvable"),
                                  QObject::tr("erreur.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void Dialog_enfant::on_pushButton_5_clicked()
{
    QString nom=ui->lineEdit_8->text();
    QString prenom=ui->lineEdit_9->text();
    QString datenais=ui->dateEdit_2->text();
    QString sexe=ui->comboBox_2->currentText();
    float poids=ui->lineEdit_11->text().toFloat();
    float hauteur=ui->lineEdit_10->text().toFloat();
    enfant e(id,nom,prenom,sexe,datenais,poids,hauteur);
    if(tmpenf.rechercher(id)){
    bool test=e.modifier(id);

        if(test)
        { ui->tableView->setModel(tmpenf.afficher());
            ui->groupBox->setDisabled(true);
            QMessageBox::information(nullptr, QObject::tr("enfant modifié"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("enfant non modifié"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else  {QMessageBox::critical(nullptr, QObject::tr("identifiant introuvable"),
                                 QObject::tr("erreur.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
    }




