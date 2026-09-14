
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define FILE_NAME "bank_m.txt"


struct account {
    int accountNumber;
    char name[50];
    int age;
    char address[100];
    char contact[20];
    char accountType[20];
    float balance;
};


struct account accounts[100];
int accountCount = 0;
int nextAccountNumber = 100001;


void createAccount();
void viewAccount();
void deposit();
void withdraw();
void checkBalance();
void searchAccount();
void updateAccount();
void deleteAccount();
void saveAccount();
void loadAccount();
void refreshScreen();


int main(){

    int choice;

    loadAccount();

    while (true) {

        refreshScreen();

        printf("\nWelcome to the Bank Management System\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Check Balance\n");
        printf("6. Search Account\n");
        printf("7. Update Account\n");
        printf("8. Delete account\n");
        printf("9. Exit\n");


        printf("\nEnter choice: ");

        if(scanf("%d", &choice) != 1){
            while(getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }


        refreshScreen();


        switch(choice) {

            case 1:
                createAccount();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 2:
                viewAccount();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 3:
                deposit();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 4:
                withdraw();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 5:
                checkBalance();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 6:
                searchAccount();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 7:
                updateAccount();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 8:
                deleteAccount();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;


            case 9:
                saveAccount();

                printf("Exiting the program.\n");
                exit(0);


            default:
                printf("Invalid option, try again!");

                printf("\nPress Enter to return to Main Menu...");
                while(getchar() != '\n');
                getchar();

        }

    }
}


void createAccount()
{

    if(accountCount >= 100){
        printf("Account storage is full.\n");
        return;
    }


    accounts[accountCount].accountNumber = nextAccountNumber;
    nextAccountNumber++;


    printf("\n========== CREATE ACCOUNT ==========\n");


    printf("Name: ");
    scanf(" %49[^\n]", accounts[accountCount].name);


    printf("Age: ");
    scanf("%d", &accounts[accountCount].age);


    printf("Address: ");
    scanf(" %99[^\n]", accounts[accountCount].address);


    while (1){

        printf("Contact Number: ");
        scanf("%19s", accounts[accountCount].contact);

        if(strlen(accounts[accountCount].contact) == 11){
            break;
        }

        printf("Invalid contact number. Must be exactly 11 digits.\n");
    }


    printf("Account Type [Savings/Current]: ");
    scanf(" %19[^\n]", accounts[accountCount].accountType);


    printf("Enter Initial Deposit: ");
    scanf("%f", &accounts[accountCount].balance);


    printf("\nAccount Successfully Created!\n");
    printf("Your Account Number: %d\n",
           accounts[accountCount].accountNumber);


    accountCount++;


    saveAccount();

}


void viewAccount()
{

    int searchNumber;
    bool found = false;


    printf("\n========== VIEW ACCOUNT ==========\n");


    printf("Enter account number: ");
    scanf("%d", &searchNumber);


    for (int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            printf("\nAccount Number: %d\n",
                   accounts[i].accountNumber);

            printf("Name: %s\n",
                   accounts[i].name);

            printf("Age: %d\n",
                   accounts[i].age);

            printf("Address: %s\n",
                   accounts[i].address);

            printf("Contact Number: %s\n",
                   accounts[i].contact);

            printf("Account Type: %s\n",
                   accounts[i].accountType);

            printf("Balance: %.2f\n",
                   accounts[i].balance);


            found = true;
            break;
        }

    }


    if (!found){
        printf("Account not found\n");
    }

}


void deposit()
{

    int searchNumber;
    bool found = false;
    float amount;


    printf("\n========== DEPOSIT ==========\n");


    printf("Enter account number: ");
    scanf("%d", &searchNumber);


    for(int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            found = true;


            printf("Current Balance: %.2f\n",
                   accounts[i].balance);


            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);


            if(amount > 0){

                accounts[i].balance += amount;


                printf("Deposit successfully\n");


                saveAccount();


                printf("New balance: %.2f\n",
                       accounts[i].balance);
            }

            else {

                printf("Invalid amount\n");

            }


            break;
        }

    }


    if(!found){
        printf("Account not found\n");
    }

}


void withdraw()
{

    int searchNumber;
    bool found = false;
    float amount;


    printf("\n========== WITHDRAW ==========\n");


    printf("Enter account number: ");
    scanf("%d", &searchNumber);


    for(int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            found = true;


            printf("Current Balance: %.2f\n",
                   accounts[i].balance);


            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);


            if (amount <= 0){

                printf("Invalid amount.\n");

            }


            else if (amount > accounts[i].balance){

                printf("Insufficient balance\n");

            }


            else {

                accounts[i].balance -= amount;


                printf("Withdraw successfully\n");


                saveAccount();


                printf("New balance: %.2f\n",
                       accounts[i].balance);
            }


            break;
        }

    }


    if (!found){

        printf("Account not found\n");

    }

}


void checkBalance()
{

    int searchNumber;
    bool found = false;


    printf("\n========== CHECK BALANCE ==========\n");


    printf("Enter account number: ");
    scanf("%d", &searchNumber);


    for(int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            found = true;


            printf("\n================================\n");
            printf("         ACCOUNT BALANCE        \n");
            printf("================================\n");


            printf("Account Number: %d\n",
                   accounts[i].accountNumber);

            printf("Current Balance: %.2f\n",
                   accounts[i].balance);


            printf("================================\n");


            break;

        }

    }


    if(!found){

        printf("Account not found\n");

    }

}


void searchAccount()
{

    int searchNumber;
    bool found = false;


    printf("\n========== SEARCH ACCOUNT ==========\n");


    printf("Enter account number: ");
    scanf("%d", &searchNumber);


    for (int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            printf("\nAccount Number: %d\n",
                   accounts[i].accountNumber);

            printf("Name: %s\n",
                   accounts[i].name);

            printf("Age: %d\n",
                   accounts[i].age);

            printf("Address: %s\n",
                   accounts[i].address);

            printf("Contact Number: %s\n",
                   accounts[i].contact);

            printf("Account Type: %s\n",
                   accounts[i].accountType);

            printf("Balance: %.2f\n",
                   accounts[i].balance);


            found = true;
            break;
        }

    }


    if (!found){

        printf("Account not found\n");

    }

}


void updateAccount()
{

    int searchNumber;
    bool found = false;


    printf("\n========== UPDATE ACCOUNT ==========\n");


    printf("Account Number: ");
    scanf("%d", &searchNumber);


    for(int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            printf("Enter New Name: ");
            scanf(" %49[^\n]", accounts[i].name);


            printf("Enter New Age: ");
            scanf("%d", &accounts[i].age);


            printf("Enter New Address: ");
            scanf(" %99[^\n]", accounts[i].address);


            printf("Enter New Contact Number: ");
            scanf("%19s", accounts[i].contact);


            printf("Enter New Account Type [Saving/Current]: ");
            scanf(" %19[^\n]", accounts[i].accountType);


            found = true;


            saveAccount();


            printf("Account Successfully Updated!\n");


            break;
        }

    }


    if(!found){

        printf("Account not found\n");

    }

}


void deleteAccount()
{

    int searchNumber;
    bool found = false;


    printf("\n========== DELETE ACCOUNT ==========\n");


    printf("Account Number: ");
    scanf("%d", &searchNumber);


    for(int i = 0; i < accountCount; i++){

        if(accounts[i].accountNumber == searchNumber){

            found = true;


            for(int j = i; j < accountCount - 1; j++){

                accounts[j] = accounts[j + 1];

            }


            accountCount--;


            saveAccount();


            printf("Account deleted successfully!\n");


            break;
        }

    }


    if (!found) {

        printf("Account not found.\n");

    }

}


void saveAccount()
{

    FILE *file;


    file = fopen(FILE_NAME, "w");


    if(file == NULL){

        printf("Unable to open file.\n");
        return;

    }


    for(int i = 0; i < accountCount; i++){

        fprintf(file,
                "%d|%s|%d|%s|%s|%s|%.2f\n",
                accounts[i].accountNumber,
                accounts[i].name,
                accounts[i].age,
                accounts[i].address,
                accounts[i].contact,
                accounts[i].accountType,
                accounts[i].balance);

    }


    fclose(file);

}


void loadAccount()
{

    FILE *file;


    file = fopen(FILE_NAME, "r");


    if(file == NULL){

        printf("No file, starting with empty accounts.\n");
        return;

    }


    while(accountCount < 100 &&
          fscanf(file,
                 "%d|%49[^|]|%d|%99[^|]|%19[^|]|%19[^|]|%f\n",
                 &accounts[accountCount].accountNumber,
                 accounts[accountCount].name,
                 &accounts[accountCount].age,
                 accounts[accountCount].address,
                 accounts[accountCount].contact,
                 accounts[accountCount].accountType,
                 &accounts[accountCount].balance) == 7){

        if(accounts[accountCount].accountNumber >= nextAccountNumber){

            nextAccountNumber =
                accounts[accountCount].accountNumber + 1;

        }


        accountCount++;

    }


    fclose(file);

}


void refreshScreen()
{

    printf("\033[H\033[J");
    fflush(stdout);

}

