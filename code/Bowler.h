#ifndef BOWLER_H
#define BOWLER_H

#include <QtGui>
#include "HostileDefence.h"
#include "Bowl.h"

/**
 * \class Bowler
 * \brief Représente un joueur de pétanque
 *
 * Le joueur de pétanque est une défence offensive (et hérite donc de la classe HostileDefence).
 *
 * Il utilise des projectiles de type Bowl qui sont des boules de pétanque.
 */
class Bowler : public HostileDefence
{
    Q_OBJECT
    public:
	/**
	 * Crée un joueur de pétanque en passant par le constructeur de sa classe mère : HostileDefence
	 */
        Bowler ():
            HostileDefence (4, 15, 40, 80, 0.5, 15, "crawling", 1, false) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine un joueur de pétanque en réimplémentant la méthode paint de HostileDefence
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

	/**
	 * \fn Projectile* fireAt (Enemy* e)
	 * \brief Fait tirer une boule (Bowl) au joueur de pétanque en lui spécifiant une cible (Enemy)
	 * \param e Cible du joueur de pétanque
	 * \return Le projectile (Projectile) généré
	 */
	Projectile* fireAt (Enemy* e);

    public slots:
	/**
	 * \fn void upgrade ()
	 * \brief Implémente le slot upgrade de Defence en indiquant la façon dont la défense est améliorée
	 */
	void upgrade ();
};

#endif
