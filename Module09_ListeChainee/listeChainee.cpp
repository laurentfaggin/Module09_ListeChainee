#include<stdexcept>
#include "listeChainee.h"


ListeChainee::ListeChainee():
	m_debut (nullptr),
	m_fin (nullptr),
	m_nombreMaillons (0)
{
}

ListeChainee::ListeChainee(const ListeChainee& p_listeACopier): 
	m_debut(nullptr),
	m_fin(nullptr),
	m_nombreMaillons(0)
{
	Node* noeudListeACopier = p_listeACopier.m_debut;
	while (noeudListeACopier != nullptr) {
		Node* noeudCopie = new Node(noeudListeACopier->obtenirDonnee());
		if (m_fin == nullptr) {
			m_debut = m_fin = noeudCopie;
		}
		else {
			m_fin->m_suivant = noeudCopie;
			m_fin = noeudCopie;
		}

		++m_nombreMaillons;
		noeudListeACopier = noeudListeACopier->m_suivant;
	}
}

ListeChainee::ListeChainee(ListeChainee&& p_listeADeplacer) :
	m_debut(p_listeADeplacer.m_debut),
	m_fin(p_listeADeplacer.m_fin),
	m_nombreMaillons(p_listeADeplacer.m_nombreMaillons) 
{
	p_listeADeplacer.m_debut = nullptr;
	p_listeADeplacer.m_fin = nullptr;
	p_listeADeplacer.m_nombreMaillons = 0;
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
	this->m_nombreMaillons = 0;
}

void ListeChainee::ajouterDebut(const int& p_valeur) {	
	Node* noeudDebut = new Node(p_valeur,this->m_debut);
	this->m_debut = noeudDebut;
	if (this->m_nombreMaillons == 0) {
		this->m_fin = noeudDebut;
	}
	++this->m_nombreMaillons;
}

Node* ListeChainee::nodePrecedent(const int& p_indice) {
	Node* noeudPrecedent = this->m_debut;
	int compteur = 0;
	if (p_indice > 0) {
		compteur = p_indice - 1;		
	}
	while(compteur){
		if (this->m_nombreMaillons == 0) {
			std::invalid_argument("la liste est vide");
		}
		noeudPrecedent = noeudPrecedent->m_suivant;
		--compteur;
	} 
	return noeudPrecedent;
}

Node* ListeChainee::nodeCourant(const int& p_indice) {
	Node* noeudCourant = this->m_debut;
	int compteur = p_indice;
	while (compteur != 0) {
		noeudCourant = noeudCourant->m_suivant;
		--compteur;
	}
	return noeudCourant;
}

void ListeChainee::ajouterFin(const int& p_valeur) {
	Node* noeudFin = new Node(p_valeur);
	if (this->m_nombreMaillons == 0) {
		this->m_debut = noeudFin;
		this->m_fin = noeudFin;
	}
	else {
		Node* futurPrecedent = this->nodePrecedent(this->m_nombreMaillons);
		noeudFin->modifierSuivant(futurPrecedent->m_suivant);
		futurPrecedent->modifierSuivant(noeudFin);
		this->m_fin = noeudFin;
	}
	++this->m_nombreMaillons;
}

void ListeChainee::inserer(const int& p_valeur, const int& p_indice) {
	Node* newNode = new Node(p_valeur);
	if (p_indice > this->m_nombreMaillons) {
		std::invalid_argument("valeur d'indice trop elevee");
	}
	else if (this->m_nombreMaillons != 0) {
		Node* futurNoeudPrecedent = this->nodePrecedent(p_indice);
		newNode->modifierSuivant(futurNoeudPrecedent->m_suivant);
		futurNoeudPrecedent->modifierSuivant(newNode);
	}
	else {
		this->ajouterDebut(newNode->obtenirDonnee());
	}
}

void ListeChainee::supprimerDebut() {
	if (this->m_nombreMaillons == 0) {
		std::invalid_argument("la liste est vide");
	}
	else if (this->m_nombreMaillons == 1) {
		this->m_debut = nullptr;
		this->m_fin = nullptr;
		this->m_nombreMaillons = 0;
	}
	else {
		Node* noeudAEffacer = this->m_debut;
		this->m_debut = this->m_debut->m_suivant;
		noeudAEffacer->m_suivant = nullptr;
		delete noeudAEffacer;
		--this->m_nombreMaillons;
	}
}

void ListeChainee::supprimerFin() {
	int compteur = this->m_nombreMaillons;
	if (this->m_nombreMaillons == 0) {
		std::invalid_argument("la liste est vide");
	}
	else if (this->m_nombreMaillons == 1) {
		Node* noeudAEffacer = this->m_debut;
		this->m_debut = this->m_fin = nullptr;
		delete this->m_fin;
		delete noeudAEffacer;
	}
	else {
		Node* futurDernier = this->nodePrecedent(this->m_nombreMaillons);
		delete futurDernier->m_suivant;		
		futurDernier->m_suivant = nullptr;
		this->m_fin = futurDernier;
		--m_nombreMaillons;
	}
}

void ListeChainee::supprimerA(const int& p_indice) {
	
	if (p_indice >= 0 && p_indice < this->m_nombreMaillons) {
		if (p_indice == 0) {
			this->supprimerDebut();
		}
		else {
			Node* noeudPrecedent = this->nodePrecedent(p_indice);
			Node* noeudAEffacer = this->nodeCourant(p_indice);
			noeudPrecedent->modifierSuivant(noeudAEffacer->m_suivant);
			noeudAEffacer->m_suivant = nullptr;
		}
		--m_nombreMaillons;
	}
	else {
		std::invalid_argument("l'indice n'est pas correct ou  la liste est vide");
	}
}

void ListeChainee::vider(){
	while (this->m_nombreMaillons > 0) {
		this->supprimerDebut();
	}
}

int ListeChainee::obtenir(const int& p_indice) {
	if (this->m_nombreMaillons == 0 || p_indice >= this->m_nombreMaillons) {
		std::invalid_argument("aucun element a la position donnee");
	}
	else {
		Node* elementCherche = this->nodeCourant(p_indice);
		return elementCherche->obtenirDonnee();	
	}
}

int ListeChainee::nombreElement() const {
	return this->m_nombreMaillons;
}

ListeChainee& ListeChainee:: operator=(ListeChainee&& p_listeADeplacer) {
	if (this != &p_listeADeplacer) {
		this->vider();
		this->m_debut = p_listeADeplacer.m_debut;
		this->m_fin = p_listeADeplacer.m_fin;
		this->m_nombreMaillons = p_listeADeplacer.m_nombreMaillons;

		this->m_debut = nullptr;
		this->m_fin = nullptr;
		this->m_nombreMaillons = 0;
	}
	return *this;
}

void ListeChainee::parcourir(void(*p_fonction)(const int&)) {
	if (this->m_nombreMaillons == 0) {
		std::invalid_argument("la liste est vide");
	}
	else {
		Node* noeudCourant = this->m_debut;
		while (noeudCourant != nullptr) {
			p_fonction(noeudCourant->obtenirDonnee());
			noeudCourant = noeudCourant->m_suivant;
		}
	}
}

void ListeChainee::trier(bool(*p_fonctionTri)(const int&, const int&)) {
	if (this->m_nombreMaillons == 0) {
		std::invalid_argument("la liste est vide");
	}
	else {
		Node* noeudCourant = this->m_debut;		
		while (noeudCourant != nullptr) {
			Node* noeudSuivant = noeudCourant->m_suivant;
			while (noeudSuivant != nullptr) {
				if (!p_fonctionTri(noeudCourant->obtenirDonnee(), noeudSuivant->obtenirDonnee())) {
					int temp = noeudCourant->obtenirDonnee();
					noeudCourant->modifierDonnees(noeudSuivant->obtenirDonnee());
					noeudSuivant->modifierDonnees(temp);
				}
				noeudSuivant = noeudSuivant->m_suivant;
			}
			noeudCourant = noeudCourant->m_suivant;
		}
	}
}