/**
 * \file controller_hunt.c
 *
 * \brief This file contains implementation of structure and fonctions to manage the controller of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
**/

#include <stdlib.h>
#include <assert.h>

#include "controller_hunt.h"

struct controller_t {
    struct view_t *vh;
    ModelHunt *mh;
    GtkWidget *pButtonRestart;
    GtkWidget *pButton[3];
    unsigned result; //1 if the player have win, if not 0. 
};

ControllerHunt *create_controller_hunt(ViewHunt *vh, ModelHunt *mh){
    assert(mh!=NULL && vh!=NULL);

    ControllerHunt *ch = malloc(sizeof(ControllerHunt));
    if(ch==NULL)
        return NULL;
    
    ch->vh = vh;
    ch->mh = mh;
    ch->result = 0;

    ch->pButtonRestart = NULL;
    ch->pButton[0] = NULL;
    ch->pButton[1] = NULL;
    ch->pButton[2] = NULL;

    return ch;
}//end create_controller_hunt()

GtkWidget *draw_button(char *filename){
    assert(filename!=NULL);

    GdkPixbuf * pb_temp = gdk_pixbuf_new_from_file (filename, NULL );
    if ( pb_temp == NULL ){
        printf (" [ERROR] In loading of the picture %s !\n",filename);
        return NULL ;
    }
    GdkPixbuf * pb = gdk_pixbuf_scale_simple ( pb_temp , 100 , 100 , GDK_INTERP_NEAREST );

    GtkWidget * pButton = gtk_button_new ();

    GtkWidget * image = gtk_image_new_from_pixbuf ( pb );
    gtk_button_set_image ( GTK_BUTTON ( pButton ), image );

    return pButton ;
}

void redraw_button(char *filename,GtkWidget *pButton){
    assert(filename!=NULL && pButton!=NULL);

    GdkPixbuf * pb_temp = gdk_pixbuf_new_from_file (filename, NULL );
    if ( pb_temp == NULL ){
        printf (" [ERROR] In loading of the picture %s !\n",filename);
        return NULL ;
    }
    GdkPixbuf * pb = gdk_pixbuf_scale_simple ( pb_temp , 100 , 100 , GDK_INTERP_NEAREST );

    GtkWidget * image = gtk_image_new_from_pixbuf ( pb );
    gtk_button_set_image ( GTK_BUTTON ( pButton ), image );
}

void click_restart(GtkWidget *pf, gpointer data){
    ControllerHunt *ch = (ControllerHunt *)data;
    
    redraw_button("Pictures/coffre_ferme.jpg",ch->pButton[1]);
    redraw_button("Pictures/coffre_ferme.jpg",ch->pButton[0]);
    redraw_button("Pictures/coffre_ferme.jpg",ch->pButton[2]);
    gtk_widget_set_sensitive ( ch->pButtonRestart , FALSE );
    redraw(ch->vh,2);
    treasure_choice(ch->mh);
}

void click_treasure0(GtkWidget *pf, gpointer data){
    ControllerHunt *ch = (ControllerHunt *)data;

    if(get_round(ch->mh)==1){
        if(reveal_treasure(ch->mh,0)){
            redraw_button("Pictures/coffre_plein.jpg",ch->pButton[0]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 1;
            add_round(ch->mh);
            redraw(ch->vh, ch->result);
        }
        else{
            redraw_button("Pictures/coffre_vide.jpg",ch->pButton[0]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 0;
            redraw(ch->vh,ch->result);
            add_round(ch->mh);
        }
    }
    if(get_round(ch->mh)==0){
        redraw_button("Pictures/coffre_vide.jpg",ch->pButton[random_treasure(ch->mh,0)]);
        add_round(ch->mh);
    }
}

void click_treasure1(GtkWidget *pf, gpointer data){
    ControllerHunt *ch = (ControllerHunt *)data;

    if(get_round(ch->mh)==1){
        if(reveal_treasure(ch->mh,1)){
            redraw_button("Pictures/coffre_plein.jpg",ch->pButton[1]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 1;
            redraw(ch->vh,ch->result);
            add_round(ch->mh);
        }
        else{
            redraw_button("Pictures/coffre_vide.jpg",ch->pButton[1]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 0;
            redraw(ch->vh,ch->result);
            add_round(ch->mh);
        }
    }
    if(get_round(ch->mh)==0){
        redraw_button("Pictures/coffre_vide.jpg",ch->pButton[random_treasure(ch->mh,1)]);
        add_round(ch->mh);
    }
}

void click_treasure2(GtkWidget *pf, gpointer data){
    ControllerHunt *ch = (ControllerHunt *)data;

    if(get_round(ch->mh)==1){
        if(reveal_treasure(ch->mh,2)){
            redraw_button("Pictures/coffre_plein.jpg",ch->pButton[2]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 1;
            redraw(ch->vh,ch->result);
            add_round(ch->mh);
        }
        else{
            redraw_button("Pictures/coffre_vide.jpg",ch->pButton[2]);
            gtk_widget_set_sensitive ( ch->pButtonRestart , TRUE );
            ch->result = 0;
            redraw(ch->vh,ch->result);
            add_round(ch->mh);
        }
    }
    if(get_round(ch->mh)==0){
        redraw_button("Pictures/coffre_vide.jpg",ch->pButton[random_treasure(ch->mh,2)]);
        add_round(ch->mh);
    }
}

GtkWidget *get_Button(ControllerHunt *ch, unsigned i){
    assert(ch!=NULL);
    return ch->pButton[i];
}

void set_Button(ControllerHunt *ch, unsigned i,GtkWidget *pButton){
    assert(ch!=NULL && pButton!=NULL);
    ch->pButton[i] = pButton;
}

GtkWidget *get_Button_Restart(ControllerHunt *ch){
    assert(ch!=NULL);
    return ch->pButtonRestart;
}

void set_Button_Restart(ControllerHunt *ch,GtkWidget *pButton){
    assert(ch!=NULL && pButton!=NULL);
    ch->pButtonRestart = pButton;
}