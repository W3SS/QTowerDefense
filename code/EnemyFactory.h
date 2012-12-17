#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"

/**
 * \class EnemyFactory
 * \brief Représente une usine (design pattern) à ennemis (Enemy).
 *
 * L'usine produit des ennemis en fonction de texte fourni à la méthode statique unique getEnemy.
 */
class EnemyFactory {
    public:
	/**
	 * \fn static Enemy* getEnemy (Map* map, QString enemyName, int size)
	 * \brief Produit un ennemi du type spécifié en paramètre
	 * \param map La carte sur laquelle évoluera l'ennemi
	 * \param enemyName Le type d'ennemi que l'on souhaite générer
	 * \param size La taille de l'ennemi que l'on souhaite générer
	 * \return L'ennemi généré
	 */
	static Enemy* getEnemy (Map* map, QString enemyName, int size);
};

#endif
