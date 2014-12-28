#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( )
{
    FILE* fptr;
    char extension[] = ".c";

    char file_name[FILENAME_MAX];  /* defined in stdio.h*/
    int char_count;

    printf("\n\n\tFile name (NO extension):\t");
    scanf("%s",file_name);
    strcat(file_name,extension);
    fptr=fopen(file_name,"rb");

    for(char_count=0; getc(fptr) !=EOF; ++char_count);
    printf("\n\tByte size:\t%d", char_count);
    fclose(fptr);

    return EXIT_SUCCESS;
}