#include "card.h"
#include "mainwindow.h"
Card::Card(QWidget *parent):QLabel(parent)
{
    setScaledContents(true);
    found = false;
}

void Card::loadImage(int incomingImage)
{
    QImage coverImgae(":image/kapak.png");
    setPixmap(QPixmap::fromImage(coverImgae));
    hiddenImage = QString::number(incomingImage);
}

void Card::closeCard()
{
    QImage coverImage(":image/kapak.png");
    setPixmap(QPixmap::fromImage(coverImage));
}

void Card::setFound()
{
    found = true;
}

QString Card::getHiddenImage()
{
    return hiddenImage;
}

void Card::mousePressEvent(QMouseEvent *)
{
    if(found){
        return;
    }
    if(this == mainForm->getFirst()){
        return;
    }
    QImage hidden(":image/"+hiddenImage+".png");
    setPixmap(QPixmap::fromImage(hidden));
    mainForm->control(this);
}
