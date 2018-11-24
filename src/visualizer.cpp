#include <QtWidgets>
#include "visualizer.h"
#include "renderarea.h"
#include "outliner.h"
#include "model.h"

Visualizer::Visualizer(QWidget *parent):QWidget(parent)
{
    layout = new (std::nothrow) QGridLayout;
    renderarea = new (std::nothrow) RenderArea;
    outliner = new (std::nothrow) Outliner;
    presenter = new (std::nothrow) GraphicsItemListModel(this);
    layout->addWidget(renderarea,0,0);
    layout->addWidget(outliner,0,1);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);    
    outliner->SetModelComboBox(presenter->GraphItemTypeModel);
    outliner->SetModelListView(presenter->GraphItemListModel);
    renderarea->slot_renderscene(presenter->ModelScene);
    bool success = connect(outliner,&Outliner::signal_buttonAddClicked,presenter,&GraphicsItemListModel::slot_CreateNewItem);
    Q_ASSERT(success);
    success = connect(outliner,&Outliner::signal_buttonDelClicked,presenter,&GraphicsItemListModel::slot_DeleteItem);
    Q_ASSERT(success);
    success  = connect(outliner,&Outliner::signal_listviewSelected,presenter,&GraphicsItemListModel::slot_SelectItem);
    Q_ASSERT(success);
    success = connect(presenter,&GraphicsItemListModel::signal_DeselectItem,outliner,&Outliner::slot_deselectItemListView);
    Q_ASSERT(success);
    success = connect(presenter,&GraphicsItemListModel::signal_SelectItem,outliner,&Outliner::slot_selectItemListView);
    Q_ASSERT(success);
}
Visualizer::~Visualizer()
{
    delete renderarea;
    delete outliner;
    delete layout;
    delete presenter;
}
