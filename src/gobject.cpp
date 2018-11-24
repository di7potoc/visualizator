#include "gobject.h"
#include "geffect.h"
#include <QDebug>

unsigned int GObject::object_counter = 0;

GObject::GObject(const QString &name,QObject *parent):QObject(parent)
{
    this->name = name + QString::number(object_counter);
    width = 30;
    object_counter++;
    effect = nullptr;
    penDef.setBrush(Qt::NoBrush);
    penDef.setColor(Qt::green);
}

GObject::~GObject()
{
    if(effect !=nullptr)delete effect;
}

QString GObject::GetNameItem()
{
    return name;
}

void GObject::setEffect(GEffect *effectNew)
{
    if(effectNew != nullptr)
    {
        effect = effectNew;
        bool success = connect(this,&GObject::signal_enableEffect,effect,&GEffect::slot_setEnableEffect);
    }
}
