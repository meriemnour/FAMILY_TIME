#ifndef REPAS_H
#define REPAS_H

#include <QtDebug>
#include <QSqlQueryModel>
class repas
{

public:
    repas();
    repas(QString,int,QString,QString,QString,int);
    QString getavis_repas() {return avis_repas;}
    int getid_repas(){return id_repas;}
    QString getnom() {return nom;}
    QString gettype() {return type;}
    QString getrecette() {return recette;}
    int getnb_calories(){return nb_calories;}



    void setavis_repas(QString avis_repas){this->avis_repas=avis_repas;}
    void setid_repas(int id_repas){this->id_repas=id_repas;}
    void setnom(QString nom){this->nom=nom;}
    void settype(QString type){this->type=type;}
    void setrecette(QString recette){this->recette=recette;}
    void setnb_calories(int nb_calories){this->nb_calories=nb_calories;}


    bool ajouterr();
    QSqlQueryModel * afficherr ();

    bool modifierr();
    bool supprimerr(int);


private:
    QString avis_repas;
    int id_repas;
    QString nom;
    QString type;
    QString recette;
    int nb_calories;


};


#endif // REPAS_H
