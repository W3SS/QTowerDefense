#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QtGui>
#include "Game.h"
#include "EnemyFactory.h"
#include "Projectile.h"

/**
 * \class GameScene
 * \brief Représente le canevas 2D sur lequel le jeu est dessiné.
 *
 * La GameScene hérite de QGraphicsScene et permet de dessiner des formes géométriques et des images à l'écran.
 *
 * Elle représente l'aire de jeu associé à une partie à l'écran.
 */
class GameScene : public QGraphicsScene {
    private:
        Q_OBJECT
        Game* game;
        QList<Defence*> defences;
        QList<Enemy*> enemies;
        QList<Projectile*> projectiles;
        QTimer* spawnTimer;
        QTimer* nextWaveTimer;

    public:
	/**
	 * Crée une aire de jeu
	 * \param game La partie que représente l'aire de jeu
	 */
        GameScene (Game* game, QWidget* parent = 0):
            QGraphicsScene (parent), game (game), spawnTimer (new QTimer (this)), nextWaveTimer (new QTimer (this)) {
            QObject::connect (this->spawnTimer, SIGNAL (timeout ()), this, SLOT (addEnemy ()));
            QObject::connect (this->nextWaveTimer, SIGNAL (timeout ()), this, SLOT (addWave ()));
            for (int i = 0; i < game->getMap ()->getSize (); i++) {
                for (int j = 0; j < game->getMap ()->getSize (); j++) {
                    if (game->getMap ()->getTile (i, j) == 0) {
			QGraphicsPixmapItem* item = new QGraphicsPixmapItem (QPixmap ("herbe.jpg").scaled (40, 40));
			item->setPos ((j - 8) * 40, (i - 8) * 40);
                        this->addItem (item);
			//QGraphicsRectItem* item2 = new QGraphicsRectItem (0, 0, 40, 40);
                        //item2->setPen (QPen ("green"));
			//item2->setPos ((j - 8) * 40, (i - 8) * 40);
                        //this->addItem (item2);
                    }
		    else if (game->getMap ()->getTile (i, j) <= 26 && game->getMap ()->getTile (i, j) >= 16) {
			QGraphicsRectItem* item = new QGraphicsRectItem (0, 0, 40, 40);
			item->setBrush (QBrush ("red"));
			//item->setPen (QPen ("green"));
			item->setPos ((j - 8) * 40, (i - 8) * 40);
			this->addItem (item);
			this->getGame()->getMap()->setStartingTile(i, j);
		    }
		    else if (game->getMap ()->getTile (i, j) >= 1 && game->getMap ()->getTile (i, j) <= 15) {
			QGraphicsRectItem* item = new QGraphicsRectItem (0, 0, 40, 40);
			item->setBrush (QBrush ("lightblue"));
                        //item->setPen (QPen ("green"));
			item->setPos ((j - 8) * 40, (i - 8) * 40);
			this->addItem (item);
                    }
                    else if (game->getMap ()->getTile (i, j) == 32) {
			QGraphicsPixmapItem* item = new QGraphicsPixmapItem (QPixmap ("but.png").scaled (40, 40));
			item->setPos ((j - 8) * 40, (i - 8) * 40);
                        this->addItem (item);
                    }
                    else if (game->getMap ()->getTile (i, j) == 64) {
			QGraphicsRectItem* item = new QGraphicsRectItem (0, 0, 40, 40);
                        //item->setPen (QPen ("brown"));
                        item->setBrush (QBrush ("brown"));
			item->setPos ((j - 8) * 40, (i - 8) * 40);
                        this->addItem (item);
                    }
                }
            }
        }

	/**
	 * \fn Game* getGame () const
	 * \return La partie à laquelle est associée l'aire de jeu
	 */
        Game* getGame () const { return this->game; }

	/**
	 * \fn QList<Defence*> getDefences () const
	 * \return La QList qui contient toutes les défenses actuellement affichées sur l'aire de jeu
	 */
        QList<Defence*> getDefences () const { return this->defences; }

	/**
	 * \fn QList<Enemy*> getEnemies () const
	 * \return La QList qui contient tous les ennemis actuellement affichés sur l'aire de jeu
	 */
        QList<Enemy*> getEnemies () const { return this->enemies; }

	/**
	 * \fn QList<Projectile*> getProjectiles () const
	 * \return La QList qui contient tous les projectiles actuellement affichés sur l'aire de jeu
	 */
	QList<Projectile*> getProjectiles () const { return this->projectiles; }

	/**
	 * \fn void addDefence (Defence* d)
	 * \brief Ajoute une défense sur l'aire de jeu
	 * \param d La défense à ajouter à l'aire de jeu
	 */
        void addDefence (Defence* d) {
            this->defences << d;
            this->addItem (d);
        }

	/**
	 * \fn void addEnemy (Enemy* e)
	 * \brief Ajoute un ennemi sur l'aire de jeu
	 * \param e L'ennemi à ajouter à l'aire de jeu
	 */
        void addEnemy (Enemy* e) {
            this->enemies << e;
            this->addItem (e);
        }

	/**
	 * \fn void addProjectile (Projectile* p)
	 * \brief Ajoute un projectile sur l'aire de jeu
	 * \param p Le projectile à ajouter à l'aire de jeu
	 */
        void addProjectile (Projectile* p) {
            this->projectiles << p;
            this->addItem (p);
        }

	/**
	 * \fn void removeDefence (Defence* d)
	 * \brief Retire une défense de l'aire de jeu
	 * \param d La défense à retirer de l'aire de jeu
	 */
        void removeDefence (Defence* d) {
            this->defences.removeOne (d);
            this->removeItem (d);
            this->getGame()->getMap()->setTile(Map::toI(d->pos().y()), Map::toJ(d->pos().x()), 0);
        }

	/**
	 * \fn void removeEnemy (Enemy* e)
	 * \brief Retire un ennemi de l'aire de jeu
	 * \param e L'ennemi à retirer de l'aire de jeu
	 */
        void removeEnemy (Enemy* e) {
            this->enemies.removeOne (e);
            this->removeItem (e);
        }

	/**
	 * \fn void removeProjectile (Projectile* p)
	 * \brief Retire un projectile de l'aire de jeu
	 * \param p Le projectile à retirer de l'aire de jeu
	 */
        void removeProjectile (Projectile* p) {
            this->projectiles.removeOne (p);
            this->removeItem (p);
        }

    public slots:
	/**
	 * \fn void enemyTrespassed (Enemy* e)
	 * \brief Slot appelé lorsqu'un ennemi atteint le but
	 * \param e L'ennemi ayant atteint le but
	 */
        void enemyTrespassed (Enemy* e) {
            this->game->setLives (this->game->getLives() - 1);
            this->removeEnemy (e);
        }

	/**
	 * \fn void addWave ()
	 * \brief Commence à générer la vague d'ennemis suivante
	 */
        void addWave () {
            this->game->setCurrentSwarmIndex (0);
	    if (this->getGame ()->getCurrentWaveIndex() < this->getGame()->getWavesNumber())
		this->addSwarm ();
	}

	/**
	 * \fn void addSwarm ()
	 * \brief Commence à générer l'essaim d'ennemis suivant
	 */
        void addSwarm () {
	    Wave* wave = this->getGame ()->getWave (this->getGame ()->getCurrentWaveIndex ());
	    if  (this->getGame ()->getCurrentSwarmIndex () < wave->getSwarmsNumber ()) {
		Swarm* swarm = wave->getSwarm (this->getGame ()->getCurrentSwarmIndex ());
		this->getGame ()->setCurrentEnemyIndex (0);
		this->spawnTimer->start (1000 / 40 * swarm->getSpawnFrequency ());
	    }
		//this->nextWaveTimer->start (1000 * 15);

            else
            {
		// fin de partie
		//this->nextWaveTimer->stop();
		this->getGame ()->setCurrentWaveIndex (this->getGame ()->getCurrentWaveIndex () + 1);
		this->spawnTimer->stop();
		emit gameWon ();
            }
        }

	/**
	 * \fn void addEnemy ()
	 * \brief Commence à générer l'ennemi suivant
	 */
        void addEnemy () {
	    Wave* wave = this->getGame ()->getWave (this->getGame ()->getCurrentWaveIndex ());
	    Swarm* swarm = wave->getSwarm (this->getGame ()->getCurrentSwarmIndex ());

	    if  (this->getGame ()->getCurrentEnemyIndex () < swarm->getNumber ()) {
		Enemy* enemy = EnemyFactory::getEnemy (this->getGame()->getMap(), swarm->getEnemiesType (), swarm->getEnemiesSize ());
                QObject::connect (enemy, SIGNAL (enemyTrespassed(Enemy*)), this, SLOT (enemyTrespassed(Enemy*)));
                this->addEnemy (enemy);
                enemy->setPos (Map::toX(this->getGame()->getMap()->getStartingTileX()), Map::toY(this->getGame()->getMap()->getStartingTileY()));
                this->getGame ()->setCurrentEnemyIndex (this->getGame ()->getCurrentEnemyIndex () + 1);
            }
            else {
                this->spawnTimer->stop ();
		this->getGame ()->setCurrentSwarmIndex (this->getGame ()->getCurrentSwarmIndex () + 1);
		this->addSwarm();
            }
        }

    signals:
	/**
	 * \fn void gameWon ()
	 * \brief Signal émis lorsque le joueur a gagné la partie
	 */
	void gameWon ();
};

#endif
