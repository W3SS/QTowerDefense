#include <QtGui>
#include "Water.h"

void Water::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("blue"));
    Projectile::paint(p, o, w);
}
