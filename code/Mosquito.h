#ifndef MOSQUITO_H
#define MOSQUITO_H

#include <QtGui>

#include "Enemy.h"
#include "QTimer.h"

/**
 * \class Mosquito
 * \image html img/moustique.png
 * \brief Représente un moustique.
 *
 * Le moustique alterne entre vol et déplacement au sol sur un interval de temps régulier.
 */
class Mosquito : public Enemy
{
    Q_OBJECT
    private:
	QTimer* timerFlyingSwitch;
 
    public:
	/**
	 * Crée un moustique en passant par le constructeur de sa classe mère : Enemy
	 * \param map La carte sur laquelle évoluera le moustique
	 * \param size La taille du moustique
	 */
	Mosquito (Map* map, int size):
	    Enemy (map, size , 6 * size * size, true, size * size, 2 + size / 2), timerFlyingSwitch(new QTimer()) {
	    QObject::connect(this->timerFlyingSwitch, SIGNAL(timeout()), this, SLOT(switchFlying()));
	    this->timerFlyingSwitch->start(7000);
	    this->appendPixmap("moustiquevolant1.png");
	    this->appendPixmap("moustiquevolant2.png");
	    this->appendPixmap("moustiquevolant1.png");
	    this->appendPixmap("moustiquevolant2.png");
	    this->appendPixmap("moustiquerampant.png");
	}

	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

    public slots:
	void switchFlying () {
	    this->setFlying(!this->isFlying());
	    if (this->isFlying()) {
		this->setCurrentSpeed(2 + (float)this->getSize()/2);
		this->setResistance(this->getSize() * this->getSize());
		this->timerFlyingSwitch->start(7000);
	    }
	    else {
		this->setCurrentSpeed(1 + (float)this->getSize()/2);
		this->setResistance(15 * this->getSize());
		this->timerFlyingSwitch->start(3000);
	    }
	}
};

#endif
