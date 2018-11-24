#ifndef MODEL_H
#define MODEL_H

#include <QObject>
class QGraphicsItem;
class QGraphicsScene;
class QStringListModel;
#include <QModelIndex>

class GraphicsItemListModel:public QObject
{
    Q_OBJECT
public:
    GraphicsItemListModel(QObject *parent);
    virtual ~GraphicsItemListModel();

    QStringListModel *GraphItemTypeModel;
    QStringListModel *GraphItemListModel;
    QGraphicsScene *ModelScene;
public slots:
    virtual void slot_CreateNewItem(int indexTypeItem);
    virtual void slot_DeleteItem(int indexItem);
    virtual void slot_SelectItem(int indexItem);

signals:
    void signal_DeselectItem(int indexItem);
    void signal_SelectItem(int indexItem);
private:
    QList<QGraphicsItem*> *listItem;
    QModelIndex prevSelected;

};


#endif // MODEL_H
