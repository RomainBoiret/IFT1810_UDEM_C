/* Fichier : Numero A du TP2
   Auteur : Romain Boiret
   Cours : IFT 1810 section B
   Trimestre : Hiver 2023
   But : Ce programme permet de calculer la somme 1 (S1 = 25 + 35 + . . . + 95 + 105) à l'aide de deux types de boucles : une boucle 'while' et une boucle 'for'.
   		 Et de calculer la somme 2 (S2 = 1/5 + 1/7 + 1/9 + . . . + 1/9999) à l'aide de deux types de boucles : une boucle 'do ... while' et une boucle 'for'.
   Derniere mise a jour : 13 Mars 2023

*/

#include <stdio.h> // fichier d'en-tete d'entree

int main()
{   
    /* initialisation des constantes pour la somme 1 (somme1 = 25 + 35 + . . . + 95 + 105) */
	const int BORNE1 = 25,
              BORNE2 = 105,
              LE_PAS1 = 10;
    /* initialisation des constantes pour la somme 2 (somme2 = 1/5 + 1/7 + 1/9 + . . . + 1/9999) : */   
	const int BORNE3 = 5,
              BORNE4 = 9999,
              LE_PAS2 = 2;
    /* initialisation des variables : */      
    float somme1, valeur1;
	float somme2, valeur2;

    /* boucle while pour la somme 1 : */
    somme1 = 0;
	valeur1 = BORNE1;
	while (valeur1 <= BORNE2)
	{ somme1 += valeur1 ;
	  valeur1 += LE_PAS1;
	
    } 
    printf("Avec la boucle        while, la somme 1 vaut : %.0f\n", somme1);
    
    /* boucle do ... while pour la somme 2 : */
	somme2 = 0;   
	valeur2 = 5;
	do
	{ somme2 += 1/valeur2;
	  valeur2 += LE_PAS2;
    
	} while (valeur2 <= BORNE4);
    printf("Avec la boucle do ... while, la somme 2 vaut : %f\n", somme2);

    /* boucle for pour les sommes 1 et 2 : */
    somme1 = 0 ;
	for (valeur1 = BORNE1; valeur1 <= BORNE2; valeur1 += LE_PAS1) // pour la somme 1
	     somme1 += valeur1 ;
	  
    printf("Avec la boucle for...      , la somme 1 vaut : %.0f\n", somme1);
    
    somme2 = 0 ;
	for (valeur2 = BORNE3; valeur2 <= BORNE4; valeur2 += LE_PAS2) // pour la somme 2
	     somme2 += 1/valeur2 ;
	  
    printf("Avec la boucle for...      , la somme 2 vaut : %f\n", somme2);

	return 0;
}
/* Execution :
Avec la boucle        while, la somme 1 vaut : 585
Avec la boucle do ... while, la somme 2 vaut : 3.907017
Avec la boucle for...      , la somme 1 vaut : 585
Avec la boucle for...      , la somme 2 vaut : 3.907017

--------------------------------
Process exited after 0.04048 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
