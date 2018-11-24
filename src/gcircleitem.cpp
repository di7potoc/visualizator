#include <QPainter>
#include "gcircleitem.h"
#include "geffect.h"


GCircleItem::GCircleItem(const QString &name):GObject(name)
{
    qreal xpos = static_cast<qreal>(width*(static_cast<int>(object_counter)));
    QPointF start(xpos,0);
    polygon[0] = start;
    polygon[1] = start + QPointF(0,width);
    polygon[2] = start + QPointF(width,width);
    polygon[3] = start + QPointF(width,0);
}

void GCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(penDef);
    if (effect != nullptr)
        effect->applyEffect(painter);
    painter->drawEllipse(QRectF(polygon[0],polygon[2]));
    painter->restore();
}

QRectF GCircleItem::boundingRect() const
{
    return QRectF(polygon[0]-QPointF(1,1),polygon[2]+QPointF(1,1));
}
