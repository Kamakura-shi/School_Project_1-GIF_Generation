#include "mod_quiz_1.h"

unsigned char t_pixel_calculer_norme(const t_pixel* pixel_ptr)
{
	return sqrt(pow(pixel_ptr->b,2) + pow(pixel_ptr->g,2) + pow(pixel_ptr->r,2));
}

void t_pixel_normaliser(t_pixel* pixel_ptr)
{
	pixel_ptr->r / t_pixel_calculer_norme(pixel_ptr);
	pixel_ptr->g / t_pixel_calculer_norme(pixel_ptr);
	pixel_ptr->b / t_pixel_calculer_norme(pixel_ptr);
}

void t_pixel_permuter(t_pixel* pixel_1_ptr, t_pixel* pixel_2_ptr)
{
	t_pixel temp;
	temp.r = pixel_1_ptr->r;
	pixel_1_ptr->r = pixel_2_ptr->r;
	pixel_2_ptr->r = temp.r;
	temp.g = pixel_1_ptr->g;
	pixel_1_ptr->g = pixel_2_ptr->g;
	pixel_2_ptr->g = temp.g;
	temp.b = pixel_1_ptr->b;
	pixel_1_ptr->b = pixel_2_ptr->b;
	pixel_2_ptr->b = temp.b;
}