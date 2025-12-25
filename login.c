#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

const char *password = "ABC"; 

int main(void)
{
    char *entered_password = calloc(100, sizeof(char)); 
    printf("Enter the Password: ");
    fgets(entered_password, 100, stdin);
    entered_password[strlen(entered_password) - 1] = '\0';
    
    if (strcmp(entered_password, password) == 0)
    {
        printf("Successful!\n");
        free(entered_password);
        return 0;
    }
    else
    {
        printf("Fail!\n");
        free(entered_password);
        return 1;
    }

    

}