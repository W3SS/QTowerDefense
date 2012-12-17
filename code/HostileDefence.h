#ifndef HOSTILE_DEFENCE_H
#define HOSTILE_DEFENCE_H

#include <QtGui>
#include "Markable.h"
#include "Defence.h"
#include "PowerBuff.h"
#include "Projectile.h"

/**
 * \class HostileDefence
 * \brief Représente une défense aggressive.
 *
 * Les défenses aggressives tirent des projectiles dès qu'un ennemi rentre dans leur portée.
 */
class HostileDefence : public Defence/* , public Markable */{
    private:
        Q_OBJECT
	float firingRate;
	float power;
		  QString canTarget;
        bool loaded;
 
    public:
        HostileDefence (float range, int level1Cost, int level2Cost, int level3Cost, float firingRate, float power, QString canTarget, int level = 1, bool selected = false):
            Defence (range, level1Cost, level2Cost, level3Cost, level, selected), firingRate (firingRate), power (power), canTarget (canTarget), loaded (true) {}

        QString getTargetables () const { return this->canTarget; }
        float getFiringRate () const { return this->firingRate; }
        float getPower () const { return this->power; }
		  void setPower (const float power) { this->power = power; }
        void setFiringRate (const float firingRate) { this->firingRate = firingRate; }
        void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
            Defence::paint (p, o, w);
        }

        void unload () { this->loaded = false; }
        bool isLoaded () const { return this->loaded; }

        void fire () {
            this->unload();
            QTimer::singleShot (1000 / this->firingRate, this, SLOT (reload ()));
        }

        virtual Projectile* fireAt (Enemy* e) = 0;


    public slots:
        void reload () { this->loaded = true; }
};

#endif
