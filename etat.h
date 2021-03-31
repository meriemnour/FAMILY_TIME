#ifndef ETAT_H
#define ETAT_H


#include <QtDebug>
#include <QSqlQueryModel>

class Etat_enfant
{


public:
    Etat_enfant();
    Etat_enfant(int,QString,QString);
    int getid_etat(){return id_etat;}
    QString getetat_sante() {return etat_sante;}
    QString getetat_psychique(){return etat_psychique;}
//    QString getetat_scolaire();
//    QString getetat_social();

    void setid_etat(int id_etat){this->id_etat=id_etat;}
    void setetat_sante(QString etat_sante){this->etat_sante=etat_sante;}
    void setetat_psychique(QString etat_psychique){this->etat_psychique=etat_psychique;}
//    void setetat_scolaire(QString);
//    void setetat_social(QString);

    bool ajouter();
    QSqlQueryModel * afficher ();

    bool modifier();
    bool supprimer(int);



private:
    int id_etat;
    QString etat_sante;
    QString etat_psychique;

};
#endif // ETAT_H
