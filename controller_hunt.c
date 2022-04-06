/**
 * \file controller_hunt.c
 *
 * \brief This file contains implementation of structure and fonctions to manage the controller of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/

#include <stdlib.h>
#include <assert.h>

#include "controller_hunt.h"

struct controller_t {
    ViewHunt *vh;
    ModelHunt *mh;
    GtkWidget *pButtonRestart;
    GtkWidget *pButtonT0;
    GtkWidget *pButtonT1;
    GtkWidget *pButtonT2;
};

ControllerHunt *create_controller_hunt(struct view_t *vh, ModelHunt *mh){
    assert(mh!=NULL && vh!=NULL);

    ControllerHunt *ch = malloc(sizeof(ControllerHunt));
    if(ch==NULL)
        return NULL
    
    ch->vh = vh;
    ch->mh = mh;

    ch->pButtonRestart = NULL;
    ch->pButtonT0 = NULL;
    ch->pButtonT1 = NULL;
    ch->pButtonT2 = NULL;

    return ch;
}//end create_controller_hunt()

void click_restart(GtkWidget *pf, gpointer data){
    ControllerHunt *ch = (ControllerHunt *)data;

    
}

/**
 * \fn void click_treasure(GtkWidget *pf, gpointer data)
 *
 * \brief The callback associate with one of the treasure button .
 *
 * \param pf a pointer on GtkWidget.
 * \param data an aditionnal information.
 */
void click_treasure(GtkWidget *pf, gpointer data);