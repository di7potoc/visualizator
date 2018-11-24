#ifndef GEFFECT_H
#define GEFFECT_H

#include <QObject>
#include <QPainter>


class GEffect:public QObject
{
    Q_OBJECT
public:
    GEffect();
    virtual ~GEffect();
    virtual void applyEffect(QPainter *)=0;
    inline bool isEnabled();
public slots:
    void slot_setEnableEffect(bool enable);
protected:
    bool enableEffect;
};

class GColorPenEffect final:public GEffect
{
    Q_OBJECT
public:
    GColorPenEffect();
    GColorPenEffect(const QColor &);
    ~GColorPenEffect();
    void applyEffect(QPainter *);
    void setColor(const QColor &);
private:
    QColor colorPen;
};
class GSizeEffect final:public GEffect
{
    Q_OBJECT
public:
    GSizeEffect();
    GSizeEffect(const qreal);
    ~GSizeEffect();
    void applyEffect(QPainter *);
    void setSize(const qreal );
private:
    qreal scaleParam;
};
class GThickPenEffect final:public GEffect
{
    Q_OBJECT
public:
    GThickPenEffect();
    GThickPenEffect(const qreal);
    ~GThickPenEffect();
    void applyEffect(QPainter *);
    void setThickness(const qreal );
private:
    qreal thickParam;
};

#endif // GEFFECT_H
