#include "EnemyFactory.h"
#include "Ant.h"
#include "Cockroach.h"
#include "Wasp.h"
#include "Mosquito.h"

Enemy* EnemyFactory::getEnemy (Map* map, QString enemyName, int size) {
    if (enemyName == "fourmi") { return new Ant (map, size); }
    else if (enemyName == "cafard") { return new Cockroach (map, size); }
    else if (enemyName == "guepe") { return new Wasp (map, size); }
    else { return new Mosquito (map, size); }
}
