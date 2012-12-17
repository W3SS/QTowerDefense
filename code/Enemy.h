#ifndef ENEMY_H
#define ENEMY_H

#include <QtGui>
#include "Markable.h"
#include "SpeedDebuff.h"
#include "Map.h"

/**
 * \class Enemy
 * \brief Représente un ennemi (insecte).
 *
 * Cette classe représente tous les types d'ennemis présents dans le jeu qui ont chacun leurs spécificités.
 */
class Enemy : public QObject, public Markable, public QGraphicsPixmapItem
{
    private:
        Q_OBJECT
	Map* map;
        int size;
	int health;
        int currentHealth;
	bool flying;
	int resistance;
        float currentSpeed;
        float speed;
	SpeedDebuff* speedDebuff;
	QStringList pixmaps;
	int currentPixmapIndex;
	int lastTile[2];
	QTimer* slowTimer;
 
    public:
	/**
	 * \fn Map* getMap () const
	 * \return La carte sur laquelle évolue l'ennemi
	 */
	Map* getMap () const { return this->map; }

	/**
	 * Crée un ennemi
	 * \param map La carte sur laquelle évoluera l'ennemi
	 * \param size La taille de l'ennemi
	 * \param health La santé de l'ennemi
	 * \param flying Vrai si l'ennemi se déplace en volant
	 * \param resistance La résistance de l'ennemi
	 * \param speed La vitesse de déplacement de l'ennemi
	 */
	Enemy (Map* map, int size, int health, bool flying, int resistance, float speed):
		 map (map), size (size), health (health), currentHealth (health), flying (flying), resistance (resistance), currentSpeed (speed), speed (speed), currentPixmapIndex (0), slowTimer (new QTimer()) {
				QObject::connect (this->slowTimer, SIGNAL(timeout()), this, SLOT(accelerateBack()));
		 }

	/**
	 * \fn int getSize () const
	 * \return La taille de l'ennemi
	 */
        int getSize () const { return this->size; }

	/**
	 * \fn int getHealth () const
	 * \return La santé maximum de l'ennemi
	 */
        int getHealth () const { return this->health; }

	/**
	 * \fn int getCurrentHealth () const
	 * \return La santé actuelle de l'ennemi
	 */
        int getCurrentHealth () const { return this->currentHealth; }

	/**
	 * \fn bool isFlying () const
	 * \return Vrai si l'ennemi est actuellement en vol
	 */
        bool isFlying () const { return this->flying; }

	/**
	 * \fn int getResistance () const
	 * \return La résistance de l'ennemi
	 */
        int getResistance () const { return this->resistance; }

	/**
	 * \fn float getCurrentSpeed () const
	 * \return La vitesse actuelle de l'ennemi
	 */
        float getCurrentSpeed () const { return this->currentSpeed; }

	/**
	 * \fn float getSpeed () const
	 * \return La vitesse de base de l'ennemi
	 */
        float getSpeed () const { return this->speed; }

	/**
	 * \fn QString getPixmap (const int i) const
	 * \param i Un index
	 * \return L'image d'index i de l'ennemi
	 */
	QString getPixmap (const int i) const { return this->pixmaps[i]; }

	/**
	 * \fn int getCurrentPixmapIndex () const
	 * \return L'index de l'image actuellement affichée à l'écran dans la liste des images de l'ennemi
	 */
	int getCurrentPixmapIndex () const { return this->currentPixmapIndex; }

	/**
	 * \fn void setSize (const int size)
	 * \param size La taille à affecter à l'ennemi
	 */
        void setSize (const int size) { this->size = size; }

	/**
	 * \fn void setCurrentHealth (const int currentHealth)
	 * \param currentHealth La santé à affecter à l'ennemi
	 */
        void setCurrentHealth (const int currentHealth) { this->currentHealth = currentHealth; }

	/**
	 * \fn void setFlying (const bool flying)
	 * \param flying Vrai si l'on veut faire voler l'ennemi à partir de cet instant
	 */
        void setFlying (const bool flying) { this->flying = flying; }

	/**
	 * \fn void setResistance (const int resistance)
	 * \param resistance La résistance à affecter à l'ennemi
	 */
        void setResistance (const int resistance) { this->resistance = resistance; }

	/**
	 * \fn void setCurrentSpeed (const float currentSpeed)
	 * \param currentSpeed La vitesse actuelle à affecter à l'ennemi
	 */
        void setCurrentSpeed (const float currentSpeed) { this->currentSpeed = currentSpeed; }

	/**
	 * \fn void appendPixmap (const QString path)
	 * \param path Le chemin d'accès de l'image à ajouter à la liste des images de l'ennemi
	 */
	void appendPixmap (const QString path) { this->pixmaps << path; }

	/**
	 * \fn void setCurrentPixmapIndex (const int index)
	 * \param index L'index correspondant à l'image de l'ennemi actuellement affichée à l'écran
	 */
	void setCurrentPixmapIndex (const int index) { this->currentPixmapIndex = index; }

	/**
	 * \fn void hurt(const int damage)
	 * \brief Blesse l'ennemi en lui retirant de la vie
	 * \param damage Le nombre de dégâts à infliger à l'ennemi
	 */
	virtual void hurt(const int damage);

	/**
	 * \fn void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w)
	 * \brief Dessine un enemi en réimplémentant la méthode paint de QGraphicsItem
	 */
	void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

	/**
	 * \fn void advance (int step)
	 * \brief Fais évoluer la position de l'ennemi à chaque battement d'horloge en réimplémentant la méthode advance de la classe QGraphicsItem
	 */
	void advance (int step);

	void slowDown () {
		  this->setCurrentSpeed(this->getSpeed() / 2);
		  this->slowTimer->start (4000);
	 }

    signals:
	/**
	 * \fn void enemyTrespassed (Enemy* e)
	 * \brief Signal émis lorsqu'un ennemi atteint le but
	 * \param e L'ennemi qui a atteint le but
	 */
		  void enemyTrespassed (Enemy* e);

	 public slots:
	 void accelerateBack () {
		  this->setCurrentSpeed(this->getSpeed());
		  this->slowTimer->stop ();
	 }
};

#endif
