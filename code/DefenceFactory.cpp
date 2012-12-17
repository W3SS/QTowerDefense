#include "DefenceFactory.h"
#include "Slingshot.h"
#include "WaterGun.h"
#include "Paintball.h"
#include "Bowler.h"
#include "Musician.h"

Defence* DefenceFactory::getDefence (QString defenceName) {
    if (defenceName == "Lance-pierres") { return new Slingshot (); }
    else if (defenceName == "Pistolet à eau") { return new WaterGun (); }
    else if (defenceName == "Paintball") { return new Paintball (); }
    else if (defenceName == "Joueur de pétanque") { return new Bowler (); }
    else { return new Musician (); }
}
