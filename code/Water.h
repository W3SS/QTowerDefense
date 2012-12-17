#ifndef WATER_H
#define WATER_H

#include <QtGui>
#include "Projectile.h"

/**
 * \class Water
 * \brief Représente une giclée d'eau
 *
 * L'eau n'a pas d'effet particulier sur les ennemis.
 */
class Water : public Projectile
{
    public:
	/**
	 * Crée une goutte d'eau en passant par le constructeur de sa classe mère : Projectile
	 * \param target La cible que doit atteindre la goutte d'eau
	 * \param power La puissance de la goutte d'eau (influe sur les dégâts occasionnés)
	 * \param level Le niveau du pistolet à eau qui a émis la goutte d'eau (influe sur l'apparence visuelle du projectile)
	 */
        Water (Enemy* target, float power, int level):
            Projectile (target, power, 40, "both", level) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une goutte d'eau en réimplémentant la méthode paint de Projectile
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);
};

#endif
