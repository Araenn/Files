/* Replaces, in a file containing text, line breaks with spaces. If
several line returns follow each other, only the first one will be replaced. The names of the source files and
destination are entered using the keypad. */

#include <stdio.h>

void test() {

    FILE* reader = fopen("test.txt", "r");
    FILE* writer = fopen("result.txt", "w");

    int currentCharCode;

    while ((currentCharCode = fgetc(reader)) != EOF) {
        char car = char(currentCharCode);
        if (car == '\n') {
            fputc(car = ' ', writer); // remove '\n' in ' ' 
        } else {
            fputc(car, writer);
        }
    }
    printf("\n");
    fclose(reader);
    fclose(writer);
}

main(){

    test();
   
    return 0;
}
