/* Program that reads a 'family.txt' file and displays the information on the screen that it contains. */

#include <stdio.h>
#include <string.h>

int i = 0;

int eqStr(char* one, char two[]) {

    if ((strlen(one) != strlen(two)) && (strlen(one) + 1 != strlen(two))) {
        return 0;
    }

    int j = 0;
    if (i != 0 && int(two[0]) == 10) {
        j = 1;
    }

    for (int i = 0; i < strlen(one); i++, j++) {
        if (one[i] != two[j]) {
            return 0;
        }
    }
    return 1;
}

main(){

    char* familyNeeded;
    printf("Enter your name:");
    scanf("%s", familyNeeded);

    FILE* reader = fopen("family.txt", "r");

    char family[40];
    char father[40];
    char mother[40];
    int nchild;

    while (fscanf(reader, "%99[^,],%99[^,],%99[^,],%d", &family, &father, &mother, &nchild) != EOF) {
        
        if (eqStr(familyNeeded,family)) {
            printf("For the family : %s\n", family);
            printf("Father : %s\n", father);
            printf("Mother : %s\n", mother);
            printf("Number of children : %d\n", nchild);
            break;
        }
        i++;
    }

    fclose(reader);
    return 0;
}
