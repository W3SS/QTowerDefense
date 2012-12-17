#ifndef SPEED_BUFF_H
#define SPEED_BUFF_H

#include <QtGui>
#include "TimedMark.h"
#include "Markable.h"

/**
 * \class SpeedBuff
 * \brief Représente une marque qui augmente temporairement la vitesse de la cible sur laquelle elle est placée.
 *
 * La marque d'accélération est non-cumulable, et se réinitialise si elle est de nouveau appliquée avant terme.
 */
class SpeedBuff : public TimedMark {
	 public:
		  SpeedBuff (float intensity, bool isStackable, QTimer* timer):
				TimedMark (intensity, false, new QTimer ()) {}
};


#endif
