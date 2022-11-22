#include "mod_quiz_2_1.h"

void t_pile_image_empiler(t_pile_image* pile_image_ptr, t_image* image_ptr)
{
	if (t_pile_image_est_pleine(pile_image_ptr))
	{
		printf("t_pile_image_empiler > ERREUR > La pile est pleine\n");
	}
	else
	{
		pile_image_ptr->tab_image[pile_image_ptr->taille++] = image_ptr;
		printf("t_pile_image_empiler > Il reste %i/%i places dans la pile\n", TAILLE_PILE_IMAGE_MAX - pile_image_ptr->taille, TAILLE_PILE_IMAGE_MAX);
	}
}