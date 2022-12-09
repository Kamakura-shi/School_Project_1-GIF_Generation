#ifndef _MOD_QUIZ_2_1_
#define _MOD_QUIZ_2_1_

#include "mod_quiz_1.h"	

/* Taille maximale d'une pile de image */
#define TAILLE_PILE_IMAGE_MAX 2

/* Indicateur d'etat */
#define VRAI   1
#define FAUX   0

/* Type structure qui represente une pile de image */
typedef struct
{
	t_image* tab_image[TAILLE_PILE_IMAGE_MAX];
	unsigned char taille;
} t_pile_image;

/*
T_PILE_IMAGE_INITIALISER

	Initialise une pile d'images.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pile_image_initialiser(t_pile_image* pile_image_ptr);

/*
T_PILE_IMAGE_EST_VIDE

	Indique si la pile est vide ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- est_vide: Indicateur de vide (type: unsigned char).
*/
unsigned char t_pile_image_est_vide(t_pile_image* pile_image_ptr);

/*
T_PILE_IMAGE_EST_PLEINE

	Indique si la pile est pleine ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- est_pleine: Indicateur de plein (type: unsigned char).
*/
unsigned char t_pile_image_est_pleine(t_pile_image* pile_image_ptr);

/*
T_PILE_IMAGE_EMPILER

	Empile une image.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).
	- image_ptr: Une reference vers une image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pile_image_empiler(t_pile_image* pile_image_ptr, t_image* image_ptr);

/*
T_PILE_IMAGE_DEPILER

	Depile une image.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image depilee (type: t_image*).
*/
t_image* t_pile_image_depiler(t_pile_image* pile_image_ptr);

#endif