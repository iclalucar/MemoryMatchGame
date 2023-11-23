#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    first = NULL;
    srand(time(NULL));
    int X = 10;
    int Y = 10;
    int imageIndex = 0;
    QList<int> imageList;
    QList<int> shortList;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k) {
            imageList.push_back(i);
            shortList.push_back(rand() % 500);
        }
    }
    imageList = sort(imageList,shortList);
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k) {
            Card *card = new Card(this);
            card->setGeometry(X, Y, 100, 100);
            card->mainForm = this;
            card->loadImage(imageList[imageIndex]);
            card->show();
            imageIndex++;
            Y += 110;
        }
        X += 110;
        Y = 10;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::control(Card *incoming)
{
    if(first == NULL){
        first = incoming;
    }
    else if(first->getHiddenImage() == incoming->getHiddenImage()){
        incoming->setFound();
        first->setFound();
        first = NULL;
    }
    else{
        QTimer::singleShot(1000, [this, incoming]() {
            first->closeCard();
            incoming->closeCard();
            first = NULL;
            count++;
            ui->label_2->setText(QString::number(count));
        });
    }
}

Card *MainWindow::getFirst() const
{
    return first;
}

QList<int> MainWindow::sort(QList<int> imageList, QList<int> sortList)
{
    int status = 0;
    int tmp;
    while (status == 0) {
        status = 1;
        for (int i = 0; i < imageList.size() - 1; ++i) {
            if (sortList[i] > sortList[i + 1]) {
                tmp = sortList[i];
                sortList[i] = sortList[i + 1];
                sortList[i + 1] = tmp;
                tmp = imageList[i];
                imageList[i] = imageList[i + 1];
                imageList[i + 1] = tmp;
                status = 0;
            }
        }
    }
    return imageList;
}

