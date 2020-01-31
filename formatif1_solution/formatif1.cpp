#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;
#include "donnees.h"
#include "activite.h" 
#include "eleve.h" 

Donnees lesDonneesDuProgramme;

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();

void Afficher(Activite inActivite);
//partie 2
void AjouterLesEleves();
void AfficherLesEleves();
void InscrireUnEleve(string, string, string);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter tous les eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher tous les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une certaine activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une certaine activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].InitialiserActivite(code, titre);
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau



	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void Afficher(Activite inActivite)
{
	cout << "Code activite: " << inActivite.getCodeActivite() << "\n";
	cout << "Titre: " << inActivite.getTitre() << "\n";
	cout << "Responsable: " << inActivite.getResponsable() << "\n" << "\n";
}

void Afficher(Eleve inEleves)
{
	cout << "Code eleve: " << inEleves.getCodeEleve() << "---";
	cout << " Nom: " << inEleves.getNom() << "  ";
	cout << " Prenom: " << inEleves.getPrenom() << "  ";
	if (inEleves.getActivite() == NULL)
	{
		cout << " Activite: Aucune" << "\n" << "\n";
	}
	else
	{
		cout << " Activite: " << inEleves.getActivite()->getTitre() << "\n" << "\n";
	}
}


void AfficherLesActivites()
{
	int i=0;
	ClrScr();
	for (i = 0; i < nombreActivitesReelles;i++)
	{
		Afficher(lesDonneesDuProgramme.lesActivites[i]);
	}


	_getch();
}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	int i = 0;
	ClrScr();

	for (i = 0; i < nombreElevesReels; i++)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[i]);
	}
	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	lesDonneesDuProgramme.lesEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);
	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);

	if (cptEleve < maxEleves && cptActivite < maxActivites)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
		Afficher(lesDonneesDuProgramme.lesActivites[cptActivite]);
		lesDonneesDuProgramme.lesEleves[cptEleve].InscrireAUneActivite(&lesDonneesDuProgramme.lesActivites[cptActivite]);
	}

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	bool trouve = false;
	int position = 0;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			trouve = true;
			position = cptEleve;
		}
		cptEleve++;
	}
	return position;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = 0;
	int position = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		if (lesDonneesDuProgramme.lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			trouve = true;
			position = cptActivite;
		}
		cptActivite++;
	}
	return position;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	Activite* ActiviteDeEtudiant;
	int cptEleve = 0;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;
	while (cptEleve < maxEleves)
	{
		ActiviteDeEtudiant = lesDonneesDuProgramme.lesEleves[cptEleve].getActivite();
		if (ActiviteDeEtudiant != NULL)
		{
			if (ActiviteDeEtudiant->getCodeActivite() == activite)
			{
				Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
			}
			
		}
		cptEleve++;
		_getch();
	}
}







