#ifndef GSQUAREITEM_H
#define GSQUAREITEM_H
#include "gobject.h"

class GSquareItem:public GObject
{
    Q_OBJECT
public:
    explicit GSquareItem(const QString &name);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPointF polygon[4];
};

#endif // GSQUAREITEM_H
