#include <stdio.h>
#include <conio.h>
void main()
{ 
    char pass[30]="admin123";
    char pass1[30];
    int i=0;
    char ch;
    clrscr();
    printf("Enter the password:");
    do 
    {
        ch=getch();
        if (i==0 && ch =='\b')
        {
            continue;
        }
    if (ch == '\b')
    {
        printf("\b \b");
        i--;
        continue;
    }
    else if (ch != '\r')
    {
        printf("*");
        pass1[i++]=ch;
    }
}while(ch!='\r');
    pass1[i]='\0';

    getch();
} 