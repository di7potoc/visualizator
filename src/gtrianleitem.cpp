#include "gtrianleitem.h"
#include "geffect.h"
#include <QPainter>

GTrianleItem::GTrianleItem(const QString &name):GObject(name)
{
    qreal xpos = static_cast<qreal>(width*(static_cast<int>(object_counter)));
    QPointF start(xpos,100);
    polygon[0] = start;
    polygon[1] = start + QPointF(0,width);
    polygon[2] = start + QPointF(width,width);
}

void GTrianleItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->save();
    painter->setPen(penDef);
    if(effect != nullptr)
        effect->applyEffect(painter);
    painter->drawPolygon(polygon,3);
    painter->restore();
}

QRectF GTrianleItem::boundingRect() const
{

    return QRectF(polygon[0],polygon[2]);
}
