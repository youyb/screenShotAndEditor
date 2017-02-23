#ifndef TEXTPAINTINGSTEP_H
#define TEXTPAINTINGSTEP_H

#include <QTextEdit>
#include "ipaintingstep.h"

class TextPaintingStep: public IPaintingStep
{
public:
    TextPaintingStep(QString str){
        text = str;
    }

    void setFirstPoint(int x, int y) {
        rectangle.setLeft(x);
        rectangle.setTop(y);
    }

//    void setSecondPoint(const QPoint &p) {
//        rectangle.setRight(p.x());
//        rectangle.setBottom(p.y());
//    }

    void paint(QPainter *painter) {
        QPen backup = painter->pen();
        painter->setPen(pen);
        //painter->drawRect(rectangle.left(), rectangle.top(), rectangle.width() - 1, rectangle.height() - 1);
        painter->drawText(rectangle.left(), rectangle.top(), text);
        painter->setPen(backup);
    }

private:
    QRect rectangle;
    QString text;
};

#endif // TEXTPAINTINGSTEP_H
