#ifndef GOBJECT_H
#define GOBJECT_H
#include <QGraphicsItem>
#include <QObject>
#include <QPen>
#include <memory>

class GEffect;

class GObject:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GObject(const QString &name,QObject *parent = nullptr);
    QString GetNameItem();
    void setEffect(std::unique_ptr<GEffect>&&);
    virtual ~GObject();
protected:
    QString name;
    static unsigned int object_counter;
    int width;
    std::unique_ptr<GEffect> effect;
    QPen penDef;
signals:
    void signal_enableEffect(bool);
};

enum GObjectType{TRIANGLE,SQUARE,CIRCLE};
#endif // GOBJECT_H
