#ifndef CONSTRUCTION_MODE_H
#define CONSTRUCTION_MODE_H

#include <QtGui>
#include "Mode.h"
#include "Defence.h"
#include "DefenceFactory.h"

class ConstructionMode : public Mode
{
    /**
     * \class ConstructionMode
     * \brief Représente le mode de construction.
     *
     * Il s'agit du cas où le joueur a cliqué sur l'un des boutons de construction pour créer une défense.
     *
     * Dans ce mode, le joueur visualise, à la pointe de son curseur, sur l'aire de jeu, l'ombre de la tour qu'il va acheter à l'emplacement où il va la construire et avec une représentation de sa portée.
     *
     * Le joueur peut quitter facilement le mode de construction en déplaçant son pointeur sur le panneau de contrôles.
     */
    private:
        Q_OBJECT
        Defence* defenceShadow;
        QString defenceName;

    public:
	/**
	 * Crée un mode de construction en passant par le constructeur de sa classe mère : Mode
	 * \param defenceName Le type de défense que le joueur souhaite construire
	 */
        ConstructionMode (QString defenceName):
            defenceShadow (DefenceFactory::getDefence (defenceName)), defenceName (defenceName) {
            this->getDefenceShadow ()->select ();
            this->getDefenceShadow ()->setOpacity (0.5);
        }

	/**
	 * \fn Defence* getDefenceShadow () const
	 * \return La défense que le joueur souhaite construire
	 */
        Defence* getDefenceShadow () const { return this->defenceShadow; }

	/**
	 * \fn QString getDefenceName () const
	 * \return Le type de défense que le joueur souhaite construire
	 */
        QString getDefenceName () const { return this->defenceName; }
};

#endif
