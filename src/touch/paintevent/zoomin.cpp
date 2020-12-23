#include "../tabletcanvas.h"
#include <QDebug>

/* automenta lo zoom */
void TabletCanvas::zoomin(QPaintEvent *event){
    if(!this->iszoomin) return;
    //qDebug() << "TabletCanvas::Zoomin";

    if(m_pixmap.width() < width())
        this->initPixmap(-1);
    else{
        int i, len = data->x.length();

        for(i=0; i < len; i ++){
            if(data->x.at(i) < posizionezoom_puntof.x())
                data->x[i] /= (data->zoom / (data->zoom + 0.05));
            else if(data->x.at(i) > posizionezoom_puntof.x())
                data->x[i] *= (data->zoom / data->zoom + 0.05);
        }

        for(i=0; i < len; i++)
            if(data->y.at(i) < posizionezoom_puntof.y())
                data->y[i] /= (data->zoom / data->zoom + 0.05);
            else if(data->y.at(i) > posizionezoom_puntof.y())
                data->y[i] *= (data->zoom / data->zoom + 0.05);
    }

    data->zoom += 0.05;

    this->isloading = true;
    this->iszoomin = false;
}