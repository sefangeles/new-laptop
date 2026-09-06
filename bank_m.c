#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



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


void createAccount();
void viewAccount();
void deposit();
void withdraw();
void checkBalance();
void searchAccount();
void updateAccount();
void deleteAccount();

int main(){

    int choice;

    while (true) {
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


        scanf("%d", &choice);   

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                checkBalance();
                break;
            case 6:
                searchAccount();
                break;

            case 7:
                updateAccount();
                break;
            
            case 8:
                deleteAccount();
                break;

            case 9:
                printf("Exiting the program.\n");
                exit(0);

        }


    }   
}


void createAccount()
{
    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);

    printf("Name: ");
    scanf("%s", &accounts[accountCount].name);

    printf("Age: ");
    scanf("%d", &accounts[accountCount].age);

    printf("Address: ");
    scanf(" %[^\n]", &accounts[accountCount].address);

    printf("Contact Number: ");
    scanf("%s", &accounts[accountCount].contact);

    printf("Account Type [Saving/Current]: ");
    scanf(" %[^\n]", &accounts[accountCount].accountType);

    printf("Enter Initial Deposit: ");
    scanf("%d", &accounts[accountCount].balance);

    accountCount ++;

    printf("Account Successfully Created!\n");
}

void viewAccount()
{


    int searchNumber;
    bool found = false;
    
    printf("\n========== VIEW ACCOUNT ==========\n");

    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);

    for (int i = 0; i < accountCount; i++){
        
        if(accounts[i].accountNumber == searchNumber){

            printf("Account Number: %d\n", accounts[accountCount].accountNumber);
            printf("Name: %s\n", accounts[accountCount].name);
            printf("Age: %d\n", accounts[accountCount].age);
            printf("Address: &%s\n", accounts[accountCount].address);
            printf("Contact Number: &%s\n", accounts[accountCount].contact);
            printf("Account Type: &%s\n", accounts[accountCount].accountType);
            printf("Balance: &%f\n", accounts[accountCount].balance);
            

            found = true;
            break;
        }

        if (!found){
            printf("Account not found\n");

    }

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

            printf("Current Balance: %.2f\n", accounts[accountCount].balance);

            printf("Enter Deposit Amount: ");
            scanf("%f", amount);

                if(amount > 0){
                    accounts[accountCount].balance += amount;

                    printf("Deposit succesfully\n");
                    printf("New balance: %.2f", accounts[accountCount].balance);
                }

                else {
                    printf("Invalid amount");
                }
                break;
        }
    }

    if(!found){
            printf("Account not found");
    
    }
}

void withdraw()
{
    int searchNumber; 
    bool found = false;
    float amount;


    printf("\n========== WIDRAW ==========\n");

    printf("Enter account number: ");
    scanf("%d", &searchNumber);

    for(int i = 0; i < accountCount; i++){
        if(accounts[i].accountNumber == searchNumber){
            found = true; 
            
            printf("Current Balance: %.2f\n", accounts[i].balance);

            printf("Enter withdrawal amount: ");
            scanf("%.2f", amount);
                if (amount <= 0){
                    printf("Invalid amount.\n");
                }

                else if (amount >  accounts[accountCount].balance){
                    printf("Insufficient balance\n");
                }           
                else {
                    accounts[accountCount].balance -= amount;
                    printf("Withdraw sucessfully\n");
                    printf("New balance: %.2f", accounts[accountCount].balance);
                }
                
                break;
        }
        if (!found){
            printf("Account not found\n");
        }
}
}
void checkBalance()
{
    int searchNumber; 
    bool found = false;
    float amount;


    printf("\n========== CHECKL BALANCE ==========\n");

    printf("Enter account number: ");
    scanf("%d", &searchNumber);

        for( int i = 0; i < accountCount; i++){
            if( accounts[i].accountNumber == searchNumber){
                found = true; 

                printf("================================");
                printf("         ACCOUNT BALANCE        ");
                printf("================================");
                printf("Account Number: %d", accounts[accountCount].accountNumber);
                printf("Current Balance: %.2f", accounts[accountCount].balance);
                printf("================================");


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

            printf("Account Number: %d\n", accounts[accountCount].accountNumber);
            printf("Name: %s\n", accounts[accountCount].name);
            printf("Age: %d\n", accounts[accountCount].age);
            printf("Address: &%s\n", accounts[accountCount].address);
            printf("Contact Number: &%s\n", accounts[accountCount].contact);
            printf("Account Type: &%s\n", accounts[accountCount].accountType);
            printf("Balance: &%f\n", accounts[accountCount].balance);
            

            found = true;
            break;
        }

        if (!found){
            printf("Account not found\n");

    }

}
}


void updateAccount()
{
    int searchNumber;
    bool found = false;


    printf("Account Number: ");
    scanf("%d", &searchNumber);
    for( int i = 0; i < accountCount; i ++){
        if(accounts[i].accountNumber == searchNumber){
            

            printf("Enter New Name: ");
            scanf("%s", &accounts[accountCount].name);

            printf("Enter New Age: ");
            scanf("%d", &accounts[accountCount].age);

            printf("Enter New Address: ");
            scanf(" %[^\n]", &accounts[accountCount].address);

            printf("Enter New Contact Number: ");
            scanf("%s", &accounts[accountCount].contact);

            printf("Enter New Account Type [Saving/Current]");
            scanf(" %[^\n]", &accounts[accountCount].accountType);

        
            found = true;
            
            printf("Account Successfully Updated!\n");

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


    printf("Account Number: ");
    scanf("%d", &searchNumber);
    for( int i = 0; i < accountCount; i ++){
        if(accounts[i].accountNumber == searchNumber){

            found = true;

            for(int j = 1; j < accountCount-1; j++){
                accounts[j] = accounts[j+1];
            }
            
            accountCount--;

            printf("Account deleted successfully!\n");

            break;
        }
        if (!found) {
            printf("Account not found.\n");
        }
    }
}