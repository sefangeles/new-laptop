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


int main(){
    printf("\n===============System Management System================\n"
           "1. Create Account\n"
           "2. Create Account\n"
           "3. Create Account\n"
           "4. Create Account\n");
}
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
    printf("Course: ");
    scanf("%s", &studs[i].course);

        printf("\nAccount Successfully Created!\n");
        printf("Your Roll Number: %d\n", studs[i].roll_n);

    i++;

    save();

    
}

void f_rl(){


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

void f_name(){
    
    char find[20] = 0;
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



void total_s(){

    printf("The total number of students "
            "is %d\n", i);

    printf("\nYou can only have maximum # "
            "of 50 students\n");

    printf("\nYou can have %d more students", 50 - i);
    
}



void update(){

}

void delete(){
    printf("");
}