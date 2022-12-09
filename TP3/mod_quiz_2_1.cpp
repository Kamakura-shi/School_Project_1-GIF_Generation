#include "mod_quiz_2_1.h"

void t_pile_image_initialiser(t_pile_image* pile_image_ptr)
{
	pile_image_ptr->taille = 0;
}

unsigned char t_pile_image_est_vide(t_pile_image* pile_image_ptr)
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

unsigned char t_pile_image_est_pleine(t_pile_image* pile_image_ptr)
{
	if (pile_image_ptr->taille == TAILLE_PILE_IMAGE_MAX)
	{
		return VRAI;
	}
	else
	{
		return FAUX;
	}
}

void t_pile_image_empiler(t_pile_image* pile_image_ptr, t_image* image_ptr)
{

	/* Si la pile est pleine : */
	if (t_pile_image_est_pleine(pile_image_ptr))
	{
		/* On affiche le message suivant et on ne fait rien : */
		printf("t_pile_image_empiler > ERREUR > La pile est pleine\n");
	}
	else
	{
		
		/* On ajoute l'image au sommet de la pile et on incremente sa taille */
		pile_image_ptr->tab_image[pile_image_ptr->taille++] = image_ptr;

		/* On affiche un message de la forme suivante pour indiquer l'etat de la pile : */
		printf("t_pile_image_empiler > Il reste %i/%i places dans la pile\n", TAILLE_PILE_IMAGE_MAX - pile_image_ptr->taille, TAILLE_PILE_IMAGE_MAX);

	}

}

t_image* t_pile_image_depiler(t_pile_image* pile_image_ptr)
{

	/* Si la pile est vide : */
	if (t_pile_image_est_vide(pile_image_ptr))
	{
		/* On affiche le message suivant et on ne fait rien : */
		printf("t_pile_image_depiler > ERREUR > La pile est vide!\n");
	}
	else
	{
		
		/* On retourne l'image au sommet de la file et on decremente sa taille */
		t_image* img_retournee = pile_image_ptr->tab_image[--pile_image_ptr->taille];

		/* On affiche un message de la forme suivante pour indiquer l'etat de la pile : */
		printf("t_pile_image_depiler > Il reste %i / %i  places dans la pile\n", TAILLE_PILE_IMAGE_MAX - (pile_image_ptr->taille), TAILLE_PILE_IMAGE_MAX);
		return img_retournee;
	
	}

}