#ifndef _MOD_QUIZ_3_1_
#define _MOD_QUIZ_3_1_

#include "mod_quiz_3_0.h"

/* Indicateur d'etat */
#define VRAI   1
#define FAUX   0

/* Type structure qui represente une pile dynamique d'images */
typedef t_liste_image t_pile_dynamique_image;

/*
T_PILE_DYNAMIQUE_IMAGE_INITIALISER

	Initialise une pile dynamique d'images.

 PARAMÈTRES :

	- image_ptr: Une reference vers un image (type: t_image*).

 VALEUR DE RETOUR :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).
*/
t_pile_dynamique_image* t_pile_dynamique_image_initialiser(t_image* image_ptr);

/*
T_PILE_DYNAMIQUE_IMAGE_EMPILER

	Empile une image dans une pile dynamique.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).
	- image_ptr: Une reference vers l'image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- est_succes: Un indicateur de succes/echec (type: unsigned char).
*/
unsigned char t_pile_dynamique_image_empiler(t_pile_dynamique_image* pile_image_ptr, t_image* image_ptr);

/*
T_PILE_DYNAMIQUE_IMAGE_EST_VIDE

	Indique si la pile est vide ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).

 VALEUR DE RETOUR :

	- est_vide: Un indicateur de vide (type: unsigned char).
*/
unsigned char t_pile_dynamique_image_est_vide(t_pile_dynamique_image* pile_image_ptr);

/*
T_PILE_DYNAMIQUE_IMAGE_DEPILER

	Depile une image dans une pile dynamique.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image depilee (type: t_image*).
*/
t_image* t_pile_dynamique_image_depiler(t_pile_dynamique_image* pile_image_ptr);

#endif