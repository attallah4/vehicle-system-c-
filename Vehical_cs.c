#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcs_Interface.h"
#include "Vehical_cs_Interface.h"



/*************state vars****************/

STATUS_T AC=OFF;
STATUS_T engine_temp_ctrl=OFF;
STATUS_T engine_state=OFF;
char vehicle_speed=0;
float room_temp=20;
float engine_temp=125;

/************************************/

void vehical_menu_init(void)
{
    int choice=4;
    do
    {
        printf("       ****************************\n");
        printf("       *  WELCOME TO THE VEHICLE  *\n");
        printf("       ****************************\n");
        printf("1. Turn on  the vehicle engine\n");
        printf("2. Turn off the vehicle engine\n");
        printf("3. Quit the system\n");
        printf("choice :");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            engine_state=ON;
            turn_on();
            break;
        case 2:
            engine_state=OFF;
            system("cls");
            printf("       *****************************\n");
            printf("       * The vehicle is turned off *\n");
            printf("       *****************************\n");

            break;
        case 3:
            system("cls");
            printf("       **********************************************\n");
            printf("       * Thank you for using our services. Goodbye. *\n");
            printf("       **********************************************\n");
            choice=4;
            break;
        default:
            system("cls");
            printf("       ************************************\n");
            printf("       * Wrong choice!! Please try again. *\n");
            printf("       ************************************\n");
            break;
        }
    }
    while (choice != 4);
}


void turn_on(void)
{
    system("cls");
    int choice=4;
    do
    {
        printf("       ****************************\n");
        printf("       * The vehicle is turned on *\n");
        printf("       ****************************\n");
        printf("1. Turn off the engine\n");
        printf("2. Set the traffic light color\n");
        printf("3. Set the room temperature\n");
        printf("4. Set the engine temperature\n");
        printf("choice :");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            engine_state=OFF;
            system("cls");
            printf("       *****************************\n");
            printf("       * The vehicle is turned off *\n");
            printf("       *****************************\n");
            choice=5;
            break;
        case 2:
            set_traffic_light();
            print_states();

            break;
        case 3:
            set_room_temp();
            print_states();
            break;
        case 4:
            set_engine_temp();
            print_states();
            break;
        }
    }
    while (choice != 5);
}
void set_traffic_light(void)
{
    char light='R';
    char flag=1;

    printf("The Light(G-R-O):");
    do
    {
        scanf("%c",&light);
        switch(light)
        {
        case 'R' :
            system("cls");
            vehicle_speed=0;
            flag=0;
            break;
        case 'G' :
            system("cls");
            vehicle_speed=100;
            flag=0;
            break;
        case 'O' :
            system("cls");
            vehicle_speed=30;
            AC=ON;
            room_temp=(room_temp*5/4)+1;
            engine_temp_ctrl=ON;
            engine_temp=(engine_temp*5/4)+1;
            flag=0;
            break;
        }
    }
    while(flag);
}

void set_room_temp(void)
{
    char flag=1;
    printf("The Room Temperature:");
    do
    {
        scanf("%f",&room_temp);
        if(room_temp<10)
        {
            system("cls");
            AC=ON;
            room_temp=20;
            flag=0;
        }
        else if (room_temp >30)
        {
            system("cls");
             AC=ON;
            room_temp=20;
            flag=0;
        }
        else
        {
            system("cls");
             AC=OFF;
            flag=0;
        }
    }
    while(flag);

}

void set_engine_temp(void)
{
    char flag=1;
    printf("The Engine Temperature:");
    do
    {
        scanf("%f",&engine_temp);
        if(engine_temp<100)
        {
            system("cls");
            engine_temp_ctrl=ON;
            engine_temp=125;
            flag=0;
        }
        else if (engine_temp >150)
        {
            system("cls");
            engine_temp_ctrl=ON;
            engine_temp=125;
            flag=0;
        }
        else
        {
            system("cls");
           engine_temp_ctrl=OFF;
            flag=0;
        }
    }
    while(flag);
}


void print_states(void)
{
                            printf("*************VEHICLE STATE*****************\n");
     (engine_state)?        printf("* -Engine State :ON                        \n") :  printf("* -Engine State :OFF                       \n");
     (AC)?                  printf("* -AC state :ON                            \n") :  printf("* -AC state :OFF                           \n");
                            printf("* -Vehicle Speed      : %d                 \n",vehicle_speed);
                            printf("* -Room Temperature   : %.2f C               \n",room_temp);
     (engine_temp_ctrl)?    printf("* -Engine Temperature Controller State :ON \n") :  printf("* -Engine Temperature Controller State :OFF \n");
                            printf("* -Engine Temperature : %.2f C\n",engine_temp);
                            printf("*************VEHICLE STATE*****************\n");


}
