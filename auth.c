#include <stdio.h>
#include <stdlib.h>
void login(char *name)
{
    system("cls");
    boundary();
    gotoxy(1, 1);
    printf("</SNAKE GAME>\n");
    printf("%cENTER YOUR USERNAME : ", 179);
    fflush(stdout);
    scanf("%s", name);
    FILE *f = fopen("data.txt", "a+");
    char line[50], found = 0;
    int score;
    rewind(f);
    while (fscanf(f, "%[^,],%d\n", line, &score) != EOF)
    {
        if (strcmp(line, name) == 0)
        {
            found = 1;
            printf("%cWelcome back %s! Your last score : %d\n", 179, name, score);
            fflush(stdout);
            break;
        }
    }
    if (!found)
    {
        fprintf(f, "%s,0\n", name);
        printf("%cWelcome %s!\n", 179, name);
        fflush(stdout);
    }
    fclose(f);
    printf("%cUse W, A, S & D for movements.\n", 179);
    printf("%cEnter any key to continue.", 179);
    getch();
    system("cls");
    boundary();
}

void saveScore(char *name, int score)
{
    FILE *f = fopen("data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[50];
    int s;

    while (fscanf(f, "%[^,],%d\n", line, &s) != EOF)
    {
        if (strcmp(line, name) == 0)
            fprintf(temp, "%s,%d\n", name, score);
        else
            fprintf(temp, "%s,%d\n", line, s);
    }

    fclose(f);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void showLeaderboard()
{
    FILE *f = fopen("data.txt", "r");
    char names[100][50];
    int scores[100], count = 0;

    while (fscanf(f, "%[^,],%d\n", names[count], &scores[count]) != EOF)
        count++;
    fclose(f);

    // bubble sort descending
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (scores[j] < scores[j + 1])
            {
                int tmp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tmp;
                char t[50];
                strcpy(t, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], t);
            }

    printf("\n=== LEADERBOARD ===\n");
    for (int i = 0; i < count && i < 5; i++)
        printf("%d. %s - %d\n", i + 1, names[i], scores[i]);
}
