#ifndef WASP_H
#define WASP_H

#include <QtGui>
#include "Enemy.h"

/**
 * \class Wasp
 * \image html img/guepe.png
 * \brief Représente une guêpe
 *
 * La guêpe est un ennemi volant. À sa mort, elle tombe au sol et blesse les ennemis à une case et demi de distance d'elle.
 */
class Wasp : public Enemy {
    public:
	/**
	 * Crée une guêpe en passant par le constructeur de sa classe mère : Enemy
	 * \param map La carte sur laquelle évoluera la guêpe
	 * \param size La taille de la guêpe
	 */
	Wasp (Map* map, int size):
	    Enemy (map, size , 7 * size * size, true, 4 * size * size, 3) {
	    this->appendPixmap("guepe1.png");
	    this->appendPixmap("guepe2.png");
	    this->appendPixmap("guepe1.png");
	    this->appendPixmap("guepe2.png");
	}
};

#endif
