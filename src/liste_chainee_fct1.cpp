#include "my.h"

liste *initialisation(void)
{
    liste *list = reinterpret_cast<liste*>(malloc(sizeof(*list)));
    list->premier = NULL;
    return list;
}

void insertion(liste *liste, char chunk[21][11][11], int pos[2], Dot_vector *vector, int grid[10][10], int height, int height_factor)
{
    Element *nouveau = reinterpret_cast<Element*>(malloc(sizeof(*nouveau)));
    nouveau->vector = vector;
    nouveau->pos[0] = pos[0];
    nouveau->pos[1] = pos[1];
    nouveau->height = height;
    nouveau->height_factor = height_factor;
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                nouveau->chunk[w][i][y] = chunk[w][i][y];
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int y = 0; y < 10; ++y) {
            nouveau->grid[i][y] = grid[i][y];
        }
    }
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    if (liste->premier->suivant == NULL)
        liste->dernier = liste->premier;
}

void supprimer(liste *liste)
{
    if (liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void show_liste(liste *liste)
{
    std::cout << " DEBUT "<< std::endl;
    Element *actuel = liste->premier;
    while (actuel != NULL) {
        std::cout << " x = "<< actuel->pos[0] << " z = " << actuel->pos[1];
        actuel = actuel->suivant;
    }
    std::cout << " FIN "<< std::endl;
}
