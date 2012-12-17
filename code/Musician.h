#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <QtGui>
#include "Defence.h"

/**
 * \class Musician
 * \brief Représente un musicien.
 *
 * Le musicien est une défense de support. Il augmente la puissance des défences alliés dans sa portée.
 */
class Musician : public Defence
{
    Q_OBJECT
private:
	 float powerBuffPower;

    public:


        Musician (float range = 1.5, int level1Cost = 15, int level2Cost = 40, int level3Cost = 80, int level = 1, bool selected = false):
				Defence (range, level1Cost, level2Cost, level3Cost, level, selected), powerBuffPower (1.2) {}

        void paint (QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w);

		  float getPowerBuffPower () const { return this->powerBuffPower; }

		  void setPowerBuffPower (const float power) { this->powerBuffPower = power; }


public slots:

        void upgrade () {
            if (this->getLevel() < 3) {
                this->setLevel(this->getLevel() + 1);
					 this->setPowerBuffPower(this->getPowerBuffPower () + 0.2);
            }
        }
};

#endif
