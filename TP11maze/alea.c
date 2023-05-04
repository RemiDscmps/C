#include <time.h>
#include <stdio.h>
#include <stdlib.h>


//programme qui tire 30 nombres au hasard
int main()
{

srand(time(NULL)); //initialisation du generateur de nombre aleatoire 
int haz,i;


for(i=0;i<30;i++)
{  
 haz=rand() % 100; //rand() renvoie une grande valeur mais celle ci est divisée par 100 et le reste de cette division est rangée dans haz (on a donc : 0<=haz<100)
 printf("%d ",haz);
}

return 0;
}
