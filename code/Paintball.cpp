#include <QtGui>
#include "Paintball.h"

void Paintball::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("grey"));
    HostileDefence::paint (p, o, w);
}

Projectile* Paintball::fireAt (Enemy* e) {
    Paint* s = new Paint (e, this->getPower (), this->getLevel());
    HostileDefence::fire ();
    return s;
}

void Paintball::upgrade () {
    if (this->getLevel () < 3) {
	this->setLevel(this->getLevel() + 1);
	this->setRange(4 + (float)this->getLevel() / 2);
	this->setPower(4 * std::pow(this->getLevel(), 1.5));

    }
}
