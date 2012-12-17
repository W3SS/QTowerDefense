#include "Game.h"


void Game::loadMap () {
    QFile file (this->mapFilePath);
    bool fileOpened = file.open (QIODevice::ReadOnly);
    if (fileOpened) {
        QTextStream ts (&file);
        QString s = ts.readAll ();
        file.close ();

        QStringList sl = s.split (QRegExp ("\\s+"));
        for (int i = 0; i < this->map->getSize (); i++) {
            for (int j = 0; j < this->map->getSize (); j++) {
                this->map->setTile (i, j, sl[this->map->getSize () * i + j].toInt ());
            }
        }
    }
}

void Game::loadWaves () {
    QFile file (this->wavesFilePath);
    bool fileOpened = file.open (QIODevice::ReadOnly);
    if (fileOpened) {
	QTextStream ts (&file);
	QString s = ts.readAll ();
	file.close ();

	QStringList sl = s.split (QRegExp("\n"));
	for (int i = 0; i < sl.size(); i++) {
	    waves << new Wave (sl[i]);
	}
    }
}
