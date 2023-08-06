#pragma once

class node {
public:
	node(int p_donnee);
	node(int p_donnee, node* p_suivant);
	~node();
	int obtenir() const;
	node* m_suivant;
private:
	int m_donnee;
};
