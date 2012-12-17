#include <QtGui>
#include "Mosquito.h"

void Mosquito::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setPen(QPen("black"));
    QColor c("green");
    c.setAlpha(125);
    p->setBrush (QBrush(c));
    p->drawRect (-9, -19, (float)this->getCurrentHealth () / (float)this->getHealth() * 20, 4);
    int size = (int)(36 + 40/5 * (this->getSize () - 1));
    if (this->isFlying()) {
	p->drawPixmap (-size/2, -size/2, size, size, QPixmap (this->getPixmap((this->getCurrentPixmapIndex ()/10) % 4)));
	this->setCurrentPixmapIndex(this->getCurrentPixmapIndex () + 1);
    }
    else {
		p->drawPixmap (-size/2, -size/2, size, size, QPixmap (this->getPixmap(4)));
    }
}
