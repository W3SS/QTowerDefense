#include <QtGui>
#include "Bowl.h"

void Bowl::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("yellow"));
    Projectile::paint(p, o, w);
}
