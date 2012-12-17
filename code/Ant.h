#ifndef ANT_H
#define ANT_H

#include <QtGui>
#include "Enemy.h"
#include "SpeedBuff.h"

/**
 * \class Ant
 * \image html img/fourmi.png
 * \brief Représente une fourmi
 *
 * La fourmi est un insecte (et hérite donc de la classe Enemy).
 *
 * Elle a la spécificité d'accélérer lorsqu'elle est touchée par un projectile.
 */
class Ant : public Enemy
{
    Q_OBJECT
    private:
	QTimer* speedTimer;

    public:
	/**
	 * Crée une fourmi en passant par le constructeur de sa classe mère : Enemy
	 * \param map La carte sur laquelle évoluera la fourmi
	 * \param size La taille de la fourmi
	 */
	Ant (Map* map, int size):
	    Enemy (map, size , 5 * size * size, false, size * size, 2 + size / 2), speedTimer(new QTimer()) {
	    QObject::connect(speedTimer, SIGNAL(timeout()), this, SLOT(calmDown()));
	    this->appendPixmap("fourmi1.png");
	    this->appendPixmap("fourmi2.png");
	    this->appendPixmap("fourmi3.png");
	    this->appendPixmap("fourmi2.png");
	}

	/**
	 * \fn void hurt(const int damage)
	 * \brief Blesse l'ennemi en lui retirant de la vie ; fonction réimplémentée dans Ant pour prendre en compte l'accélération des fourmis blessées
	 * \param damage Le nombre de dégâts à infliger à la fourmi
	 */
	void hurt(const int damage) {
	    Enemy::hurt(damage);
	    this->speedTimer->start(5000);
	    this->setCurrentSpeed(this->getSpeed()*1.5);
	}

    public slots:
	void calmDown () {
	    this->setCurrentSpeed(this->getSpeed());
		 this->speedTimer->stop ();
	}
};

#endif
