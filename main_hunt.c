/**
 * \file main_hunt.c
 *
 * \brief The main file for treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
**/

#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

#include "model_hunt.h"
#include "view_hunt.h"
#include "controller_hunt.h"

void delete_window(GtkWidget *pF, gpointer data){
  gtk_main_quit();
}


int main(int argc, char **argv){
    //creation of a model for the treasure hunt
    ModelHunt *mh = create_model_hunt(0,0);
    if(mh==NULL)
        return EXIT_FAILURE;
    treasure_choice(mh);

    //creation of a view for the treasure hunt
    ViewHunt *vh = create_view_hunt(mh);
    if(vh==NULL)
        return EXIT_FAILURE;

    //creation of a controller for the treasure hunt
    ControllerHunt *ch = create_controller_hunt(vh, mh);
    if(ch==NULL)
        return EXIT_FAILURE;
    
    // Man/Machine Interface
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pHBoxRestart;
    GtkWidget *pHBoxLabelI;
    GtkWidget *pWindow;
    GtkWidget *pButton0 = get_Button(ch,0);
    GtkWidget *pButton1 = get_Button(ch,1);
    GtkWidget *pButton2 = get_Button(ch,2);
    GtkWidget *pButtonRestart = get_Button_Restart(ch);
    GtkWidget *pLabelV = get_LabelV(vh);
    GtkWidget *pLabelI = get_LabelI(vh);

    //GTK Initialisation 
    gtk_init(&argc, &argv);

    //window creation
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pWindow), "Le jeu du trésor");

    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(delete_window), NULL);

    //Button creation
    pButton0 = draw_button("Pictures/coffre_ferme.jpg");
    g_signal_connect(G_OBJECT( pButton0 ), "clicked", G_CALLBACK(click_treasure0), ch);

    pButton1 = draw_button("Pictures/coffre_ferme.jpg");
    g_signal_connect(G_OBJECT(pButton1), "clicked", G_CALLBACK(click_treasure1), ch);

    pButton2 = draw_button("Pictures/coffre_ferme.jpg");
    g_signal_connect(G_OBJECT(pButton2), "clicked", G_CALLBACK(click_treasure2), ch);
    
    pButtonRestart = gtk_button_new_with_label("Recommencer");
    g_signal_connect(G_OBJECT(pButtonRestart), "clicked", G_CALLBACK(click_restart), ch);
    gtk_widget_set_sensitive ( pButtonRestart , FALSE );

    pLabelV = gtk_label_new("Victoires: 0  Défaites: 0");
    pLabelI = gtk_label_new("Choisissez un coffre!");

    pVBox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pLabelV, TRUE, FALSE, 0);
    pHBoxLabelI = gtk_hbox_new(TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBoxLabelI, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBoxLabelI), pLabelI, TRUE, FALSE, 0);
    pHBoxRestart = gtk_hbox_new(TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBoxRestart, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBoxRestart), pButtonRestart, TRUE, TRUE, 0);
    pHBox = gtk_hbox_new(TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pButton0, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pButton1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pButton2, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);
    gtk_widget_show_all(pWindow);

    set_Button(ch,0,pButton0);
    set_Button(ch,1,pButton1);
    set_Button(ch,2,pButton2);
    set_Button_Restart(ch,pButtonRestart);
    set_LabelV(vh,pLabelV);
    set_LabelI(vh,pLabelI);
    
    gtk_main();

    return EXIT_SUCCESS;
}