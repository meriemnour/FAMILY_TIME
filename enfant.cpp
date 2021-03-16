#include "enfant.h"

enfant::enfant()
{

}
enfant::enfant(int iden,QString name,QString fname,QString gender,QString birthdate,float p,float h)
{
    id=iden;
    nom=name;
    prenom=fname;
    sexe=gender;
    datenais=birthdate;
    poids=p;
    hauteur=h;

}

bool enfant::rechercher(int rech)
{
    QSqlQuery q;
    QString res=QString::number(rech);
    q.prepare("select id from enfants where id=:id");
    q.bindValue(":id",res);
    q.exec();
    return q.next();

}
bool enfant::ajouter()
{
    QString res=QString::number(poids);
    QString res1=QString::number(hauteur);
    QSqlQuery q;
    q.prepare("insert into enfants values(:nom,:prenom,:sexe,:datenais,:poids,:hauteur,:id)");
    q.bindValue(":id",id);
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":sexe",sexe);
    q.bindValue(":datenais",datenais);
    q.bindValue(":poids",res);
    q.bindValue(":hauteur",res1);
    return q.exec();
}
bool enfant::supprimer(int a)
{
    QSqlQuery q;
    QString res=QString::number(a);
    q.prepare("delete from enfants where id=:id");
    q.bindValue(":id",res);
    return q.exec();
}
QSqlQueryModel * enfant::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from enfants");
    /*model->setHeaderData(0,Qt::Horizontal,tr("aa"));
    model->setHeaderData(1, Qt::Horizontal, tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, tr("SEXE"));
    model->setHeaderData(1, Qt::Horizontal, tr("DATENAIS"));
    model->setHeaderData(1, Qt::Horizontal, tr("POIDS"));
    model->setHeaderData(1, Qt::Horizontal, tr("HAUTEUR"));*/
    return model;
}
