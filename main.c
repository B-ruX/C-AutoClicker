#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void printConsole(int first, int second);
int random(int first, int second);

int main(){

    int first = 6; // default first parameter

    int second = 10; // default second parameter

    line13: printConsole(first,second);

    bool execution = true; // true = running program, false = stop program

    bool isRunning = false; // true = auto clicker running, false = auto clicker stopped

    bool right = false; // true = right click, false = left click


    while(execution) {
        if (GetAsyncKeyState(0x75)) { //F6 switch between left and right click
            right = !right;
        }
        if (GetAsyncKeyState(0x76)) { //F7 start auto clicker
            isRunning = true;
        }
        if (GetAsyncKeyState(0x77)) { //F8 stop auto clicker
            isRunning = false;
        }
        else if (GetAsyncKeyState(0x78)) { //F9 stop program
            execution = false;
        }
        else if (GetAsyncKeyState(0x79)) { //F10 change cps

            //Edit cps here
            line26: system("cls");
            printf("\n\n\n");
            printf("First CPS: ");
            scanf("%d", &first);
            printf("Second CPS: ");
            scanf("%d", &second);
            system("cls");

            if(first > second) { //check to see if first parameter is bigger than second parameter
                printf("\n\n\n\n");
                printf("First CPS must be less than second CPS!");
                Sleep(2000);
                goto line26;
            }

            goto line13;
        }
        if (isRunning == true && right == false) { //left click

            int randomNum = random(first, second);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(1000/randomNum);

        } else if (isRunning == true && right == true) { //right click

            int randomNum = random(first, second);
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(1000/randomNum);

        }
    }
}

void printConsole(int first,int second) {
    printf("================================================================================\n");
    printf("\n"
           "   _____          __         _________ .__  .__        __               ____   ________ \n"
           "  /  _  \\  __ ___/  |_  ____ \\_   ___ \\|  | |__| ____ |  | __ __________\\   \\ /   /_   |\n"
           " /  /_\\  \\|  |  \\   __\\/  _ \\/    \\  \\/|  | |  |/ ___\\|  |/ // __ \\_  __ \\   Y   / |   |\n"
           "/    |    \\  |  /|  | (  <_> )     \\___|  |_|  \\  \\___|    <\\  ___/|  | \\/\\     /  |   |\n"
           "\\____|__  /____/ |__|  \\____/ \\______  /____/__|\\___  >__|_ \\\\___  >__|    \\___/   |___|\n"
           "        \\/                           \\/             \\/     \\/    \\/                     ");
    printf("\n");
    printf("================================================================================\n");
    printf("by B ruX#6074\n");
    printf("================================================================================\n");
    printf("CPS set: %d - %d \n", first, second);
    printf("\n\n\n\n");
    printf("Press F6 to change mode (right/left)\n");
    printf("Press F7 to start the autoclicker\n");
    printf("Press F8 to stop the autoclicker\n");
    printf("Press F9 to exit the program\n");
    printf("\n");
    printf("Press F10 to edit the CPS\n");
}

int random(int first, int second)
{
    srand (time(NULL));
    int random = rand()%((second+1)-first) + first;
    return random;
}
