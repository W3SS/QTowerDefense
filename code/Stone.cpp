#include <QtGui>
#include "Stone.h"

void Stone::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("red"));
    Projectile::paint(p, o, w);
}
