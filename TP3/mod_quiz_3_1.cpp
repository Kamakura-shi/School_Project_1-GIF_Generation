#include "mod_quiz_3_1.h"

t_pile_dynamique_image* t_pile_dynamique_image_initialiser(t_image* image_ptr)
{

	/* On alloue la memoire dynamiquement */
	t_pile_dynamique_image* pile_image_ptr = (t_pile_dynamique_image*)malloc(sizeof(t_pile_dynamique_image));

	/* En cas d'echec : */
	if (pile_image_ptr == NULL)
	{
		
		/* Le message suivant est affiché */
		printf(" t_pile_dynamique_image_initialiser -> Erreur d'allocation de memoire\n");
		
		/* On retourne le pointeur nul */
		return NULL;
	
	}
	
	/* Si le pointeur d'image est le pointeur nul : */
	if (image_ptr == NULL)
	{
		
		/* On initialise la tete de la pile egale a ce dernier */
		pile_image_ptr->tete = t_noeud_image_initialiser(image_ptr);

		/* On fixe la taille a zero */
		pile_image_ptr->taille = 0;
	
	}
	else
	{
		
		/* On initialise un noeud a partir du pointeur d'image */
		pile_image_ptr->tete = t_noeud_image_initialiser(image_ptr);

		if (pile_image_ptr->tete == NULL)
		{
			/* On libere la memoire allouee pour la pile */
			free(pile_image_ptr);
			
			/* On quitte la fonction en retournant le pointeur nul */
			return NULL;
		}
		/* Si l'initialisation fonctionne : */
		else
		{
			
			/* On fixe la taille a 1 */
			pile_image_ptr->taille = 1;
			
			/* On retourne la pile */
			return pile_image_ptr;
		
		}
	
	}

}

unsigned char t_pile_dynamique_image_est_vide(t_pile_dynamique_image* pile_image_ptr)
{
	if (pile_image_ptr->taille == 0)
	{
		return VRAI;
	}
	else
	{
		return FAUX;
	}

}

unsigned char t_pile_dynamique_image_empiler(t_pile_dynamique_image* pile_image_ptr, t_image* image_ptr)
{
	
	unsigned char est_succes = EXIT_SUCCESS;

	/* En cas d'échec : */
	if (pile_image_ptr == NULL)
	{
		/* On retourne un indicateur d'échec (c.-à-d. EXIT_FAILURE) */
		est_succes = EXIT_FAILURE;
	}

	/* Initialiser un noeud */
	t_noeud_image* noeud_image_ptr = t_noeud_image_initialiser(image_ptr);

	/* En cas d'échec : */
	if (noeud_image_ptr == NULL)
	{
		/* On retourne un indicateur d'échec (c.-à-d. EXIT_FAILURE) */
		est_succes = EXIT_FAILURE;
	}

	/* Ajouter le noeud */
	if (pile_image_ptr->taille == 0)
	{
		pile_image_ptr->tete = noeud_image_ptr;
	}
	else
	{
		
		/* On remplace la tete par le nouveau noeud */
		pile_image_ptr->tete->prochain = noeud_image_ptr;
		
		/* On relie le nouveau noeud à l'ancienne tete */
		pile_image_ptr->tete = noeud_image_ptr;
	
	}

	/* On incremente la taille de la pile */
	pile_image_ptr->taille++;

	return est_succes;

}

t_image* t_pile_dynamique_image_depiler(t_pile_dynamique_image* pile_image_ptr)
{
	/* Si la pile est vide, on affiche le message suivant et on retourne le pointeur nul : */
	if (t_pile_dynamique_image_est_vide(pile_image_ptr))
	{
		
		/* on affiche le message suivant */
		printf("t_pile_dynamique_image_depiler > ERREUR > La pile est vide");
		
		/* On retourne le pointeur nul */
		return NULL;

	}
	else
	{
		
		/* On remplace la tete par le prochain noeud */
		t_noeud_image* noeud_suivant_ptr = pile_image_ptr->tete->prochain;
	
		/* retourner la référence vers l'image encapsulée par celle-ci */
		t_noeud_image* noeud_supprimer = pile_image_ptr->tete;
		
		/* On libere la memoire allouee pour le noeud depile (i.e. l'ancienne tete) */
		t_noeud_image_detruire(pile_image_ptr->tete);

		pile_image_ptr->tete = noeud_suivant_ptr;

		/* On decremente la taille de la pile */
		pile_image_ptr->taille--;

		return noeud_supprimer->image;

	}

}