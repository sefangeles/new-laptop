#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define FILE_NAME "sms.txt" 

int i = 0;
struct student{
    char first[20];
    char last[20];
    int roll_n;
    float CGPA;
    int course[15];
};

struct student studs[50];

void load(){
    FILE *file;

    file = fopen(FILE_NAME, "r");

    if (file == NULL){
        printf("Student Account Not Found.");
    }
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
}

void add_stud(){
    printf("First Name: ");
    scanf("%s", &studs[i].first);
    printf("Last Name: ");
    scanf("%s", &studs[i].last);
    printf("Enter Roll Number: ");
    scanf("%d", &studs[i].roll_n);
    printf("Enter you CGPA: ");
    scanf("%.2f", &studs[i].CGPA);
    printf("Course: ");
    scanf("%s", &studs[i].course);
    
}

void f_rl(){


    int find;
    bool found = false;


    printf("Enter your Roll Number: ");
    scanf("%d", &find);


    for (int x = 0; x < i; x++){

        if(studs[x].roll_n == find){

            printf("NAME: %s %s\n", studs[i].first, studs[i].last);
            printf("CGPA: %.2f\n", studs[i].CGPA);
            printf("COURSE: %d", studs[i].course);

            found = true;
            break;
           
    }

    if (!found){
        printf("Roll Number not found..");
    }
}

void f_name(){
    char find[20] = 0;
    bool found = false;

    printf("Enter your Roll Number: ");
    scanf("%d", &find);


}



