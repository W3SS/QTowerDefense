#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "GameScene.h"
#include "Game.h"
#include "Slingshot.h"
#include "Ant.h"
#include "EnemyFactory.h"
#include "DefenceFactory.h"
#include "Bowl.h"
#include "Cockroach.h"
#include "Musician.h"
#include "Wasp.h"
#include "Paint.h"
#include <cmath>
/**
 * \class MainWindow
 * \brief Représente la fenêtre principale du jeu.
 *
 * La fenêtre principale contient tous les éléments de l'interface utilisateur, ainsi que le canevas 2D qui affiche le jeu.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        GameScene* gameScene;
        QGraphicsView* graphicsView;
        Game* game;
        bool hoveringGraphicsScene;
        QPushButton* waveLauncher;
        QPushButton* slingshotButton;
        QPushButton* waterGunButton;
        QPushButton* paintballButton;
        QPushButton* bowlerButton;
        QPushButton* musicianButton;
        QLCDNumber* livesLCD;
        QLCDNumber* moneyLCD;
        QDockWidget* dock;
        QLabel* test;
        QLabel* selectionInfo;
        QPushButton* upgradeButton;
        QPushButton* sellButton;
        QGridLayout* selectionLayout;

    public:
        MainWindow (QWidget* parent = 0):
            QMainWindow (parent), hoveringGraphicsScene (false) {

            // setup and add menubar
            /*
            QMenu *gameMenu = menuBar()->addMenu("&Jeu");

                QAction *newGame = gameMenu->addAction("&Nouvelle partie");
                QAction *pauseGame = gameMenu->addAction("&Pause");
                gameMenu->addSeparator();
                QAction *saveGame = gameMenu->addAction("&Sauvegarder la partie");
                QAction *loadGame = gameMenu->addAction("&Charger une partie");
                gameMenu->addSeparator();
                QAction *quit = gameMenu->addAction("&Quitter");

                QObject::connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

            QMenu *optionsMenu = menuBar()->addMenu("&Options");

            QMenu *helpMenu = menuBar()->addMenu("&Aide");
            */

            // setup and add dock
				this->dock = new QDockWidget ("Contrôles", this);
            dock->setFeatures (QDockWidget::NoDockWidgetFeatures);
				dock->setFixedWidth (300);
            QWidget* w = new QWidget ();
            QGridLayout* gl = new QGridLayout (w);
				//test = new QLabel ("Test");
				//test->setMaximumHeight(50);
				//gl->addWidget (test, 1, 1, 1, 2);


            waveLauncher = new QPushButton ("Lancer la vague");

            gl->addWidget (waveLauncher, 2, 1, 1, 2);



            QLabel* lc = new QLabel ("Crédits :");
            moneyLCD = new QLCDNumber (3);
            QLabel* lv = new QLabel ("Vies :");
            livesLCD = new QLCDNumber (3);
            lc->setMaximumHeight(40);
            moneyLCD->setMaximumHeight(40);
            lv->setMaximumHeight(40);
            livesLCD->setMaximumHeight(40);
            gl->addWidget (lc, 3, 1);
            gl->addWidget (moneyLCD, 3, 2);
            gl->addWidget (lv, 4, 1);
            gl->addWidget (livesLCD, 4, 2);
            QGroupBox* construction = new QGroupBox ("Créer une défense");
				this->slingshotButton = new QPushButton ("Lance-pierres\n(12)");
            slingshotButton->setStyleSheet ("background: red;");
				this->waterGunButton = new QPushButton ("Pistolet à eau\n(8)");
            waterGunButton->setStyleSheet ("background: blue;");
				this->paintballButton = new QPushButton ("Paintball\n(12)");
            paintballButton->setStyleSheet ("background: grey;");
				this->bowlerButton = new QPushButton ("Joueur de pétanque\n(15)");
            bowlerButton->setStyleSheet ("background: yellow;");
				this->musicianButton = new QPushButton ("Musicien\n(15)");
            musicianButton->setStyleSheet ("background: purple;");
            QGridLayout* gl2 = new QGridLayout (construction);
            gl2->addWidget (slingshotButton, 1, 1);
            gl2->addWidget (waterGunButton, 1, 2);
            gl2->addWidget (bowlerButton, 2, 1);
            gl2->addWidget (musicianButton, 2, 2);
            gl2->addWidget (paintballButton, 3, 1);
            QGroupBox* selection = new QGroupBox ("Affichage de sélection");
            gl->addWidget (construction, 5, 1, 1, 2);
            gl->addWidget (selection, 6, 1, 1, 2);
            selectionLayout = new QGridLayout (selection);
            selection->setLayout(selectionLayout);
            selectionInfo = new QLabel();
            selectionLayout->addWidget(selectionInfo, 1, 1, 1, 2);
            w->setLayout (gl);
            dock->setWidget (w);
            this->addDockWidget (Qt::RightDockWidgetArea, dock);
            upgradeButton = new QPushButton("Améliorer");
            sellButton = new QPushButton("Vendre");
            selectionLayout->addWidget(sellButton, 2, 2);
            selectionLayout->addWidget(upgradeButton, 2, 1);
            upgradeButton->hide ();
            sellButton->hide ();

            // setup game and gameScene
            this->game = new Game ();
            this->gameScene = new GameScene (this->game);

            // setup and add graphicsView
            this->graphicsView = new QGraphicsView (gameScene, this);
            graphicsView->setInteractive (true);
            graphicsView->setBackgroundBrush (QBrush (QColor (69, 169, 69)));
            graphicsView->setFixedSize (16*40, 16*40);
            graphicsView->setFrameStyle (QFrame::NoFrame);
            this->setCentralWidget (graphicsView);
            this->setFixedSize(graphicsView->width()+dock->width(), graphicsView->height()); // ajouter hauteur de menuBar

            // test de dessin de la tour
            //Slingshot* s = new Slingshot ();
            //gs.addItem (s);

            // test de dessin d'un insecte
            /*Ant* a = new Ant (gameScene->getGame()->getMap(), 1);
            gameScene->addItem (a);
            a->setPos (-8*35, -8*35);*/



            //this->gameScene->addWave ();

            /*Wave* wave = this->getGame ()->getWave (this->getGame ()->getCurrentWaveIndex ());
            Swarm* swarm = wave->getSwarm (this->getGame ()->getCurrentSwarmIndex ());

            if  (this->getGame ()->getCurrentEnemyIndex () < swarm->getNumber ()) {
                Enemy* enemy = EnemyFactory::getEnemy (swarm->getEnemiesType (), swarm->getEnemiesSize ());
                this->addItem (enemy);
                enemy->setPos (0, 100);
                this->getGame ()->setCurrentEnemyIndex (this->getGame ()->getCurrentEnemyIndex () + 1);
            }
        */
            /*QLabel* lt = new QLabel(QString::number(a->x()));
            lt->show();*/


            // animate the GameScene
            QTimer* timer = new QTimer (this);
            QObject::connect (timer, SIGNAL (timeout ()), gameScene, SLOT (advance ()));
            QObject::connect (timer, SIGNAL (timeout ()), gameScene, SLOT (update ()));
            QObject::connect (timer, SIGNAL (timeout ()), this, SLOT (update ()));
            timer->start (1000 / 40);

            QObject::connect(waveLauncher, SIGNAL(clicked()), gameScene, SLOT(addWave()));
            QShortcut *spaceBar = new QShortcut(QKeySequence(Qt::Key_Space), this);
            QObject::connect(spaceBar, SIGNAL(activated()), gameScene, SLOT(addWave()));

            /*QObject::connect(enemy, SIGNAL(aimReached()), game, SLOT(decreaseLives()));
            QObject::connect(enemy, SIGNAL(aimReached()), this, SLOT(refreshLives()));*/

				QObject::connect (slingshotButton, SIGNAL (clicked ()), this, SLOT (unselectDefence ()));
            QObject::connect (slingshotButton, SIGNAL (clicked ()), this->game, SLOT (switchToConstructionModeForSlingshot ()));
				QObject::connect (waterGunButton, SIGNAL (clicked ()), this, SLOT (unselectDefence ()));
            QObject::connect (waterGunButton, SIGNAL (clicked ()), this->game, SLOT (switchToConstructionModeForWaterGun ()));
					QObject::connect (paintballButton, SIGNAL (clicked ()), this, SLOT (unselectDefence ()));
            QObject::connect (paintballButton, SIGNAL (clicked ()), this->game, SLOT (switchToConstructionModeForPaintball ()));
					QObject::connect (bowlerButton, SIGNAL (clicked ()), this, SLOT (unselectDefence ()));
            QObject::connect (bowlerButton, SIGNAL (clicked ()), this->game, SLOT (switchToConstructionModeForBowler ()));
					QObject::connect (musicianButton, SIGNAL (clicked ()), this, SLOT (unselectDefence ()));
            QObject::connect (musicianButton, SIGNAL (clicked ()), this->game, SLOT (switchToConstructionModeForMusician ()));

            // set window settings
            this->setWindowTitle ("Tower Defense");
            this->setWindowIcon (QIcon (QPixmap ("img/aim.png")));
            //this->setFixedSize (dock->width () + this->graphicsView->width (), this->height ());
            this->installEventFilter (this);
            this->setMouseTracking (true);
        }

        bool eventFilter (QObject* object, QEvent* event) {
            // Construction
            if (QString(this->game->getMode ()->metaObject()->className()).compare("ConstructionMode") == 0) {
                if (event->type () == QMouseEvent::HoverMove) {
                    QHoverEvent* hoverEvent = static_cast<QHoverEvent*>(event);

                    // ContructionMode hover enter
                    if (hoveringGraphicsScene == false) {
                        if (hoverEvent->pos().x() <= 16 * 40) {
                            hoveringGraphicsScene = true;
                            Defence* d = static_cast<ConstructionMode*>(this->game->getMode ())->getDefenceShadow ();
                            this->gameScene->addItem (d);

                            return true;
                        }
                    }
                    else {
                        // ContructionMode hover leave
                        if (hoverEvent->pos().x() > 16 * 40) {
                            hoveringGraphicsScene = false;
                            Defence* d = static_cast<ConstructionMode*>(this->game->getMode ())->getDefenceShadow ();
                            this->gameScene->removeItem (d);
                            this->game->switchToSelectionMode ();


                            return true;
                        }
                        else {
                            // ContructionMode hover move
                            Defence* d = static_cast<ConstructionMode*>(this->game->getMode ())->getDefenceShadow ();
                            d->setPos (-8*40+(hoverEvent->pos ().x()) - ((hoverEvent->pos ().x()) % 40), -8*40+(hoverEvent->pos ().y ()) - ((hoverEvent->pos ().y ()) % 40));

                            return true;
                        }
                    }
                }
                else if (event->type () == QMouseEvent::MouseButtonPress) {
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

                    // ConstructionMode build
                    Defence* d = DefenceFactory::getDefence (static_cast<ConstructionMode*>(this->game->getMode ())->getDefenceName ());
                    if (this->game->getMoney () >= d->getLevel1Cost () && mouseEvent->pos().x() <= 16 * 40 && mouseEvent->pos().y() <= 16 * 40 && this->game->getMap()->getTile(Map::toI(mouseEvent->pos().y() - 8 * 40), Map::toJ(mouseEvent->pos().x() - 8 * 40)) == 0) {
                        this->gameScene->addDefence (d);
								Musician* m = dynamic_cast<Musician*> (d);
								if (m != NULL) {
									 foreach (Defence* d2, this->gameScene->getDefences()) {
										  HostileDefence* hd = dynamic_cast<HostileDefence*> (d2);
										  if (hd != NULL) {
												hd->setPower (hd->getPower () * m->getPowerBuffPower ());
										  }
									 }
								}
                        this->game->getMap()->setTile(Map::toI(mouseEvent->pos().y() - 8 * 40), Map::toJ(mouseEvent->pos().x() - 8 * 40), 66);
                        d->setPos (-8*40+(mouseEvent->pos ().x()) - ((mouseEvent->pos ().x()) % 40), -8*40+(mouseEvent->pos ().y ()) - ((mouseEvent->pos ().y ()) % 40));
                        this->game->setMoney (this->game->getMoney () - d->getLevel1Cost ());

                        return true;
                    }
                }
            }
            // Selection
            else if (QString(this->game->getMode ()->metaObject()->className()).compare("SelectionMode") == 0) {
                if (event->type () == QMouseEvent::MouseButtonPress) {
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if (mouseEvent->pos().x() <= 16 * 40) {
								// selection
								foreach (Defence* d, this->gameScene->getDefences()) {

									 if ((Map::toJ(d->pos ().x ()) == Map::toJ(mouseEvent->pos ().x () - 8 * 40)) && (Map::toI(d->pos ().y ()) == Map::toI(mouseEvent->pos ().y () - 8 * 40))) {
										  SelectionMode* m = static_cast<SelectionMode*>(this->game->getMode());
										  // Selection (change selected tower)
										  if (m->getSelectedDefence () != NULL) {
												this->unselectDefence ();
												this->selectDefence (d);
												return true;
										  }
										  // Selection (select first tower)
										  else {
												this->selectDefence (d);
												return true;
										  }


									 }
								}
                        // Deselection
                        this->unselectDefence ();
                        return true;
                    }
                }
            }

            return false;
        }

		  void hurtEnemy (Enemy* e, Projectile* p, int damage) {
				e->hurt (damage);
				Paint* paint = dynamic_cast<Paint*>(p);
				if (paint != NULL) {
					 e->slowDown ();
				}
				if (e->getCurrentHealth () <= 0) {

				this->gameScene->removeEnemy (e);
					 this->game->setMoney (this->game->getMoney() + 1);
				Cockroach* c = dynamic_cast<Cockroach*>(e);
				 if (c != NULL) {
					if (c->getSize() > 1) {
						 Enemy* enemy = EnemyFactory::getEnemy (this->game->getMap(), "cafard", e->getSize() - 1);
					  QObject::connect (enemy, SIGNAL (enemyTrespassed(Enemy*)), this->gameScene, SLOT (enemyTrespassed(Enemy*)));
						 this->gameScene->addEnemy(enemy);
						 enemy->setPos (e->x()+3, e->y()+3);
						 Enemy* enemy2 = EnemyFactory::getEnemy (this->game->getMap(), "cafard", e->getSize() - 1);
						 this->gameScene->addEnemy(enemy2);
						 QObject::connect (enemy2, SIGNAL (enemyTrespassed(Enemy*)), this->gameScene, SLOT (enemyTrespassed(Enemy*)));
						 enemy2->setPos (e->x()-3, e->y()-3);
				  }
			 }
			Wasp* w = dynamic_cast<Wasp*>(e);
			if (w != NULL) {
					 foreach (Enemy* e2, this->gameScene->getEnemies()) {
							if (e2 != w && std::sqrt (std::pow (w->x() - e2->x(), 2) + std::pow (w->y() - e2->y(), 2)) <= 60) {
								 this->hurtEnemy (e2, p, 5 * w->getSize () * w->getSize ());
							}
					 }
		  }


		}
	 }

    public slots:
	 void unselectDefence () {
				SelectionMode* m = static_cast<SelectionMode*>(this->game->getMode());
				this->selectionInfo->setText("");

				if (m->getSelectedDefence() != NULL) {
					 QObject::disconnect (upgradeButton, SIGNAL(clicked()), this, SLOT(upgradeSelectedDefence()));
					 QObject::disconnect (sellButton, SIGNAL(clicked()), this, SLOT(sellSelectedDefence()));
				}
				this->upgradeButton->hide();
				this->sellButton->hide();

				this->game->switchToSelectionMode ();
		  }

        void update () {
            // Lives and money
            livesLCD->display (this->game->getLives());
            moneyLCD->display (this->game->getMoney());

            // Upgrade and sell buttons
            if (QString(this->game->getMode ()->metaObject()->className()).compare("SelectionMode") == 0) {
                Defence* d = static_cast<SelectionMode*>(this->game->getMode ())->getSelectedDefence ();
                if (d != NULL) {
						  if (d->getLevel () < 3 && this->game->getMoney() >= (d->getLevel()==1 ? d->getLevel2Cost() : d->getLevel3Cost())) {
                        upgradeButton->setEnabled(true);
                    }
                    else {
                        upgradeButton->setDisabled(true);
                    }
                }
            }



            // Test
            // test->setText (this->game->getMode()->metaObject()->className());

            // Towers firing
            foreach (Defence* d, this->gameScene->getDefences ()) {
                foreach (Enemy* e, this->gameScene->getEnemies ()) {
                    HostileDefence* hd = dynamic_cast<HostileDefence*>(d);
                    if (hd != NULL) {
                        if (std::sqrt (std::pow (hd->x() - e->x(), 2) + std::pow (hd->y() - e->y(), 2)) <= hd->getRange() * 40) {
                            if (hd->isLoaded ()) {
                                if (hd->getTargetables () == "both" || (hd->getTargetables () == "flying" && e->isFlying ()) || (hd->getTargetables () == "crawling" && !e->isFlying ())) {
                                    Projectile* p = hd->fireAt (e);
                                    //hd->unload ();
                                    this->gameScene->addProjectile (p);
                                    p->setPos (hd->x() + 20, hd->y() + 20);
                                }
                            }
                        }
                    }
                }
            }

            // Projectiles aiming
            foreach (Projectile* p, this->gameScene->getProjectiles ()) {
                Enemy* e = p->getTarget ();
                if (! this->gameScene->getEnemies ().contains (e)) {
                    this->gameScene->removeProjectile (p);
                }
                else {
                    float distanceToTarget = std::sqrt (std::pow (e->x() - p->x(), 2) + std::pow (e->y() - p->y(), 2));
                    float distanceToCover = p->getSpeed () * 40 / 40;
                    float distanceCovered = distanceToCover / distanceToTarget;
                    if (distanceCovered > 1) {distanceCovered = 1; }
                    int dx = distanceCovered * (e->x() - p->x());
                    int dy = distanceCovered * (e->y() - p->y());
                    p->setPos (p->x() + dx, p->y() + dy);

                    // Enemy reached
                    if ((p->x() <= e->x() + 1) && (p->x() >= e->x() - 1) && (p->y() <= e->y() + 1) && (p->y() >= e->y() - 1)) {
                        Bowl* b = dynamic_cast<Bowl*>(p);
                        // Projectile = Bowl donc explosion
								if (b != NULL) {
                            foreach (Enemy* e, this->gameScene->getEnemies()) {
                                if (std::sqrt (std::pow (e->x() - p->x(), 2) + std::pow (e->y() - p->y(), 2)) <= 40) {
												this->hurtEnemy (e, p, p->getPower ());
										  }
                            }
                        }
                        // Projectile différent de Bowl
                        else {
									 this->hurtEnemy (e, p, p->getPower ());
                        }
                        this->gameScene->removeProjectile (p);
                    }
                }
            }
        }
        void refreshLives () {
            this->livesLCD->display(this->game->getLives());
        }

		  void selectDefence (Defence* d) {
				this->game->switchToSelectionMode (d);
				this->selectionInfo->setText(QString("Niveau ").append(QString::number(d->getLevel ())));
				HostileDefence* hd = dynamic_cast<HostileDefence*> (d);
				if (hd != NULL) {
					 this->selectionInfo->setText(QString("Niveau ").append(QString::number(d->getLevel ())).append(", Puissance ").append(QString::number(hd->getPower ())));
				}
				else {
					 Musician* m = dynamic_cast<Musician*> (d);
					 this->selectionInfo->setText(QString("Niveau ").append(QString::number(d->getLevel ())).append (", Boost ").append(QString::number(m->getPowerBuffPower ())));
				}
				upgradeButton->setText(d->getLevel() < 3 ? QString("Améliorer\n(").append(QString::number(d->getLevel()==1 ? d->getLevel2Cost() : d->getLevel3Cost()).append(" crédits)")) : QString("Niveau maximum"));
				sellButton->setText(QString("Vendre\n(").append(QString::number(d->getLevel()==1 ? d->getLevel1Cost()/2 : (d->getLevel()==2 ? (d->getLevel1Cost()+d->getLevel2Cost())/2 : (d->getLevel1Cost()+d->getLevel2Cost()+d->getLevel3Cost())/2) )).append(" crédits)"));

				QObject::connect(upgradeButton, SIGNAL(clicked()), this, SLOT(upgradeSelectedDefence()));
				QObject::connect(sellButton, SIGNAL(clicked()), this, SLOT(sellSelectedDefence()));
				upgradeButton->show();
				sellButton->show();
		  }

        void sellSelectedDefence() {
            Defence* d = static_cast<SelectionMode*>(this->game->getMode())->getSelectedDefence();
            this->game->increaseMoney(d->getLevel()==1 ? d->getLevel1Cost()/2 : (d->getLevel()==2 ? (d->getLevel1Cost()+d->getLevel2Cost())/2 : (d->getLevel1Cost()+d->getLevel2Cost()+d->getLevel3Cost())/2));
            this->unselectDefence ();
				Musician* m = dynamic_cast<Musician*> (d);
				if (m != NULL) {
					 foreach (Defence* d2, this->gameScene->getDefences()) {
						  HostileDefence* hd = dynamic_cast<HostileDefence*> (d2);
						  if (hd != NULL) {
								hd->setPower ((float)hd->getPower () / m->getPowerBuffPower ());
						  }
					}
				}
				this->gameScene->removeDefence(d);
        }

        void upgradeSelectedDefence () {
            Defence* d = static_cast<SelectionMode*>(this->game->getMode())->getSelectedDefence();
            this->game->decreaseMoney(d->getLevel()==1 ? d->getLevel2Cost() : d->getLevel3Cost());
				Musician* m = dynamic_cast<Musician*> (d);
				if (m != NULL) {
					 float previousPower = m->getPowerBuffPower();
					 d->upgrade();
					 foreach (Defence* d2, this->gameScene->getDefences()) {
						  HostileDefence* hd = dynamic_cast<HostileDefence*> (d2);
						  if (hd != NULL) {
								hd->setPower ((float)hd->getPower () / previousPower * m->getPowerBuffPower ());
						  }
					}
				}
				else {
					 d->upgrade();
				}
				HostileDefence* hd = dynamic_cast<HostileDefence*> (d);
				if (hd != NULL) {
					 this->selectionInfo->setText(QString("Niveau ").append(QString::number(d->getLevel ())).append(", Puissance ").append(QString::number(hd->getPower ())));
				}
				else {
					 Musician* m = dynamic_cast<Musician*> (d);
					 this->selectionInfo->setText(QString("Niveau ").append(QString::number(d->getLevel ())).append (", Boost ").append(QString::number(m->getPowerBuffPower ())));
				}


				upgradeButton->setText(d->getLevel() < 3 ? QString("Améliorer\n(").append(QString::number(d->getLevel()==1 ? d->getLevel2Cost() : d->getLevel3Cost()).append(" crédits)")) : QString("Niveau maximum"));
				sellButton->setText(QString("Vendre\n(").append(QString::number(d->getLevel()==1 ? d->getLevel1Cost()/2 : (d->getLevel()==2 ? (d->getLevel1Cost()+d->getLevel2Cost())/2 : (d->getLevel1Cost()+d->getLevel2Cost()+d->getLevel3Cost())/2) )).append(" crédits)"));
        }
};

#endif
