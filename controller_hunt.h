/**
 * \file controller_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the controller of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
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
 * \fn ControllerHunt create_controller_hunt(ViewHunt *vh, ModelHunt *mh)
 *
 * \brief Allocate memory for the structure ControllerHunt.
 *
 * \param vh a pointer on ViewHunt.
 * \param mh a pointer on ModelHunt.
 * 
 * \return the struct ControllerHunt with allocated memory. If there is a problem return NULL.
 */
ControllerHunt *create_controller_hunt(ViewHunt *vh, ModelHunt *mh);

/**
 * \fn GtkButton *draw_button(char *filename)
 *
 * \brief Draw a treasure button.
 *
 * \param filename the path of a the picture to put in the button.
 * 
 * \return GtkWidget *, a pointer to a button.
 *         Null if error.
 */
GtkWidget *draw_button(char *filename);

/**
 * \fn void redraw_button(char *filename,GtkWidget *pButton)
 *
 * \brief redraw a treasure button.
 *
 * \param filename the path of a the picture to put in the button.
 * \param pButton the button to redraw
 */
void redraw_button(char *filename,GtkWidget *pButton);

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
 * \fn void click_treasure0(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with the first treasure button .
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_treasure0(GtkWidget *pf, gpointer data);

/**
 * \fn void click_treasure1(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with the second treasure button .
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_treasure1(GtkWidget *pf, gpointer data);

/**
 * \fn void click_treasure2(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with the third treasure button .
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_treasure2(GtkWidget *pf, gpointer data);

/**
 * \fn GtkWidget *get_Button(ControllerHunt *mh, unsigned i)
 *
 * \brief The getter for the button member from the structure ControllerHunt.
 *
 * \param ch a pointer on ControllerHunt.
 * \param i the button position.
 * 
 * \return GtkWidget *, a pointer to a button.
 *         Null if error.
 */
GtkWidget *get_Button(ControllerHunt *ch, unsigned i);

/**
 * \fn void set_Button(ControllerHunt *ch, unsigned i,GtkWidget *pButton)
 *
 * \brief The setter for the button member from the structure ControllerHunt.
 *
 * \param ch a pointer on ControllerHunt.
 * \param i the button position.
 * \param pButton a pointer on GtkWidget.
 */
void set_Button(ControllerHunt *ch, unsigned i,GtkWidget *pButton);

/**
 * \fn GtkWidget *get_Button_Restart(ControllerHunt *ch)
 *
 * \brief The getter for the restart button member from the structure ControllerHunt.
 *
 * \param ch a pointer on ControllerHunt.
 * 
 * \return GtkWidget *, a pointer to a button.
 *         Null if error.
 */
GtkWidget *get_Button_Restart(ControllerHunt *ch);

/**
 * \fn void set_Button_Restart(ControllerHunt *ch,GtkWidget *pButton)
 *
 * \brief The setter for the restart button member from the structure ControllerHunt.
 *
 * \param ch a pointer on ControllerHunt.
 * \param pButton a pointer on GtkWidget.
 */
void set_Button_Restart(ControllerHunt *ch,GtkWidget *pButton);

/**
 * \fn void free_controller(ControllerHunt *ch)
 *
 * \brief Free the memory previously allocated for the structure ControllerHunt.
 *
 * \param ch a pointer on ControllerHunt.
 */
void free_controller(ControllerHunt *ch);
#endif //__CONTROLLER_HUNT__