/**
 * \file model_hunt.h
 *
 * \brief This file contains the declerations of structure and fonctions to manage the model of a treasure hunt.
 *
 * \author: Lorenzen Pierre s203724
 * \date: 08/04/2022
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
 * \fn ModelHunt *create_model_hunt(unsigned v, unsigned d)
 *
 * \brief Allocate memory for the structure ModelHunt.
 *
 * \param v the number of victory while you are playing.
 * \param d the number of defeat while you are playing.
 * 
 * \return the struct ModelHunt with allocated memory. If there is a problem return NULL.
 */
ModelHunt *create_model_hunt(unsigned v, unsigned d);

/**
 * \fn void treasure_choice(ModelHunt *mh)
 *
 * \brief Choose randomly a treasure to be the full treasure.
 *
 * \param mh a pointer on ModelHunt.
 */
void treasure_choice(ModelHunt *mh);

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
 * \fn void add_round(ModelHunt *mh)
 *
 * \brief Add a round to the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 */
void add_round(ModelHunt *mh);

/**
 * \fn unsigned get_round(ModelHunt *mh)
 *
 * \brief Get the round member from the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 * 
 * \return the round member from the struc ModelHunt.
 */
unsigned get_round(ModelHunt *mh);

/**
 * \fn unsigned get_victory(ModelHunt *mh)
 *
 * \brief Get the victory member from the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 * 
 * \return the victory member from the struc ModelHunt.
 */
unsigned get_victory(ModelHunt *mh);

/**
 * \fn unsigned get_defeat(ModelHunt *mh)
 *
 * \brief Get the defeat member from the struc ModelHunt.
 *
 * \param mh a pointer on ModelHunt.
 * 
 * \return the defeat member from the struc ModelHunt.
 */
unsigned get_defeat(ModelHunt *mh);
#endif //__MODEL_HUNT__