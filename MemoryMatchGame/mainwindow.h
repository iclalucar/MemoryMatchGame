#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "card.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void control(Card *);
    Card *getFirst() const;
private:
    Ui::MainWindow *ui;
    QList<int> sort(QList<int>, QList<int>);
    Card *first;
    int count;
};
#endif // MAINWINDOW_H
