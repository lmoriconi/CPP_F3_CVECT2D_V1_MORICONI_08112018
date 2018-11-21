#include "cVect2D.h"
#include <math.h>

float CVect2D::getVectX()const {

	return m_fltX;
}

float CVect2D::getVectY()const {

	return m_fltY;
}

void CVect2D::setVectX(float fltX) {

	m_fltX = fltX;
}

void CVect2D::setVectY(float fltY) {

	m_fltY = fltY;
}

CVect2D::CVect2D() {

	m_fltX = 0.0f;
	m_fltY = 0.0f;
}

CVect2D::CVect2D(float fltX, float fltY) {

	m_fltX = fltX;
	m_fltY = fltY;
}

CVect2D::CVect2D(float fltZero = 0.0f) {

	m_fltX = fltZero;
	m_fltY = fltZero;
}

void CVect2D::sumVect(CVect2D u, CVect2D v) {

	//Je récupère les valeurs x et y de u et v...
	float ux = u.getVectX();
	float uy = u.getVectY();
	float vx = v.getVectX();
	float vy = v.getVectY();

	//... puis je les additionne
	m_fltX = ux + vx;
	m_fltY = uy + vy;

}

void CVect2D::subVect(CVect2D u, CVect2D v) {

	//Je récupère les valeurs x et y de u et v...
	float ux = u.getVectX();
	float uy = u.getVectY();
	float vx = v.getVectX();
	float vy = v.getVectY();

	//... puis je les soustraits
	m_fltX = ux - vx;
	m_fltY = uy - vy;
}

void CVect2D::multVect(CVect2D u, CVect2D v) {

	//Je récupère les valeurs x et y de u et v...
	float ux = u.getVectX();
	float uy = u.getVectY();
	float vx = v.getVectX();
	float vy = v.getVectY();

	//... puis je les multiplie
	m_fltX = ux * vx;
	m_fltY = uy * vy;
}

void CVect2D::multScal(float r) {

	//Je multiplie mon vecteur par le scalaire
	m_fltX *= r;
	m_fltY *= r;
}

float CVect2D::multNorm(CVect2D v) {

	//Je récupère les valeurs x et y de v...

	float vx = v.getVectX();
	float vy = v.getVectY();

	//... puis je multiplie les normes
	return sqrt(pow(vx - this->m_fltX, 2) + pow(vy - this->m_fltY, 2));
}

CVect2D::~CVect2D() {}