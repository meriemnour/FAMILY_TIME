#include "repas.h"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>
repas::repas()
{
// avis_repas="";id_repas=0;nom="";type="";recette="";nb_calories=0;
}
repas::repas(QString avis_repas,int id_repas,QString nom,QString type,QString recette,int nb_calories)
{

    this->avis_repas=avis_repas;
    this->id_repas=id_repas;
    this->nom=nom;
    this->type=type;
    this->recette=recette;
    this->nb_calories=nb_calories;
}


bool repas::ajouterr()
{

    QSqlQuery query ;
    QString  res = QString::number(id_repas);
    QString  res1 = QString::number(nb_calories);


            query.prepare("INSERT INTO REPAS (AVIS_REPAS,ID_REPAS,NOM,TYPE,RECETTE,NB_CALORIES)"
                          "VALUES (:AVIS_REPAS,:ID_REPAS, :NOM, :TYPE, :RECETTE, :NB_CALORIES)");

               query.bindValue(":AVIS_REPAS",avis_repas);
               query.bindValue(":ID_REPAS", res );
               query.bindValue(":NOM", nom);
               query.bindValue(":TYPE", type);
               query.bindValue(":RECETTE", recette);
               query.bindValue(":NB_CALORIES",res1);

                return query.exec();
}


QSqlQueryModel * repas::afficherr()

   {

    QSqlQueryModel *model = new QSqlQueryModel ();

         model->setQuery("SELECT * FROM REPAS");

          model->setHeaderData(0, Qt::Horizontal,QObject::tr ("id_repas"));

         model->setHeaderData(1, Qt::Horizontal,QObject::tr ("nom"));

         model->setHeaderData(2, Qt::Horizontal, QObject::tr ("type"));

         model->setHeaderData(3, Qt::Horizontal,QObject::tr ("recette"));

         model->setHeaderData(4, Qt::Horizontal,QObject::tr ("nb_calories"));

         model->setHeaderData(5, Qt::Horizontal,QObject::tr ("avis_repas"));



    return model ;


 }
bool repas::modifierr()

{
    QSqlQuery query;
    QString  res = QString::number(id_repas);
    QString  res1 = QString::number(nb_calories);


   query.prepare("UPDATE REPAS SET AVIS_REPAS=:AVIS_REPAS,NOM=:NOM,TYPE=:TYPE,RECETTE=:RECETTE,NB_CALORIES=:NB_CALORIES where ID_REPAS=:ID_REPAS ");

   query.bindValue(":AVIS_REPAS",avis_repas);
   query.bindValue(":ID_REPAS", res );
   query.bindValue(":NOM", nom);
   query.bindValue(":TYPE", type);
   query.bindValue(":RECETTE", recette);
   query.bindValue(":NB_CALORIES",res1);

    return    query.exec();
}
bool repas::supprimerr(int id_repas)
    {

        QSqlQuery query;
        QString  res = QString::number(id_repas);


     query.prepare("Delete from REPAS  where ID_REPAS= :ID_REPAS ");

     query.bindValue(":ID_REPAS", res );

       return query.exec();

    }

