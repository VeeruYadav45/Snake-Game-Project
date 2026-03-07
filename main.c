#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "gamePlay.c"
#include "homePage.c"
#include "auth.c"

int main(){
    char name[50];
    login(name);
    game(name);
    return 0;
}