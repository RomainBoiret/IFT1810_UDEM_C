/* Fichier : Numero B du TP2
   Auteur : Romain Boiret
   Cours : IFT 1810 section B
   Trimestre : Hiver 2023
   But : Ce programme permet d'afficher le contenu de trois tableaux chacun regroupant les donnees differentes d'une entreprise (postes, nombre de cafes consommes par personne, age de chaque employe).
   		 Puis, d'effectuer des analyses comme par exemple de compter et d'afficher le nombre de secretaires (voir Bloc 3) ou encore de determiner et d'afficher la consommation maximale de cafe des analystes (voir Bloc 4).
   		 A la fin, le programme tri toutes les donnees en fonction de l'age des employes du plus jeune au plus vielle employe.
   Derniere mise a jour : 13 Mars 2023

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{ 
  char poste[] = { 'P', 'P', 'O', 'A', 'P', 'A', 'O', 'A' };
  int nbCafe[]= { 2, 1, 7, 0, 5, 2, 1, 3 },
        age[] = { 25, 19, 27, 36, 54, 24, 56, 29  } ;
  int nbPers = sizeof(poste) / sizeof(char);
  int i, j, indMin, tempo, nbAnalystes, nbSecretaires, nbOperateurs, nbEmployes;
  char tempoPoste, temponbCafe;
  
  /* Bloc 1 : afficher le contenu de 3 tableaux : */          
  printf("Contenu des 3 tableaux au debut\n");
  printf("indice	nbCafe  age	poste\n");
  for ( i = 0; i < nbPers; i++)
  {
    printf("%d	%d	%d", i, nbCafe[i], age[i]);
    switch (poste[i])
    {
        case 'P' : printf("	programmeur\n"); break;
        case 'O' : printf("	operateur\n"); break;
        case 'A' : printf("	analyste\n"); break;
	}
   }
  printf("\n");  
  
  /* Bloc 2 : compter + afficher le nombre d'analystes : */   
  nbAnalystes = 0 ;   
 
  for( i = 0 ; i < nbPers ; i++ )
     if (poste[i] == 'A')
        nbAnalystes++;
  printf("Le nombre d'analystes : %d\n", nbAnalystes);

  /* Bloc 3 : compter + afficher le nombre de secretaires : */   
  nbSecretaires = 0;   
 
  for(i = 0 ; i < nbPers ; i++)
      if (poste[i] == 'S')
    	  nbSecretaires++;
  printf("Le nombre de secretaires : %d\n", nbSecretaires);

  /* Bloc 4 : determiner + afficher la consommation maximale de cafe des analystes : */
  int consoCafeAMax = -INT_MAX;
	for(i = 0; i < nbPers; i++)
	    if (poste[i] == 'A' & nbCafe[i] > consoCafeAMax)
	        consoCafeAMax = nbCafe[i];
	printf("La consommation maximale de cafe des analystes : %d\n", consoCafeAMax) ;
	
  /* Bloc 5 : determiner + afficher l’age minimal des programmeurs : */  
  int agePMin = INT_MAX;
	for(i = 0; i < nbPers; i++)
	    if (poste[i] == 'P' & age[i] < agePMin)
	        agePMin = age[i];
	printf("L'age minimal des programmeurs : %d\n", agePMin);
	
  /* Bloc 6 : calculer + afficher la consommation moyenne de cafe des operateurs : */
  nbOperateurs = 0;   
 
  for(i = 0 ; i < nbPers ; i++)
      if(poste[i] == 'O')
    	 nbOperateurs++;
  
  int consoCafeOMoy;
  int sommeCafeO = 0;
  	for(i = 0; i < nbPers; i++)
  	    if(poste[i] == 'O')
  		   sommeCafeO = sommeCafeO + nbCafe[i];
  
  consoCafeOMoy = sommeCafeO / nbOperateurs;
  printf("La consommation moyenne de cafe des operateurs : %d\n", consoCafeOMoy);
  
  /* Bloc 7 : calculer + afficher l’age moyen de tous les employes : */
  nbEmployes = 0;
  
  for(i = 0 ; i < nbPers ; i++)
  	  if(poste[i] == 'A' || poste[i] == 'P' || poste[i] == 'O')
  	  	 nbEmployes++;

  float AgeEMoy;
  float sommeAgeE = 0;
  	for(i = 0; i < nbPers; i++)
  	    if(poste[i] == 'A' || poste[i] == 'P' || poste[i] == 'O')
		   sommeAgeE = sommeAgeE + age[i];
		 
  AgeEMoy = sommeAgeE / nbEmployes;
  printf("L'age moyen de tous les employes : %.2f\n", AgeEMoy);
  printf("\n");
    
  /* Bloc 8 : trier selon les ages et reafficher les 3 tableaux : */
  for (i = 0; i < nbPers-1 ; i++)
  {
    indMin = i ;
    for (j = i+1; j < nbPers; j++)
        if (age[j] < age[indMin])
                indMin = j;
    if(indMin != i)
    {
        tempo = age[i];
        age[i] = age[indMin];
        age[indMin] = tempo;
            
        tempoPoste = poste[i];
        poste[i] = poste[indMin];
        poste[indMin] = tempoPoste;
        
        temponbCafe = nbCafe[i];
        nbCafe[i] = nbCafe[indMin];
        nbCafe[indMin] = temponbCafe;
    }             
        
  }
  /* afficher les tableaux apres le tri : */
  printf("Contenu des 3 tableaux apres le tri\n");
  printf("indice	nbCafe  age	poste\n");
  for ( i = 0; i < nbPers; i++)
  {
    printf("%d	%d	%d", i, nbCafe[i], age[i]);
    switch (poste[i])
    {
        case 'P' : printf("	programmeur\n"); break;
        case 'O' : printf("	operateur\n"); break;
        case 'A' : printf("	analyste\n"); break;
	}
   }
  printf("\n");   
  
  return 0;   
}
/* Execution:
Contenu des 3 tableaux au debut
indice  nbCafe  age     poste
0       2       25      programmeur
1       1       19      programmeur
2       7       27      operateur
3       0       36      analyste
4       5       54      programmeur
5       2       24      analyste
6       1       56      operateur
7       3       29      analyste

Le nombre d'analystes : 3
Le nombre de secretaires : 0
La consommation maximale de cafe des analystes : 3
L'age minimal des programmeurs : 19
La consommation moyenne de cafe des operateurs : 4
L'age moyen de tous les employes : 33.75

Contenu des 3 tableaux apres le tri
indice  nbCafe  age     poste
0       1       19      programmeur
1       2       24      analyste
2       2       25      programmeur
3       7       27      operateur
4       3       29      analyste
5       0       36      analyste
6       5       54      programmeur
7       1       56      operateur


--------------------------------
Process exited after 0.04529 seconds with return value 0
Appuyez sur une touche pour continuer...
*/    
