#include<stdexcept>
#include "listeChainee.h"


ListeChainee::ListeChainee():
	m_debut (nullptr),
	m_fin (nullptr),
	m_nombreElement (0)
{
}

ListeChainee::ListeChainee(const ListeChainee& p_listeACopier): 
	m_debut(nullptr),
	m_fin(nullptr),
	m_nombreElement(0)
{
	Node* noeudListeACopier = p_listeACopier.m_debut;
	while (noeudListeACopier != nullptr) {
		Node* noeudCopie = new Node(noeudListeACopier->obtenir());
		if (m_fin == nullptr) {
			m_debut = m_fin = noeudCopie;
		}
		else {
			m_fin->m_suivant = noeudCopie;
			m_fin = noeudCopie;
		}

		++m_nombreElement;
		noeudListeACopier = noeudListeACopier->m_suivant;
	}
}

ListeChainee::ListeChainee(ListeChainee&& p_listeADeplacer) :
	m_debut(p_listeADeplacer.m_debut),
	m_fin(p_listeADeplacer.m_fin),
	m_nombreElement(p_listeADeplacer.m_nombreElement) 
{
	p_listeADeplacer.m_debut = nullptr;
	p_listeADeplacer.m_fin = nullptr;
	p_listeADeplacer.m_nombreElement = 0;
}

ListeChainee::~ListeChainee() {
	Node* noeudCourant = this->m_debut;
	while (noeudCourant != nullptr) {
		Node* noeud = noeudCourant;
		noeudCourant = noeudCourant->m_suivant;
		delete noeud;
	}
	this->m_debut = nullptr;
	this->m_fin = nullptr;
	this->m_nombreElement = 0;
}

void ListeChainee::ajouterDebut(const int& p_valeur) {	
	Node* noeudDebut = new Node(p_valeur,this->m_debut);
	this->m_debut = noeudDebut;
	if (this->m_nombreElement == 0) {
		this->m_fin = noeudDebut;
	}
	++this->m_nombreElement;
}

Node* ListeChainee::nodePrecedent(const int& p_indice) {
	Node* noeudPrecedent = this->m_debut;
	int compteur = 0;
	if (p_indice > 0) {
		compteur = p_indice - 1;		
	}
	while(compteur){
		noeudPrecedent = noeudPrecedent->m_suivant;
		--compteur;
	} 
	return noeudPrecedent;
}

void ListeChainee::inserer(const int& p_valeur, const int& p_indice) {
	Node* newNode = new Node(p_valeur);
	if (p_indice > this->m_nombreElement) {
		std::invalid_argument("valeur d'indice trop elevee");
	}
	else if (this->m_nombreElement != 0) {
		Node* futurNoeudPrecedent = this->nodePrecedent(p_indice);
		newNode->modifierSuivant(futurNoeudPrecedent->m_suivant);
		futurNoeudPrecedent->modifierSuivant(newNode);
	}
	else {
		this->ajouterDebut(newNode->obtenirValeur());
	}

}