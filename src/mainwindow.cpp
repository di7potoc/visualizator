#include "mainwindow.h"
#include <QtWidgets>
#include "visualizer.h"

MainWindow::MainWindow(QWidget *parent):QWidget(parent)
{
    visualizer = new (std::nothrow) Visualizer;
    layout = new (std::nothrow) QHBoxLayout;
    layout->addWidget(visualizer);
    setLayout(layout);
    setWindowTitle("Banzai");
}

MainWindow::~MainWindow()
{
    delete visualizer;
    delete layout;
}
