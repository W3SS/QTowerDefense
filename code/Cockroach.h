#ifndef COCKROACH_H
#define COCKROACH_H

#include <QtGui>
#include "Enemy.h"

/**
 * \class Cockroach
 * \image html img/cafard.png
 * \brief Représente un cafard
 *
 * Le cafard est un insecte (et hérite donc de la classe Enemy).
 *
 * Il a la spécificité de donner naissance à deux cafards de taille inférieure lorsqu'il est tué.
 */
class Cockroach : public Enemy {
    public:
	/**
	 * Crée un cafard en passant par le constructeur de sa classe mère : Enemy
	 * \param map La carte sur laquelle évoluera le cafard
	 * \param size La taille du cafard
	 */
	Cockroach (Map* map, int size):
	    Enemy (map, size , 10 * size * size, false, 5 * size * size, 2) {
	    this->appendPixmap("cafard1.png");
	    this->appendPixmap("cafard2.png");
	    this->appendPixmap("cafard3.png");
	    this->appendPixmap("cafard2.png");
	}

};

#endif
