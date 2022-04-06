/**
 * \file view_hunt.c
 *
 * \brief This file contains implementation of structure and fonctions to manage the view of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <gtk/gtk.h>

#include "view_hunt.h"
#include "controller_hunt.h"

struct view_t{
    GtkWidget *pLabelV; //The label for the victory
    GtkWidget *pLabelD; //The label for the defeat
    GtkWidget *pLabelI; //The label for the information string
    ModelHunt *mh; 
};

ViewHunt *create_view_hunt(ModelHunt *mh){
    assert(mh!=NULL);

    ViewHunt *vh = malloc(sizeof(ViewHunt));
    if(vh==NULL)
        return NULL;
    
    vh->mh = mh;
    return vh;
}//end create_view_hunt()

void redraw(ViewHunt *vh, unsigned result){
    assert(vh!=NULL);

    char *vLabel;
    sprintf(vLabel,"Victoires: %d",mh->v);
    char *dLabel;
    sprintf(dLabel,"Défaites: %d",mh->d);
    char *iLabel;

    if(result)
        iLabel = "Gagné";
    else
        iLabel = "Perdu";

    //Redessiner
    gtk_label_set_text(GTK_LABEL(vt->pLabelV),vLabel);
    gtk_label_set_text(GTK_LABEL(vt->pLabelD),dLabel);
    gtk_label_set_text(GTK_LABEL(vt->pLabelI),iLabel);
}//end redraw()
