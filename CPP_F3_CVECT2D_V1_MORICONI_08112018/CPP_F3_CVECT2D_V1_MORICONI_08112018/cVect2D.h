#pragma once

class CVect2D {

	//Données membres
private:						//Quand on crée une classe, si on ne précise pas la méthode d'encapsulation, d'office les Données membres sont privées
	float m_fltX;
	float m_fltY;

	//Fonctions membres
public:

	//Assesseurs
	float getVectX()const;
	float getVectY()const;

	//Mutateurs
	void setVectX(float fltX);
	void setVectY(float fltY);

	//Constructeur sans paramètre
	CVect2D();

	//Constructeur avec paramètres
	CVect2D(float fltX, float fltY);

	//Constructeur avec paramètres par défaut
	CVect2D(float fltZero);

	//Méthodes de calcul
	void sumVect(CVect2D u, CVect2D v);
	void subVect(CVect2D u, CVect2D v);
	void multVect(CVect2D u, CVect2D v);
	void multScal(float r);
	float multNorm(CVect2D v);

};