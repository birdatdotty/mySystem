#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

private:
    QGridLayout mainLayout;
    QLabel *labelCache;
    QPushButton *btnCache;

private slots:
    void clearCache();

};

#endif // WIDGET_H
