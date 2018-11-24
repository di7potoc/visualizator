#include "geffect.h"
#include <QDebug>

GEffect::GEffect()
{
    enableEffect = false;
}

GEffect::~GEffect()
{

}

bool GEffect::isEnabled()
{
    return enableEffect;
}

void GEffect::slot_setEnableEffect(bool enable)
{
    enableEffect = enable;
}

GColorPenEffect::GColorPenEffect()
{

}

GColorPenEffect::GColorPenEffect(const QColor &color)
{
    colorPen = color;
}

GColorPenEffect::~GColorPenEffect()
{

}

void GColorPenEffect::applyEffect(QPainter *painter)
{
    if(painter != nullptr)
    {
        if(this->enableEffect)
        {
            QPen pen = painter->pen();
            pen.setColor(colorPen);
            painter->setPen(pen);
        }
    }
}

void GColorPenEffect::setColor(const QColor& color)
{
    colorPen = color;
}

GSizeEffect::GSizeEffect()
{
    scaleParam = 0;
}

GSizeEffect::GSizeEffect(const qreal scale)
{
    scaleParam = scale;
}

GSizeEffect::~GSizeEffect()
{

}

void GSizeEffect::applyEffect(QPainter *painter)
{
    if(painter != nullptr)
    {
        if(this->enableEffect)
        {
            QTransform transfom;
            transfom.scale(scaleParam,scaleParam);
            painter->setTransform(transfom);

        }
    }
}

void GSizeEffect::setSize(const qreal scale)
{

    scaleParam = scale;
}

GThickPenEffect::GThickPenEffect()
{

}

GThickPenEffect::GThickPenEffect(const qreal thickness)
{
    thickParam = thickness;
}

GThickPenEffect::~GThickPenEffect()
{

}

void GThickPenEffect::applyEffect(QPainter *painter)
{
    if(painter != nullptr)
    {
        if(this->enableEffect)
        {
            QPen pen = painter->pen();
            pen.setWidthF(thickParam);
            painter->setPen(pen);
        }
    }
}

void GThickPenEffect::setThickness(const qreal thickness)
{
    thickParam = thickness;
}
