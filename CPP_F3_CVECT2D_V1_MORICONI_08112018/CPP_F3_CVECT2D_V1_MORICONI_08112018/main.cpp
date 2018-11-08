#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include "cVect2D.h"


using namespace std;

int main(int argc, char * argv[])
{

	//Je déclare deux vecteurs : u et, auxquels je passe des paramètres
	CVect2D u(2.2f, 3.3f);
	CVect2D v(1.1f, 4.4f);

	
	/**** Addition vectorielle ****/
	CVect2D uv;
	uv.sumVect(u, v);

	//Affichage
	cout << "**** Addition vectorielle ****" << endl;
	cout << uv.getVectX() << endl;
	cout << uv.getVectY() << endl;


	/**** Soustraction vectorielle ****/
	uv.subVect(u, v);

	//Affichage
	cout << "**** Soustraction vectorielle ****" << endl;
	cout << uv.getVectX() << endl;
	cout << uv.getVectY() << endl;


	/**** Produit vectoriel de deux vecteurs ****/
	uv.multVect(u, v);

	//Affichage
	cout << "**** Multiplication vectorielle ****" << endl;
	cout << uv.getVectX() << endl;
	cout << uv.getVectY() << endl;


	/**** Multiplication d'un vecteur par un scalaire ****/
	float r = 10.0f;
	u.multScal(r);
	
	//Affichage
	cout << "**** Multiplication d'un vecteur par un scalaire ****" << endl;
	cout << u.getVectX() << endl;
	cout << u.getVectY() << endl;

	/**** Produit des normes ****/
	//Je réinitialise u et v à leurs paramètres d'origine
	u.setVectX(2.2f);
	u.setVectY(3.3f);
	v.setVectX(1.1f);
	v.setVectY(4.4f);

	//Je déclare un réel qui recevra mon produit scalaire
	float norme = 0.0f;

	norme = u.multNorm(v);

	//Affichage
	cout << "**** Produit des normes ****" << endl;
	cout << norme << endl;

	return 0;
}