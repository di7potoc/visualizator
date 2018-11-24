#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class QGraphicsScene;
class QGraphicsView;

class RenderArea:public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parrent = nullptr);
    ~RenderArea();
public slots:
    void slot_renderscene(QGraphicsScene *newScene);
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // RENDERAREA_H
