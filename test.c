#include <stdio.h>
#include <string.h>
int main(){
    char *ptr1 = "Input1\n";
    char **ptr2 = &ptr1;
    char *input = strdup(*ptr2);
    int length = strlen(input);
    for(int i = 0; i < length; i++){
        if(input[i] == '\n'){
            printf("Found a newline\n");
            input[i] = '\0';
            printf("Changed it to a null char\n");
        }
    }
    if(input[strlen(input)] == '\0'){
        printf("Eureka!\n");
    }
    return 0;
}