#include "node.h"


Node::Node() {
	m_donnee = 0;
	m_suivant = nullptr;
}

Node::Node(int p_donnee) {
	m_donnee = p_donnee;
	m_suivant = nullptr;
}

Node::Node(int p_donnee, Node* p_suivant) {
	m_donnee = p_donnee;
	m_suivant = p_suivant;
}

Node::~Node() {
	if (this->m_suivant != nullptr) {
		delete this->m_suivant;
		this->m_suivant = nullptr;
	}
}

int Node::obtenirValeur() {
	return this->m_donnee;
}

int Node::obtenir() const {
	return m_donnee;
}

void Node::modifierSuivant(Node* p_nouveauSuivant) {
	m_suivant = p_nouveauSuivant;
}
