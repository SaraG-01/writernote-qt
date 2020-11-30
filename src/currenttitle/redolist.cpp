#ifndef REDO_LIST_CPP
#define REDO_LIST_CPP

#include "../mainwindow.h"


/*
Siccome con un singolo click cambia l'item nella lista, è necessario, in caso non si
voglia passare a un altro copybook, reimpostare quello precedente.
*/
void redolist(MainWindow *parent)
{
    if(parent->self->currentTitle == "")
        return;
    int posizione = parent->self->indice.titolo.indexOf(parent->self->currentTitle.c_str(), 0);
    parent->ui->listWidgetSX->setCurrentRow(posizione);
}

#endif
