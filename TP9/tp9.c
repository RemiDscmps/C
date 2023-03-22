// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"


int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier file.c");
printf("\n 2 : tester mon fichier pile.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_File mafile;
T_Pile mapile;
int chx;
int i, test;
// int taille;
//char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		initFile(&mafile);
		while(ajouter(&mafile,&i)){i = i * 2 + 3;}
		afficherFile(&mafile);
		//testez toutes vos fonctions par un jeu de test de votre choix
		//testPile(&mapile); //TP9 partie 1 : à ecrire 
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		// testFile(&mafile); //TP9 partie 1 : à ecrire 

		initPile(&mapile);
		printf("1 = %d \n", pilevide(&mapile));//test initpile et pile vide
		mapile.nbElts =5;
		mapile.Elts[4]=12;
		printf(" 12 = %d \n",sommet(&mapile)); // test sommet
		printf(" 5 = %d \n",hauteur(&mapile)); // test hauteur
		mapile.nbElts =10;
		printf("1 = %d \n", pilepleine(&mapile));//test pilepleine
		initPile(&mapile);
		for(i=0 ; i <= 9 ; i++){
			saisirElt(&test);
			empiler(&mapile,test);
			//printf("%d \n",hauteur(&mapile));
		}
		printf("\nC'EST \n");
		afficherPile(&mapile);//test afficherpile
		printf("\n PLUS CASSE\n");
		for(i=0;i < mapile.nbElts; i++){
			printf("\n");
			printf("%d/ ",mapile.Elts[i]);
		} //test le ré-empilement de mapile àprès afficherpile
		
		break; 
	case 3 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}
