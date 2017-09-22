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
    qDebug()<<newfile->size();
    ecb.EcryptFile(newfile,encryptedFile,DES_ENCRYPT);
    ecb.EcryptFile(encryptedFile,decryptedFile,DES_DECRYPT);
    if (newfile->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while (!newfile->atEnd())
        {
            //qDebug()<<ecb.EcryptOneLine(newfile->readLine());
        }
        newfile->close();
    }

    newfile->deleteLater();
    encryptedFile->deleteLater();
    decryptedFile->deleteLater();

    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <openssl/des.h>

//#include "hex.h"

///************************************************************************
// * DES-ECB加密方式
// * 8位密钥，加密内容8位补齐，补齐方式为：PKCS7。
// *
// * file: test_des_ecb.c
// * gcc -Wall -O2 -o test_des_ecb test_des_ecb.c hex.c -lcrypto
// *
// * author: tonglulin@gmail.com by www.qmailer.net
// ************************************************************************/
//int main(int argc, char *argv[])
//{
//    DES_key_schedule ks;

//    int i = 0;
//    int len = 0;
//    int nlen = 0;
//    int count = 0;

//    char *data = "12345678123456781234567812345678";  /* 原始明文, 十六进制字符串 */
//    char *okey = "0000000000000000";                  /* 原始密钥, 十六进制字符串 */

//    unsigned char ch = '\0';
//    unsigned char *ptr = NULL;

//    unsigned char src[16] = {0}; /* 补齐后的明文, data补齐后的1/2长度 */
//    unsigned char dst[16] = {0}; /* 解密后的明文, data补齐后的1/2长度 */

//    unsigned char out[8] = {0};
//    unsigned char tmp[8] = {0};
//    unsigned char block[8] = {0};

//    /* 设置密码表 */
//    ptr = hex2bin(okey, strlen(okey), &nlen);
//    memcpy(block, ptr, 8);
//    free(ptr);
//    DES_set_key_unchecked((const_DES_cblock*)block, &ks);

//    /* 分析补齐明文所需空间及补齐填充数据 */
//    len = strlen((char *)data);
//    ptr = hex2bin(data, len, &nlen);
//    len = (nlen / 8 + (nlen % 8 ? 1: 0)) * 8;
//    memcpy(src, ptr, len);
//    free(ptr);

//    ch = 8 - nlen % 8;
//    memset(src + nlen, ch, 8 - nlen % 8);

//    printf("加密之前: ");
//    for (i = 0; i < len; i++) {
//        printf("%.2X", *(src + i));
//    }
//    printf("\n");

//    /* 分组加密，每8字节一组 */
//    count = len / 8;
//    for (i = 0; i < count; i++) {
//        memcpy(tmp, src + 8 * i, 8);
//        DES_ecb_encrypt((const_DES_cblock*)tmp, (DES_cblock*)out, &ks, DES_ENCRYPT);
//        memcpy(dst + 8 * i, out, 8);
//    }

//    printf("加密之后: ");
//    for (i = 0; i < len; i++) {
//        printf("%.2X", *(dst + i));
//    }
//    printf("\n");

//    return 0;
//}
