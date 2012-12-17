#ifndef SPEED_DEBUFF_H
#define SPEED_DEBUFF_H

#include <QtGui>
#include "TimedMark.h"
#include "Markable.h"

/**
 * \class SpeedDebuff
 * \brief Représente une marque qui baisse temporairement la vitesse de la cible sur laquelle elle est placée.
 *
 * La marque de ralentissement est non-cumulable, et se réinitialise si elle est de nouveau appliquée avant terme.
 */
class SpeedDebuff : public TimedMark {
	 public:
		  SpeedDebuff (float intensity, bool isStackable, QTimer* timer):
				TimedMark (intensity, false, new QTimer ()) {}
};

#endif
