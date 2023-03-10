#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherLivre(T_Bibliotheque *ptrB);
int rechercherAuteur(T_Bibliotheque *ptrB);
int supprimerLivre(T_Bibliotheque *ptrB);
int emprunter(T_Bibliotheque *ptrB);
int rendreLivre(T_Bibliotheque *ptrB);
int TrierTitres(T_Bibliotheque *ptrB);


#endif
