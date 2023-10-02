/* Fichier : Numero B du TP1
   Auteur : Romain Boiret
   Cours : IFT 1810 section B
   Trimestre : Hiver 2023
   But : Ce programme permet a un utilisateur de saisir le code d'une figure geometrique parmis un cercle, un rectangle ou un carre et de calculer son perimetre ainsi que sa surface.
   		 Si l'utilisateur saisie un caractere qui ne correspond a aucune des figures du programme, celui-ci renvoit un message adapte.
   		 Une fois les donnes saisies par l'utilisateur, celui-ci renvoit les dimensions de la figure avec le perimetre et la surface calcule.
   		 L'utilisateur peut continuer autant de fois que necessaire.
   		 Une fois que l'utilisateur choisi de mettre fin au programme, celui-ci renvoit d'autres informations tel que le nombre de cercle(s), de rectangle(s) et de carre(s) traite(s), mais aussi :
		 	Le perimetre le plus grand des cercles traites ;
		 	Le perimetre moyen des rectangles traites ;
		 	La surface la plus grande des rectangles traites ;
		 	Le cote le plus petit des carres traites.	 
   Derniere mise a jour : 10 Février 2023

*/
	
#include <stdio.h> // fichier d'en-tete d'entree
#include <ctype.h> // pour la fonction toupper
#include <float.h> // pour FLT_MIN

int main()
{
  const float PI = 3.14159 ; // la valeur arrondi de PI	
  char codeFig, reponse ;
  float rayon, longueur, largeur, cote, perimetre, surface ; // variable pour les donnes de figures
  float perimetreCMAX = 0.0 ; // le perimetre le plus grand des cercles traites
  float surfaceRMAX = 0.0 ; // la surface la plus grande des rectangles traites
  float somperimetre, perimetreRMOY = 0.0 ; // le perimetre moyen des rectangles traites
  float coteKMIN = FLT_MAX ; // le cote le plus petit des carres traites
  int nbCercle = 0, nbRectangle = 0, nbcarre = 0 ; // nombre de cercle, derectangle et de carre traites
  
  do // debut de la boucle
  {
  	printf("Tapez c ou C pour un cercle\n") ;
  	printf("Tapez r ou R pour un rectangle\n") ;
  	printf("Tapez k ou K pour un carre\n") ;
  	printf("Quel est le code de la figure ? ") ;
  	scanf(" %c", &codeFig) ;
  	
  	codeFig = toupper(codeFig) ; // conversion en lettre MAJUSCULE
  	
  	switch (codeFig)
  	{         
  	
  	    case 'C'	: // code pour les cercles
  	   	  nbCercle++ ;
  	   	  printf("Tapez le rayon du cercle (ex: 7) : ") ;
  	   	  scanf("%f", &rayon) ;
  	   	  perimetre = 2 * PI * rayon ;
  	   	  surface = PI * rayon * rayon ;
  	   	  printf("Infos du cercle traite :\n") ;
  	   	  printf(" - rayon	: %.1f\n", rayon) ;
  	   	  printf(" - perimetre	: %.2f\n", perimetre) ;
  	   	  printf(" - surface	: %.2f\n", surface) ;
  	   	  
  	   	  if (perimetre > perimetreCMAX)
  	   	       perimetreCMAX = perimetre ;
  	   	  break ;
  	   	  
  	    case 'R' : // code pour les rectangles
		  nbRectangle++ ;
		  printf("Tapez la longueur et la largeur du rectangle (ex: 10 5) : ") ;
		  scanf("%f%f", &longueur, &largeur) ;
		  perimetre = 2 * (longueur + largeur) ;
		  surface = longueur * largeur ;
  	   	  printf("Infos du rectangle traite :\n") ;
  	   	  printf(" - dimension	: longueur %.1f et largeur %.1f\n", longueur, largeur) ;
  	   	  printf(" - perimetre	: %.2f\n", perimetre) ;
  	   	  printf(" - surface	: %.2f\n", surface) ;
  	   	  
		  somperimetre += perimetre ;
		  
  	   	  if (surface > surfaceRMAX)
  	   	       surfaceRMAX = surface ;
		  break;
  	      
  	    case 'K' : // code pour les carres
		  nbcarre++ ;
		  printf("Tapez la longueur des cotes du carre (ex: 8) : ") ;
		  scanf("%f", &cote) ;
		  perimetre = 4 * cote ;
		  surface = cote * cote ;
	  	  printf("Infos du carre traite :\n") ;
	  	  printf(" - cote		: %.1f\n", cote) ;
	  	  printf(" - perimetre	: %.2f\n", perimetre) ;
	  	  printf(" - surface	: %.2f\n", surface) ;
	
	  	  if (cote < coteKMIN)
	  	   	   coteKMIN = cote ;
  	      break ;
  	                
  	    default  : printf(" Code Imprevu\n") ; // message renvoye pour une figure non traitable
					    
	}
	printf("\nAvez-vous une autre figure a traiter ? (o/n) ") ;
	scanf(" %c", &reponse) ;
	  
  } while(toupper(reponse) == 'O') ; // fin de la boucle
	
	/* Informations de fin de boucle */
	
	 /* Pour les cercles */
	 printf("Le nombre de cercle(s) traite(s) : %d\n", nbCercle) ; // message renvoyant le nombre de cercle(s) traite(s)
	        
	 if(nbCercle > 0)        
	     printf("Le perimetre le plus grand des cercles traites : %.2f\n", perimetreCMAX) ;
	 else
	     printf("Pas de cercle traite => pas de perimetre a calculer\n") ;
	 
	 /* Pour les rectangles */
	 printf("Le nombre de rectangle(s) traite(s) : %d\n", nbRectangle) ; // message renvoyant le nombre de rectangle(s) traite(s)
	 
	 if(nbRectangle > 0) 
	     printf("Le perimetre moyen des rectangles traites : %.1f\n", somperimetre / nbRectangle) ;
     else
	     printf("Pas de rectangle traite => pas de perimetre a calculer\n") ;
	
	 if(nbRectangle > 0)        
	     printf("La surface la plus grande des rectangles traites : %.2f\n", surfaceRMAX) ;
     else
	     printf("Pas de rectangle traite => pas de surface a calculer\n") ;

	 /* Pour les carres */
	 printf("Le nombre de carre(s) traite(s) : %d\n", nbcarre) ; // message renvoyant le nombre de carre(s) traite(s)
	        
 	 if(nbcarre > 0)        
	     printf("Le cote le plus petit des carres traites : %.2f\n", coteKMIN) ;
	 else
	     printf("Pas de carre traite => pas de cote a calculer\n") ;
	
	/*
		Auteur : Romain Boiret IFT 1810 B, hiver 2023
		Date : 12 Février 2023 à 23h59
	*/
    
	return 0;   
}

/* Execution:
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? c
Tapez le rayon du cercle (ex: 7) : 7.5
Infos du cercle traite :
 - rayon        : 7.5
 - perimetre    : 47.12
 - surface      : 176.71

Avez-vous une autre figure a traiter ? (o/n) o
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? r
Tapez la longueur et la largeur du rectangle (ex: 10 5) : 9.2 4.8
Infos du rectangle traite :
 - dimension    : longueur 9.2 et largeur 4.8
 - perimetre    : 28.00
 - surface      : 44.16

Avez-vous une autre figure a traiter ? (o/n) o
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? c
Tapez le rayon du cercle (ex: 7) : 8.3
Infos du cercle traite :
 - rayon        : 8.3
 - perimetre    : 52.15
 - surface      : 216.42

Avez-vous une autre figure a traiter ? (o/n) o
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? R
Tapez la longueur et la largeur du rectangle (ex: 10 5) : 5.3 3.7
Infos du rectangle traite :
 - dimension    : longueur 5.3 et largeur 3.7
 - perimetre    : 18.00
 - surface      : 19.61

Avez-vous une autre figure a traiter ? (o/n) o
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? C
Tapez le rayon du cercle (ex: 7) : 3.9
Infos du cercle traite :
 - rayon        : 3.9
 - perimetre    : 24.50
 - surface      : 47.78

Avez-vous une autre figure a traiter ? (o/n) o
Tapez c ou C pour un cercle
Tapez r ou R pour un rectangle
Tapez k ou K pour un carre
Quel est le code de la figure ? r
Tapez la longueur et la largeur du rectangle (ex: 10 5) : 15.1 5.9
Infos du rectangle traite :
 - dimension    : longueur 15.1 et largeur 5.9
 - perimetre    : 42.00
 - surface      : 89.09

Avez-vous une autre figure a traiter ? (o/n) n
Le nombre de cercle(s) traite(s) : 3
Le perimetre le plus grand des cercles traites : 52.15
Le nombre de rectangle(s) traite(s) : 3
Le perimetre moyen des rectangles traites : 29.3
La surface la plus grande des rectangles traites : 89.09
Le nombre de carre(s) traite(s) : 0
Pas de carre traite => pas de cote a calculer

--------------------------------
Process exited after 143.1 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
