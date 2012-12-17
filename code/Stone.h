#ifndef STONE_H
#define STONE_H

#include <QtGui>
#include "Projectile.h"

/**
 * \class Stone
 * \brief Représente une pierre
 *
 * La pierre est le projectile du lance-pierres. Touche seulement les ennemis aériens.
 */
class Stone : public Projectile
{
    public:
	/**
	 * Crée une pierre en passant par le constructeur de sa classe mère : Projectile
	 * \param target La cible que doit atteindre la pierre
	 * \param power La puissance de la pierre (influe sur les dégâts occasionnés)
	 * \param level Le niveau du lance-pierres qui a émis la pierre (influe sur l'apparence visuelle du projectile)
	 */
        Stone (Enemy* target, float power, int level):
            Projectile (target, power, 25, "flying", level) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une pierre en réimplémentant la méthode paint de Projectile
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);
};

#endif
