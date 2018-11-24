#ifndef GTRIANLEITEM_H
#define GTRIANLEITEM_H
#include "gobject.h"

class GTrianleItem:public GObject
{
    Q_OBJECT
public:
    explicit GTrianleItem(const QString &name);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPointF polygon[3];
};

#endif // GTRIANLEITEM_H
