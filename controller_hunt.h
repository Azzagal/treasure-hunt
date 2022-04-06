/**
 * \file controller_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the controller of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/
#ifndef __CONTROLLER_HUNT__
#define __CONTROLLER_HUNT__

#include <gtk/gtk.h>

#include "model_hunt.h"
#include "view_hunt.h"

/**
 * \struct ControllerHunt
 * 
 * \brief Represent the controller of a treasure hunt.
 *
 */
typedef struct controller_t ControllerHunt;

/**
 * \fn ControllerHunt create_controller_hunt(struct view_t *vh, ModelHunt *mh)
 *
 * \brief Allocate memory for the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param mh a pointer on ModelHunt.
 * 
 * \return the struct ControllerHunt with allocated memory. If there is a problem return NULL.
 */
ControllerHunt *create_controller_hunt(struct view_t *vh, ModelHunt *mh);

/**
 * \fn void click_restart(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with the restart button.
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_restart(GtkWidget *pf, gpointer data);

/**
 * \fn void click_treasure(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with one of the treasure button .
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_treasure(GtkWidget *pf, gpointer data);
#endif //__CONTROLLER_HUNT__