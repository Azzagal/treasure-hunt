/**
 * \file model_hunt.c
 *
 * \brief This file contains implementation of structure and fonctions to manage the model of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "model_hunt.h"

struct model_t{
    unsigned v; //The number of victory while you are playing
    unsigned d; //The number of defeat while you are playing
    unsigned treasure_pos; //The position of the treasure
};

ModelHunt *create_model_hunt(unsigned v, unsigned d, unsigned treasure_pos){
    ModelHunt *mh = malloc(sizeof(ModelHunt));
    if(mh==NULL)
        return NULL;
    
    mh->v = v;
    mh->d = d;
    mh->treasure_pos = treasure_pos;

    return mh;
} //end create_model_hunt()

unsigned random_treasure(ModelHunt *mh, unsigned click_pos){
    assert(mh!=NULL);

    srand(time(NULL));
    unsigned pos = mh->treasure_pos;
    while(pos = mh->treasure_pos && pos = click_pos){
        pos = rand()%3;
    }
    return pos;
}//end random_treasure()

int reveal_treasure(ModelHunt *mh, unsigned click_pos){
    assert(mh!=NULL);

    if(mh->treasure_pos = click_pos)
        return 1;
    else
        return 0;
}//end reveale_treasure()

void add_victory(ModelHunt *mh){
    assert(mh!=NULL);

    mh->v++;
}// end add_victory()

void add_defeat(ModelHunt *mh){
    assert(mh!=NULL);

    mh->d++;
}// end add_defeat()