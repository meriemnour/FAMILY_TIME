#include "objet_enfant.h"



objet_enfant::objet_enfant()
{

}
objet_enfant::objet_enfant(int iden,QString name,int nb,QString types,QString priorite)
{
    id=iden;
    nomobjet=name;
    nbobjet=nb;
    type=types;
    priority=priorite;

}


bool objet_enfant::ajouter()
{

    QSqlQuery q;
    q.prepare("insert into objet_enfant values(:id,:nomobjet,:nbobjet,:type,:priority)");
    q.bindValue(":id",id);
    q.bindValue(":nomobjet",nomobjet);
    q.bindValue(":type",type);
    q.bindValue(":nbobjet",nbobjet);
    q.bindValue(":priority",priority);
    return q.exec();
}
 QSqlQueryModel * objet_enfant::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from objet_enfant");
     return model;
 }
bool objet_enfant::supprimer(int a)
{
    QSqlQuery q;
    QString res=QString::number(a);
    q.prepare("delete from objet_enfant where id=:id");
    q.bindValue(":id",res);
    return q.exec();
}



