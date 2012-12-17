#ifndef MARKABLE_H
#define MARKABLE_H

#include <QtGui>
#include "Mark.h"

/**
 * \class Markable
 * \brief Représente un objet marquable.
 *
 * Un object marquable est suceptible de recevoir une marque.
 */
class Markable {
    public:
	bool hasMark ();
	void addMark ();
	void removeMark ();
};

#endif
