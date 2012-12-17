#ifndef WATER_GUN_H
#define WATER_GUN_H

#include <QtGui>
#include "HostileDefence.h"
#include "Water.h"

/**
 * \class WaterGun
 * \brief Représente un pistolet à eau
 *
 * Le pistolet à eau est une défence offensive. Il tire de l'eau sur les ennemis. Il peut cibler les ennemis au sol et en l'air.
 */
class WaterGun : public HostileDefence
{
    Q_OBJECT
    public:
	/**
	 * Crée un pistolet à eau en passant par le constructeur de sa classe mère : HostileDefence
	 */
        WaterGun ():
            HostileDefence (2.5, 8, 20, 45, 3.5, 5, "both", 1, false) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine un pistolet à eau en réimplémentant la méthode paint de HostileDefence
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

	/**
	 * \fn Projectile* fireAt (Enemy* e)
	 * \brief Fait tirer une goutte d'eau (Water) au pistolet à eau en lui spécifiant une cible (Enemy)
	 * \param e Cible du pistolet à eau
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
