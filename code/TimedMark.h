#ifndef TIMED_MARK_H
#define TIMED_MARK_H

#include <QtGui>
#include "Mark.h"
#include "QTimer.h"

/**
 * \class TimedMark
 * \brief Représente une marque temporaire
 *
 * Une marque temporaire disparaît au bout d'un moment. Elle permet de marquer temporairement un objet.
 */
class TimedMark : public Mark
{
    private:
		  QTimer* timer;

	 public:
		  TimedMark (float intensity, bool isStackable, QTimer* timer):
		  Mark (intensity, isStackable) {}
};

#endif
