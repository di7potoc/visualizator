#include "renderarea.h"
#include <QtWidgets>

RenderArea::RenderArea(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *layout = new (std::nothrow) QVBoxLayout;
    view = new (std::nothrow) QGraphicsView;
    scene = new (std::nothrow) QGraphicsScene;
    view->setScene(scene);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    layout->addWidget(view);
    setLayout(layout);
}

RenderArea::~RenderArea()
{
    delete scene;
    delete view;
}

void RenderArea::slot_renderscene(QGraphicsScene *newScene)
{
    if(newScene != nullptr)
        view->setScene(newScene);

}

