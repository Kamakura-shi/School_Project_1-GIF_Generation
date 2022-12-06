#include "mod_quiz_4.h"

t_image* t_image_initialiser(void)
{
	t_image* image_ptr = (t_image*)malloc(sizeof(t_image));

	/* Valider */
	if (image_ptr == NULL)
	{
		printf("t_image_initialiser > Erreur d'allocation de memoire\n");
		return NULL;
	}

	return image_ptr;

}

t_animation* t_animation_charger_pile(const char* nom_fichier)
{
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

	/* La position initiale */
	t_noeud_image* noeud_courant = animation_ptr->tete;

	/* Le nombre de noeuds à lire */
	int nb_noeuds;

	/* Lire le texte ligne par ligne tant que le fichier n'est pas épuisé */
	//Sur a 80%
	for (unsigned i = 0; i < nb_noeuds; i++)
	{
		if (fichier_ptr == NULL)
		{
			return NULL;
		}
		else
		{
			noeud_courant = noeud_courant->prochain;
		}
	}

	/* Découper la ligne courante et insérer chaque élément dans la bonne couleur (.r, .g ou .b) du bon pixel de la bonne ligne de l'image courante */
	//Vraiment pas sur, rempli d'erreurs
	char nb_noeuds_char[TAILLE_LIGNE_MAX];
	for (unsigned i = 0; i < 286; i++)
	{
		i = fichier_ptr;
		fgets(nb_noeuds_char, TAILLE_LIGNE_MAX, fichier_ptr->i);
		strtok(fichier_ptr->i, nb_noeuds_char);
		for (unsigned j = 0; j < 220; j++)
		{
			strtok(fichier_ptr->i, nb_noeuds_char);
		}
	}

	/* Passer à la prochaine ligne en prenant s'assurant de retourner à zéro lorsqu'on atteint la fin de la couleur courante qui est un multiple de 286 */
	//???

	/* Passer à la prochaine couleur R → G → B */
	//???

	/* Lorsqu'un cycle R → G → B est complet, on empile l'image dans l'animation et on réinitialise l'image courante */
	//Il faut juste trouver comment régler l'erreur du =
	animation_ptr->tete->image = t_pile_dynamique_image_empiler(animation_ptr, image_ptr);

	/* En cas d'échec, on affiche le message suivant avant de retourner le pointeur nul : */
	if (fichier_ptr == NULL)
	{
		printf("t_animation_charger > ERREUR > La reinitialisation de l'image a echoue\n");
		return NULL;
	}

	/* Fermer le fichier */
	fclose(fichier_ptr);

	/* Retourner la référence vers l'animation */
	return animation_ptr;

}