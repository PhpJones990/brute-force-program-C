#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main(void)
{
    char *forced_password = calloc(100, sizeof(char));
    char *pass_holder = calloc(101, sizeof(char)); 
    FILE *login_file;
    int len = 1;
    int max_length = 95;

    int exit_code;
    while (1)
    {

        for (int i = 0; i < len; i++)
        {
            forced_password[i] = ' ';
        }
        forced_password[len] = '\0';

        while (1)
        {
            login_file = _popen("login.exe", "w");
            if (!login_file)
            {
                printf("[Brute Force]: Failed to run login program!\n");
                return -1;
            }

            strcpy(pass_holder, forced_password);
            strcat(pass_holder, "\n");

            printf("%s", pass_holder);

            fprintf(login_file, pass_holder);
            fflush(login_file);

            exit_code = _pclose(login_file);

            if (exit_code == 0)
            {
                printf("\n[SUCCESS] Password Found!\n");
                printf("The password is: %s\n", forced_password);
                
                // Cleanup and Exit
                free(forced_password);
                free(pass_holder);
                return 0;
            }

            // string combination 
            int i = len - 1;

            while (i >= 0)
            {
                forced_password[i]++;

                if (forced_password[i] > '~')
                {
                    forced_password[i] = ' ';
                    i--;
                }
                else
                {
                    break;
                }
            }

            if (i < 0)
            {
                break;
            }
        }
        if (len <= max_length)
        {
            len++;
            continue;
        }
        else
        {
            printf("[Brute Force]: Unable to Brute Force!\n");
            break;
        }

    }


    free(forced_password);
    free(pass_holder);

    printf("Fine!\n");
    return 0;
}