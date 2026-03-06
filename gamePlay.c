#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x,int y){
    COORD p;
    p.X=x;
    p.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
void boundary(){
    int x=119,y=28;
    printf("%c",218);
    for(int i=1;i<x;i++){
        printf("%c",196);
    }
    printf("%c",191);
    for(int i=1;i<y;i++){
        gotoxy(x,i);
        printf("%c",179);
        gotoxy(0,i);
        printf("%c",179);
    }
    printf("\n%c",192);
    for(int i=1;i<x;i++){
        printf("%c",196);
    }
    printf("%c",217);
    gotoxy(0,0);
}

void over(int,int,int);


void move(int *x,int *y,char *l,char c,int len){
      gotoxy(x[len-1],y[len-1]);
      printf(" ");
      for(int i=len;i>0;i--){
            x[i]=x[i-1];
            y[i]=y[i-1];
      }
      *l=c;
      if(len>1){
            gotoxy(x[1],y[1]);
            printf("o");
        }
}

int check(int px,int py,int *x,int *y,int len){
    for(int i=0;i<len;i++){
        if(px==x[i]&&py==y[i])
        return 1;
    }
    return 0;
}

void game(){
    srand(time(NULL));
    int *x,*y,px=((rand()%57)*2)+3,py=(rand()%27)+1,len=1;
    char c,l;
    clock_t t;
    
    x=(int*)malloc(len*sizeof(int)*(len+1));
    y=(int*)malloc(len*sizeof(int)*(len+1));
    x[0]=25;
    y[0]=20;
    
    gotoxy(px,py);
    printf("%c",254);
    
    gotoxy(x[0],y[0]);
    printf("%c",153);
    
    while(1){
        do{
            t=clock();
            while(clock()<t+250&&!kbhit());
            if(clock()<t+250){
                c=getch();
                if(c==75&&l==77) c=77;
                else if(c==77&&l==75) c=75;
                else if(c==72&&l==80) c=80;
                else if(c==80&&l==72) c=72;
            }
            switch(c){
                case 0:
                break;
                case 13:
                break;
                case 80:
                move(x,y,&l,c,len);
                gotoxy(x[0],++y[0]);
                printf("%c",153);
                
                if(y[0]>=28)
                over(x[0],y[0],len);
                break;
                
                case 72:
                move(x,y,&l,c,len);
                gotoxy(x[0],--y[0]);
                printf("%c",153);
                
                if(y[0]<=0)
                over(x[0],y[0],len);
                break;

                case 75:
                move(x,y,&l,c,len);
                gotoxy(x[0]=x[0]-2,y[0]);
                printf("%c",153);
                
                if(x[0]<=0)
                over(x[0],y[0],len);
                break;

                case 77:
                move(x,y,&l,c,len);
                gotoxy(x[0]=x[0]+2,y[0]);
                printf("%c",153);
                
                if(x[0]>=119)
                over(x[0],y[0],len);
                break;

                default:
                break;
            }
            for (int i=4;i<len;i++){
                if(x[0]==x[i]&&y[0]==y[i])
                over(x[0],y[0],len);
                
            }
            
        }while (x[0]!=px||y[0]!=py);

        gotoxy(x[len],y[len]);
        Beep(400,500);
        printf("o");
        len++;
        
        x=(int*)realloc(x,sizeof(int)*(len+1));
        y=(int*)realloc(y,sizeof(int)*(len+1));
        
        do{
            px=((rand()%57)*2)+3,py=(rand()%27)+1;
        }while(check(px,py,x,y,len));
        
        gotoxy(px,py);
        printf("%c",254);
    }
}
void over(int x,int y,int len){
    gotoxy(x,y);
    printf("x");
    Beep(500,400);
    Beep(400,400);
    Beep(300,400);
    Beep(200,700);
    gotoxy(1,1);
    printf("GAME OVER!\n");
    printf("%cScore : %d \n",179,len-1);
    // while(getch()!=13);
    printf("%cDo you want to retry? (Y/N)",179); 
    char c=getch();
    if(c=='Y'||c=='y'){ 
        system("cls");
        boundary();
        game();
    }
    else if(c=='N'||c=='n'){
        exit(0);
    }
}