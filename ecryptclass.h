#ifndef ECRYPTCLASS_H
#define ECRYPTCLASS_H

#include <des.h>
#include <string.h>
#include <QtCore>

class EcryptClass
{
public:
    EcryptClass();
    bool EcryptFile(QFile*, QFile *encrypted_file,int);
    bool DecryptFile(QFile*);
    QString DecryptOneLine(QString);

    QByteArray EcryptOneLine(QByteArray input_str, int Type);
    QList<QByteArray> *DivideQStringtoFixedWidth(QByteArray str);
private:
    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock input;
    DES_cblock output;

    void FillBlock(const QByteArray,DES_cblock&);
    void FillQString(const DES_cblock&, QByteArray &);

};

#endif // ECRYPTCLASS_H
