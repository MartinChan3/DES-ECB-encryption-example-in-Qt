#include "ecryptclass.h"

EcryptClass::EcryptClass()
{
    DES_string_to_key("UnionTech102",&key);
    DES_set_key_checked(&key,&schedule);
}

QByteArray EcryptClass::EcryptOneLine(QByteArray input_str,int Type)
{
    QList<QByteArray> *list = DivideQStringtoFixedWidth(input_str);
    QByteArray result;
    result.clear();
    QByteArray tmp_str;
    for (int i=0;i<list->size();i++)
    {
        tmp_str = list->value(i);
        FillBlock(tmp_str,input);
        DES_ecb_encrypt(&input,&output,&schedule,Type);
        FillQString(output,tmp_str);
        result += tmp_str;
    }

    return result;
}

bool EcryptClass::EcryptFile(QFile *tmp_file,QFile *encrypted_file,int Type)
#define ANOTHER
{
    QByteArray single_line_str;
    if (tmp_file->open(QIODevice::ReadOnly))
    {
        if (encrypted_file->open(QIODevice::WriteOnly))
        {
            QDataStream stream(encrypted_file);
            single_line_str = tmp_file->readAll();
            QByteArray tmp_arr = EcryptOneLine(single_line_str,Type);
            stream.writeRawData(tmp_arr.constData(),tmp_arr.size());

            encrypted_file->close();
        }
        tmp_file->close();
        return true;
    }
    else
    {
        qDebug()<<"Wrong when open the decrypted file";
        return false;
    }
}
#ifdef  ANOTHER
#else

{
    QString single_line_str;
    if (tmp_file->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        if (encrypted_file->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QTextStream stream(encrypted_file);
            while(!tmp_file->atEnd())
            {
                single_line_str = tmp_file->readLine();
                stream << EcryptOneLine(single_line_str,Type) << endl;
            }
            encrypted_file->close();
        }
        tmp_file->close();
        return true;
    }
    else
    {
        qDebug()<<"Wrong when open the decrypted file";
        return false;
    }
}
#endif

QString EcryptClass::DecryptOneLine(QString ecrypted_str)
{
    ecrypted_str.size();
    //output = ecrypted_str.toLocal8Bit().constData();
    DES_ecb_encrypt(&output,&input,&schedule,DES_DECRYPT);
    //return QString(QLatin1String(input));
    return QString(" ");
}


QList<QByteArray> *EcryptClass::DivideQStringtoFixedWidth(QByteArray str)
{
    QList<QByteArray> *vec = new QList<QByteArray>();
    QByteArray left8;
    while(str.size()>0)
    {
        if (str.size()>8)
        {
            left8 = str.left(8);
            str = str.right(str.size()-8);

        }
        else
        {
            left8 = str;
            str.clear();
        }
        vec->append(left8);
    }

    return vec;
}

void EcryptClass::FillBlock(const QByteArray str, DES_cblock &block)
{
    if (str.size()==8)
    {
        for(int i=0;i<8;i++)
        {
            block[i] = str.at(i);
        }
    }
    else if (str.size()<8)
    {
        for (int i=0;i<str.size();i++)
        {
            block[i] = str.at(i);
        }
        for (int j=str.size();j<8;j++)
        {
            block[j] = '\0';
        }
    }
    *(block+8) = '\0';

}

void EcryptClass::FillQString(const DES_cblock &block, QByteArray &str)
{
    str.clear();
//    char single_char;
//    for (int i=0;i<8;i++)
//    {
//        single_char = (char)block[i];
//        str.append(single_char);
//    }
//    str.append('\0');
    str.setRawData((char*)block,8);
}

bool EcryptClass::DecryptFile(QFile *tmp_file)
{
    QString single_line_str;
    if (tmp_file->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while(!tmp_file->atEnd())
        {
            single_line_str = tmp_file->readLine();
            qDebug()<<DecryptOneLine(single_line_str);
        }
        tmp_file->close();
        return true;
    }
    else
    {
        qDebug()<<"Wrong when open the ecrypted file";
        return false;
    }
}
