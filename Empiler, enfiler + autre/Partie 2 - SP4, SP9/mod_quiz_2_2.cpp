#include "mod_quiz_2_2.h"

void t_file_image_enfiler(t_file_image* file_image_ptr, t_image* image_ptr)
{
	if (t_file_image_est_pleine(file_image_ptr))
	{
		printf("t_file_image_empiler > ERREUR > La file est pleine\n");
	}
	else
	{
		file_image_ptr->tab_image[file_image_ptr->taille++] = image_ptr;
		printf("t_file_image_empiler > Il reste %i/%i places dans la file\n", TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille, TAILLE_FILE_IMAGE_MAX);
		file_image_ptr->tab_image[file_image_ptr->i_enfiler++];
	}
}