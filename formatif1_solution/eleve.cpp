#include "eleve.h"
#include <conio.h>

Eleve::Eleve()
{
	codeEleve = "";
	nom = "";
	prenom = "";
	activite = NULL;
}

Eleve::Eleve(string inCodeEleve, string inNom, string inPrenom)
{
	codeEleve = inCodeEleve;
	nom = inNom;
	prenom = inPrenom;
	activite = NULL;
}

string Eleve::getCodeEleve()const
{
	return codeEleve;
}

string Eleve::getNom()const
{
	return nom;
}

string Eleve::getPrenom()const
{
	return prenom;
}
Activite* Eleve::getActivite()const
{
	return activite;
}

void Eleve::InscrireEleve(string inCodeEleve, string inNom, string inPrenom)
{
	
	codeEleve = inCodeEleve;
	nom = inNom;
	prenom = inPrenom;
	activite = NULL;
}

void Eleve::InscrireAUneActivite(Activite* inActivite)
{
	activite = inActivite;
}