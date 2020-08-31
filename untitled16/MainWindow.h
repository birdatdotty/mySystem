#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPixmap icon;
    // tray
    QAction *minimizeAction;
    QAction *normalAction;
    QAction *maximizeAction;
    QAction *quitAction;

    // toolbar
    QToolBar* ptb;

    Widget* widget;

private slots:
    void tbClick();
};
#endif // MAINWINDOW_H
