#include <QPainter>
#include "gsquareitem.h"
#include "geffect.h"
GSquareItem::GSquareItem(const QString &name):GObject(name)
{
    qreal xpos = static_cast<qreal>(width*(static_cast<int>(object_counter)));
    QPointF start(xpos,0);
    polygon[0] = start;
    polygon[1] = start + QPointF(0,width);
    polygon[2] = start + QPointF(width,width);
    polygon[3] = start + QPointF(width,0);
}

void GSquareItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(penDef);
    if (effect != nullptr)
        effect->applyEffect(painter);
    painter->drawPolygon(polygon,4);
    painter->restore();
}

QRectF GSquareItem::boundingRect() const
{
    return QRectF(polygon[0],polygon[2]);
}
