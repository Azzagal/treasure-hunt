/**
 * \file model_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the model of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 02/04/2022
**/
#ifndef __MODEL_HUNT__
#define __MODEL_HUNT__

/**
 * \struct ModelHunt
 * 
 * \brief Represent the model of a treasure hunt.
 *
 */
typedef struct model_t ModelHunt;

/**
 * \fn ModelHunt *create_model_hunt(unsigned v, unsigned d, unsigned treasure_pos)
 *
 * \brief Allocate memory for the structure ModelHunt.
 *
 * \param v the number of victory while you are playing.
 * \param d the number of defeat while you are playing.
 * \param treasure_pos the position of the treasure.
 * 
 * \return the struct ModelHunt with allocated memory. If there is a problem return NULL.
 */
ModelHunt *create_model_hunt(unsigned v, unsigned d, unsigned treasure_pos);

/**
 * \fn unsigned random_treasure(ModelHunt *mh, unsigned click_pos)
 *
 * \brief Choose randomly an empty treasure from the unchoose treasure.
 *
 * \param mh a pointer on ModelHunt.
 * \param click_pos the position of the chosen treasure.
 * 
 * \return The place of the chosen treasure : 0 for the first one , 1 for the second one and 2 for the last one.
 */
unsigned random_treasure(ModelHunt *mh, unsigned click_pos);

/**
 * \fn int reveal_treasure(ModelHunt *mh, unsigned click_pos)
 *
 * \brief Reveal the chosen treasure.
 *
 * \param mh a pointer on ModelHunt.
 * \param click_pos the position of the chosen treasure.
 * 
 * \return If click_pos is the treasure position, the fonction return 1. If not return 0.
 */
int reveal_treasure(ModelHunt *mh, unsigned click_pos);

/**
 * \fn void add_victory(ModelHunt *mh)
 *
 * \brief Add a victory to the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 */
void add_victory(ModelHunt *mh);

/**
 * \fn void add_defeat(ModelHunt *mh)
 *
 * \brief Add a defeat to the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 */
void add_defeat(ModelHunt *mh);

#endif //__MODEL_HUNT__