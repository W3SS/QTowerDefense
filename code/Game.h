#ifndef GAME_H
#define GAME_H

#include <QtGui>
#include "Map.h"
#include "Wave.h"
#include "Mode.h"
#include "SelectionMode.h"
#include "ConstructionMode.h"
#include "Defence.h"
#include "DefenceFactory.h"

/**
 * \class Game
 * \brief Représente une partie de jeu.
 *
 * Une partie correspond au suivi de l'avancement du joueur et du jeu à partir des conditions initiales (argent, vies).
 */
class Game : public QObject {
    private:
        Q_OBJECT
        int lives;
        int money;
        int currentSwarmIndex;
        int currentEnemyIndex;
        QString mapFilePath;
        QString wavesFilePath;
        Map* map;
        int currentWaveIndex;
        QList<Wave*> waves;
        Mode* mode;
 
    public:
	/**
	 * Crée une partie
	 * \param lives Le nombre de vies du joueur
	 * \param money L'argent qu'a le joueur au début de la partie
	 * \param mapFilePath Le chemin d'accès au fichier contenant les données de la carte
	 * \param wavesFilePath Le chemin d'accès au fichier contenant les données des vagues d'ennemis
	 */
	Game (int lives = 10, int money = 200, QString mapFilePath = "map.txt", QString wavesFilePath = "waves.txt"):
            lives (lives), money (money), mapFilePath (mapFilePath), wavesFilePath (wavesFilePath), map (new Map ()), currentWaveIndex (0), mode (new SelectionMode ()) {
            this->loadMap ();
	    this->loadWaves ();
        }

	/**
	 * \fn int getCurrentWaveIndex () const
	 * \return L'index de la vague d'ennemis actuellement généré
	 */
        int getCurrentWaveIndex () const { return this->currentWaveIndex; }

	/**
	 * \fn int getCurrentSwarmIndex () const
	 * \return L'index de l'essaim d'ennemis actuellement généré
	 */
        int getCurrentSwarmIndex () const { return this->currentSwarmIndex; }

	/**
	 * \fn int getCurrentEnemyIndex () const
	 * \return L'index de l'ennemi actuellement généré
	 */
        int getCurrentEnemyIndex () const { return this->currentEnemyIndex; }

	/**
	 * \fn Map* getMap () const
	 * \return La carte associée à la partie
	 */
        Map* getMap () const { return this->map; }

	/**
	 * \fn Wave* getWave (const int i) const
	 * \param i L'index de la vague d'ennemis que l'on souhaite obtenir
	 * \return La vague d'ennemis d'index i
	 */
        Wave* getWave (const int i) const { return this->waves[i]; }

	/**
	 * \fn Mode* getMode () const
	 * \return Le mode de jeu actuel (construction ou sélection)
	 */
        Mode* getMode () const { return this->mode; }

	/**
	 * \fn int getLives () const
	 * \return Le nombre de vies qu'il reste actuellement à la partie
	 */
        int getLives () const { return this->lives; }

	/**
	 * \fn int getMoney () const
	 * \return L'argent dont dispose actuellement la partie
	 */
        int getMoney () const { return this->money; }

	/**
	 * \fn int getWavesNumber () const
	 * \return Le nombre total de vagues chargées depuis le fichier de vagues
	 */
	int getWavesNumber () const { return this->waves.size (); }

	/**
	 * \fn void setLives (const int i)
	 * \param i Le nombre de vies à affecter à la partie
	 */
        void setLives (const int i) { this->lives = i; }

	/**
	 * \fn void setMoney (const int i)
	 * \param i La quantité d'argent à affecter à la partie
	 */
        void setMoney (const int i) { this->money = i; }

	/**
	 * \fn void setCurrentWaveIndex (const int i)
	 * \param i L'index de vague à attribuer à la partie
	 */
        void setCurrentWaveIndex (const int i) { this->currentWaveIndex = i; }

	/**
	 * \fn void setCurrentSwarmIndex (const int i)
	 * \param i L'index d'essaim à attribuer à la partie
	 */
        void setCurrentSwarmIndex (const int i) { this->currentSwarmIndex = i; }

	/**
	 * \fn void setCurrentEnemyIndex (const int i)
	 * \param i L'index d'ennemi à attribuer à la partie
	 */
        void setCurrentEnemyIndex (const int i) { this->currentEnemyIndex = i; }

    private:
	/**
	 * \fn void loadMap ()
	 * \brief Charge la carte dont le chemin d'accès est spécifié en attribut de classe
	 */
        void loadMap ();

	/**
	 * \fn void loadWaves ()
	 * \brief Charge les vagues dont le chemin d'accès du fichier texte descriptif est spécifié en attribut de classe
	 */
	void loadWaves();

    public slots:
	/**
	 * \fn void switchToSelectionMode ()
	 * \brief Passe en mode de sélection vide (prêt à sélectionner une tour)
	 */
        void switchToSelectionMode () {
            delete this->mode;
            this->mode = new SelectionMode ();
        }

	/**
	 * \fn void switchToSelectionMode (Defence* selectedTower)
	 * \brief Passe en mode de sélection de la défense spécifiée en paramètre
	 * \param selectedTower La défense que l'on sélectionne
	 */
        void switchToSelectionMode (Defence* selectedTower) {
            delete this->mode;
            this->mode = new SelectionMode (selectedTower);
        }

	/**
	 * \fn void switchToConstructionModeForSlingshot ()
	 * \brief Passe en mode de construction de lance-pierres
	 */
        void switchToConstructionModeForSlingshot () {
            delete this->mode;
            this->mode = new ConstructionMode ("Lance-pierres");
        }

	/**
	 * \fn void switchToConstructionModeForWaterGun ()
	 * \brief Passe en mode de construction de pistolet à eau
	 */
        void switchToConstructionModeForWaterGun () {
            delete this->mode;
            this->mode = new ConstructionMode ("Pistolet à eau");
        }

	/**
	 * \fn void switchToConstructionModeForPaintball ()
	 * \brief Passe en mode de construction de joueur de paintball
	 */
        void switchToConstructionModeForPaintball () {
            delete this->mode;
            this->mode = new ConstructionMode ("Paintball");
        }

	/**
	 * \fn void switchToConstructionModeForBowler ()
	 * \brief Passe en mode de construction de joueur de pétanque
	 */
        void switchToConstructionModeForBowler () {
            delete this->mode;
            this->mode = new ConstructionMode ("Joueur de pétanque");
        }

	/**
	 * \fn void switchToConstructionModeForMusician ()
	 * \brief Passe en mode de construction de musicien
	 */
        void switchToConstructionModeForMusician () {
            delete this->mode;
            this->mode = new ConstructionMode ("Musicien");
        }

	/**
	 * \fn void decreaseLives ()
	 * \brief Retire une vie à la partie
	 */
	void decreaseLives () { this->lives--; }

	/**
	 * \fn void decreaseMoney (const int i)
	 * \brief Débite de l'argent à la partie
	 * \param i La quantité d'argent à débiter à la partie
	 */
	void decreaseMoney (const int i) { this->money -= i; }

	/**
	 * \fn void increaseMoney (const int i)
	 * \brief Crédite de l'argent à la partie
	 * \param i La quantité d'argent à créditer à la partie
	 */
	void increaseMoney (const int i) { this->money += i; }
};

#endif
