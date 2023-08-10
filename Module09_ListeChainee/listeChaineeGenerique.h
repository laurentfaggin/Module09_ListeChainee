#pragma once
#include <stdexcept>
#include "nodeGenerique.h"

template <class TypeElement>
class ListeChainee {
public:
	ListeChainee():
		m_debut(nullptr),
		m_fin(nullptr),
		m_nombreMaillons (0)
	{;}

	ListeChainee(const ListeChainee<TypeElement>& p_listeACopier) :
		m_debut(p_listeACopier.m_debut),
		m_fin(p_listeACopier.m_fin),
		m_nombreMaillons(0) 
	{
		Node<TypeElement>* noeudListeAcopier = p_listeACopier.m_debut;
		while (noeudListeAcopier != nullptr) {
			Node<TypeElement> noeudCopie = new Node<TypeElement>(noeudListeAcopier->obtenirDonnees());
			if (m_finn == nullptr) {
				m_debut = m_fin = noeudCopie;
			}
			else {
				m_fin->modifierSuivant = noeudCopie;
				m_fin = noeudCopie;
			}
			++nombreMaillons;
			noeudCopie = noeudCopie.Next();
		}
	}

	ListeChainee(ListeChainee<TypeElement>&& p_listeADeplacer):
		m_debut(p_listeADeplacer.m_debut),
		m_fin(p_listeADeplacer.m_fin),
		m_nombreMaillons(p_listeADeplacer.m_nombreMaillons)
	{
		p_listeADeplacer.m_debut = nullptr;
		p_listeADeplacer.m_fin = nullptr;
		p_listeADeplacer.m_nombreMaillons = 0;
	}

	~ListeChainee() 
	{
		Node<TypeElement>* noeudCourant = this->m_debut;
		while (noeudCourant != nullptr){
			Node<TypeElement>* noeud = noeudcourant;
			noeudCourant = noeudCourant->m_next;
			delete noeud;
		}
		this->m_debut = nullptr;
		this->m_fin = nullptr;
		this->m_nombreMaillons = 0;
	}

	void ajouterDebut(const int& p_valeur) {
		Node<TypeElement>* noeudDebut = new Node<TypeElement>(p_valeur, this->m_debut);
		this->m_debut = noeudDebut;
		if (this->m_nombreMaillons == 0) {
			this->m_fin = noeudDebut;
		}
		++this->m_nombreMaillons;
	}

	Node<TypeElement>* nodePrecedent(const int& p_indice) {
		Node<TypeElement>* noeudPrecedent = this->m_debut;
		int compteur = 0;
		if (indice > 0) {
			compteur = p_indice - 1;
		}
		while (compteur) {
			if (this->m_nombreMaillons == 0) {
				std::invalid_argument("la liste est vide");
			}
			noeudPrecedent = noeudPrecedent->m
		}
	}

private:
	int m_nombreMaillons;
	Node<TypeElement>* m_debut;
	Node<TypeElement>* m_fin;
};
