#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define FILE_NAME "sms.txt"

struct student{
    char first[20];
    char last[20];
    int roll_n;
    float CGPA;
    int course;
    char Cname[50];
};

struct student studs[50];

int i = 0;
int rol = 20260001;

void addstud(void);
void Frl(void);
void Fname(void);
void totalS(void);
void save(void);
void load(void);
void update(void);
void delete(void);
void ref_screen(void);
void header(void);
void menu(void);
void pause_screen(void);

int main(){

    int choice;

    load();

    while(true){

        ref_screen();
        header();
        menu();

        printf("\n  Enter your choice: ");

        if(scanf("%d", &choice) != 1){

            while(getchar() != '\n');

            printf("\n  [!] Invalid input. Please enter a number.");

            pause_screen();

            continue;
        }

        while(getchar() != '\n');

        switch(choice){

            case 1:

                ref_screen();
                addstud();

                break;

            case 2:

                ref_screen();
                Fname();

                break;

            case 3:

                ref_screen();
                Frl();

                break;

            case 4:

                ref_screen();
                update();

                break;

            case 5:

                ref_screen();
                delete();

                break;

            case 6:

                ref_screen();
                totalS();

                break;

            case 7:

                ref_screen();

                printf("\n");
                printf("============================================================\n");
                printf("||                                                        ||\n");
                printf("||              THANK YOU FOR USING SMS!                 ||\n");
                printf("||                                                        ||\n");
                printf("||                  EXITING SYSTEM...                    ||\n");
                printf("||                                                        ||\n");
                printf("============================================================\n");

                save();

                return 0;

            default:

                printf("\n");
                printf("------------------------------------------------------------\n");
                printf("  [!] Invalid option.\n");
                printf("  [!] Please choose a number from 1 to 7.\n");
                printf("------------------------------------------------------------\n");

                pause_screen();

                break;
        }
    }

    return 0;
}

void header(){
    

    printf("\033[H\033[J");

    printf("\n");
    printf("============================================================\n");
    printf("||                                                        ||\n");
    printf("||              STUDENT MANAGEMENT SYSTEM                 ||\n");
    printf("||                                                        ||\n");
    printf("||              STUDENT INFORMATION PORTAL                ||\n");
    printf("||                                                        ||\n");
    printf("============================================================\n");
}

void menu(){

    printf("\n");
    printf("                     MAIN MENU\n");
    printf("------------------------------------------------------------\n");

    printf("  [1]  Create Student Account\n");
    printf("  [2]  Find Student by Name\n");
    printf("  [3]  Find Student by Roll Number\n");
    printf("  [4]  Update Student Information\n");
    printf("  [5]  Delete Student Account\n");
    printf("  [6]  View Total Students\n");
    printf("  [7]  Exit System\n");

    printf("------------------------------------------------------------\n");
}

void pause_screen(){

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("  Press ENTER to return to Main Menu...");
    printf("\n------------------------------------------------------------");

    getchar();
}

void load(){

    FILE *file;

    file = fopen(FILE_NAME, "r");

    if(file == NULL){
        return;
    }

    while(i < 50 &&
          fscanf(file,
          "%19[^|]|%19[^|]|%d|%f|%d-%49[^\n]\n",
          studs[i].first,
          studs[i].last,
          &studs[i].roll_n,
          &studs[i].CGPA,
          &studs[i].course,
          studs[i].Cname) == 6){

        if(studs[i].roll_n >= rol){
            rol = studs[i].roll_n + 1;
        }

        i++;
    }

    fclose(file);
}

void ref_screen(){

    printf("\033[H\033[J");

    fflush(stdout);
}

void save(){

    FILE *file;

    file = fopen(FILE_NAME, "w");

    if(file == NULL){

        printf("\n");
        printf("------------------------------------------------------------\n");
        printf("  [!] Unable to save student data.\n");
        printf("------------------------------------------------------------\n");

        return;
    }

    for(int x = 0; x < i; x++){

        fprintf(file,
                "%s|%s|%d|%f|%d-%s\n",
                studs[x].first,
                studs[x].last,
                studs[x].roll_n,
                studs[x].CGPA,
                studs[x].course,
                studs[x].Cname);
    }

    fclose(file);
}

void addstud(){

    if(i >= 50){

        printf("\n");
        printf("============================================================\n");
        printf("                    STORAGE FULL\n");
        printf("============================================================\n");

        printf("  [!] Student storage is full.\n");
        printf("  [!] Maximum students: 50\n");

        printf("============================================================\n");

        pause_screen();

        return;
    }

    printf("\n");
    printf("============================================================\n");
    printf("                    CREATE ACCOUNT\n");
    printf("============================================================\n");

    printf("\n");
    printf("                  STUDENT INFORMATION\n");
    printf("------------------------------------------------------------\n");

    printf("  First Name       : ");
    scanf("%19s", studs[i].first);

    printf("  Last Name        : ");
    scanf("%19s", studs[i].last);

    printf("  CGPA             : ");
    scanf("%f", &studs[i].CGPA);

    printf("\n");
    printf("============================================================\n");
    printf("                    AVAILABLE COURSES\n");
    printf("============================================================\n");

    printf("  [101]  Computer Programming\n");
    printf("  [102]  Discrete Mathematics\n");
    printf("  [103]  Computer Organization\n");
    printf("  [104]  Web Development\n");
    printf("  [105]  Database Systems\n");

    printf("------------------------------------------------------------\n");

    printf("  Enter Course ID  : ");
    scanf("%d", &studs[i].course);

    if(studs[i].course == 101){

        strcpy(studs[i].Cname,
               "Computer Programming");
    }

    else if(studs[i].course == 102){

        strcpy(studs[i].Cname,
               "Discrete Mathematics");
    }

    else if(studs[i].course == 103){

        strcpy(studs[i].Cname,
               "Computer Organization");
    }

    else if(studs[i].course == 104){

        strcpy(studs[i].Cname,
               "Web Development");
    }

    else if(studs[i].course == 105){

        strcpy(studs[i].Cname,
               "Database Systems");
    }

    else{

        printf("\n");
        printf("------------------------------------------------------------\n");
        printf("  [!] Invalid Course ID.\n");
        printf("  [!] Account creation cancelled.\n");
        printf("------------------------------------------------------------\n");

        while(getchar() != '\n');

        pause_screen();

        return;
    }

    studs[i].roll_n = rol;

    rol++;

    printf("\n");
    printf("============================================================\n");
    printf("                  ACCOUNT CREATED!\n");
    printf("============================================================\n");

    printf("  Name        : %s %s\n",
           studs[i].first,
           studs[i].last);

    printf("  Roll Number : %d\n",
           studs[i].roll_n);

    printf("  CGPA        : %.2f\n",
           studs[i].CGPA);

    printf("  Course      : %d - %s\n",
           studs[i].course,
           studs[i].Cname);

    printf("============================================================\n");

    i++;

    save();

    pause_screen();
}

void Frl(){

    int find;

    bool found = false;

    printf("\n");
    printf("============================================================\n");
    printf("              FIND STUDENT - ROLL NUMBER\n");
    printf("============================================================\n");

    printf("\n");
    printf("  Enter Roll Number : ");

    scanf("%d", &find);

    printf("\n");
    printf("------------------------------------------------------------\n");

    for(int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            printf("\n");
            printf("                  STUDENT FOUND\n");
            printf("------------------------------------------------------------\n");

            printf("  Name        : %s %s\n",
                   studs[x].first,
                   studs[x].last);

            printf("  Roll Number : %d\n",
                   studs[x].roll_n);

            printf("  CGPA        : %.2f\n",
                   studs[x].CGPA);

            printf("  Course ID   : %d\n",
                   studs[x].course);

            printf("  Course Name : %s\n",
                   studs[x].Cname);

            printf("------------------------------------------------------------\n");

            found = true;

            break;
        }
    }

    if(!found){

        printf("\n");
        printf("  [!] Student with Roll Number %d was not found.\n",
               find);

        printf("------------------------------------------------------------\n");
    }

    while(getchar() != '\n');

    pause_screen();
}

void Fname(){

    char find[20];

    bool found = false;

    printf("\n");
    printf("============================================================\n");
    printf("                FIND STUDENT - NAME\n");
    printf("============================================================\n");

    printf("\n");
    printf("  Enter First Name : ");

    scanf("%19s", find);

    printf("\n");
    printf("------------------------------------------------------------\n");

    for(int x = 0; x < i; x++){

        if(strcmp(studs[x].first, find) == 0){

            printf("\n");
            printf("                  STUDENT FOUND\n");
            printf("------------------------------------------------------------\n");

            printf("  Name        : %s %s\n",
                   studs[x].first,
                   studs[x].last);

            printf("  Roll Number : %d\n",
                   studs[x].roll_n);

            printf("  CGPA        : %.2f\n",
                   studs[x].CGPA);

            printf("  Course ID   : %d\n",
                   studs[x].course);

            printf("  Course Name : %s\n",
                   studs[x].Cname);

            printf("------------------------------------------------------------\n");

            found = true;

            break;
        }
    }

    if(!found){

        printf("\n");
        printf("  [!] Student named \"%s\" was not found.\n",
               find);

        printf("------------------------------------------------------------\n");
    }

    while(getchar() != '\n');

    pause_screen();
}

void totalS(){

    printf("\n");
    printf("============================================================\n");
    printf("                    STUDENT STATISTICS\n");
    printf("============================================================\n");

    printf("\n");
    printf("                  CURRENT CAPACITY\n");
    printf("------------------------------------------------------------\n");

    printf("  Total Students       : %d\n", i);

    printf("  Maximum Capacity     : 50\n");

    printf("  Available Slots      : %d\n",
           50 - i);

    printf("------------------------------------------------------------\n");

    if(i == 50){

        printf("  Status               : FULL\n");
    }

    else{

        printf("  Status               : AVAILABLE\n");
    }

    printf("============================================================\n");

    pause_screen();
}

void update(){

    int find;

    bool found = false;

    printf("\n");
    printf("============================================================\n");
    printf("              UPDATE STUDENT INFORMATION\n");
    printf("============================================================\n");

    printf("\n");
    printf("  Enter Roll Number : ");

    scanf("%d", &find);

    for(int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            found = true;

            printf("\n");
            printf("------------------------------------------------------------\n");

            printf("  Student Found: %s %s\n",
                   studs[x].first,
                   studs[x].last);

            printf("------------------------------------------------------------\n");

            printf("\n");
            printf("                  UPDATE INFORMATION\n");

            printf("------------------------------------------------------------\n");

            printf("  New First Name : ");

            scanf("%19s", studs[x].first);

            printf("  New Last Name  : ");

            scanf("%19s", studs[x].last);

            printf("  New CGPA       : ");

            scanf("%f", &studs[x].CGPA);

            printf("\n");
            printf("============================================================\n");
            printf("                    AVAILABLE COURSES\n");
            printf("============================================================\n");

            printf("  [101]  Computer Programming\n");
            printf("  [102]  Discrete Mathematics\n");
            printf("  [103]  Computer Organization\n");
            printf("  [104]  Web Development\n");
            printf("  [105]  Database Systems\n");

            printf("------------------------------------------------------------\n");

            printf("  New Course ID  : ");

            scanf("%d", &studs[x].course);

            if(studs[x].course == 101){

                strcpy(studs[x].Cname,
                       "Computer Programming");
            }

            else if(studs[x].course == 102){

                strcpy(studs[x].Cname,
                       "Discrete Mathematics");
            }

            else if(studs[x].course == 103){

                strcpy(studs[x].Cname,
                       "Computer Organization");
            }

            else if(studs[x].course == 104){

                strcpy(studs[x].Cname,
                       "Web Development");
            }

            else if(studs[x].course == 105){

                strcpy(studs[x].Cname,
                       "Database Systems");
            }

            else{

                printf("\n");
                printf("------------------------------------------------------------\n");
                printf("  [!] Invalid Course ID.\n");
                printf("  [!] Update cancelled.\n");
                printf("------------------------------------------------------------\n");

                while(getchar() != '\n');

                pause_screen();

                return;
            }

            save();

            printf("\n");
            printf("============================================================\n");
            printf("                 INFORMATION UPDATED!\n");
            printf("============================================================\n");

            printf("  Name   : %s %s\n",
                   studs[x].first,
                   studs[x].last);

            printf("  CGPA   : %.2f\n",
                   studs[x].CGPA);

            printf("  Course : %d - %s\n",
                   studs[x].course,
                   studs[x].Cname);

            printf("============================================================\n");

            break;
        }
    }

    if(!found){

        printf("\n");
        printf("------------------------------------------------------------\n");

        printf("  [!] Account not found.\n");

        printf("------------------------------------------------------------\n");
    }

    while(getchar() != '\n');

    pause_screen();
}

void delete(){

    int find;

    bool found = false;

    printf("\n");
    printf("============================================================\n");
    printf("                    DELETE STUDENT\n");
    printf("============================================================\n");

    printf("\n");
    printf("  Enter Roll Number : ");

    scanf("%d", &find);

    for(int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            found = true;

            printf("\n");
            printf("------------------------------------------------------------\n");

            printf("  Student Found\n");

            printf("------------------------------------------------------------\n");

            printf("  Name        : %s %s\n",
                   studs[x].first,
                   studs[x].last);

            printf("  Roll Number : %d\n",
                   studs[x].roll_n);

            printf("  Course      : %d - %s\n",
                   studs[x].course,
                   studs[x].Cname);

            printf("------------------------------------------------------------\n");

            for(int j = x; j < i - 1; j++){

                studs[j] = studs[j + 1];
            }

            i--;

            save();

            printf("\n");
            printf("============================================================\n");
            printf("                  ACCOUNT DELETED!\n");
            printf("============================================================\n");

            printf("  Student account has been successfully removed.\n");

            printf("============================================================\n");

            break;
        }
    }

    if(!found){

        printf("\n");
        printf("------------------------------------------------------------\n");

        printf("  [!] Account not found.\n");

        printf("------------------------------------------------------------\n");
    }

    while(getchar() != '\n');

    pause_screen();
}