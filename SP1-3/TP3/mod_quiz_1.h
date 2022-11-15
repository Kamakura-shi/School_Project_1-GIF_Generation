#ifndef _MOD_QUIZ_1_
#define _MOD_QUIZ_1_

/* Librairie graphique */
#include "graphics.h"
#pragma comment(lib, "graphics")

/* Librairies externes */
#include <math.h>

#define IMAGE_HAUTEUR 286	// Hauteur de l'image en nombre de pixels
#define IMAGE_LARGEUR 220	// Largeur de l'image en nombre de pixels
#define PIXEL_MIN     0		// Valeur minimale d'un composant de pixel RGB
#define PIXEL_MAX     255	// Valeur maximale d'un composant de pixel RGB

/* Macro-fonction qui genere une composante d'un pixel aleatoire */
#define GENERER_PIXEL_ALEATOIRE ((unsigned char)(rand() % (PIXEL_MAX + 1)))

/* Macro-fonction qui genere un entier aleatoire entre bornes */
#define RANDBETWEEN(a, b) (a + (rand() % (b - a)))

/* Type structure qui represente un pixel */
typedef struct
{
	unsigned char r;	// Composant rouge
	unsigned char g;	// Composant vert
	unsigned char b;	// Composant bleu
} t_pixel;

/* Type structure qui represente une image */
typedef struct
{
	t_pixel pixels[IMAGE_HAUTEUR][IMAGE_LARGEUR];	/* Tableau 2D de pixels */
} t_image;

/*
T_PIXEL_CALCULER_NORME

	Calcule la norme d'un pixel.

 PARAMÈTRES :

	 - pixel_ptr : Une reference vers un pixel (type: t_pixel*).

 VALEUR DE RETOUR :

	- norme : La norme du pixel (type: unsigned char)
*/
unsigned char t_pixel_calculer_norme(const t_pixel* pixel_ptr);

/*
T_PIXEL_NORMALISER

	Normalise un pixel enn divisant les composants par la norme.

 PARAMÈTRES :

	 - pixel_ptr : Une reference vers un pixel (type: t_pixel*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pixel_normaliser(t_pixel* pixel_ptr);

/*
T_PIXEL_PERMUTER

	Permute deux pixels en permutant leurs composants.

 PARAMÈTRES :

	- pixel_1_ptr : Une reference vers un premier pixel (type: t_pixel*).
	- pixel_2_ptr : Une reference vers un deuxieme pixel (type: t_pixel*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pixel_permuter(t_pixel* pixel_1_ptr, t_pixel* pixel_2_ptr);

/*
T_PIXEL_AFFICHER

	Affiche un pixel sur un canevas a une position (x,y) donnee.

 PARAMÈTRES :

	- x: La position x du pixel a afficher (type: unsigned int).
	- y: La position y du pixel a afficher (type: unsigned int).
	- pixel_ptr: Une reference vers le pixel a afficher (type: t_pixel*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pixel_afficher(const unsigned int x,
	const unsigned int y,
	const t_pixel* pixel_ptr);

/*
T_IMAGE_INITIALISER_ALEATOIRE

	Initialise une image avec des pixels dont les composants sont choisis de maniere aleatoire.

 PARAMÈTRES :

	- image_ptr: Une reference vers une image (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_image_initialiser_aleatoire(t_image* image_ptr);

/*
T_IMAGE_NORMALISER

	Normalise les pixels d'une image.

 PARAMÈTRES :

	- image_ptr: Une reference vers une image (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_image_normaliser(t_image* image_ptr);

/*
T_IMAGE_NORMALISER

	Affiche une image sur un canevas.

 PARAMÈTRES :

	- image_ptr: Une reference vers une image (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_image_afficher(const t_image* image_ptr);

#endif