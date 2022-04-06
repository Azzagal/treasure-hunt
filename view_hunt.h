/**
 * \file view_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the view of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/
#ifndef __VIEW_HUNT__
#define __VIEW_HUNT__

#include <gtk/gtk.h>

#include "model_hunt.h"
#include "controller_hunt.h"

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
 * \fn void redraw(ViewHunt *vh)
 *
 * \brief Redraw the view of the treasure hunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param result indicates if the player have win(1) or lose(0) 
 */
void redraw(ViewHunt *vh, unsigned result);
#endif //__VIEW_HUNT__