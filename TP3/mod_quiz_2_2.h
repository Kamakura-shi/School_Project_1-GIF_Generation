#ifndef _MOD_QUIZ_2_2_
#define _MOD_QUIZ_2_2_

#include "mod_quiz_1.h"

/* Taille maximale d'une pile d'images */
#define TAILLE_FILE_IMAGE_MAX 2

/* Indicateur d'etat */
#define VRAI   1
#define FAUX   0

/* Type structure qui represente une pile de image */
typedef struct
{
	t_image* tab_image[TAILLE_FILE_IMAGE_MAX];
	unsigned char taille;
	unsigned char i_defiler;
	unsigned char i_enfiler;
} t_file_image;

/*
T_FILE_IMAGE_INITIALISER

	Initialise une File d'images.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_file_image_initialiser(t_file_image* file_image_ptr);

/*
T_FILE_IMAGE_EST_VIDE

	Indique si la file est vide ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- est_vide: Indicateur de vide (type: unsigned char).
*/
unsigned char t_file_image_est_vide(t_file_image* file_image_ptr);

/*
T_FILE_IMAGE_EST_PLEINE

	Indique si la file est pleine ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- est_pleine: Indicateur de plein (type: unsigned char).
*/
unsigned char t_file_image_est_pleine(t_file_image* file_image_ptr);

/*
T_FILE_IMAGE_ENFILER

	Enfile une image.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).
	- image_ptr: Une reference vers une image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_file_image_enfiler(t_file_image* file_image_ptr, t_image* image_ptr);

/*
T_FILE_IMAGE_DEFILER

	Defile une image.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image defilee (type: t_image*).
*/
t_image* t_file_image_defiler(t_file_image* file_image_ptr);

#endif