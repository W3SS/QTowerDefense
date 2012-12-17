#include <QtGui>
#include "Slingshot.h"

void Slingshot::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("red"));
    HostileDefence::paint(p, o, w);
}

Projectile* Slingshot::fireAt (Enemy* e) {
    Stone* s = new Stone (e, this->getPower (), this->getLevel());
    HostileDefence::fire ();
    return s;
}

void Slingshot::upgrade () {
    if (this->getLevel () < 3) {
    this->setLevel(this->getLevel() + 1);
    this->setRange(3 + (float)this->getLevel() / (float)2);
    this->setPower(10 * std::pow(this->getLevel(), 1.5));
    }
}
