#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include <QtGui>
#include "HostileDefence.h"
#include "Stone.h"
#include "GameScene.h"

/**
 * \class Slingshot
 * \brief Représente un lance-pierre.
 *
 * Le lance-pierre cible les ennemis volant.
 */
class Slingshot : public HostileDefence
{
    private:
        Q_OBJECT

    public:
	/**
	 * Crée un lance-pierres en passant par le constructeur de sa classe mère : HostileDefence
	 */
        Slingshot ():
                HostileDefence (3.5, 12, 25, 60, 1, 10, "flying", 1, false) {}

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine un lance-pierres en réimplémentant la méthode paint de HostileDefence
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

	/**
	 * \fn Projectile* fireAt (Enemy* e)
	 * \brief Fait tirer une pierre (Stone) au lance-pierres en lui spécifiant une cible (Enemy)
	 * \param e Cible du lance-pierres
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
