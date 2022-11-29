#include "mod_quiz_3_1.h"

unsigned char t_pile_dynamique_image_empiler(t_pile_dynamique_image* pile_image_ptr, t_image* image_ptr)
{
	unsigned char est_succes = EXIT_SUCCESS;

	/* Valider l'entree */
	if (pile_image_ptr == NULL)
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
	if (pile_image_ptr->taille == 0)
	{
		pile_image_ptr->tete = noeud_image_ptr;
	}
	else
	{
		pile_image_ptr->tete->prochain = noeud_image_ptr;
		pile_image_ptr->tete = noeud_image_ptr;
	}

	pile_image_ptr->taille++;

	return est_succes;
}