#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char uname[100];
char pass[100];

void menu();
void signUp();
void changeDetails();
void logIn();
void deleteAccount();

typedef struct logInInfo
{
    char name[100];
    char pass[100];
    char uname[100];
    char contact[12];
    char address[20];
    char email[20];
} login;

void menu()
{
    system("color 0F");
    int choice;
start:
    system("cls");
    printf("\t\t<<-- AUTHENTICATION SYSTEM -->>\n\n");
    system("color 0F");
    printf("Instructions\n");
    printf("----------\n");
    printf("1. Sign Up\n");
    printf("2. Change Details\n");
    printf("3. Log In\n");
    printf("4. Delete Account\n");
    printf("5. EXIT\n");
    system("color 0F");
    printf("\nChoose : ");
    fflush(stdin);
    scanf("%d", &choice);

    while (1)
    {
        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            changeDetails();
            break;
        case 3:
            logIn();
            break;
        case 4:
            deleteAccount();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Command\n");
            printf("Press any key to retry ");
            fflush(stdin);
            getch();
            goto start;
        }
    }
}

void signUp()
{
    system("color 0B");
    FILE *file;
    login log;
    system("cls");
    printf("\t\t<<-- SIGN UP -->>\n\n");
    printf("Follow the given instructions to create an account\n");
    printf("--------------------------------------------------\n");
    printf("Enter your name.\n");
    fflush(stdin);
    fgets(log.name, 100, stdin);
    printf("Enter your username.\n");
    fflush(stdin);
    fgets(log.uname, 100, stdin);
    printf("Enter your contact number.\n");
    fflush(stdin);
    fgets(log.contact, 100, stdin);
    printf("Enter your address.\n");
    fflush(stdin);
    fgets(log.address, 100, stdin);
    printf("Enter your email.\n");
    fflush(stdin);
    fgets(log.email, 100, stdin);
    printf("Enter your password.\n");
    fflush(stdin);
    fgets(log.pass, 100, stdin);
    printf("\n(Press any key to confirm) ");
    fflush(stdin);
    getch();

    file = fopen("login.txt", "wb+");

    if (file == NULL)
    {
        printf("\nError opening file\n");
        exit(1);
    }

    fwrite(&log, sizeof(login), 1, file);
    fclose(file);

    printf("\n\n!!! Account Created Successfully !!!\n");
    printf("\nPress any key to continue ");
    fflush(stdin);
    getch();
    menu();
}

void changeDetails()
{
    system("color 0E");
    FILE *file;
    login log;
refill1:
    system("cls");
    printf("\t\t<<-- CHANGE DETAILS -->>\n\n");
    printf("Username\n");
    fflush(stdin);
    fgets(uname, 100, stdin);
    printf("\nPassword\n");
    fgets(pass, 100, stdin);
    file = fopen("login.txt", "rb+");
    if (file == NULL)
    {
        printf("\nError opening file\n");
        exit(1);
    }

    while (fread(&log, sizeof(login), 1, file))
    {
        if (strcmp(uname, log.uname) == 0 && strcmp(pass, log.pass) == 0)
        {
            printf("\nLogged in successfully : )\nPress any key to continue ");
            fflush(stdin);
            getch();
        refill2:
            system("cls");
            printf("Refill your details\n");
            printf("-------------------\n");
            printf("Name :");
            fflush(stdin);
            fgets(log.name, 100, stdin);
            printf("Username : ");
            fflush(stdin);
            fgets(log.uname, 100, stdin);
            printf("Contact : ");
            fflush(stdin);
            fgets(log.contact, 100, stdin);
            printf("Address : ");
            fflush(stdin);
            fgets(log.address, 100, stdin);
            printf("Email : ");
            fflush(stdin);
            fgets(log.email, 100, stdin);
            printf("Password : ");
            fflush(stdin);
            fgets(log.pass, 100, stdin);
            printf("\nEnter 'r' to refill and any other key to save changes ");
            fflush(stdin);
            char a = getch();

            if (a == 'r' || a == 'R')
            {
                goto refill2;
            }

            else
            {
                fseek(file, -sizeof(log), SEEK_CUR);
                fwrite(&log, sizeof(log), 1, file);
            }
        }
        else
        {
            printf("\n!!! User doesn't exist !!!\nPlease re - check the information\n");
            printf("Enter any key to retry ");
            fflush(stdin);
            getch();
            goto refill1;
        }
    }
    fclose(file);

    printf("Press any key to continue ");
    fflush(stdin);
    menu();
}

void logIn()
{
    system("color 0A");
    FILE *file;
    login log;
relogin:
    system("cls");
    printf("\t\t<<-- LOG IN -->>\n\n");
    printf("Username\n");
    fflush(stdin);
    fgets(uname, 100, stdin);
    printf("\nPassword\n");
    fgets(pass, 100, stdin);
    file = fopen("login.txt", "rb+");
    if (file == NULL)
    {
        printf("\nError opening file\n");
        exit(1);
    }

    while (fread(&log, sizeof(login), 1, file))
    {
        if (strcmp(uname, log.uname) == 0 && strcmp(pass, log.pass) == 0)
        {
            printf("\nLogged in successfully : )\n");
            printf("Press any key to continue.");
            fflush(stdin);
            getch();
            system("cls");
            printf("\t\t\tWelcome Mr. %s\n", log.name);
            printf("Your Details\n");
            printf("------------\n");
            printf("Name : %s\n", log.name);
            printf("Contact : %s\n", log.contact);
            printf("Address : %s\n", log.address);
            printf("Email : %s\n", log.email);
        }
        else
        {
            printf("\n!!! User doesn't exist !!!\nPlease re - check the information\n");
            printf("Enter any key to retry ");
            fflush(stdin);
            getch();
            goto relogin;
        }
    }
    fclose(file);

    printf("\nPress any key to continue ");
    fflush(stdin);
    getch();
    menu();
}

void deleteAccount()
{
    system("color 0C");
    FILE *file, *file2;
    login log;
refill:
    system("cls");
    printf("\t\t<<-- DELETE ACCOUNT -->>\n\n");
    printf("Username\n");
    fflush(stdin);
    fgets(uname, 100, stdin);
    printf("\nPassword\n");
    fgets(pass, 100, stdin);
    file = fopen("login.txt", "rb+");
    file2 = fopen("temp.txt", "wb+");

    if (file == NULL)
    {
        printf("\nError opening file\n");
        exit(1);
    }

    while (fread(&log, sizeof(login), 1, file))
    {
        if (strcmp(uname, log.uname) == 0 && strcmp(pass, log.pass) == 0)
        {
            printf("\nDo you really want to delete your account ?\n(Press 'd' to delete and any other key to prevent deletion) ");
            fflush(stdin);
            char a = getch();
            if (a == 'd' | a == 'D')
            {
            }
            else
            {
                fclose(file);
                fclose(file2);
                menu();
            }

            fwrite(&log, sizeof(file2), 1, file2);
            printf("\n\n!!! Account Successfully Deleted !!!\n");
        }
        else
        {
            printf("\n!!! User doesn't exist !!!\nPlease re - check the information\n");
            printf("Enter any key to retry ");
            fflush(stdin);
            getch();
            goto refill;
        }
    }

    fclose(file);
    fclose(file2);
    remove("login.txt");
    rename("temp.txt", "login.txt");

    fflush(stdin);
    printf("\nPress any key to continue ");
    getch();
    menu();
}

int main()
{
    //LogIn System in C
    menu();
    return 0;
}
