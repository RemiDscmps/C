#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
	ptrF->Tete = -1;
	ptrF->Queue = -1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
	if(! fileVide(ptrF)){
		affecterElt(ptrE, ptrF->Elts + ptrF->Tete);
		ptrF->Tete = ptrF->Tete + 1;
		if(ptrF->Tete == ptrF->Queue + 1){ptrF->Tete = -1; ptrF->Queue = -1;}
		if(ptrF->Tete == MAX) ptrF->Tete = 0;
		return 1;
	}
	return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
	if(filePleine(ptrF) == 0){
		if(ptrF->Tete == -1)ptrF->Tete = 0;
		ptrF->Queue = ptrF->Queue + 1;
		if(ptrF->Queue == MAX) ptrF->Queue = 0;
		affecterElt(ptrF->Elts + ptrF->Queue,ptrE);
		return 1;
	}
	return 0;
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
	if(ptrF->Tete == ptrF->Queue && ptrF->Tete == -1 )return 1;	
	return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
	if((ptrF->Tete - ptrF->Queue == 1 )||(ptrF->Tete == 0 && ptrF->Queue == MAX - 1)) return 1;
	return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
	if(! fileVide(ptrF))return ptrF->Elts[ptrF->Tete];
	return 0;
}

void afficherFile(T_File *ptrF)
{
	T_File aux;
	T_Elt elt;
	initFile(&aux);
	while(!fileVide(ptrF)){
		retirer(ptrF,&elt);
		afficherElt(&elt);
		ajouter(&aux,&elt);
	}
	*ptrF = aux;
}






