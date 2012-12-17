#ifndef PAINT_H
#define PAINT_H

#include <QtGui>
#include "Projectile.h"

/**
 * \class Paint
 * \brief Représente une bille de peinture.
 *
 * La bille de peinture applique un ralentissement à l'impact. Ce ralentissement est non-cumulable, mais chaque impact réinitialise sa durée.
 */
class Paint : public Projectile
{
    public:
	/**
	 * Crée une bille de peinture en passant par le constructeur de sa classe mère : Projectile
	 * \param target La cible que doit atteindre la bille de peinture
	 * \param power La puissance de la bille de peinture (influe sur les dégâts occasionnés)
	 * \param level Le niveau du joueur de paintball qui a émis la bille de peinture (influe sur l'apparence visuelle du projectile)
	 */
        Paint (Enemy* target, float power, int level):
            Projectile (target, power, 30, "both", level) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une bille de peinture en réimplémentant la méthode paint de Projectile
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);
};

#endif
