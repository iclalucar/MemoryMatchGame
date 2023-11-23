#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QMouseEvent>
class MainWindow;

class Card : public QLabel
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = 0);
    MainWindow *mainForm;
    void loadImage(int);
    void closeCard();
    void setFound();
    QString getHiddenImage();
private:
    void mousePressEvent(QMouseEvent*);
    QString hiddenImage;
    bool found;
};

#endif // CARD_H
