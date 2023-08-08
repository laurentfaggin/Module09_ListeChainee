#pragma once

class Node {
public:
	Node();
	Node(int p_donnee);
	Node(int p_donnee, Node* p_suivant);
	~Node();
	int obtenir() const;
	void modifierSuivant(Node* p_nouveausuivant);
	int obtenirValeur();
	Node* m_suivant;
private:
	int m_donnee;
};
