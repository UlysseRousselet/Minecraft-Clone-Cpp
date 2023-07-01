#include "my.h"

int get_len(Element *actuel)
{
    int maxlen = 0;
    while (actuel != NULL) {
        maxlen++;
        actuel = actuel->suivant;
    }
    return maxlen;
}

void free_list(liste *liste)
{
    int len = get_len(liste->premier);
    for (int i = 0; i < len; i++) {
        supprimer(liste);
    }
    free(liste);
}