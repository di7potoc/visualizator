#ifndef GCIRCLEITEM_H
#define GCIRCLEITEM_H
#include "gobject.h"

class GCircleItem:public GObject
{
    Q_OBJECT
public:
    GCircleItem();
    explicit GCircleItem(const QString & name);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    inline QRectF boundingRect() const override;
private:
    QPointF polygon[4];
};

#endif // GCIRCLEITEM_H
