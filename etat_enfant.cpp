#include "etat_enfant.h"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>



Etat_enfant::Etat_enfant()
{

//  id_etat; etat_sante=""; etat_social=""; etat_scolaire=""; etat_psychique="";
}



Etat_enfant::Etat_enfant( int id_etat,QString etat_sante,QString etat_psychique)
{
this->id_etat=id_etat;
    this->etat_sante=etat_sante;
    this->etat_psychique=etat_psychique;

    }

bool Etat_enfant::ajouter()
{

    QSqlQuery query ;
    QString  res = QString::number(id_etat);



            query.prepare("INSERT INTO COMMANDE (id_etat, NB_PRODUIT,PRIX_T,DATE_COMMANDE) " "VALUES (:id_etay, :etat_sante, :etat_psychique)");

               query.bindValue(":id_etat", res );
               query.bindValue(":etat_sante", etat_sante);
               query.bindValue(":etat_psychique", etat_psychique);

                return query.exec();
}

bool Etat_enfant::modifier(int id_etat,QString etat_sante,QString etat_psychique)

{
    QSqlQuery query;
    QString res=QString::number(id_etat);

    //query.prepare("UPDATE historique SET  ID_ETAT='"+id_etat+"' , ETAT_SANTE='"+etat_sante+"' ETAT_PSYCHIQUE='"+etat_psychique+"' where id_etat= :id_etat ");
    query.bindValue(":ID_ETAT", res);
    query.bindValue(":ETAT_SANTE", etat_sante);
    query.bindValue(":ETAT_PSYCHIQUE", etat_psychique);

    return    query.exec();
}


bool Etat_enfant::supprimer(int id_etat)
    {

        QSqlQuery query;
        QString res=QString::number(id_etat);

     query.prepare("Delete from ETAT_ENFANT  where ID_ETAT= :id_etat ");

     query.bindValue(":id_etat", res );

       return query.exec();

    }



QSqlQueryModel * Etat_enfant::afficher()

   {

    QSqlQueryModel *model = new QSqlQueryModel ();

         model->setQuery("SELECT * FROM ETAT_ENFANT");

          model->setHeaderData(0, Qt::Horizontal,QObject::tr ("id_etat"));

         model->setHeaderData(1, Qt::Horizontal,QObject::tr ("etat_sante"));

         model->setHeaderData(2, Qt::Horizontal, QObject::tr ("etat_enfant"));


    return model ;


 }



