#define TAILLE 50

#define  NB_MAX_PRODUITS 1000


typedef struct 
{
unsigned int reference;
char libelle[TAILLE];
float prixU;
} T_Produit;

typedef struct
{
	int ref;
	int stock;
} T_Stock;

typedef T_Stock T_Stock_Total[NB_MAX_PRODUITS];

typedef T_Produit T_TableauDeProduits[ NB_MAX_PRODUITS];




