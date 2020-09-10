#define CRT_SECURE_NO_WARININGS
#include <stdio.h>

typedef struct student
{
    int num;
    char name[30];
    float grade;
}STUDENT;

typedef struct node
{
    STUDENT student;
    struct node *link;
}NODE;

int main()
{
    FILE *fp;
    STUDENT tmp;
    int count=0;
    
    fp = fopen("data.txt","r");
    
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %f",&tmp.num,tmp.name,&tmp.grade);
        count++;
        //printf("%d %s %f \n",tmp.num,tmp.name,tmp.grade);
    }
    
    
}
