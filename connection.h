#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui{
class Connection;
}



class Connection
{
 public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
