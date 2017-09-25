///////////////////////////////////////////////////////////////////////////////
// Copyright   :union tech.All rights reserved.
//
// 文件名称     :ecryptclass.h
// 简要概述     :封装openssl并提供加密/解密函数Qt接口
//
// 作者        :陈禺
// 版本        :1.0
// 创建日期     :2017-08-23
// 说明        :
///////////////////////////////////////////////////////////////////////////////
#ifndef ECRYPTCLASS_H
#define ECRYPTCLASS_H

#include <des.h>
#include <string.h>
#include <QtCore>

class EcryptClass
{
public:
    EcryptClass();
    bool EcryptFile(QFile*, QFile *encrypted_file,int);//核心函数，提供函数接口
    bool DecryptFile(QFile*);
    QString DecryptOneLine(QString);

    QByteArray EcryptOneLine(QByteArray input_str, int Type);
    QList<QByteArray> *DivideQStringtoFixedWidth(QByteArray str);
private:
    DES_cblock key;               //翻译后的密码
    DES_key_schedule schedule;    //对应密码表
    DES_cblock input;
    DES_cblock output;

    void FillBlock(const QByteArray,DES_cblock&);
    void FillQString(const DES_cblock&, QByteArray &);

};

#endif // ECRYPTCLASS_H
