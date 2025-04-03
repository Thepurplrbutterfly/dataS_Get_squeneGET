#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequenelist.h"

int main(int argc, char *argv[])
{
    sl * S = list_create(8);
     if(S == NULL)
    {
        printf("the memory assigning for S failed->the list creating failed!\n");
        return -1;
    }
    list_en(S);
    list_sequencingGET(S, 5);
    return 0;
}
