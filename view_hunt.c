/**
 * \file view_hunt.c
 *
 * \brief This file contains implementation of structure and fonctions to manage the view of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
**/

#include <stdlib.h>
#include <assert.h>
#include <gtk/gtk.h>

#include "view_hunt.h"
#include "controller_hunt.h"

struct view_t{
    GtkWidget *pLabelV; //The label for the victory and defeat
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

    char vLabel[50];
    sprintf(vLabel,"Victoires: %d  Défaites: %d",get_victory(vh->mh),get_defeat(vh->mh));
    char iLabel[60];

    switch(result){
        case 1:  
            sprintf(iLabel,"Gagné");
            break;
        case 0:
            sprintf(iLabel,"Perdu");
            break;
        default:
            sprintf(iLabel,"Choisissez un coffre!");
    }

    //Redraw
    gtk_label_set_text(GTK_LABEL(vh->pLabelV),vLabel);
    gtk_label_set_text(GTK_LABEL(vh->pLabelI),iLabel);
}//end redraw()

GtkWidget *get_LabelV(ViewHunt *vh){
    assert(vh!=NULL);
    return vh->pLabelV;
}//end get_LabelV()

void set_LabelV(ViewHunt *vh,GtkWidget *pLabel){
    assert(vh!=NULL && pLabel!=NULL);
    vh->pLabelV = pLabel;
}//end set_LabelV()

GtkWidget *get_LabelI(ViewHunt *vh){
    assert(vh!=NULL);
    return vh->pLabelI;
}//end get_LabelI()

void set_LabelI(ViewHunt *vh,GtkWidget *pLabel){
    assert(vh!=NULL && pLabel!=NULL);
    vh->pLabelI = pLabel;
}//end set_LabelI()

void free_view(ViewHunt *vh){
    assert(vh!=NULL);
    free(vh);
}