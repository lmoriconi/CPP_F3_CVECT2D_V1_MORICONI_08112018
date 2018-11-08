#pragma once

class CVect2D {

	//Donn�es membres
private:						//Quand on cr�e une classe, si on ne pr�cise pas la m�thode d'encapsulation, d'office les Donn�es membres sont priv�es
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

	//Constructeur sans param�tre
	CVect2D();

	//Constructeur avec param�tres
	CVect2D(float fltX, float fltY);

	//Constructeur avec param�tres par d�faut
	CVect2D(float fltZero);

	//M�thodes de calcul
	void sumVect(CVect2D u, CVect2D v);
	void subVect(CVect2D u, CVect2D v);
	void multVect(CVect2D u, CVect2D v);
	void multScal(float r);
	float multNorm(CVect2D v);

};