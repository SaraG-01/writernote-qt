#include "updatecheck.h"

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include <cpr/cpr.h>

//#include "encode_base.h"

#include <QFile>
#include <QTextStream>

//using Base64  = macaron::Base64;

updatecheck::updatecheck()
{
    QFile file(POSIZIONEPATHVERSIONE);

    if(!file.open(QIODevice::ReadOnly)) {
        this->currentversione = -1;
        return;
    }

    bool ok = false;
    QTextStream in(&file);

    while(!in.atEnd()) {
        this->currentversione = in.readLine().toUInt(&ok);
    }

    file.close();
}

static QString decode_frombase64(QString stringa){
    QByteArray b(stringa.toUtf8().constData());

    return b.fromBase64(b);
}

bool updatecheck::checkupdate(){
    if(this->currentversione == -1)
        return false;

    int len, lenfinale;

    cpr::Response r = cpr::Get(cpr::Url{SITOGIT});
    if(r.status_code != 200){
        // there is no internet connection
        return false;
    }


    len = r.text.find(NOMECONTENT);
    lenfinale = r.text.find(NOMEFINE);

    len += strlen(NOMECONTENT) + 3;

    QString stringatemp_int = r.text.substr(len, lenfinale - len - 8).c_str();

    stringatemp_int = decode_frombase64(stringatemp_int);

    bool ok;
    int versione = stringatemp_int.toInt(&ok);

    if(!ok)
        return false;


    if(versione > this->currentversione)
        return true;

    return true;

}




