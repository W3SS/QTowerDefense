#ifndef WAVE_H
#define WAVE_H

#include <QtGui>
#include "Swarm.h"

/**
 * \class Wave
 * \brief Représente une Vague d'ennemis
 *
 * Les vagues d'ennemis sont divisées en essais (Swarm) d'ennemis du même type.
 */
class Wave
{
    private:
        QString description;
        QList<Swarm*> swarms;

    public:
	/**
	 * Le constructeur utilise waveDescription qui correspond à une ligne du fichier waves.txt pour génerer une vague.
	 */
	Wave (QString waveDescription) {
            QStringList sl = waveDescription.split(";");
            description = sl[0];
            for (int i = 1; i < sl.size(); i++)
                swarms << new Swarm(sl[i]);
        }

        QString getDescription () const { return this->description; }
        Swarm* getSwarm (const int i) const { return this->swarms[i]; }
		  int getSwarmsNumber () const { return this->swarms.size (); }
};

#endif
