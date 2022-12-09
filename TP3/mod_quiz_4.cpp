#include "mod_quiz_4.h"

t_image* t_image_initialiser(void)
{
	
	/* La mémoire est allouée dynamiquement */
	t_image* image_ptr = (t_image*)malloc(sizeof(t_image));

	/* En cas d'échec : */
	if (image_ptr == NULL)
	{
		
		/* Le message suivant est affiché : */
		printf("t_image_initialiser > Erreur d'allocation de memoire\n");

		/* On retourne le pointeur nul */
		return NULL;
	
	}

	for (int i = 0; i < IMAGE_LARGEUR; i++)
	{
		for (int j = 0; j < IMAGE_HAUTEUR; j++)
		{

			/* Assigner des valeurs aléatoires aux composants en utilisant la macro-fonction fournie destinée à cet usage */
			image_ptr->pixels[i][j].r = 0;
			image_ptr->pixels[i][j].g = 0;
			image_ptr->pixels[i][j].b = 0;

		}
	}

	return image_ptr;

}

t_animation* t_animation_charger_pile(const char* nom_fichier)
{

	/* Découper la ligne courante et insérer chaque élément dans la bonne couleur (.r, .g ou .b) du bon pixel de la bonne ligne de l'image courante */
	char ligne_courante[TAILLE_LIGNE_MAX];

	/* Ouvrir le fichier identifié par nom_fichier en mode lecture */
	FILE* fichier_ptr = fopen(nom_fichier, "r");

	/* En cas d'échec, afficher le message suivant et retourner le pointeur nul: */
	if (fichier_ptr == NULL)
	{
		
		printf("t_animation_charger > ERREUR > Impossible d'ouvrir le fichier\n");
		return NULL;
	
	}

	/* Initialiser une image (référence) dans laquelle on stocke l'image courante qui est en cours de chargement */
	t_image* image_ptr = t_image_initialiser();

	/* Afficher le message suivant en cas d'échec avant de retourner le pointeur nul: */
	if (image_ptr == NULL)
	{
		
		printf("t_animation_charger > ERREUR > L'initialisation de l'image a echoue\n");
		return NULL;
	
	}

	/* Initialiser une animation (référence) */
	t_animation* animation_ptr = t_pile_dynamique_image_initialiser(image_ptr);

	/* afficher le message suivant en cas d'échec avant de retourner le pointeur nul : */
	if (fichier_ptr == NULL)
	{
		
		printf("t_animation_charger > ERREUR > L'initialisation de l'animation a echoue\n");
		return NULL;
	
	}

	while(fgets(ligne_courante,TAILLE_LIGNE_MAX,fichier_ptr) !=NULL)
	{
		
		/* Le nombre de noeuds à lire */
		int nb_noeuds = TAILLE_LIGNE_MAX;

		/* La position initiale */
		t_noeud_image* noeud_courant = animation_ptr->tete;

		/* Passer à la prochaine couleur R → G → B */
		switch (unsigned int couleur = ROUGE)
		{
			case ROUGE:
				/* Lire le texte ligne par ligne tant que le fichier n'est pas épuisé */
				for (unsigned int i = 0; i < nb_noeuds; i++)
				{
			
					/*  Une chaîne de caractères à découper */
					char* msg;

					msg = fgets(ligne_courante, TAILLE_LIGNE_MAX, fichier_ptr);

					/* Un separateur qui marque les endroits à découper */
					const char separateur[2] = "-";

					/* Une référence vers le jeton retourné par strtok */
					char* jeton;

					/* Le premier jeton est extrait en fournissant le message */
					jeton = strtok(msg, separateur);

					int j = 0;

					/* Les autres jetons sont obtenus en fournissant NULL à strtok */
					while (jeton)
					{

						image_ptr->pixels[i][j].r = atoi(jeton);
						jeton = strtok(NULL, separateur);
						j++;

					}

					i++;
					j = 0;

				}
				continue;
			case VERT:
				/* Lire le texte ligne par ligne tant que le fichier n'est pas épuisé */
				for (unsigned int i = 0; i < nb_noeuds; i++)
				{

					/*  Une chaîne de caractères à découper */
					char* msg;

					msg = fgets(ligne_courante, TAILLE_LIGNE_MAX, fichier_ptr);

					/* Un separateur qui marque les endroits à découper */
					const char separateur[2] = "-";

					/* Une référence vers le jeton retourné par strtok */
					char* jeton;

					/* Le premier jeton est extrait en fournissant le message */
					jeton = strtok(msg, separateur);

					int j = 0;

					/* Les autres jetons sont obtenus en fournissant NULL à strtok */
					while (jeton)
					{

						image_ptr->pixels[i][j].g = atoi(jeton);
						jeton = strtok(NULL, separateur);
						j++;

					}

					i++;
					j = 0;

				}
				continue;
			default:
				/* Lire le texte ligne par ligne tant que le fichier n'est pas épuisé */
				for (unsigned int i = 0; i < nb_noeuds; i++)
				{

					/*  Une chaîne de caractères à découper */
					char* msg;

					msg = fgets(ligne_courante, TAILLE_LIGNE_MAX, fichier_ptr);

					/* Un separateur qui marque les endroits à découper */
					const char separateur[2] = "-";

					/* Une référence vers le jeton retourné par strtok */
					char* jeton;

					/* Le premier jeton est extrait en fournissant le message */
					jeton = strtok(msg, separateur);

					int j = 0;

					/* Les autres jetons sont obtenus en fournissant NULL à strtok */
					while (jeton)
					{

						image_ptr->pixels[i][j].b = atoi(jeton);
						jeton = strtok(NULL, separateur);
						j++;

					}

					i++;
					j = 0;

				}
				break;
		}

		/* Lorsqu'un cycle R → G → B est complet, on empile l'image dans l'animation et on réinitialise l'image courante */
		t_pile_dynamique_image_empiler(animation_ptr, image_ptr);

		/* En cas d'échec, on affiche le message suivant avant de retourner le pointeur nul : */
		if (fichier_ptr == NULL)
		{

			printf("t_animation_charger > ERREUR > La reinitialisation de l'image a echoue\n");
			return NULL;

		}
	
	}

	/* Fermer le fichier */
	fclose(fichier_ptr);

	/* Retourner la référence vers l'animation */
	return animation_ptr;

}

void t_animation_jouer(t_animation* une_animation)
{
	/* Si l'animation fournie est égale au pointeur nul : */
	if (une_animation == NULL)
	{
		/* On quitte le sous-programme */
		return;
	}
	else
	{
		
		/* On initialise un canevas avec l'instruction suivante : */
		initwindow(IMAGE_LARGEUR, IMAGE_HAUTEUR);

		/* Tant que l'animation n'est pas terminée : */
		while (!t_pile_dynamique_image_est_vide(une_animation))
		{
			
			/* On dépile les images */
			t_image* image_ptr = t_pile_dynamique_image_depiler(une_animation);

			/* On les affiche une par une avec t_image_afficher de mod_quiz_1 */
			t_image_afficher(image_ptr);
		
		}
	}
}