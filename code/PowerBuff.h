#ifndef POWER_BUFF_H
#define POWER_BUFF_H

#include <QtGui>
#include "Mark.h"
#include "Markable.h"

/**
 * \class PowerBuff
 * \brief Représente une marque qui augmente la puissance de la cible sur laquelle elle est placée.
 *
 * La marque de puissance est cumulable, et les effets de chaque marque supplémentaire s'additionnent.
 */
class PowerBuff : public Mark {
    public:
		  PowerBuff (float intensity, bool isStackable):
			  Mark (intensity, true) {}
};

#endif
