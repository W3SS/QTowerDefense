#include <QtGui>
#include "Defence.h"

void Defence::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    QColor c(p->brush().color());
    if (this->isSelected ()) {
	c.setAlpha(50);
	p->setBrush (QBrush(c));
	p->setPen (QPen(QBrush(c), 1));
	p->drawEllipse ((-this->getRange () * 40), (-this->getRange () * 40), this->getRange () * 40 * 2 + 40, this->getRange () * 40 * 2 + 40);
    }
    c.setAlpha(255);
    p->setBrush (QBrush(c));
    p->setPen (QPen(QBrush(QColor("black")), this->level));
    p->drawEllipse (2, 2, 36, 36);
}
