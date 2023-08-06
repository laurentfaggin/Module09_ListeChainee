#include "node.h"

node::node(int p_donnee) {
	m_donnee = p_donnee;
	m_suivant = nullptr;
}

node::node(int p_donnee, node* p_suivant) {
	m_donnee = p_donnee;
	m_suivant = p_suivant;
}

node::~node() {
	if (this->m_suivant != nullptr) {
		delete this->m_suivant;
		this->m_suivant = nullptr;
	}
}

int node::obtenir() const {
	return m_donnee;
}