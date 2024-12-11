#include <stdio.h>
#include <ctype.h>

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Bersihkan buffer input
}

void clear_screen(){
    printf("\033[2J\033[1;1H");
}

void doTask(char task, char message[], int shift)
{
    char ch;
    if (task == 'e' || task == 'E')
    {
        for (int i = 0; message[i] != '\0'; i++)
        {

            ch = message[i];

            if (isalnum(ch))
            {
                if (isupper(ch))
                {
                    message[i] = (ch - 'A' + shift) % 26 + 'A';
                }
                else if (isdigit(ch))
                {
                    message[i] = (ch - '0' + shift) % 10 + '0';
                }
                else if (islower(ch))
                {
                    message[i] = (ch - 'a' + shift) % 26 + 'a';
                }
            }
        }
    }
    else if (task == 'd' || task == 'D')
    {
        for (int i = 0; message[i] != '\0'; i++)
        {

            ch = message[i];

            if (isalnum(ch))
            {
                if (isupper(ch))
                {
                    message[i] = (ch - 'A' - shift + 26) % 26 + 'A';
                }
                else if (isdigit(ch))
                {
                    message[i] = (ch - '0' - shift + 10) % 10 + '0';
                }
                else if (islower(ch))
                {
                    message[i] = (ch - 'a' - shift + 26) % 26 + 'a';
                }
            }
        }
    }
}

int main()
{
    // First step is to declare variable and its data type
    // We declare message with data type of char, but we make an array of char so it will be a string
    char message[100], task;
    // Then we declare the shift to count the number of shifts we want
    int shift, again;

    do
    {
        clear_screen();
        printf("============================================================ \n");
        printf("========= Caesar Cipher Encryption and Decyrption ========== \n");
        printf("============================================================ \n");
        printf("========= Choose Encrypt (e/E) or Decrypt (d/D)   ========== \n");
        printf("============================================================ \n");

        // Give information about the input, we want to input the number of shifts that we want to use to encrypt the message
        printf("Cipher do :  ");
        // Then, we create the input to get what we type to a variable named shift with integer type
        // After that, to prevent the next input to get an enter, we use getchar() method
        scanf("%c", &task);
        clear_input_buffer();
        if (task != 'e' && task != 'E' && task != 'd' && task != 'D')
        {
            continue;
        }
        // Give information about the input, we want to input the message that will be encrypted\decrypt by the program
        (task == 'e' || task == 'e')
            ? printf("Input the text that is going to be encrypted : ")
            : printf("Input the text that is going to be decrypted : ");
        // Then, we create the input to get what we type to a variable named message
        scanf("%[^\n]s", message);
        // After that, to prevent the next input to get an enter, we use getchar() method
        getchar();

        // Give information about the input, we want to input the number of shifts that we want to use to encrypt the message
        printf("Input the number of shifts you want to do : ");
        // Then, we create the input to get what we type to a variable named shift with integer type
        scanf("%d", &shift);
        // After that, to prevent the next input to get an enter, we use getchar() method
        getchar();

        doTask(task, message, shift);

        // We loop each of the message
        (task == 'e' || task == 'E') ? printf("Encrypted text : %s", message) : printf("Decrypted text : %s", message);

        printf("\nDo you want to continue (1 for yes, 0 for no) : ");
        scanf("%d", &again);
        // After that, to prevent the next input to get an enter, we use getchar() method
        clear_input_buffer();
    } while (again == 1);

    return 0;
}