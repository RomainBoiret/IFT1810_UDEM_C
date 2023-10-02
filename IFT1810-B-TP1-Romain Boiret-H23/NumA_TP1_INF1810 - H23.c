/* Fichier : Numero A du TP1
   Auteur : Romain Boiret
   Cours : IFT 1810 section B
   Trimestre : Hiver 2023
   But : Ce programme permet a un utilisateur de saisir ses donnees corporelles (poids en kg et taille en m) et de calculer son indice de masse corporelle (IMC) et de lui dire s'il est en bonne santee ou non.
   		 Une fois le poids et la taille saisie, le programme calcule l'IMC de l'utilisateur et le lui renvoit avec un petit commentaire qui varie en fonction de la valeur de son IMC.
		 Ce commentaire dit à l'utilisateur s'il est en état de maigreur, d'obesite ou en bonne santee avec son risque de developper une maladie.
		 L'utilisateur peut continuer autant de fois que necessaire.
		 Une fois que l'utilisateur choisi de mettre fin au programme, celui-ci renvoit le nombre de personne(s) traite(s).
   Derniere mise a jour : 10 Février 2023

*/
		
#include <stdio.h> // fichier d'en-tete d'entree

int main()
{
  /* nombre pour le poids et la taille */
  float nbPoids ; // poids de la personne
  float nbTaille ; // taille de la personne
  float imc ; // indice de masse corporelle
  int nbPatient = 0 ; // debut de la boucle
	 
  char reponse ; // Si le patient souhaite continuer ou non
	 
  do // debut de la boucle
  {
	nbPatient++ ;
		
	/* Saisie de données tapees au clavier */
	printf("tapez votre poids en kilogramme et votre taille en metre (ex: 80 1.80) : ") ;
	scanf("%f%f", &nbPoids, &nbTaille) ;
	 
	/* Calcule indice de masse corporelle */
	imc = nbPoids / (nbTaille * nbTaille) ;
	
	/* Affichage des donnees */
	printf("\n -vos donnees : %.1f kg et %.2f metres ", nbPoids, nbTaille) ;
	printf("\n -votre imc est de : %.1f ", imc) ;
	 
	/* Affichage des informations */
	if (imc < 18.5)
	 	printf("maigreur, risque eleve a accru") ;
	else if (imc < 25)
	 	printf("poids normal, risque faible") ;
	else if (imc < 30)
		printf("en bon point, risque eleve") ;
	else
		printf("obesite, risque tres eleve") ;

	printf("\n souhaitez-vous continuer ? (o/n)") ;
	scanf("%s", &reponse) ;
		
  } while (reponse == 'o' || reponse == 'O') ; // fin de la boucle
	 
  printf("\n nombre de patient traites : %d", nbPatient) ; //message renvoyant le nombre total de patients traites
		
			
	return 0 ;
}

/* Execution:
tapez votre poids en kilogramme et votre taille en metre (ex: 80 1.80) : 51 1.98

 -vos donnees : 51.0 kg et 1.98 metres
 -votre imc est de : 13.0 maigreur, risque eleve a accru
 souhaitez-vous continuer ? (o/n)o
tapez votre poids en kilogramme et votre taille en metre (ex: 80 1.80) : 69.4 1.63

 -vos donnees : 69.4 kg et 1.63 metres
 -votre imc est de : 26.1 en bon point, risque eleve
 souhaitez-vous continuer ? (o/n)o
tapez votre poids en kilogramme et votre taille en metre (ex: 80 1.80) : 60 1.65

 -vos donnees : 60.0 kg et 1.65 metres
 -votre imc est de : 22.0 poids normal, risque faible
 souhaitez-vous continuer ? (o/n)o
tapez votre poids en kilogramme et votre taille en metre (ex: 80 1.80) : 100 1.72

 -vos donnees : 100.0 kg et 1.72 metres
 -votre imc est de : 33.8 obesite, risque tres eleve
 souhaitez-vous continuer ? (o/n)n

 nombre de patient traites : 4
--------------------------------
Process exited after 62.1 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
