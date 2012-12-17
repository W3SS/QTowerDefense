#include <QtGui>
#include "Enemy.h"

void Enemy::hurt(const int damage) {
    this->setCurrentHealth (this->getCurrentHealth () - std::max (0, damage - this->getResistance ()));
}

void Enemy::paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    p->setPen(QPen("black"));
    QColor c("green");
    c.setAlpha(125);
    p->setBrush (QBrush(c));
    p->drawRect (-9, -19, (float)this->getCurrentHealth () / (float)this->getHealth() * 20, 4);
    int size = (int)(36 + 40/5 * (this->getSize () - 1));
    p->drawPixmap (-size/2, -size/2, size, size, QPixmap (this->getPixmap((this->getCurrentPixmapIndex ()/10) % 4)));
    this->setCurrentPixmapIndex(this->getCurrentPixmapIndex () + 1);
}

void Enemy::advance (int step) {
    if (step == 1) {
	int tile = this->getMap()->getTile(Map::toI(this->y()), Map::toJ(this->x()));
	int pxStep = this->getCurrentSpeed() * 40 / 40; // taille des cases = 40px / fréquence d'horloge = 40 Hz
	int dx = 0;
	int dy = 0;
	int r = 0;
	if (tile >= 16 && tile <= 31) { tile -= 16; }
	switch(tile) {
	case 1:
	    dy = -pxStep;
	    r = 270;
	    break;
	case 2:
	    dy = pxStep;
	    r = 90;
	    break;
	case 4:
	    dx = pxStep;
	    r = 0;
	    break;
	case 5:
	    dx = pxStep;
	    dy = -pxStep;
	    r = 315;
	    break;
	case 6:
	    dx = dy = pxStep;
	    r = 45;
	    break;
	case 8:
	    r = 180;
	    dx = -pxStep;
	    break;
	case 9:
	    dx = dy = -pxStep;
	    r = 225;
	    break;
	case 10:
	    dx = -pxStep;
	    dy = pxStep;
	    r = 135;
	    break;
	case 32:
	    emit enemyTrespassed (this);
	    break;
	}
	this->setPos (this->x () + dx, this->y () + dy);
	setRotation(r);
    }
}
