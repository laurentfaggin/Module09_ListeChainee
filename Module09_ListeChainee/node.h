#pragma once

class Node {
public:
	Node();
	Node(int p_donnee);
	Node(int p_donnee, Node* p_suivant);
	~Node();
	int obtenirDonnee() const;
	void modifierDonnees(int p_donnee);
	void modifierSuivant(Node* p_nouveausuivant);
	Node* m_suivant;
private:
	int m_donnee;
};
