#ifndef ETAT_ENFANT_H
#define ETAT_ENFANT_H


#include <QtDebug>
#include <QSqlQueryModel>

 class Etat_enfant
{
    int id_etat;
    QString Etat_sante;
    QString Etat_psychique;

public:
    Etat_enfant();
    Etat_enfant(int,QString,QString);
    int getid_etat(){return id_etat;}
    QString getetat_sante() {return etat_sante;}
    QString getetat_psychique(){return Etat_psychique;}
//    QString getetat_scolaire();
//    QString getetat_social();

    void setid_etat(int id_etat){this->id_etat=id_etat;}
    void setetat_sante(QString etat_sante){this->etat_sante=etat_sante;}
    void setetat_psychique(QString etat_psychique){this->etat_psychique=etat_psychique;}
//    void setetat_scolaire(QString);
//    void setetat_social(QString);

    bool ajouter();
    QSqlQueryModel * afficher ();

    bool modifier(int,QString,QString);
    bool supprimer(int);



private:
//    int id_etat;
    QString etat_sante, etat_psychique;

};
 #endif // CONNECTION_H


