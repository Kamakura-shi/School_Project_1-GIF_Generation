#include "mod_quiz_2_2.h"

void t_file_image_initialiser(t_file_image* file_image_ptr)
{
	
	file_image_ptr->taille = 0;

	file_image_ptr->i_defiler = 0;

	file_image_ptr->i_enfiler = 0;

}

unsigned char t_file_image_est_vide(t_file_image* file_image_ptr)
{
	if (file_image_ptr->taille <= 0)
	{
		return VRAI;
	}
	else
	{
		return FAUX;
	}
}

unsigned char t_file_image_est_pleine(t_file_image* file_image_ptr)
{
	if (file_image_ptr->taille >= TAILLE_FILE_IMAGE_MAX)
	{
		return VRAI;
	}
	else
	{
		return FAUX;
	}
}

void t_file_image_enfiler(t_file_image* file_image_ptr, t_image* image_ptr)
{
	
	/* Si la file est pleine : */
	if (t_file_image_est_pleine(file_image_ptr))
	{
		/* On affiche le message suivant et on ne fait rien : */
		printf("t_file_image_enfiler > ERREUR > La file est pleine\n");
	}
	else
	{
	
		/* On ajoute l'image au sommet de la file et on incremente sa taille */
		file_image_ptr->tab_image[file_image_ptr->taille++] = image_ptr;

		/* On affiche un message de la forme suivante pour indiquer l'etat de la file : */
		printf("t_file_image_enfiler > Il reste %i/%i places dans la file\n", TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille, TAILLE_FILE_IMAGE_MAX);

		/* On incremente circulairement l'indice d'enfilement */
		if (file_image_ptr->taille != 0)
		{
			file_image_ptr->tab_image[file_image_ptr->i_enfiler++];
		}
		else
		{
			file_image_ptr->i_enfiler = 0;
		}

	}

}

t_image* t_file_image_defiler(t_file_image* file_image_ptr)
{

	/* Si la file est vide : */
	if (t_file_image_est_vide(file_image_ptr))
	{
	
		/* On affiche le message suivant et on ne fait rien : */
		printf("t_pile_image_defiler > ERREUR > La pile est vide!\n");
	
	}
	else
	{
		
		/* On retourne l'image au sommet de la file */
		t_image* img_retournee = file_image_ptr->tab_image[file_image_ptr->i_defiler];
		
		/* On decremente sa taille */
		file_image_ptr->taille--;
		
		/* On incremente circulairement l'indice de defilement */
		file_image_ptr->i_defiler = ((file_image_ptr->i_defiler+ 1) % TAILLE_FILE_IMAGE_MAX);
		
		/* On affiche un message de la forme suivante pour indiquer l'etat de la file : */
		printf("t_pile_image_defiler > Il reste %i/%i  places dans la pile\n", TAILLE_FILE_IMAGE_MAX - (file_image_ptr->taille), TAILLE_FILE_IMAGE_MAX);
		return 	img_retournee;

	}

}