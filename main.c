#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fields.h"

int checkArgc(int argc, char *argv[])
{
  if (argc == 2 && (strcmp(argv[1], "--version") == 0))
    return 1;
  if (argc == 2 && (strcmp(argv[1], "--help") == 0))
    return 2;
  if (argc == 4 && (strcmp(argv[1], "1") == 0))//chen vao truoc ngay sinh
    return 3;
  if (argc == 3 && (strcmp(argv[1], "2") == 0))//
    return 4;
  return 0;
}
int main(int argc, char *argv[])
{
    char *date;
    IS is = new_inputstruct("ngaythangnam.txt");
    if (is == NULL)
    {
        printf("File fail!\n");
        exit(1);
    }
    
    switch(checkArgc(argc,argv))
    {
        case 1:
        {
            printf("phan mem tao mk wifi version 1.0 .\n");
            break;
        }
        case 2:
        {
            printf("./main [1/2] [name] [namefile output]\n");
            break;
        }
        case 3:
        {
            char name[50];
            char fileout[50];
            strcpy(fileout,argv[3]);
            strcpy(name,argv[2]);
            FILE *fo = fopen(fileout, "w");    // mo file de ghi
            while(get_line(is)>0)
            {                   
                date=(char*)malloc(sizeof(char)*strlen(is->fields[0])+1);
                strcpy(date,is->fields[0]);
                fprintf(fo, "%s%s\n", name, date);
                free(date);
            }
            fclose(fo);     // dong file fo
            break;
        }
        case 4:
        default:
            printf("Command fail!\nUSAGE: ./main --help\n");
            break;

    }
}
