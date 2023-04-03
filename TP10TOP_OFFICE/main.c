////////////////////////// TP10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prod.h"

int lireProchaineCommande() //pour lire l'int contenu dans nextFact
{
FILE *f;
int N;
f=fopen("nextFact","r");
fread(&N,sizeof(int),1,f);
fclose(f);
//printf("\n--->lu N=%d",N);
return N;
}

void convertirNenChaine4(int N,char *N4) //convertit l'int N en une chaine de 4 caracteres
{ // si N=1234 alors N4 sera égal à "1234"
int m,c,d,u;
char cm,cc,cd,cu;
m=N/1000;cm=48+m;
N%=1000;
c=N/100;cc=48+c;
N%=100;
d=N/10;cd=48+d;
u=N%10;
cu=48+u;
N4[0]=cm;N4[1]=cc;N4[2]=cd;N4[3]=cu;N4[4]='\0';
}

void lireCommande(char *nomCommande){
	char nomFacture[30];
	int i=0, j, N, ref, refp, qtt;
	float total = 0 ;
	T_TableauDeProduits Tabprod;
	char NNNN[5];
	char nom[30];
	FILE *ficcommande;
	FILE *ficproduits;
	FILE *ficfacture;
	strcpy(nomFacture,"./factures/facture");
	strcat(nomFacture, nomCommande + strlen(".commandes/commande"));
	printf("%s", nomFacture);
	ficcommande=fopen(nomCommande,"rt");
	ficproduits=fopen("produits.txt","rt");
	fscanf(ficcommande,"%s",nom);
	printf("%s", nom);
	ficfacture=fopen(nomFacture,"wt");
	fprintf(ficfacture,"Client : %s \n \n", nom);
	while(!feof(ficproduits)){
		fscanf(ficproduits, "%d %s %f", &Tabprod[i].reference, Tabprod[i].libelle, &Tabprod[i].prixU);
		i++;
	}
	while(!feof(ficcommande)){
		fscanf(ficcommande,"%d %d",&ref,&qtt);
		if(refp!=ref){
			for(j=0 ; j<i ; j++){
				if(ref == Tabprod[j].reference){
					fprintf(ficfacture, "%d %s (PU=%4f$)	\t%f \n", qtt, Tabprod[j].libelle, Tabprod[j].prixU, qtt * Tabprod[j].prixU);
					total = total + qtt*Tabprod[j].prixU;
					refp = ref;
				}
			}
		}
		
	}
	fprintf(ficfacture, "\t\tTOTAL = %f" , total);
	fclose(ficcommande);
	fclose(ficfacture);
	fclose(ficproduits);

}

void lireLesCommandes() //cette fonction ouvre tous les fichiers commandeXXX.txt avec XXXX démarrant à N
{
FILE *ficCommande=NULL;
int FINI=0;
int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
char NNNN[5];
char nomCommande[29];

do //ce do while prend fin dès que fichier commandeXXXX.txt est absent 
	{
	strcpy(nomCommande,"./commandes/commande");
	convertirNenChaine4(N,NNNN); 
	//printf("\n==>%s<==",NNNN);
	ficCommande=NULL;
	strcat(nomCommande,NNNN);
	strcat(nomCommande,".txt");
	
	//printf("\n traitement de  %s",nomCommande);
	
	ficCommande=fopen(nomCommande,"rt");
	if (ficCommande!=NULL)
		{ // le fichier commandeNNNN.txt existe
			printf("\n fichier %s present",nomCommande);
			lireCommande(nomCommande); // à vous de coder cette fonction lors de ce TP9
			fclose(ficCommande);
		}
	else
		{
			printf("\n toutes les commandes presentes ont ete traitees. \n");
			FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact 
			// pour 
			fwrite(&N,1,sizeof(int),f);
			fclose(f);
			FINI=1;			
		}

	N++;
	}while(FINI==0);		

}



int main()
{
	//creation d un fichier d'un seul int nommé nextFact et contenant l'int 1
	// code à utiliser pour réinitialiser nextFact à 1 si besoin au cours du TP 
	
	
	FILE *f;int N=1;
	f=fopen("nextFact","w");
	fwrite(&N,1,sizeof(int),f);
	fclose(f);
	

	//PARTIE 1 du TP : sans Gestion de stock
	lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)	
	

	//PARTIE 2 du TP : avec Gestion de stock
	//copiez coller votre travail précédent puis modifiez le  
	//lireLesCommandes2(); 	

	return 0;
}
