#pragma once
#include "node.h"

class ListeChainee {
public:
	ListeChainee();
	ListeChainee(const ListeChainee& p_listeACopier);
	ListeChainee(ListeChainee&& p_listeADeplacer);
	~ListeChainee();

	void ajouterDebut(const int& p_valeur);
	void ajouterFin(const int& p_valeur);
	void inserer(const int& p_valeur, const int& p_indice);
	void supprimerDebut();
	void supprimerFin();
	void supprimerA(const int& p_indice);
	void vider();

	int obtenir(const int& p_indice);
	int nombreElement() const;

	ListeChainee& operator=(ListeChainee&& p_listeADeplacer);
	
	void parcourir(void(*p_fonction)(const int&));
	void trier(bool (*p_fonctionTri)(const int&, const int&));

private:
	int m_nombreElement;
	node* m_debut;
	node* m_fin;
};