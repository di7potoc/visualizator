#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QWidget>

class RenderArea;
class Outliner;
class QGridLayout;
class GraphicsItemListModel;

class Visualizer:public QWidget
{
    Q_OBJECT

public:
    Visualizer(QWidget *parent = nullptr);
    ~Visualizer();
private:
    RenderArea *renderarea;
    Outliner *outliner;
    QGridLayout *layout;
    GraphicsItemListModel *presenter;
};


#endif // VISUALIZER_H
