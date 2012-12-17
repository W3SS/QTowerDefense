#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QtGui>
#include "Enemy.h"

/**
 * \class Projectile
 * \brief Représente un projectile générique.
 *
 * Un projectile est tiré par une défence aggressive (HostileDefence), et vise un ennemi (Enemy). Les projectiles sont à tête chercheuse et traquent leur cible jusqu'à l'atteindre, ou s'autodétruisent si la cible est détruite entre-temps.
 */
class Projectile : public QGraphicsRectItem {
    private:
        Enemy* target;
        float power;
        float speed;
        QString canTarget;
        int level;

    public:
	/**
	 * Crée un projectile
	 * \param target La cible que doit atteindre le projectile
	 * \param power La puissance du projectile (influe sur les dégâts occasionnés)
	 * \param speed La vitesse du projectile
	 * \param canTarget Le type de cibles que peut atteindre le projectile (rampant, volant ou les deux)
	 * \param level Le niveau de la défense qui a émis le projectile (influe sur l'apparence visuelle du projectile)
	 */
        Projectile (Enemy* target, float power, float speed, QString canTarget, int level):
            target (target), power (power), speed (speed), canTarget(canTarget), level(level) {}

	/**
	 * \fn Enemy* getTarget () const
	 * \return La cible du projectile (Enemy)
	 */
        Enemy* getTarget () const { return this->target; }

	/**
	 * \fn float getPower () const
	 * \return La puissance du projectile
	 */
        float getPower () const { return this->power; }

	/**
	 * \fn  float getSpeed () const
	 * \return La vitesse du projectile
	 */
        float getSpeed () const { return this->speed; }

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une boule de pétanque en réimplémentant la méthode paint de QGraphicsItem
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);
};

#endif
