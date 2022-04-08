/**
 * \file view_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the view of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
**/
#ifndef __VIEW_HUNT__
#define __VIEW_HUNT__

#include <gtk/gtk.h>

#include "model_hunt.h"

/**
 * \struct ViewHunt
 * 
 * \brief Represent the view of a treasure hunt.
 *
 */
typedef struct view_t ViewHunt;

/**
 * \fn ViewHunt *create_view_hunt(ModelHunt *mh)
 *
 * \brief Allocate memory for the structure ViewHunt.
 *
 * \param mh a pointer on ModelHunt.
 * 
 * \return the struct ViewHunt with allocated memory. If there is a problem return NULL.
 */
ViewHunt *create_view_hunt(ModelHunt *mh);

/**
 * \fn void redraw(ViewHunt *vh, unsigned result)
 *
 * \brief Redraw the view of the treasure hunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param result indicates if the player have win(1) or lose(0) 
 */
void redraw(ViewHunt *vh, unsigned result);

/**
 * \fn GtkWidget *get_LabelV(ViewHunt *vh)
 *
 * \brief The getter for the label of victory and defeat member from the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * 
 * \return GtkWidget *, a pointer to a label.
 *         Null if error.
 */
GtkWidget *get_LabelV(ViewHunt *vh);

/**
 * \fn void set_LabelV(ViewHunt *vh,GtkWidget *pLabel)
 *
 * \brief The setter for the label of victory and defeat member from the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param pLabel a pointer on GtkWidget.
 */
void set_LabelV(ViewHunt *vh,GtkWidget *pLabel);

/**
 * \fn GtkWidget *get_LabelI(ViewHunt *vh)
 *
 * \brief The getter for the label of information member from the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * 
 * \return GtkWidget *, a pointer to a label.
 *         Null if error.
 */
GtkWidget *get_LabelI(ViewHunt *vh);

/**
 * \fn void set_LabelI(ViewHunt *vh,GtkWidget *pLabel)
 *
 * \brief The setter for the label of information member from the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param pLabel a pointer on GtkWidget.
 */
void set_LabelI(ViewHunt *vh,GtkWidget *pLabel);
#endif //__VIEW_HUNT__