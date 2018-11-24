#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Visualizer;
class QHBoxLayout;
class QMenuBar;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Visualizer *visualizer;
    QMenuBar *mainmenu;
    QHBoxLayout *layout;
};

#endif // MAINWINDOW_H
