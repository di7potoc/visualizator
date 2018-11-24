#include <QtWidgets>
#include "model.h"
#include "gobject.h"
#include "gtrianleitem.h"
#include "gsquareitem.h"
#include "gcircleitem.h"
#include "geffect.h"

GraphicsItemListModel::GraphicsItemListModel(QObject *parent):QObject (parent)
{
    listItem = new (std::nothrow) QList<QGraphicsItem*>();
    QStringList list ;
    list <<"TRIANGLE" << "SQUARE" << "CIRCLE";
    GraphItemTypeModel = new (std::nothrow) QStringListModel();
    GraphItemTypeModel->setStringList(list);
    GraphItemListModel = new (std::nothrow) QStringListModel();

    ModelScene = new (std::nothrow) QGraphicsScene(this);
    ModelScene->setSceneRect(0,0,800,600);

}

GraphicsItemListModel::~GraphicsItemListModel()
{
    delete listItem;
    delete ModelScene;
    delete GraphItemListModel;
    delete GraphItemTypeModel;
}


void GraphicsItemListModel::slot_CreateNewItem(int indexTypeItem)
{
    GObject *newitem = nullptr;
    GEffect *neweffect = nullptr;

    if(indexTypeItem == GObjectType::TRIANGLE)
    {
        newitem = new (std::nothrow) GTrianleItem(QString("triangle"));
        neweffect = new (std::nothrow) GSizeEffect(1.5);
    }
    if(indexTypeItem == GObjectType::SQUARE)
    {
        newitem =new (std::nothrow) GSquareItem(QString("square"));
        neweffect = new (std::nothrow) GThickPenEffect(3);
    }
    if(indexTypeItem == GObjectType::CIRCLE)
    {
        newitem = new (std::nothrow) GCircleItem(QString("circle"));
        neweffect = new (std::nothrow) GColorPenEffect(Qt::red);
    }

    auto rowcount = GraphItemListModel->rowCount();
    GraphItemListModel->insertRow(rowcount);
    rowcount = GraphItemListModel->rowCount();
    QModelIndex index = GraphItemListModel->index(rowcount-1);
    if(newitem != nullptr)
    {
        newitem->setEffect(neweffect);
        listItem->append(newitem);
        GraphItemListModel->setData(index,newitem->GetNameItem());
        ModelScene->addItem(newitem);
        ModelScene->update();
    }
}

void GraphicsItemListModel::slot_DeleteItem(int indexItem)
{
    QModelIndex index = GraphItemListModel->index(indexItem);

    auto items =  ModelScene->items();
    for(auto item:items)
    {
        QString itemName = static_cast<GObject*>(item)->GetNameItem();
        if(itemName.compare(index.data().toString()) == 0)
        {
            ModelScene->removeItem(item);
            int index = listItem->indexOf(item);
            if( index != -1)listItem->removeAt(index);
            delete item;
            break;
        }
    }
    GraphItemListModel->removeRow(indexItem);
    ModelScene->update();
}

void GraphicsItemListModel::slot_SelectItem(int indexItem)
{
    QModelIndex index = GraphItemListModel->index(indexItem);
    if(prevSelected == index)
    {
        emit signal_DeselectItem(indexItem);
        QModelIndex q;
        prevSelected = q;
        auto items =  ModelScene->items();
        for(auto item:items)
        {
            auto gooditem = static_cast<GObject*>(item);
            QString itemName = gooditem->GetNameItem();
            if(itemName.compare(index.data().toString())== 0)
            {
                emit gooditem->signal_enableEffect(false);
            }
        }
    }else
    {
        auto items =  ModelScene->items();
        for(auto item:items)
        {
            auto gooditem = static_cast<GObject*>(item);
            QString itemName = gooditem->GetNameItem();
            if(itemName.compare(index.data().toString())== 0)
            {
                emit gooditem->signal_enableEffect(true);
            }
            if(itemName.compare(prevSelected.data().toString())==0)
            {
                emit gooditem->signal_enableEffect(false);
            }
        }


        emit signal_SelectItem(indexItem);
        prevSelected = index;
    }

    ModelScene->update();
}
