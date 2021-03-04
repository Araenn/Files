/* Using getc and putc, converts the lowercase characters in a file to input into
capital letters. The result file will be saved as result.txt. */

#include <stdio.h>

void test() {

    FILE* reader = fopen("test.txt", "r"); //file to read
    FILE* writer = fopen("result.txt", "w"); //write to the file. If it does not exist, create one of that name, and then write in

    int currentCharCode;

    while ((currentCharCode = fgetc(reader)) != EOF) {
        char car = char(currentCharCode);
        if (car >= 'a' && car <= 'z') {
            fputc(int(car) - 32, writer); //uppercase 
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
