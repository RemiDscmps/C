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

int verifStock(int ref, int qtt){
	T_Stock_Total stock;
	int i = 0, j, k;
	FILE *ficStock = NULL, *ficAlert= NULL;
	ficStock = fopen("./stock.txt","rt");
	ficAlert = fopen("./alertes.txt", "wt");
	while(! feof(ficStock)){ fscanf(ficStock,"%d %d",&stock[i].ref,&stock[i].stock); i++;}
	fclose(ficStock);
	for(j = 0; j < i; j++){
		if(ref == stock[j].ref){
			if(qtt <= stock[j].stock){
				if(qtt == stock[j].stock){
					fprintf(ficAlert, "Attention plus de stock pour l'objet portant la référence :%d \n", stock[j].ref);
				}
				stock[j].stock = stock[j].stock - qtt;
				ficStock = fopen("./stock.txt","wt");
				fprintf(ficStock,"%d %d", stock[0].ref, stock[0].stock);
				for(k = 1; k < i; k++){
					fprintf(ficStock,"\n%d %d", stock[k].ref, stock[k].stock);
				}
				fclose(ficStock);
				fclose(ficAlert);
				return 1;
			}
			return 0;
		}
	}
}

void lireCommande(char *nomCommande){
	char nomFacture[30], nomClient[20];
	int ref, qtt, refp; 
	float total	= 0;
	FILE *fic = NULL, *ficCommande = NULL, *ficFacture = NULL;
	int i = 0, j = 0;
	T_TableauDeProduits Tableau;
	strcpy(nomFacture,"./factures/facture");
	strcat(nomFacture,nomCommande + strlen("./commandes/commande"));
	fic = fopen("./produits.txt","rt");
	while(! feof(fic)){ fscanf(fic,"%d %s %f",&Tableau[i].reference,Tableau[i].libelle,&Tableau[i].prixU); i++;}
	fclose(fic);
	ficCommande = fopen(nomCommande,"rt");
	ficFacture = fopen(nomFacture,"wt");
	fscanf(ficCommande,"%s",nomClient);
	fprintf(ficFacture, "Client : %s\n",nomClient);
	while(! feof(ficCommande)){
		fscanf(ficCommande,"%d %d",&ref,&qtt);
		if (ref != refp){
		for(j = 0; j < i; j++){
			if(ref == Tableau[j].reference){
				if(verifStock(ref,qtt)){
				fprintf(ficFacture,"%d %s  (PU=%f€) :: %f€\n",qtt,Tableau[j].libelle,Tableau[j].prixU,Tableau[j].prixU * qtt);
				total = total + Tableau[j].prixU * qtt;}
				else {fprintf(ficFacture,"%s : stock non suffisant\n", Tableau[j].libelle); printf("\n Stock insuffisant");}
			}
		refp = ref;
		}
	}
	}
	fprintf(ficFacture,"\t\tTOTAL = %f€",total);
	fclose(ficCommande);
	fclose(ficFacture);
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
			fclose(ficCommande);
			lireCommande(nomCommande); // à vous de coder cette fonction lors de ce TP9
			
		}
	else
		{
			printf("\n toutes les commandes presentes ont ete traitees.\n");
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
	
	/*
	
	*/

	//PARTIE 1 du TP : sans Gestion de stock
	lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)	
	

	//PARTIE 2 du TP : avec Gestion de stock
	//copiez coller votre travail précédent puis modifiez le  
	//lireLesCommandes2(); 	
	/*
	FILE *f;int N=1;
	f=fopen("nextFact","w");
	fwrite(&N,1,sizeof(int),f);
	fclose(f);
	*/
	return 0;
}