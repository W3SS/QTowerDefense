#include <QtGui>
#include "WaterGun.h"

void WaterGun::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("blue"));
    HostileDefence::paint(p, o, w);
}

Projectile* WaterGun::fireAt (Enemy* e) {
    Water* s = new Water (e, this->getPower (), this->getLevel());
    HostileDefence::fire ();
    return s;
}

void WaterGun::upgrade () {
    if (this->getLevel() < 3) {
	this->setLevel(this->getLevel() + 1);
	this->setRange(2 + (float)this->getLevel() / 2);
	this->setPower(5 * std::pow(this->getLevel(), 1.5));
	this->setFiringRate(4 - this->getLevel() / 2);
    }
}
