#ifndef SWARM_H
#define SWARM_H

#include <QtGui>
#include "Enemy.h"

/**
 * \class Swarm
 * \brief Représente un essaim
 *
 * Un essaim est composé de plusieurs ennemis de mêmes types, tailles, et fréquence d'apparition.
 */
class Swarm
{
    private:
        int spawnFrequency;
        float enemiesSize;
        int number;
        QString enemiesType;

    public:
        Swarm (QString swarmDescription) {
            QStringList sl = swarmDescription.split(":");
            this->enemiesType = sl[0];
            this->enemiesSize = sl[1].toFloat ();
            this->number = sl[2].toInt ();
            this->spawnFrequency = sl[3].toInt ();
        }

        int getSpawnFrequency () const { return this->spawnFrequency; }
        float getEnemiesSize () const { return this->enemiesSize; }
        int getNumber () const { return this->number; }
        QString getEnemiesType () const { return this->enemiesType; }
};

#endif
