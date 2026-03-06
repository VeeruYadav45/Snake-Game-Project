
void home(){
    boundary();
    gotoxy(1,1);
    printf("</SNAKE GAME>\n");
    printf("%cUse W, A, S & D for movements.\n",179);
    printf("%cEnter any key to continue.",179); 
    getch();
    system("cls");
    boundary();
}