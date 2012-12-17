#ifndef PAINTBALL_H
#define PAINTBALL_H

#include <QtGui>
#include "HostileDefence.h"
#include "Paint.h"

/**
 * \class Paintball
 * \brief Représente un joueur de paintball.
 *
 * Le joueur de paintball vise les ennemis au sol. Il applique un ralentissement à l'impact. Ce ralentissement est non-cumulable, mais chaque impact réinitialise sa durée.
 */
class Paintball : public HostileDefence
{
    Q_OBJECT
    public:
        Paintball ():
	    /**
	     * Crée un joueur de paintball en passant par le constructeur de sa classe mère : HostileDefence
	     */
            HostileDefence (4.5, 12, 25, 60, 2, 4, "both", 1, false) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine un joueur de paintball en réimplémentant la méthode paint de HostileDefence
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

	/**
	 * \fn Projectile* fireAt (Enemy* e)
	 * \brief Fait tirer une bille de peinture (Paint) au joueur de paintball en lui spécifiant une cible (Enemy)
	 * \param e Cible du joueur de paintball
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
