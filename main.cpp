#include "ecryptclass.h"
#include "QFile"
#include <QDebug>

int main(int argc,char **argv)
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    EcryptClass ecb;
    QFile *newfile = new QFile("drogba.txt");
    QFile *encryptedFile = new QFile("encrypted.txt");
    QFile *decryptedFile = new QFile("decrypted.txt");
    ecb.EcryptFile(newfile,encryptedFile,DES_ENCRYPT);
    ecb.EcryptFile(encryptedFile,decryptedFile,DES_DECRYPT);

    newfile->deleteLater();
    encryptedFile->deleteLater();
    decryptedFile->deleteLater();

    return 0;
}
