#ifndef DEFENCE_H
#define DEFENCE_H

#include <QtGui>
#include "Markable.h"
#include <cmath>

/**
 * \class Defence
 * \brief Représente une défense
 *
 * Cette classe représente toutes les formes de défenses présentes dans le jeu.
 *
 * Il en existe deux types : les passives (tel que le musicien) et les offensives (tel que le joueur de pétanque).
 */
class Defence : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
    private:
        float range;
        int level1Cost;
        int level2Cost;
        int level3Cost;
        int level;
        bool selected;

    public:
	/**
	 * Crée une défense
	 * \param range La portée de la défense
	 * \param level1Cost Le prix de base de la défense
	 * \param level2Cost Le prix de l'amélioration au niveau 2
	 * \param level3Cost Le prix de l'amélioration au niveau 3
	 * \param level Le niveau actuel de la défense
	 * \param selected L'état de sélection de la tour
	 */
        Defence (float range, int level1Cost, int level2Cost, int level3Cost, int level = 1, bool selected = false):
            range (range), level1Cost (level1Cost), level2Cost (level2Cost), level3Cost (level3Cost), level (level), selected (selected) {}

	/**
	 * \fn float getRange () const
	 * \return La portée de la tour
	 */
        float getRange () const { return this->range; }

	/**
	 * \fn int getLevel () const
	 * \return Le niveau de la tour
	 */
        int getLevel () const { return this->level; }

	/**
	 * \fn int getLevel1Cost () const
	 * \return Le coût de base de la tour
	 */
        int getLevel1Cost () const { return this->level1Cost; }

	/**
	 * \fn int getLevel2Cost () const
	 * \return Le coût d'amélioration de la tour au niveau 2
	 */
        int getLevel2Cost () const { return this->level2Cost; }

	/**
	 * \fn int getLevel3Cost () const
	 * \return Le coût d'amélioration de la tour au niveau 3
	 */
        int getLevel3Cost () const { return this->level3Cost; }

	/**
	 * \fn void setLevel (const int level)
	 * \param level Le niveau à affecter à la tour
	 */
        void setLevel (const int level) { this->level = level; }

	/**
	 * \fn void setRange (const float range)
	 * \param range La portée à affecter à la tour
	 */
        void setRange (const float range) { this->range = range; }

	/**
	 * \fn void select ()
	 * \brief Passe la tour en état sélectionné
	 */
	void select () { this->selected = true; }

	/**
	 * \fn void unselect ()
	 * \brief Passe la tour en état désélectionné
	 */
	void unselect () { this->selected = false; }

	/**
	 * \fn bool isSelected () const
	 * \return L'état de sélection de la tour
	 */
        bool isSelected () const { return this->selected; }

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine une défense en réimplémentant la méthode paint de QGraphicsItem
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

    public slots:
	/**
	 * \fn void upgrade ()
	 * \brief Crée le slot virtuel pur upgrade qui sera implémenté dans les différents types de défense et qui spécifiera la façon dont les défenses s'améliorent
	 */
        virtual void upgrade () =0;
};

#endif
