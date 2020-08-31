#include "MainWindow.h"
#include <QStatusBar>

#include <QToolBar>
#include <QMenuBar>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QPushButton>

#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      icon(":/qt.png"),
      widget(new Widget)
{
    setWindowIcon(icon);
    /// menu
    QMenu *menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(tr("Save layout..."), this, &MainWindow::tbClick);
    menu->addAction(tr("Load layout..."), this, &MainWindow::tbClick);

    QMenu *mainWindowMenu = menuBar()->addMenu(tr("Main window"));

    QAction *action = mainWindowMenu->addAction(tr("Animated docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & AnimatedDocks);
    connect(action, &QAction::toggled, this, &MainWindow::tbClick);

    action = mainWindowMenu->addAction(tr("Allow nested docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & AllowNestedDocks);
    connect(action, &QAction::toggled, this, &MainWindow::tbClick);



    /// toolbar
    QToolBar* ptb = new QToolBar("Linker ToolBar");
    for (int i = 1; i < 10; i++)
        ptb->addAction(icon, QString::number(i),
                       this, &MainWindow::tbClick);
    addToolBar(Qt::TopToolBarArea, ptb);

    ///statusbar
    statusBar()->showMessage(tr("Status Bar"));
    // hide
    // statusBar()->hide();

    /// tray
    QMenu* trayIconMenu = new QMenu(this);

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    normalAction = new QAction(tr("Normal"), this);
    maximizeAction = new QAction(tr("Ma&ximize"), this);
    quitAction = new QAction(tr("&Quit"), this);

    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);
    connect(normalAction, &QAction::triggered, this, &QWidget::showNormal);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);
    connect(quitAction, &QAction::triggered, this, &QCoreApplication::quit);

    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(normalAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(quitAction);

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(icon));
    trayIcon->show();

    /// main widget
        setCentralWidget(widget);
//    QPushButton* btn = new QPushButton("TEST");
//    connect(btn, &QPushButton::released,
//            this, &MainWindow::tbClick);
//    setCentralWidget(btn);
}

MainWindow::~MainWindow()
{
}
#include <QDebug>
void MainWindow::tbClick()
{
    const QObject* sender = QObject::sender();
    const QAction* action = qobject_cast<const QAction*>(sender);

    if (action)
        QMessageBox::warning(this, tr("My Application"),
                             tr("void MainWindow::clk1(): %1").arg(action->text()));
}

