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

    char Cname;



};

struct student studs[50];
int i = 0;
int rol = 20260001;


void addstud(void);
void Frl(void);
void Fname(void);
void totalS();
void save();
void load();
void update();
void delete();
void ref_screen();


int main(){

    int choice; 
    int courseC;

    load();

    while (true){
    printf("\n===============System Management System================\n"
        "1. Create Account\n"
        "2. Find Student by Name\n"
        "3. Find Student by Roll Number\n"
        "4. Update Student\n"
        "5. Delete Student\n"
        "6. Total Students\n"
        "7. Exit\n");

        printf("\nEnter choice: ");

        if(scanf("%d", &choice) != 1){
            while(getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }

        ref_screen();


        switch(choice){

            case 1:
                addstud();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;
            case 2:
                Fname();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;

            case 3:
                Frl();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;
            
            case 4:
                update();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;
            
            case 5:
                delete();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;

            case 6:
                totalS();

                printf("\nPress Enter to return to Main Menu...");
                while (getchar() != '\n');
                getchar();
                break;
            case 7:

                save();

                printf("Exiting the program. \n");
                exit(0);

            default:
                printf("Invalid option, try again!");

                printf("\nPress Enter to return to Main Menu...");
                while(getchar() != '\n');
                getchar();

        }
    }
    
    return 0;
}
void load(){
    FILE *file;

    file = fopen(FILE_NAME, "r");

    if (file == NULL){
        printf("Student Account Not Found.\n");
        return;
    }


    while(i < 50 && 
        fscanf(file, 
        "%19[^|]|%19[^|]|%d|%f|%d\n",
        studs[i].first,
        studs[i].last,
        &studs[i].roll_n,
        &studs[i].CGPA,
        &studs[i].course,
        studs[i].Cname) == 8){
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

    if (file == NULL){
        printf("Student Account Not Found.\n");
        return;
    }

    for( int x = 0; x < i; x++){

        fprintf(file,"%s|%s|%d|%f|%d\n",
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


    if (i >= 50){
        printf("Account storage is full.\n");
        return;
    }

    studs[i].roll_n = rol;
    rol++;


    printf("First Name: ");
    scanf("%19s", studs[i].first);
    printf("Last Name: ");
    scanf("%19s", studs[i].last);
    printf("Enter you CGPA: ");
    scanf("%f", &studs[i].CGPA);
    printf("\n==========Available Course===========\n"
            "101 - Computer Programming\n"
            "102 - Discrete Mathematics\n"
            "103 - Computer Organization\n"
            "104 - Web Development\n"
            "105 - Database Systems\n"
            );
    scanf("%d", &studs[i].course);
            
            if (studs[i].course == 101){
                strcpy(studs[i].Cname, "Computer Programming");
            }
                else if (studs[i].course == 102){
                strcpy(studs[i].Cname, "Discrete Mathematics");
            }
                else if (studs[i].course == 103){
                strcpy(studs[i].Cname, "Computer Organization");
            }
            
            else if (studs[i].course == 104){
                strcpy(studs[i].Cname, "Web Development");
            }

            else if (studs[i].course == 105){
                strcpy(studs[i].Cname, "Database Systems");
            }

                else{
                    printf("Invalid Course Id\n");
                    return;
                }

        printf("\nAccount Successfully Created!\n");
        printf("Your Roll Number: %d\n", studs[i].roll_n);

    i++;

    save();

    
}

void Frl(){


    int find;
    bool found = false;


    printf("Enter your Roll Number: ");
    scanf("%d", &find);


    for (int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            printf("NAME: %s %s\n", studs[x].first, studs[x].last);
            printf("ROLL NUMBER: %d\n", studs[x].roll_n);
            printf("CGPA: %.2f\n", studs[x].CGPA);
            printf("COURSE: %d - %s\n", studs[x].course, studs[x].Cname);

            found = true;
            break;
        
    }

    if (!found){
        printf("Roll Number not found..");
    }
}
}

void Fname(){
    
    char find;
    bool found = false;

    printf("Enter your First Name: ");
    scanf("%19s", &find);

    for(int x = 0; x < i; x++){
        if(strcmp(studs[x].first, find) == 0)


        printf("Name: %s %S\n", studs[x].first, studs[x].last);
        printf("Roll Number: %d\n", studs[x].roll_n);
        printf("CGPA: %f\n", studs[x].CGPA);
        printf("COURSE: %d - %s\n", studs[x].course, studs[x].Cname);


        found = true;
        break;


    }

}



void totalS(){
    printf("================================ ");
    printf("The total number of students "
            "is %d\n", i);
    printf("\nYou can only have maximum # "
            "of 50 students\n");
    printf("\nYou can have %d more students", 50 - i);
    printf("================================ ");
}



void update(){
    int find;
    bool found = false;


    printf("Enter your Roll Number: ");
    scanf("%d", &find);


    for(int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            printf("First Name: ");
            scanf("%s", &studs[x].first);

            printf("Last Name: ");
            scanf("%s", &studs[x].last);

            printf("Enter you CGPA: ");
            scanf("%f", &studs[x].CGPA);



            printf("==========Available Course==========="
                    "101 - Computer Programming"
                    "102 - Discrete Mathematics"
                    "103 - Computer Organization"
                    "104 - Web Development"
                    "105 - Database Systems"
                    );
            scanf("%d", &studs[i].course);
            found = true;
            break;

        }
    }
    
    if (!found){
        printf("Account not found.\n");
    }

}

void delete(){


    int find;
    bool found = false;


    printf("Enter your Roll Number: ");
    scanf("%d", &find);

    for(int x = 0; x < i; x++){

        if(studs[x].roll_n == find){
            found = true;


            for(int j = x; j < i - 1; j++){
                studs[j] = studs[j + 1];
            }


            i--;

            save();
            printf("Account deleted successfully!\n");
            break;
        }
        
        if (!found){
            printf("Account not found.\n");
        }
    }
}


