#include "mod_quiz_3_2.h"

unsigned char t_file_dynamique_image_enfiler(t_file_dynamique_image* file_image_ptr, t_image* image_ptr)
{
	unsigned char est_succes = EXIT_SUCCESS;

	/* Valider l'entree */
	if (file_image_ptr == NULL)
	{
		est_succes = EXIT_FAILURE;
	}

	/* Initialiser un noeud */
	t_noeud_image* noeud_image_ptr = t_noeud_image_initialiser(image_ptr);

	/* Valider le noeud */
	if (noeud_image_ptr == NULL)
	{
		est_succes = EXIT_FAILURE;
	}

	/* Ajouter le noeud */
	for (unsigned int i = 0; i < file_image_ptr->taille - 1; i++)
	{
		if (file_image_ptr->taille == 0)
		{
			file_image_ptr->tete = noeud_image_ptr;
		}
		else
		{
			file_image_ptr->tete->prochain = noeud_image_ptr;
			file_image_ptr->tete = noeud_image_ptr;
		}
	}

	file_image_ptr->taille--;

	return est_succes;
}