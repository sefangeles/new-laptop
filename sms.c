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
    int course[15];
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

            case 6:
                totalS();
            
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
    
}
void load(){
    FILE *file;

    file = fopen(FILE_NAME, "r");

    if (file == NULL){
        printf("Student Account Not Found.");
    }


    while(i < 100 && 
        fscanf(file, 
        "[%49[^|]|%20[^|]|%d|%f|%d",
        studs[i].first,
        studs[i].last,
        &studs[i].roll_n,
        &studs[i].CGPA,
        &studs[i].course) == 5){
            if(studs[i].roll_n >= rol){
                rol = studs[i].roll_n + 1;
            }
            i++;
        }

        fclose(file);
}

void ref_screen(){

    printf("\033[H\033[j");
    fflush(stdout);
}

void save(){
    FILE *file;

    file = fopen(FILE_NAME, "w");

    if (file == NULL){
        printf("Student Account Not Found.");
        
    }

    for( int x = 0; x < i; x++){

        fprintf(file,"%s|%s|%d|%f|%d",
                studs[x].first,
                studs[x].last,
                studs[x].roll_n,
                studs[x].CGPA,
                studs[x].course);

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
    scanf("%s", &studs[i].first);
    printf("Last Name: ");
    scanf("%s", &studs[i].last);
    printf("Enter you CGPA: ");
    scanf("%.2f", &studs[i].CGPA);
    printf("==========Available Course==========="
            "101 - Computer Programming"
            "102 - Discrete Mathematics"
            "103 - Computer Organization"
            "104 - Web Development"
            "105 - Database Systems"
            );
    scanf("%s", &studs[i].course);

            

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

            printf("NAME: %s %s\n", studs[x].first, studs[i].last);
            printf("CGPA: %.2f\n", studs[x].CGPA);
            printf("COURSE: %d", studs[x].course);

            found = true;
            break;
        
    }

    if (!found){
        printf("Roll Number not found..");
    }
}
}

void Fname(){
    
    char find[20];
    bool found = false;

    printf("Enter your First Name: ");
    scanf("%d", &find);

    for(int x = 0; x < i; x++){
        if(studs[x].first == find)


        printf("First Name: %s", studs[x].first);
        printf("Last Name: %s", studs[x].last);
        printf("Roll Number: %d", studs[x].roll_n);
        printf("CGPA: %f", studs[x].CGPA);
        printf("Course ID: %d", studs[x].course);


        found = true;
        break;


    }

}



void totalS(){

    printf("The total number of students "
            "is %d\n", i);

    printf("\nYou can only have maximum # "
            "of 50 students\n");

    printf("\nYou can have %d more students", 50 - i);
    
}



void update(){
    int find;
    bool found = false;


    printf("Enter your Roll Number: ");
    scanf("%d", &find);


    for(int x = 0; x < i; i++){

        if(studs[x].roll_n == find){


            found = true;
            break;

        }
    }

}

void delete(){
    printf("");
}