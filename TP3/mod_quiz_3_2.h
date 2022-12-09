#ifndef _MOD_QUIZ_3_2_
#define _MOD_QUIZ_3_2_

#include "mod_quiz_3_0.h"

/* Indicateur d'etat */
#define VRAI   1
#define FAUX   0

/* Type structure qui represente une file dynamique d'images */
typedef t_liste_image t_file_dynamique_image;

/*
T_FILE_DYNAMIQUE_IMAGE_INITIALISER

	Initialise une file dynamique d'images.

 PARAMÈTRES :

	- image_ptr: Une reference vers un image (type: t_image*).

 VALEUR DE RETOUR :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).
*/
t_file_dynamique_image* t_file_dynamique_image_initialiser(t_image* image_ptr);

/*
T_FILE_DYNAMIQUE_IMAGE_ENFILER

	Enfile une image dans une file dynamique.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).
	- image_ptr: Une reference vers l'image a enfiler (type: t_image*).

 VALEUR DE RETOUR :

	- est_succes: Un indicateur de succes/echec (type: unsigned char).
*/
unsigned char t_file_dynamique_image_enfiler(t_file_dynamique_image* file_image_ptr, t_image* image_ptr);

/*
T_FILE_DYNAMIQUE_IMAGE_EST_VIDE

	Indique si la file est vide ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).

 VALEUR DE RETOUR :

	- est_vide: Un indicateur de vide (type: unsigned char).
*/
unsigned char t_file_dynamique_image_est_vide(t_file_dynamique_image* file_image_ptr);

/*
T_FILE_DYNAMIQUE_IMAGE_DEPILER

	Defile une image dans une file dynamique.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image defilee (type: t_image*).
*/
t_image* t_file_dynamique_image_defiler(t_file_dynamique_image* file_image_ptr);

#endif