#ifndef MAP_H
#define MAP_H

#include <QtGui>

/**
 * \class Map
 * \brief Représente la carte (plateau/niveau) de jeu. La carte est divisée en 16*16 divisions.
 *
 * Le joueur de paintball vise les ennemis au sol. Il applique un ralentissement à l'impact. Ce ralentissement est non-cumulable, mais chaque impact réinitialise sa durée.
 */
class Map
{
    private:
        int** tiles;
        int size;
		  int startingTile[2];

    public:
        Map (int size = 16):
            size (size) {
            //this->tiles = new int[size][size];

            this->tiles = new int*[size];
            for (int i = 0; i < size; i++)
                this->tiles[i] = new int[size];
        }

        int getTile (const int i, const int j) const { return this->tiles[i][j]; }
        int getSize () const { return this->size; }
	int getStartingTileX () const { return this->startingTile[1]; }
	int getStartingTileY () const { return this->startingTile[0]; }

        void setTile (const int i, const int j, const int value) { this->tiles[i][j] = value; }
	void setStartingTile (const int i, const int j) {
	    this->startingTile[0] = i;
	    this->startingTile[1] = j;
	}

	static float toX (int j) { return (j-8)*40+20; }
	static float toY (int i) { return (i-8)*40+20; }
	static int toJ (float x) { return x/40 + 8; }
	static int toI (float y) { return y/40 + 8; }
};

#endif
