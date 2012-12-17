#include <QtGui>
#include "Musician.h"

void Musician::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("purple"));
    Defence::paint(p, o, w);
}
