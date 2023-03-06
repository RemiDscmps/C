# include "biblio.h"


void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}

int rechercherLivre(T_Bibliotheque *ptrB)
{
int i;
int NrbLvrCorspd = 0; //Nombre de livres correspondant au titre donné
T_Titre titre;
lireChaine("Saisissez le titre du livre recherché", titre, MAX_TITRE);
for (i = 0 ; i < ptrB->nbLivres ; i++){
	if(strcmp(ptrB->etagere[i].titre, titre) == 0)
		NrbLvrCorspd++;
}
return NrbLvrCorspd;

}

int rechercherAuteur(T_Bibliotheque *ptrB){
	int i;
	int test = 0;
	T_Aut auteur;
	lireChaine("Saisissez l'auteur recherché", auteur, MAX);
	for (i = 0 ; i < ptrB->nbLivres ; i++){
		if(strcmp(ptrB->etagere[i].auteur, auteur) == 0){
			test = 1;
			afficherChaine("\n Titre:", ptrB->etagere[i].titre);
		}
	}

return test ;

}	
	
	
int supprimerLivre(T_Bibliotheque *ptrB){
	int i;
	int test = 0;
	T_Titre titre;
	lireChaine("Saisissez le titre du livre à supprimer", titre, MAX_TITRE);
	for (i = 0 ; i < ptrB->nbLivres ; i++){
		if (strcmp(ptrB->etagere[i].titre, titre) == 0){
			ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres - 1];
			ptrB->nbLivres = ptrB->nbLivres - 1 ;
			test = 1;
		}
	}
	return test ;

}

int emprunter(T_Bibliotheque *ptrB){
	int i;
	int test = 0;
	T_Emp Emp;
	T_Titre titre;
	lireChaine("Saisissez le titre du livre à emprunter", titre, MAX_TITRE);
	for (i = 0 ; i < ptrB->nbLivres ; i++){
		if (strcmp(ptrB->etagere[i].titre, titre) == 0){
			if (ptrB->etagere[i].emprunteur.nomemprunteur[0] == '\0'){
				lireChaine("Saisissez le nom de l'emprunteur", Emp.nomemprunteur, MAX);
				strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, Emp.nomemprunteur);
				test = 1 ;
			}
		}
	}
	return test;
	
}
	
int rendreLivre(T_Bibliotheque *ptrB){
	int i;
	int test = 0;
	T_Titre titre;
	lireChaine("Saisissez le titre du livre à rendre", titre, MAX_TITRE);
	for (i = 0 ; i < ptrB->nbLivres ; i++){
		if (strcmp(ptrB->etagere[i].titre, titre) == 0){
			if (ptrB->etagere[i].emprunteur.nomemprunteur[0] != '\0'){
				strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, "\0");
				test = 1;
			}
		}
	}
	return test;
	
}
	

int TrierTitres(T_Bibliotheque *ptrB){
	
	
	
	

}
	
