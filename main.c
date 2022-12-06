
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int hour = 0; minute = 0; second = 0; flag = 0;

void delay(ms)
{
    clock_t timeDelay = ms + clock();
    while(timeDelay > clock());
}

int counter()
{
    while(!kbhit() && flag == 0)
    {
        if(second > 59)
        {
            second = 0;
            ++minute;
        }
        if(minute > 59)
        {
            minute = 0;
            ++hour;
        }
        printData();
        delay(1000);
        ++second;
    }
    selection();
}

int selection()
{
    switch(getch())    // getch = get character
    {
    case 49:           // 49 = 1
        flag = 0;
        break;
    case 50:           // 50 = 2
        flag = 1;
        break;
    case 51:           // 51 = 3
        hour = minute = second = 0;
        flag = 1;
        printData();
        break;
    case 52:           // 52 = 4
        exit(0);
        break;
    }
}

int printData()
{
    system("cls");
    printf("1.Start 2.Stop 3.Reset 4.End\n");
    printf("****************************\n");
    printf("          %d:%d:%d\n", hour, minute, second);
    printf("****************************\n");
}

int main()
{
    while(1)
    {
        counter();
    }

    //printData();
    return 0;
}
