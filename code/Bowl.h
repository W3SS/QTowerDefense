#ifndef BOWL_H
#define BOWL_H

#include <QtGui>
#include "Projectile.h"

/**
 * \class Bowl
 * \brief Représente une boule de pétanque
 *
 * La boule de pétanque est un projectile (et hérite donc de la classe Projectile).
 *
 * Elle a la spécificité d'occasionner des dégâts de zone lorsqu'elle atteint sa cible.
 */
class Bowl : public Projectile
{
    public:
	/**
	 * Crée une boule de pétanque en passant par le constructeur de sa classe mère : Projectile
	 * \param target La cible que doit atteindre la boule de pétanque
	 * \param power La puissance de la boule de pétanque (influe sur les dégâts occasionnés)
	 * \param level Le niveau du joueur de pétanque qui a émis la boule (influe sur l'apparence visuelle du projectile)
	 */
        Bowl (Enemy* target, float power, int level):
            Projectile (target, power, 20, "crawling", level) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une boule de pétanque en réimplémentant la méthode paint de Projectile
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);
};

#endif
