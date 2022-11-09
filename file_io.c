#include <stdio.h>
#include <cstring>
#include <stdlib.h>
int read_file(char** arr);
int write_file();
int read(char *buffer[]);
int read_one(char** buffer, FILE *fp);


//g++ -Wall 
int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");

    //char** arr = (char**)malloc(100*255);
    char* buffer[100];
    char* buff;
    buff = (char*)malloc(255);
    int rv = 0;
    //write_file();
    //read_file(arr);
    // rv = read(buffer);
    // printf("%s\n", buffer[0]);
    // printf("%s\n", buffer[2]);
    // printf("%s\n", buffer[7]);
    read_one(&buff, fp);
    printf("%s\n", buff);
    read_one(&buff, fp);
    printf("%s\n", buff);
    read_one(&buff, fp);
    printf("%s\n", buff);
}


int read_file(char** arr) {
   FILE *fp;
   char buff[255];

   fp = fopen("test.txt", "r");
   for (int i = 0; i < 100; i++) {
        fgets(buff, 255, (FILE*)fp);
        strcpy(arr[i], buff);

        printf("%s\n", arr[i] );
   }
   printf("\n \n %s", arr[20]);
   printf("\n \n %s", arr[19]);


   return 0;
}

int read_one(char** buffer, FILE *fp) {
    
    char buff[255];
    fgets(buff, 255, (FILE*)fp);
    strcpy(*buffer,buff);
    return 0;
}


int read(char *buffer[]) {
    FILE *fp;
    char buff[255];
    fp = fopen("test.txt", "r");

    for (int i = 0; i < 100; i++) {
            fgets(buff, 255, (FILE*)fp);
            buffer[i] = (char*)malloc(255);
            strcpy(buffer[i],buff);

    }

    return 0;
}
int write_file() {
    FILE *fp;
    fp = fopen("test.txt", "w+");
    for (int i = 0; i < 100; i++) {
        fprintf(fp, "%d.%s.%d\n", i, "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", i);
    }
    fclose(fp);
    return 0;
}