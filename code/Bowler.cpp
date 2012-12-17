#include <QtGui>
#include "Bowler.h"

void Bowler::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setBrush (QBrush("yellow"));
    HostileDefence::paint(p, o, w);
}

Projectile* Bowler::fireAt (Enemy* e) {
    Bowl* s = new Bowl (e, this->getPower (), this->getLevel());
    HostileDefence::fire ();
    return s;
}

void Bowler::upgrade () {
    if (this->getLevel() < 3) {
	this->setLevel(this->getLevel() + 1);
	this->setRange(3 + this->getLevel());
	this->setPower(15 * std::pow(this->getLevel(), 1.5));
    }
}
