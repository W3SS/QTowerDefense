#ifndef MARK_H
#define MARK_H

#include <QtGui>
#include "Markable.h"

/**
 * \class Mark
 * \brief Représente une marque.
 *
 * Une marque se place sur un objet et l'affecte. Certaines marques sont cumulables, alors que d'autre sont temporaires et se réinitialise si l'on tente d'en ajouter une seconde.
 */
class Mark
{
	 private:
		float intensity;
		bool isStackable;
 
	 public:
	 Mark (float intensity, bool isStackable):
		  intensity (intensity), isStackable (isStackable) {}

	 void mark ();
	 void unmark ();
};

#endif
