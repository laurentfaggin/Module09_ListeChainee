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
	node* noeudListeACopier = p_listeACopier.m_debut;
	while (noeudListeACopier != nullptr) {
		node* noeudCopie = new node(noeudListeACopier->obtenir());
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

