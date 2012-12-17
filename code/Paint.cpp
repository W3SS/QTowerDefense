#include <QtGui>
#include "Paint.h"

void Paint::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("grey"));
    Projectile::paint(p, o, w);
}
