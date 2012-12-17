#ifndef DEFENCEFACTORY_H
#define DEFENCEFACTORY_H

#include "Defence.h"

/**
 * \class DefenceFactory
 * \brief Représente une usine (design pattern) à défenses (Defence).
 *
 * L'usine produit des défenses en fonction de texte fourni à la méthode statique unique getDefence.
 */
class DefenceFactory {
    public:
	/**
	 * \fn static Defence* getDefence (QString defenceName)
	 * \brief Produit une défense du type spécifié en paramètre
	 * \param defenceName Le type de défense que l'on souhaite générer
	 * \return La défense générée
	 */
        static Defence* getDefence (QString defenceName);
};

#endif
