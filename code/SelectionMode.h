#ifndef SELECTION_MODE_H
#define SELECTION_MODE_H

#include <QtGui>
#include "Mode.h"
#include "Defence.h"

/**
 * \class SelectionMode
 * \brief Représente le mode de sélection.
 *
 * Il s'agit soit du cas où une défense est sélectionnée par le joueur, soit du cas où aucune défence n'est sélectionnée, mais le joueur n'est pas en mode construction.
 *
 * Le joueur peut quitter le mode de sélection rapidement en cliquant à un emplacement vide sur l'aire de jeu.
 */
class SelectionMode : public Mode {
	 private:
		  Q_OBJECT
		  Defence* selectedDefence;

	 public:
		  SelectionMode (Defence* selectedDefence):
				selectedDefence (selectedDefence) {
				this->getSelectedDefence ()->select ();
		  }
		  SelectionMode (): selectedDefence (0) {}

		  ~SelectionMode () {
				if (this->selectedDefence != NULL) {
					 this->selectedDefence->unselect ();
				}
		  }

		  Defence* getSelectedDefence () const { return this->selectedDefence; }
};

#endif
