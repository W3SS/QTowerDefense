#include <QtGui>
#include "Projectile.h"

void Projectile::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->drawRect (0, 0, level*2, level*2);
}
