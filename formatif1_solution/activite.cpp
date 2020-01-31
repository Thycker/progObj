#include "activite.h"
Activite::Activite()
{
	codeActivite = "";
	titre = "";
	responsable = "";
}

Activite::Activite(string inCodeActivite, string inTitreActivite, string inResponsable)
{
	codeActivite = inCodeActivite;
	titre = inTitreActivite;
	responsable = inResponsable;
}

string Activite::getCodeActivite()const
{
	return codeActivite;
}

string Activite::getTitre()const
{
	return titre;
}

string Activite::getResponsable()const
{
	return responsable;
}

void Activite::InitialiserActivite(string inCodeActivite, string inTitre)
{
	codeActivite = inCodeActivite;
	titre = inTitre;
}

void Activite::AssignerResponsable(string inResponsable)
{
	responsable = inResponsable;
}