/****************************************************************************************

Auteur(e) :
Dernière Modification :
Fichier :

Écrire description ici*

*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/

#define BROUILLON   1
#define QUIZ_1		0
#define QUIZ_2_1	0
#define QUIZ_2_2	0
#define QUIZ_3_1    0
#define QUIZ_3_2    0
#define QUIZ_4      0

/****************************************************************************************
*                           DÉFINTION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/

#if BROUILLON

	/* Test preliminaire */

	#include "graphics.h"
	#pragma comment(lib, "graphics")

	int main(void)
	{

		initwindow(250, 250);
		setcolor(WHITE);
		line(50, 50, 50, 100);
		line(50, 50, 100, 50);
		line(100, 50, 100, 100);
		line(50, 100, 100, 100);
		setcolor(RED);
		circle(125, 125, 25);
		setcolor(LIGHTCYAN);
		line(150, 150, 150, 200);
		line(150, 150, 200, 150);
		line(200, 150, 200, 200);
		line(150, 200, 200, 200);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif QUIZ_1

	#include "mod_quiz_1.h"

	#define TRUE 1

	int main(void)
	{

		/* L'image a afficher */
		t_image une_image;

		/* Initialisation aleatoire */
		t_image_initialiser_aleatoire(&une_image);

		/* Ouvrir un canevas */
		initwindow(IMAGE_LARGEUR, IMAGE_HAUTEUR);

		/* Normaliser l'image */
		t_image_normaliser(&une_image);

		/* Afficher l'image */
		t_image_afficher(&une_image);

		/* Permuter des pixels aleatoirement */
		unsigned int x1;
		unsigned int y1;
		unsigned int x2;
		unsigned int y2;

		while(TRUE)
		{

			/* Permuter deux pixels choisis aleatoirement */
			x1 = RANDBETWEEN(0, IMAGE_HAUTEUR - 1);
			y1 = RANDBETWEEN(0, IMAGE_LARGEUR - 1);
			x2 = RANDBETWEEN(0, IMAGE_HAUTEUR - 1);
			y2 = RANDBETWEEN(0, IMAGE_LARGEUR - 1);

			t_pixel_permuter(&une_image.pixels[x1][y1],
							 &une_image.pixels[x2][y2]);

			/* Afficher les pixels permutes */
			t_pixel_afficher(x1, y1, &une_image.pixels[x1][y1]);
			t_pixel_afficher(x2, y2, &une_image.pixels[x2][y2]);

		}

		system("pause");
		return EXIT_SUCCESS;

	}

#elif QUIZ_2_1

	#include "mod_quiz_2_1.h"

	int main(void)
	{

		/* Une serie de image */
		t_image image_1;
		t_image image_2;
		t_image image_3;

		/* Initialiser une pile de image */
		t_pile_image pile_image;
		t_pile_image_initialiser(&pile_image);

		/* Tenter de depiler une pile vide -> ERREUR */
		t_pile_image_depiler(&pile_image);

		/* Empiler 2 images (i.e. remplir la pile) */
		t_pile_image_empiler(&pile_image, &image_1);
		t_pile_image_empiler(&pile_image, &image_2);

		/* Tenter d'empiler dans une pile pleine -> ERREUR */
		t_pile_image_empiler(&pile_image, &image_3);

		/* Vider la pile */
		while (!t_pile_image_est_vide(&pile_image))
		{
			t_pile_image_depiler(&pile_image);
		}

		system("pause");
		return EXIT_SUCCESS;
	}

#elif QUIZ_2_2

	#include "mod_quiz_2_2.h"

	int main(void)
	{

		/* Une serie d'image */
		t_image image_1;
		t_image image_2;
		t_image image_3;

		/* Initialiser une file de image */
		t_file_image file_image;
		t_file_image_initialiser(&file_image);

		/* Tenter de defiler une file vide -> ERREUR */
		t_file_image_defiler(&file_image);

		/* Enfiler 2 image (i.e. remplir la file) */
		t_file_image_enfiler(&file_image, &image_1);
		t_file_image_enfiler(&file_image, &image_2);

		/* Tenter d'enfiler dans une file pleine -> ERREUR */
		t_file_image_enfiler(&file_image, &image_3);

		/* Vider la file */
		while (!t_file_image_est_vide(&file_image))
		{
			t_file_image_defiler(&file_image);
		}

		/* Enfiler 2 images et en defiler une */
		t_file_image_enfiler(&file_image, &image_1);
		t_file_image_enfiler(&file_image, &image_2);
		t_file_image_defiler(&file_image);

		/* Afficher les indices pour valider l'incrementation circulaire */
		printf("i_defiler = %i\n", file_image.i_defiler);
		printf("i_enfiler = %i\n", file_image.i_enfiler);

		system("pause");
		return EXIT_SUCCESS;
	}

#elif QUIZ_3_1

	#include "mod_quiz_3_1.h"

	int main(void)
	{

		/* Une serie d'images */
		t_image image_1;
		t_image image_2;

		/* Initialiser la pile */
		printf("Initialiser la pile avec l'image (%p)\n", &image_1);
		t_pile_dynamique_image* pile_image_ptr = t_pile_dynamique_image_initialiser(&image_1);
		printf("Taille de la pile = %i\n", pile_image_ptr->taille);

		/* Ajouter une nouvelle image */
		printf("Ajout de l'image (%p) a la pile\n", &image_2);
		t_pile_dynamique_image_empiler(pile_image_ptr, &image_2);
		printf("Taille de la pile = %i\n", pile_image_ptr->taille);

		/* Vider la pile */
		printf("Depiler l'image (%p)\n", t_pile_dynamique_image_depiler(pile_image_ptr));
		printf("Taille de la pile = %i\n", pile_image_ptr->taille);
		
		printf("Depiler l'image (%p)\n", t_pile_dynamique_image_depiler(pile_image_ptr));
		printf("Taille de la pile = %i\n", pile_image_ptr->taille);

		/* Tenter de depiler une pile vide -> ERREUR */
		t_pile_dynamique_image_depiler(pile_image_ptr);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif QUIZ_3_2

	#include "mod_quiz_3_2.h"

	int main(void)
	{

		/* Une serie d'images */
		t_image image_1;
		t_image image_2;

		/* Initialiser la file */
		printf("Initialiser la file avec l'image (%p)\n", &image_1);
		t_file_dynamique_image* file_image_ptr = t_file_dynamique_image_initialiser(&image_1);
		printf("Taille de la file = %i\n", file_image_ptr->taille);

		/* Ajouter une nouvelle image */
		printf("Ajout de l'image (%p) a la file\n", &image_2);
		t_file_dynamique_image_enfiler(file_image_ptr, &image_2);
		printf("Taille de la file = %i\n", file_image_ptr->taille);

		/* Vider la file */
		printf("Defiler l'image (%p)\n", t_file_dynamique_image_defiler(file_image_ptr));
		printf("Taille de la file = %i\n", file_image_ptr->taille);

		printf("Defiler l'image (%p)\n", t_file_dynamique_image_defiler(file_image_ptr));
		printf("Taille de la file = %i\n", file_image_ptr->taille);

		/* Tenter de defiler une file vide -> ERREUR */
		t_file_dynamique_image_defiler(file_image_ptr);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif QUIZ_4

	#include "mod_quiz_4.h"

	int main(void)
	{

		/* Charger l'animation */
		t_animation* une_animation = t_animation_charger_pile("INF147_A2022_TP3_GIF.csv");

		/* Lancer l'animation */
		t_animation_jouer(une_animation);

		system("pause");
		return EXIT_SUCCESS;

	}

#endif 