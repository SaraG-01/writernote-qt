#include "xmlstruct.h"

#include "../currenttitle/currenttitle_class.h"

#include <zip.h>

/* la funzione gestisce la lettura del file binario */
void xmlstruct::loadbinario(){
    int err = 0;
    zip *z = zip_open(this->path_->c_str(), 0, &err);

    struct zip_stat st;
    zip_stat_init(&st);
    zip_stat(z, this->currenttitle->posizione_binario.toUtf8().constData(), 0, &st);

    zip_file *f = zip_fopen(z, this->currenttitle->posizione_binario.toUtf8().constData(), 0);

    if(f == nullptr)
    {
        qDebug() << "File impossibile da leggere";
        return;
    }

    int lunghezza=0, i;

    /* carica le x */
    zip_fread(f, &lunghezza, sizeof(int));
    int valoretemp;
    for(i=0; i < lunghezza; i++)
    {
        zip_fread(f, &valoretemp, sizeof(int));
        this->currenttitle->datatouch->x.append(valoretemp);
    }

    /* carica le y */
    zip_fread(f, &lunghezza, sizeof(int));
    for(i=0; i < lunghezza; i++){
        zip_fread(f, &valoretemp, sizeof(int));
        this->currenttitle->datatouch->y.append(valoretemp);
    }

    /* carica la posizione dei testi */
    zip_fread(f, &lunghezza, sizeof(int));
    for(i=0; i < lunghezza; i++)
    {
        zip_fread(f, &valoretemp, sizeof(int));
        this->currenttitle->datatouch->posizioneaudio.append(valoretemp);
    }
    /* TODO: implement the function to load the color */

    zip_fclose(f);
    zip_close(z);
}
