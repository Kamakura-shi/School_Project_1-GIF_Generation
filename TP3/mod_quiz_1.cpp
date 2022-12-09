#include "mod_quiz_1.h"

unsigned char t_pixel_calculer_norme(const t_pixel* pixel_ptr)
{

	unsigned int norme;

	norme = (int)sqrt(pow(pixel_ptr->r, 2) + pow(pixel_ptr->g, 2) + pow(pixel_ptr->b, 2));

	return norme;

}

void t_pixel_normaliser(t_pixel* pixel_ptr)
{

	/* Diviser les composants par la norme */
	unsigned int norme = t_pixel_calculer_norme(pixel_ptr);

	if (norme != 0) 
	{
		
		pixel_ptr->r /= norme;
		pixel_ptr->g /= norme;
		pixel_ptr->b /= norme;
	
	}

}

void t_pixel_permuter(t_pixel* pixel_1_ptr, t_pixel* pixel_2_ptr)
{

	t_pixel* temp_pixel = NULL; 

	/* Permuter les composants et non pas les pointeurs */
	temp_pixel->r = pixel_1_ptr->r;
	temp_pixel->g = pixel_1_ptr->g;
	temp_pixel->b = pixel_1_ptr->b;

	pixel_1_ptr->r = pixel_2_ptr->r;
	pixel_1_ptr->g = pixel_2_ptr->g;
	pixel_1_ptr->b = pixel_2_ptr->b;

	pixel_2_ptr->r = temp_pixel->r;
	pixel_2_ptr->g = temp_pixel->g;
	pixel_2_ptr->b = temp_pixel->b;

}

void t_pixel_afficher(const unsigned int x, const unsigned int y, const t_pixel* pixel_ptr)
{

	/* Pour utilisation de la macro fonction  COLOR */
	int couleur_unique;

	couleur_unique = COLOR(pixel_ptr->r, pixel_ptr->g, pixel_ptr->b);

	/* Sous-programme putpixel de la librairie graphics.h. */
	putpixel(x, y, couleur_unique);

}
	
void t_image_afficher(const t_image* image_ptr)
{

	for (int i = 0; i < IMAGE_HAUTEUR; i++) 
	{
		for (int j = 0; j < IMAGE_LARGEUR; j++)
		{
			/* Afficher l'image en posant que le pixel à la position (i, j) se trouve à la position (x, y) */
			t_pixel_afficher(i, j, &image_ptr->pixels[i][j]);			
		}
	}

}

void t_image_initialiser_aleatoire(t_image* image_ptr)
{

	/* Parcourir le tableau de pixels de l'image */
	for (int i = 0; i < IMAGE_LARGEUR; i++)
	{
		for (int j = 0; j < IMAGE_HAUTEUR; j++)
		{
		
			/* Assigner des valeurs aléatoires aux composants en utilisant la macro-fonction fournie destinée à cet usage */
			image_ptr->pixels[i][j].r = RANDBETWEEN(PIXEL_MIN, PIXEL_MAX);
			image_ptr->pixels[i][j].g = RANDBETWEEN(PIXEL_MIN, PIXEL_MAX);
			image_ptr->pixels[i][j].b = RANDBETWEEN(PIXEL_MIN, PIXEL_MAX);
		
		}
	}

}

void t_image_normaliser(t_image* image_ptr)
{

	/* Parcourir le tableau de pixels de l'image */
	for (int i = 0; i < IMAGE_HAUTEUR ; i++)
	{
		for (int j = 0; j < IMAGE_LARGEUR; j++)
		{
			/* Normaliser chacun des pixels de l'image */
			t_pixel_normaliser(&image_ptr->pixels[i][j]);						
		}
	}

}