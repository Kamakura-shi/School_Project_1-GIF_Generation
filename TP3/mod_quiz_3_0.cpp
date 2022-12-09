#include "mod_quiz_3_0.h"

t_noeud_image* t_noeud_image_initialiser(t_image* image_ptr)
{
	
	/* On alloue la memoire dynamiquement */
	t_noeud_image* noeud_image_ptr = (t_noeud_image*)malloc(sizeof(t_noeud_image));

	/* En cas d'échec : */
	if (noeud_image_ptr == NULL)
	{
		
		/* Le message suivant est affiché */
		printf(" t_pile_dynamique_image_initialiser -> Erreur d'allocation de memoire\n");

		/* On retourne le pointeur nul */
		return NULL;
	
	}
	else
	{
		
		/* On initialise le pointeur d'image */
		noeud_image_ptr->image = image_ptr;
		
		/* On fixe le pointeur vers le prochain noeud au pointeur nul */
		noeud_image_ptr->prochain = NULL;
	
		return noeud_image_ptr;

	}

}


void t_noeud_image_detruire(t_noeud_image* noeud_image_ptr)
{
	free(noeud_image_ptr);
}