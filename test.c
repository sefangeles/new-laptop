#include <stdio.h>
#include <stdlib.h>

void refreshScreen() {
    // \033[H moves cursor to row 1, column 1 (absolute top-left)
    // \033[J clears everything from the cursor position to the end of the screen
    printf("\033[H\033[J"); 
    fflush(stdout);
}

int main() {
    int choice = 0;

    while (choice != 3) {
        refreshScreen(); // Jump to top-left and clear previous text

        // 1. Draw the Menu right at the top
        printf("=== MAIN MENU ===\n");
        printf("1. View Profile\n");
        printf("2. Settings\n");
        printf("3. Exit\n");
        printf("=================\n");
        printf("Enter your choice: ");
        
        // 2. Read choice
        if (scanf("%d", &choice) != 1) {
            // Fix for infinite loops if a user types letters instead of a number
            while (getchar() != '\n'); 
            continue;
        }

        refreshScreen(); // Instantly jump back to the top-left and clear the menu text
        
        switch(choice) {
            case 1:
                printf("--- PROFILE PAGE ---\n");
                printf("Name: John Doe\n");
                printf("Role: Developer\n\n");
                
                printf("Press Enter to return to Main Menu...");
                while (getchar() != '\n'); // Clear input buffer
                getchar();                 // Wait for actual Enter press
                break;

            case 2:
                printf("--- SETTINGS PAGE ---\n");
                printf("[*] Dark Mode: Enabled\n");
                printf("[ ] Notifications: Disabled\n\n");
                
                printf("Press Enter to return to Main Menu...");
                while (getchar() != '\n'); 
                getchar();                 
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option! Try again.\n\n");
                printf("Press Enter to continue...");
                while (getchar() != '\n'); 
                getchar();
                break;
        }
    }

    return 0;
}
