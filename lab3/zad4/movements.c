#include "agents.h"

void north(struct agent *a){
    a->y++;
}

void south(struct agent *a){
    a->y--;
}

void east(struct agent *a)
{
    a->x++;
}

void west(struct agent *a){
    a->x--;
}
