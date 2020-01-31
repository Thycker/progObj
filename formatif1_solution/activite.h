#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;
class Activite
{
private:
	string codeActivite;
	string titre;
	string responsable;
public:
	Activite();
	Activite(string inCodeActivite, string inTitreActivite, string inResponsable);
	string getCodeActivite()const;
	string getTitre()const;
	string getResponsable()const;
	//void setCodeActivite(string inCodeActivite);
	//void setTitre(string inTitre);
	//void setResponsable(string inResponsable);
	void InitialiserActivite(string, string);
	void AssignerResponsable(string);
};

#endif