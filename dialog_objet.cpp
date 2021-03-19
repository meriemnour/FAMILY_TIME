#include "dialog_objet.h"
#include "ui_dialog_objet.h"

Dialog_objet::Dialog_objet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_objet)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/asus/Desktop/rsz_objet-publicitaire-enfant-http5000.png");
    ui->label->setPixmap(pix);

}

Dialog_objet::~Dialog_objet()
{
    delete ui;
}

void Dialog_objet::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    int nobjet=ui->lineEdit_3->text().toInt();
    QString type=ui->lineEdit_4->text();
    QString priority=ui->lineEdit_5->text();
   /*objet_enfant o(id,nom,nobjet,type,priority);
   bool test= o.ajouter();

       if(test)
       {ui->tableView->setModel(tmpo.afficher());
           QMessageBox::information(nullptr, QObject::tr("enfant ajouté"),
                       QObject::tr("successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("enfant non ajouté"),
                       QObject::tr("failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);*/
    if (id < 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem id"),
                         QObject::tr("verifier id\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
    else if (nobjet < 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem HAUTEUR"),
                         QObject::tr("verifier HAUTEUR\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }

    else if (nom==""  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                         QObject::tr("verifier nom\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
    else if (type==""  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem prenom"),
                         QObject::tr("verifier prenom\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
    else if (priority==""  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem date_naissence"),
                         QObject::tr("verifier date_naissence\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }


    else
    {
        objet_enfant o(id,nom,nobjet,type,priority);

if(!tmpo.rechercher(id))
{
bool test= o.ajouter();

 if(test)
 { ui->tableView->setModel(tmpo.afficher());
     QMessageBox::information(nullptr, QObject::tr("objet ajouté"),
                 QObject::tr("successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("objet non ajouté"),
                 QObject::tr("failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}
else

      QMessageBox::critical(nullptr, QObject::tr("objet existant"),
                  QObject::tr("failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void Dialog_objet::on_pushButton_2_clicked()
{
    int id=ui->lineEdit_6->text().toInt();
    bool test=tmpo.supprimer(id);
    if(test)
    {ui->tableView->setModel(tmpo.afficher());
        QMessageBox::information(nullptr, QObject::tr("objet supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("objet non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}







void Dialog_objet::on_pushButton_3_clicked()
{

}

void Dialog_objet::on_label_3_linkActivated(const QString &link)
{

}

void Dialog_objet::on_pushButton_4_clicked()
{

}
