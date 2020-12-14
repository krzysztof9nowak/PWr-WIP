#include <stdio.h>
#include "agents.h"

int main(){
    struct agent Bob = newagent(0, 0);
    struct agent Alice = newagent(3, 3);

    north(&Bob);
    south(&Alice);
    west(&Alice);
    north(&Bob);
    east(&Bob);
    south(&Alice);
    printf("odległość = %.3lf\n", distance(Bob, Alice));
    return 0;
}
