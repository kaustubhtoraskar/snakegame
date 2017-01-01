#include<stdio.h>
//#include<termios.h>
//#include<unistd.h>
//#include<fcntl.h>
#include<string.h>
//#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define rows 30
#define columns 80
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define esc 122
int lag=40, ctr=0;

inline void checkbite();//checks the biting of snake and updates score
void drawhead();//updates head's shape according to direction
inline void delay(int);
inline void makearena();//clss arena
void printarena();//to print updated arena
inline void move();//changes coordinates of head and tail according to input or direction
void drawsnake();//fills points according to algorithm
void removebend();//to remove bendpoints when tail passess through bend
void checktail();//checks if tail is passing through last bendpoint or not
void changetailcoordinates(int );//as tail follows last bendpoint this function updates tail's coordinates towards last bend
void comple();//to ignore invalid inputs
void checkfood();//to check if food is being eaten or not
inline void generatefood();
void dummy_main(int chance);
void checkmaze(int choice);
void savehighscore(int);//to save highscore
bool checkbody();//if new food coordinates are on body then it again generates new coordinaes for food
struct coordinate{
 int x;
 int y;
 };
struct coordinate head,tail,bend[500],food;
struct coordinate body[100], obs[500];
int length,i,k,j,bendno=-1,direction,previousdirection=100;
int score,bodycount;
int getch(void);
char arena[rows][columns];
void load()
{

int i,j,k,l,m,x;
char arr[9][104];
for(i=0;i<9;i++)
        {
        for(j=0;j<104;j++)
                {
                if(j==0&&i!=0&&i!=8||i!=0&&i!=8&&j==103)
                {
                arr[i][j]='|';
                }
                else if(j!=0&&i==0&&j!=103||j!=0&&j!=103&&i==8)
                {
                arr[i][j]='_';
                }
                else if(i==2&&j!=0&&j!=103)
                {
                arr[i][j]='_';
                }
                else if(i!=0&&j!=0&&j!=103&&i!=8&&i!=2)
                {
                arr[i][j]=' ';
                }
                else
                {
                arr[i][j]='*';
                }
                }
         }
arr[1][35]='P';
arr[1][31+5]='L';
arr[1][32+5]='E';
arr[1][33+5]='A';
arr[1][34+5]='S';
arr[1][35+5]='E';
arr[1][36+5]=' ';
arr[1][37+5]='W';
arr[1][38+5]='A';
arr[1][39+5]='I';
arr[1][40+5]='T';
arr[1][41+5]=' ';
arr[1][42+5]='L';
arr[1][43+5]='O';
arr[1][44+5]='A';
arr[1][45+5]='D';
arr[1][46+5]='I';
arr[1][47+5]='N';
arr[1][48+5]='G';


                for(l=0;l<9;l++)
                 {
                       for(m=0;m<104;m++)
                       {

                       printf("%c",arr[l][m]);
                       }
                       printf("\n");
                 }

for(j=2;j<=100;j++)
        {

        for(x=90;x<2000000;x++)
                {}
        system("cls");
        for(i=3;i<=7;i++)
                {
                arr[i][j]='*';
                }

 printf("\t\t\t\t");
 printf("                                         ..      .........   .u*'\n");printf("\t\t\t\t");
 printf("                                oP''*Lo*#'''''''''''7d' .d*N.   $\n");printf("\t\t\t\t");
 printf("                               @  u@''           .u*' o*'   #L  ?b\n");printf("\t\t\t\t");
 printf("                              @   '              ' .d'  .d@@e$   ?b.\n");printf("\t\t\t\t");
 printf("                             8                    @*@me@#         ''Nu\n");printf("\t\t\t\t");
 printf("                            @                                        '#b\n");printf("\t\t\t\t");
 printf("                          .P                                           $r\n");printf("\t\t\t\t");
 printf("                        .@'                                  $L        $ \n");printf("\t\t\t\t");
 printf("                      .@'                                   8'R      dP \n");printf("\t\t\t\t");
 printf("                   .d#'                                  .dP d'   .d#\n");printf("\t\t\t\t");
 printf("                  xP              .e                 .ud#'  dE.o@'( \n");printf("\t\t\t\t");
 printf("                  $             s*'              .u@*''     '''\\dP\n");printf("\t\t\t\t");
 printf("                  $             s*'              .u@*''     '''\\dP'\n");printf("\t\t\t\t");
 printf("                  ?L  ..                    ..o@''        .$  uP \n");printf("\t\t\t\t");
 printf("                   #c:$'*u.             .u@*''$          uR .@'\n");printf("\t\t\t\t");
 printf("                    ?L$. ''''***Nc    x@''   @'         d' JP\n");printf("\t\t\t\t");
 printf("                     ^#$.        #L  .$     8'         d' d'\n");printf("\t\t\t\t");
 printf("                       '          'b.'$.   @'         $' 8'\n");printf("\t\t\t\t");
 printf("                                   ''*@$L $'         $  @ \n");printf("\t\t\t\t");
 printf("                                   @L    $'         d' 8\\ \n");printf("\t\t\t\t");
 printf("                                   $$u.u$'         dF dF\n"); printf("\t\t\t\t");
 printf("                                   $ '''   o      dP xR \n");printf("\t\t\t\t");
 printf("                                   $      dFNu...@'  $\n");printf("\t\t\t\t");
 printf("                                   'N..   ?B ^'''   :R\n");printf("\t\t\t\t");
 printf("                                            '$u.   .$\n");printf("\t\t\t\t");
 printf("                                              ^'*bo@'\n\n");


        for(l=0;l<9;l++)
                 {

                 printf("\t\t\t");
                       for(m=0;m<104;m++)
                       {

                       printf("%c",arr[l][m]);
                       }
                       printf("\n");
                 }
if(j==102&&i==7)
        {
        goto loopp;
        }
        }
loopp:
arr[1][35]='P';
arr[1][31+5]='R';
arr[1][32+5]='E';
arr[1][33+5]='S';
arr[1][34+5]='S';
arr[1][35+5]=' ';
arr[1][36+5]='<';
arr[1][37+5]='E';
arr[1][38+5]='N';
arr[1][39+5]='T';
arr[1][40+5]='E';
arr[1][41+5]='R';
arr[1][42+5]='>';
arr[1][43+5]=' ';
arr[1][44+5]='T';
arr[1][45+5]='O';
arr[1][46+5]=' ';
arr[1][47+5]='C';
arr[1][48+5]='O';
arr[1][49+5]='N';
arr[1][50+5]='T';
arr[1][51+5]='I';
arr[1][52+5]='N';
arr[1][53+5]='U';
arr[1][54+5]='E';

 system("cls");
printf("\t\t\t\t");
 printf("                                         ..      .........   .u*'\n");printf("\t\t\t\t");
 printf("                                oP''*Lo*#'''''''''''7d' .d*N.   $\n");printf("\t\t\t\t");
 printf("                               @  u@''           .u*' o*'   #L  ?b\n");printf("\t\t\t\t");
 printf("                              @   '              ' .d'  .d@@e$   ?b.\n");printf("\t\t\t\t");
 printf("                             8                    @*@me@#         ''Nu\n");printf("\t\t\t\t");
 printf("                            @                                        '#b\n");printf("\t\t\t\t");
 printf("                          .P                                           $r\n");printf("\t\t\t\t");
 printf("                        .@'                                  $L        $ \n");printf("\t\t\t\t");
 printf("                      .@'                                   8'R      dP \n");printf("\t\t\t\t");
 printf("                   .d#'                                  .dP d'   .d#\n");printf("\t\t\t\t");
 printf("                  xP              .e                 .ud#'  dE.o@'( \n");printf("\t\t\t\t");
 printf("                  $             s*'              .u@*''     '''\\dP\n");printf("\t\t\t\t");
 printf("                  $             s*'              .u@*''     '''\\dP'\n");printf("\t\t\t\t");
 printf("                  ?L  ..                    ..o@''        .$  uP \n");printf("\t\t\t\t");
 printf("                   #c:$'*u.             .u@*''$          uR .@'\n");printf("\t\t\t\t");
 printf("                    ?L$. ''''***Nc    x@''   @'         d' JP\n");printf("\t\t\t\t");
 printf("                     ^#$.        #L  .$     8'         d' d'\n");printf("\t\t\t\t");
 printf("                       '          'b.'$.   @'         $' 8'\n");printf("\t\t\t\t");
 printf("                                   ''*@$L $'         $  @ \n");printf("\t\t\t\t");
 printf("                                   @L    $'         d' 8\\ \n");printf("\t\t\t\t");
 printf("                                   $$u.u$'         dF dF\n"); printf("\t\t\t\t");
 printf("                                   $ '''   o      dP xR \n");printf("\t\t\t\t");
 printf("                                   $      dFNu...@'  $\n");printf("\t\t\t\t");
 printf("                                   'N..   ?B ^'''   :R\n");printf("\t\t\t\t");
 printf("                                            '$u.   .$\n");printf("\t\t\t\t");
 printf("                                              ^'*bo@'\n\n");
 printf("\n\n\t\t                                           WELCOME TO SNAKE ARENA!!!");
 printf("\n\n\n");
 for(l=0;l<9;l++)
                 {

                 printf("\t\t\t");
                       for(m=0;m<104;m++)
                       {

                       printf("%c",arr[l][m]);
                       }
                       printf("\n");
                 }
printf("\t\t\t\t\t\t\t");
getch();


//char cha;
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease enter your name:");
char str[80];//int w;
gets(str);

FILE *fp;
fp= fopen("highscore.txt","a+");
fprintf(fp,"\n%s",str);
fclose(fp);
}
void main()
{   
int o;
for(o=0;o<500;o++)
{
obs[i].x=0;
obs[i].y=0;
}
	
    do {load(); ctr=1;} while(ctr!=1);
    mainmenu:;
int a,b,c,p,ch;
loop:
system("cls");printf("\t\t\t\t");
printf("              /^\\/^\\ \n");printf("\t\t\t\t");
printf("           _|__|  O|\n");printf("\t\t\t\t");
printf("  \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("   \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("          \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                  `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                    |     |                    ... \n");printf("\t\t\t\t");
printf("                   /     /                       \\   \n");printf("\t\t\t\t");
printf("                  /     /                         \\   \n");printf("\t\t\t\t");
printf("                 /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("               /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("              /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("             (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("              \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                   ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                           ** MAIN MENU **                         |@|\n");printf("\t\t\t\t");
printf("|@|                          -----------------                        |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 1.PLAY                                            |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 2.OPTIONS                                         |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 3.HELP                                            |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 4.SCORE                                           |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 5.QUIT                                            |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
a=getch()-48;
        switch (a)
        {
	case 1:
{
	            system("cls");printf("\t\t\t\t");
printf("              /^\\/^\\ \n");printf("\t\t\t\t");
printf("           _|__|  O|\n");printf("\t\t\t\t");
printf("  \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("   \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("          \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                  `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                    |     |                    ... \n");printf("\t\t\t\t");
printf("                   /     /                       \\   \n");printf("\t\t\t\t");
printf("                  /     /                         \\   \n");printf("\t\t\t\t");
printf("                 /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("               /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("              /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("             (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("              \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                   ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                           ** MAIN MENU **                         |@|\n");printf("\t\t\t\t");
printf("|@|                          -----------------                        |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 1.CLASSIC                                         |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                 2.ARCADE                                          |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 0 TO GO TO MAIN MENU                                  |@|\n");printf("\t\t\t\t");
printf("|@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
a=getch()-48;
	            	switch (a)
	{
	case 1:
	{
	dummy_main(1);
	break;
	}
	
	case 2:
	{
	dummy_main(2);
	break;
	}
	
	default:
	{	
	goto mainmenu;
	break;	
	}
	}
break;
}
	
	        case 2:{
		        loop1:
		        system("cls");
		        printf("\t\t\t\t");
printf("              /^\\/^\\ \n");printf("\t\t\t\t");
printf("           _|__|  O|\n");printf("\t\t\t\t");
printf("  \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("   \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("          \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                  `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                    |     |                    ... \n");printf("\t\t\t\t");
printf("                   /     /                       \\   \n");printf("\t\t\t\t");
printf("                  /     /                         \\   \n");printf("\t\t\t\t");
printf("                 /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("               /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("              /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("             (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("              \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                   ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     ** MAIN MENU **OPTIONS**                      |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     Snake Speed                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     1. Slow                                       |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     2. Fast                                       |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     3. Insane                                     |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 0 TO GO TO MAIN MENU                                  |@|\n");printf("\t\t\t\t");
printf("|@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
		       b=getch()-48;
		    switch (b)
		       {
                       
		    case 1:
		        {
                        lag=50;
		        goto loop;
		        break;
		        }
                    case 2:
			{
                        lag=20;
                        goto loop;
                        break;
			}
	 	    case 3:
			{           
			 lag=1;
			 goto loop;
			 break;
			}
			
		    case 0: 
			{
			goto loop;
			break;
			}
	        
		    default :{printf("\nPlease enter a valid character\n");goto loop1;break;}
			}
		        break;
		        }
	        case 3:{
		        loop2:
		        system("cls");printf("\t\t\t\t");
printf("              /^\\/^\\ \n");printf("\t\t\t\t");
printf("           _|__|  O|\n");printf("\t\t\t\t");
printf("  \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("   \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("          \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                  `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                    |     |                    ... \n");printf("\t\t\t\t");
printf("                   /     /                       \\   \n");printf("\t\t\t\t");
printf("                  /     /                         \\   \n");printf("\t\t\t\t");
printf("                 /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("               /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("              /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("             (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("              \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                   ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     ** MAIN MENU **HELP**                         |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     1.INSTRUCTIONS                                |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                     2.CREDITS                                     |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 9 TO GOTO HELP                                        |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 0 TO GO TO MAIN MENU                                  |@|\n");printf("\t\t\t\t");
printf("|@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
		        c=getch()-48;
		        switch (c)
		        {
		        case 1:{system("cls");
printf("\t\t\t\t");
printf("              /^\\/^\\ \n");printf("\t\t\t\t");
printf("           _|__|  O|\n");printf("\t\t\t\t");
printf("  \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("   \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("          \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                  `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                    |     |                    ... \n");printf("\t\t\t\t");
printf("                   /     /                       \\   \n");printf("\t\t\t\t");
printf("                  /     /                         \\   \n");printf("\t\t\t\t");
printf("                 /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("               /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("              /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("             (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("              \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                   ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|               ** MAIN MENU **HELP**INSTRUCTIONS**                 |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|               use 'a' to move left                                |@|\n");printf("\t\t\t\t");
printf("|@|               use 'w' to move up                                  |@|\n");printf("\t\t\t\t");
printf("|@|               use 's' to move down                                |@|\n");printf("\t\t\t\t");
printf("|@|               use 'd' to move right                               |@|\n");printf("\t\t\t\t");
printf("|@|          type space to pause the game.                            |@|\n");printf("\t\t\t\t");
printf("|@|          dont forget to eat the food and boost your score         |@|\n");printf("\t\t\t\t");
printf("|@|          see you at the leader board!                             |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|                                                                   |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 9 TO GOTO HELP                                        |@|\n");printf("\t\t\t\t");
printf("|@|     **PRESS 0 TO GO TO MAIN MENU                                  |@|\n");printf("\t\t\t\t");
printf("|@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
			        zz:
			        ch=getch()-48;
			        if(!ch){goto loop;}
			        else if(ch==9) {goto loop2;}
			        else {goto zz;}
			        break;
			        }
		        case 2:
{
				system("cls");
				printf("\t\t\t\t");
printf("               /^\\/^\\ \n");printf("\t\t\t\t");
printf("            _|__|  O|\n");printf("\t\t\t\t");
printf("   \\/     /~     \\_/ \\ \n");printf("\t\t\t\t");
printf("    \\____|__________/  \\ \n");printf("\t\t\t\t");
printf("           \\_______      \\                      ...\n");printf("\t\t\t\t");
printf("                   `\\     \\                    .....  \n");printf("\t\t\t\t");
printf("                     |     |                    ... \n");printf("\t\t\t\t");
printf("                    /     /                       \\   \n");printf("\t\t\t\t");
printf("                   /     /                         \\   \n");printf("\t\t\t\t");
printf("                  /     /                           \\\\  \n");printf("\t\t\t\t");
printf("                 /     /                             \\ \\  \n");printf("\t\t\t\t");
printf("                /     /             _----_            \\  \\  \n");printf("\t\t\t\t");
printf("               /     /           _-~      ~-_         |   |  \n");printf("\t\t\t\t");
printf("              (      (        _-~    _--_    ~-_     _/   |  \n");printf("\t\t\t\t");
printf("               \\      ~-____-~    _-~    ~-_    ~-_-~    /  \n");printf("\t\t\t\t");
printf("                 ~-_           _-~          ~-_       _-~  \n");printf("\t\t\t\t");
printf("                    ~--______-~                ~-___-~  \n");printf("\t\t\t\t");
printf("   ___________________________________________________________________\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|               ** MAIN MENU **HELP **CREDITS                       |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|               F.E SPA PROJECT                                     |@|\n");printf("\t\t\t\t");
printf(" |@|               EXECUTED BY:                                        |@|\n");printf("\t\t\t\t");
printf(" |@|               RUDRESH SOLANKI                                     |@|\n");printf("\t\t\t\t");
printf(" |@|               PARTH TAMANE                                        |@|\n");printf("\t\t\t\t");
printf(" |@|               KAUSTUBH TORASKAR                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|               SPECIAL THANKS TO:                                  |@|\n");printf("\t\t\t\t");
printf(" |@|               SUKUMAR GAOKAR(B.E.I.T)                             |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|                                                                   |@|\n");printf("\t\t\t\t");
printf(" |@|     **PRESS 0 TO GOTO HELP                                        |@|\n");printf("\t\t\t\t");
printf(" |@|     **PRESS 1 TO GO TO MAIN MENU                                  |@|\n");printf("\t\t\t\t");
printf(" |@|___________________________________________________________________|@|\n");printf("\t\t\t\t");
printf("        ");
				        ch=getch()-48;
				        if(ch){goto loop;}
				        else {goto loop2;}
				        break;

			case 9:goto loop2;break;
			case 0:goto loop;break;
		        default :{system("cls");printf("\nInvalid input!\n");goto loop2;break;}
		        }
		        break;
		        }
	        case 4: {
		    system("cls");

	            /*FILE *fp;
		        fp=fopen("highscore.txt","r");
		        char data[500];
			
		        fgets(data,500,fp);
		        printf("%s",data); //not working
		        printf("press 1 to go to MAIN MENU\n");
				        ch=getch()-48;
				        if(ch){goto loop;}
		    */
		int c;
		FILE *file;
		file = fopen("highscore.txt", "r");
		if (file) {
    		while ((c = getc(file)) != EOF)
        	putchar(c);
    		fclose(file);
		}
		printf("\n");
		delay(500);
		goto mainmenu;        
			break;
		        }
	        case 5: {
	               system("cls");
	               printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWINNERS NEVER QUIT!!!!!!!");
	               delay(1000);
		       break;
		        }
	        default :
			{
			system("cls");
			printf("\n\n\n\n\t\t\t\t\nPlease enter valid input!\n");
			goto loop;
			break;
			}
        }
system("cls"); 
}
}


void dummy_main(int choice)
{
	restart:;
	/*int ob;
	for(ob=0;ob<40;ob++)
	{
	
	obs[ob].x=rand()%(columns-18)+15;
        obs[ob].y=rand()%(rows-15)+10;
	}
	*/
	
	score=0;
	generatefood();
	head.x=5;
	head.y=5;
	tail.y=5;
	tail.x=2;
 for(k=0;1;k++)
  {
   if(kbhit())
   {
    direction=getch();
    switch(direction)
    {
    	case 32:
    		{   
    		        system("cls");
		        makearena();
    		        checkmaze(choice);
    			while(!kbhit())
    			{};
    			system("cls");
    			break;
    	    }
    	case 27:
    		{
    			system("cls");
		        makearena();
    			checkmaze(choice);
    			goto exit;
    			break;
			}
	default:
    {
    	
	comple();
    bendno++;
    bend[bendno].x=head.x;
    bend[bendno].y=head.y;
}
}
}
   makearena();
   drawsnake();
   checkmaze(choice);
   delay(lag);
   system("cls");
   previousdirection=direction;
   if(head.x>columns-2||head.x<1)
    {
        printarena();
        printf("\n");  
    	printf("                                              GAME OVER!!!!!                                   ");
    	bendno=-1;
    	direction=0;
    	goto exit;
    }
   if(head.y>rows-2||head.y<1)
    {
    	printarena();
    	printf("\n");

    	printf("                                              GAME OVER!!!!!                                     ");
    	bendno=-1; 
    	direction=0;
    	goto exit;
    }
   
    for(i=0;i<500;i++)
    {
    
    if(head.y==obs[i].y && head.x==obs[i].x)
    {
    	printarena();
    	printf("\n");


    	printf("                                              GAME OVER!!!!!                                     ");
    	bendno=-1; 
    	direction=0;
    	goto exit;
    }

    }
    
 }
 exit:;
 printf("\n\n\n\t\t\t\t\t\t\tDo you want to restart the game?  \n\n\t\t\t\t\t\t\tY or N ? ");
savehighscore(score);	
 if(getch()=='y')
 {
	fflush(stdin);
 	system("cls");
	
 	goto restart; 	
	 
}
 else
 {
	
 	fflush(stdin);
 	system("cls");
	
	main();
	
 }

}
void changetailcoordinates(int x)
{
	checktail();
    if(bendno>=0)
    {
     checktail();
     if(tail.x==bend[0].x){
     if(tail.y>bend[0].y)
     {
     	if(x>0){
     		tail.y+=2;
     	}
     	tail.y--;
     }
     else
     {

     	if(x>0){
     	tail.y-=2;
     	}
     	tail.y++;
     }
    }
     else  if(tail.y==bend[0].y)
    {
      checktail();
      if(tail.x>bend[0].x)
      {

     	if(x>0){
     		tail.x+=2;
     	}
      tail.x--;
      }
      else
      {

     	if(x>0){
     		tail.x-=2;
     	}
      	tail.x++;
      	}
     }
}
    else
    {
    	switch (direction)
        {
           case UP:
           {
             if(x>0)
             {
             	tail.y+=2;
             }
             tail.y--;
             break;
           }
           case DOWN:
           {
           	if(x>0)
             {tail.y-=2;}
             tail.y++;
              break;
           }
          case LEFT:
          {
          	if(x>0)
             {tail.x+=2;}
            tail.x--;
            break;
          }
          case RIGHT:
          {
          	if(x>0)
             {tail.x-=2;}
             tail.x++;
             break;
          }
          
   	}
   }
}
void makearena()
{ 
 for(i=0;i<rows;i++)
 {
   for(j=0;j<columns;j++)
   {
      if(i==0||i==rows-1||j==0||j==columns-1)
      {
      	arena[i][j]='*';
      }
        else 
      {
      	arena[i][j]=' ';
      }
    }
  }
//maze();
/*
for(i=0;i<15;i++)//0 1 2 3 
  {

   {
   obs[i+10].y=obs[i].y+1 ; obs[i+10].x=obs[i].x ; obs[i+20].y=obs[i].y+2 ; obs[i+20].x=obs[i].x ;
   arena[obs[i].y][obs[i].x]='+'; // 0 1 2 3
   arena[obs[i+10].y][obs[i+10].x]='+'; // 10 11 12 13
   arena[obs[i+20].y][obs[i+20].x]='+'; // 20 21 22 23
   }
  }//12
for(i=15;i<31;i++)//4 5 6
  {
   {
   obs[i+10].y=obs[i].y ; obs[i+10].x=obs[i].x+1 ; obs[i+20].y=obs[i].y ; obs[i+20].x=obs[i].x+2 ;
   arena[obs[i].y][obs[i].x]='+'; // 4 5 6 
   arena[obs[i+10].y][obs[i+10].x]='+'; // 14 15 16
   arena[obs[i+20].y][obs[i+20].x]='+'; // 24 25 26
   }
  }//9
for(i=31;i<40;i++)//7 8 9
  {   
   {
   obs[i+10].y=obs[i].y+1 ; obs[i+10].x=obs[i].x+1 ; obs[i+20].y=obs[i].y+2 ; obs[i+20].x=obs[i].x+2 ;
   arena[obs[i].y][obs[i].x]='+'; // 7 8 9
   arena[obs[i+10].y][obs[i+10].x]='+'; //17 18 19
   arena[obs[i+20].y][obs[i+20].x]='+'; //27 28 29
   }
  }//9  
/*for(i=10;i<15;i++)//10 11 12 13 14
  {   
   {
   obs[i+10].y=obs[i].y-1 ; obs[i+10].x=obs[i].x-1 ; obs[i+20].y=obs[i].y-2 ; obs[i+20].x=obs[i].x-2 ;
   arena[obs[i].y][obs[i].x]='+'; // 10 11 12 13 14
   arena[obs[i+10].y][obs[i+10].x]='+'; //20 21 22 23 24
   arena[obs[i+20].y][obs[i+20].x]='+'; //30 31 32 33 34
   }
  }//15
*/

}
 void printarena()
{
	          printf("\t\t\t");
	printf("********************************************************************************\n");	          
	printf("\t\t\t");
	printf("*                                 score:%3d                                    *",score);
	printf("\n");
   for(i=0;i<rows;i++)
   {
          printf("\t\t\t");
     for(j=0;j<columns;j++)

     {

       printf("%c",arena[i][j]);
     }
     printf("\n");
  }
            printf("\t\t\t");
   printf("*          press space to pause and esc to restart or end the game             *\n");          printf("\t\t\t");
   printf("********************************************************************************\n");
 // for (i=0;i<bodycount;i++)
  //{
  //	printf("%d       %d\n",body[i].x,body[i].y);
  //	printf("\n");
  //}
}

inline void removebend()
{
	if(bendno<0){goto nothing;}
   for(i=0;i<=bendno;i++)
  {
    bend[i].x=bend[i+1].x;
    bend[i].y=bend[i+1].y;
  }
   bend[i+1].x= 0;
   bend[i+1].y= 0;
   bendno--;
   nothing:;
}
void checktail()
{
 if(tail.x==bend[0].x&&tail.y==bend[0].y)
 {
  removebend();
  }
}
void drawsnake()
{
// checkbite();
  j=0;
  checkfood();
  arena[food.y][food.x]='#';
  checktail();
  int p=bendno;
	move();
	checktail();
	body[0].x=head.x;
	body[0].y=head.y;
  if (bendno>=0){
  	  if(head.x==bend[bendno].x)//to fill points between last bendpoint and headpoint
  {
   if(head.y>bend[bendno].y)
   {
    for(i=head.y;i>bend[bendno].y;i--)
    {
      body[j].x=head.x;
       body[j].y=i;
       j++;
     arena[i][head.x]='@';
    }
   }
  else {
   for(i=head.y;i<bend[bendno].y;i++)
   {
      body[j].x=head.x;
       body[j].y=i;
       j++;
    arena[i][head.x]='@';
   }
  }
 }
 else if(head.y==bend[bendno].y)
 {
 	if(head.x>bend[bendno].x)
   {
    for(i=head.x;i>bend[bendno].x;i--)
    {
       body[j].x=i;
       body[j].y=head.y;
       j++;
     arena[head.y][i]='@';
    }
   }
  else {
   for(i=head.x;i<bend[bendno].x;i++)
   {
     body[j].x=i;
     body[j].y=head.y;
     j++;
    arena[head.y][i]='@';
   }
  }
}
}
  if(bendno>0)
  {
   while(p>=1)
   {
     if(bend[p].x==bend[p-1].x)
    {
      if(bend[p].y>bend[p-1].y)
      {
       for(i=bend[p].y;i>bend[p-1].y;i--)
       {
         body[j].x=bend[p].x;
         body[j].y=i;
         j++;
         arena[i][bend[p].x]='@';
       }
      }
     else
     {
       for(i=bend[p].y;i<bend[p-1].y;i++)
       {
        body[j].x=bend[p].x;
        body[j].y=i;
        j++;
        arena[i][bend[p].x]='@';
       }
      }
    }
   else if(bend[p].y==bend[p-1].y)
   {
    if(bend[p].x>bend[p-1].x)
     {
      for(i=bend[p].x;i>bend[p-1].x;i--)
      {
       body[j].x=i;
       body[j].y=bend[p].y;
       j++;
       arena[bend[p].y][i]='@';
      }
  }
     else
     {
      for(i=bend[p].x;i<bend[p-1].x;i++)
       {
        body[j].x=i;
        body[j].y=bend[p].y;
        j++;
        arena[bend[p].y][i]='@';
      }
    }
   }
    p--;
  }
}
if(bendno>=0)
{
   if(tail.x==bend[0].x)//tail to bend filling
   {
    if(tail.y>bend[0].y)
    {
     for(i=bend[0].y;i<=tail.y;i++)
      {
       body[j].x=tail.x;
       body[j].y=i;
       j++;
        arena[i][tail.x]='@';
      }
     }
     else{
     for(i=bend[0].y;i>=tail.y;i--)
      {
        body[j].x=tail.x;
       body[j].y=i;
       j++;
        arena[i][tail.x]='@';
      }
     }
    }
   else if(tail.y==bend[0].y)
   {
    if(tail.x>bend[0].x)
    {
     for(i=bend[0].x;i<=tail.x;i++)
      {
        body[j].x=i;
       body[j].y=tail.y;
       j++;
       arena[tail.y][i]='@';
       }
     }
    else{
    for(i=bend[0].x;i>=tail.x;i--)
      {
       body[j].x=i;
       body[j].y=tail.y;
       j++;
        arena[tail.y][i]='@';
      }
    }
   }
}
	   if(bendno==-1){
 	if(head.x==tail.x){
 		if(head.y>tail.y){
 			for(i=tail.y;i<=head.y;i++){//1st correction
 				 body[j].x=head.x;
       body[j].y=i;
       j++;
 				arena[i][head.x]='@';
			 }
		}
			 else{
			 	for(i=head.y;i<tail.y;i++){
			 		 body[j].x=head.x;
       body[j].y=i;
       j++;
			 		arena[i][head.x]='@';
				 }
			 }
		 }
		 else if(head.y==tail.y)
		 {
		    if(head.x>tail.x){
		    	for(i=tail.x;i<=head.x;i++){//second correction
		    		   body[j].x=i;
     body[j].y=head.y;
     j++;
		    		arena[tail.y][i]='@';
				}
			}
				else{
					for(i=head.x;i<tail.x;i++){
						   body[j].x=i;
     body[j].y=head.y;
     j++;
						arena[tail.y][i]='@';
					}
				}
			}
		}
 	drawhead();
     checkbite();
     arena[tail.y][tail.x]='#';
     bodycount=j;

}
void move()
{
 switch (direction)
 {
 case UP:
 {
 	delay(5);
    head.y--;
    changetailcoordinates(0);
   break;
}
  case DOWN:
  {
  	delay(5);
   head.y++;
   changetailcoordinates(0);
   break;
   }
   case LEFT:
   {
   head.x--;
   changetailcoordinates(0);
   break;
   }
   case RIGHT:
   {
    head.x++;
    changetailcoordinates(0);
	break;
   }

  
}
}
void delay(int x)
{
 int c = 1, d = 1;

   for ( c = 1 ; c <= 327*x ; c++ )
       for ( d = 1 ; d <= 3256;d++ )
       {}
 }
//inline
 void comple()
{


	if(direction==UP&&previousdirection==DOWN||direction==DOWN&&previousdirection==UP||direction==LEFT&&previousdirection==RIGHT||direction==RIGHT&&previousdirection==LEFT)
	{
			direction=previousdirection;
	}

	else if(direction!=UP&&direction!=DOWN&&direction!=LEFT&&direction!=RIGHT)//&&direction!=esc)
	{
			direction=previousdirection;
	}

}
void drawhead()
{
 switch (direction)
 {
 case UP:
 {
    arena[head.y][head.x]='^';
   break;
}
  case DOWN:
  {
      arena[head.y][head.x]='v';
   break;
   }
   case LEFT:
   {
      arena[head.y][head.x]='<';
   break;
   }
   case RIGHT:
   {
    arena[head.y][head.x]='>';
	break;
   }
}
}
void checkfood()
{
	if(head.x==food.x&&head.y==food.y)
	{
		reset:;
	    generatefood(); if((food.x==0||food.y==0||food.y==rows-1||food.x==columns-1) ||checkbody())
        {
        	goto reset;
        }
        score++;
        changetailcoordinates(4);
	}
}
 void checkbite()
{
	int m,count=0,bcount=0;
	for(i=0;i<bodycount;i++)
	{
		if(head.x==body[i].x&&head.y==body[i].y){
			count++;
		}
		if(count==2)
		{
			   score-=(bodycount-i-1);
			    tail=body[i-1];
			    while(i<bodycount){
				for(j=0;j<=bendno;j++)
				{	       	if(body[i].x==bend[j].x&&body[i].y==bend[j].y)
	       		{
	       		  bcount++;
                	}
                }
	i++;
   }
   for(j=0;j<bcount;j++)
   {
   		for(m=0;m<bendno;m++)
	       			{
	       				bend[m]=bend[m+1];
	       		    }
	       		    bendno--;
   }
}
}
}

void maze()
{
int i,s=1,e;
char wall='*';
	e=4;
		
	{//1
	i=1;
	obs[1].y=3 ; obs[1].x=12 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}
	
	s=e+1; e=8;	
	{//2
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1 ;
	for(i=s;i<=e;i++)//horizontal
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=12;	
	{//3
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+4 ;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=14;	
	{//4
	i=1;
	obs[s].y=obs[s-1].y-1 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=22;	
	{//5
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1 ;
	for(i=s;i<=e;i++)//horizontal
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}
	
	s=e+1; e=27;	
	{//6
	i=1;
	obs[s].y=obs[s-1].y+1 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}	

	s=e+1; e=47;	
	{//7
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=50;	
	{//8
	i=1;
	obs[s].y=obs[s-1].y+1 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=58;	
	{//9
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1 ;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=61;	
	{//10
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+4 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=78;	
	{//11
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x-1 ;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=87;	
	{//12
	i=1;
	obs[s].y=3 ; obs[s].x=37 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=105;	
	{//13
	i=1;
	obs[s].y=12 ; obs[s].x=28;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}
	
	s=e+1; e=110;	
	{//14
	i=1;
	obs[s].y=obs[s-1].y+1 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=113;
	{//15
	i=1;
	obs[s].y=14 ; obs[s].x=28 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=120;	
	{//16
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=125;	
	{//17
	i=1;
	obs[s].y=14 ; obs[s].x=37;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=130;
	{//18
	i=1;
	obs[s].y=15 ; obs[s].x=39 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}
	
	s=e+1; e=150;	
	{//19
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x-1 ;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=153;	
	{//20
	i=1;
	obs[s].y=obs[s-1].y-1 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=159;	
	{//21
	i=1;
	obs[s].y=19 ; obs[s].x=1;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=164;
	{//22
	i=1;
	obs[s].y=19 ; obs[s].x=12 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=167;	
	{//23
	i=1;
	obs[s].y=23 ; obs[s].x=11;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=171;
	{//24
	i=1;
	obs[s].y=23 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=189;	
	{//25
	i=1;
	obs[s].y=23 ; obs[s].x=17;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=191;
	{//26
	i=1;
	obs[s].y=22 ; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=193;
	{//27
	i=1;
	obs[s].y=24 ; obs[s].x=22 ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=215;	
	{//28
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=220;
	{//29
	i=1;
	obs[s].y=obs[s-1].y; obs[s].x=obs[s-1].x+1 ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=240;	
	{//30
	i=1;
	obs[s].y=8 ; obs[s].x=38;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=253;
	{//31
	i=1;
	obs[s].y=obs[s-1].y+1; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}
	
	s=e+1; e=259;	
	{//32
	i=1;
	obs[s].y=obs[s-1].y-5 ; obs[s].x=obs[s-1].x-1;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=270;
	{//33
	i=1;
	obs[s].y=obs[s-1].y+1; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}
	
	s=e+1; e=274;
	{//34
	i=1;
	obs[s].y=7; obs[s].x=45 ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=290;	
	{//35
	i=1;
	obs[s].y=obs[s-1].y ; obs[s].x=obs[s-1].x+1;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=293;
	{//36
	i=1;
	obs[s].y=obs[s-1].y-1; obs[s].x=obs[s-1].x ;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=300;	
	{//35
	i=1;
	obs[s].y=18; obs[s].x=57;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=306;
	{//36
	i=1;
	obs[s].y=29; obs[s].x=63;
	for(i=s;i<=e;i++)//vertical up
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y-1 ; obs[i+1].x=obs[i].x ;
	}
	}

	s=e+1; e=312;	
	{//37
	i=1;
	obs[s].y=18; obs[s].x=79;
	for(i=s;i<=e;i++)//horizontal left
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x-1;
	}
	}

	s=e+1; e=319;	
	{//38
	i=1;
	obs[s].y=4; obs[s].x=62;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}

	s=e+1; e=325;
	{//39
	i=1;
	obs[s].y=obs[s-1].y+1; obs[s].x=68;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}

	/*s=e+1; e=328;
	{//39
	i=1;
	obs[s].y=5; obs[s].x=45;
	for(i=s;i<=e;i++)//vertical down
	{
	arena[obs[i].y][obs[i].x]='7';
	if(i==e) break;	
	obs[i+1].y=obs[i].y+1 ; obs[i+1].x=obs[i].x ;
	}
	}*///remove these points later

        s=e+1; e=334;	
	{//40
	i=1;
	obs[s].y=15; obs[s].x=64;
	for(i=s;i<=e;i++)//horizontal right
	{
	arena[obs[i].y][obs[i].x]=wall;
	if(i==e) break;	
	obs[i+1].y=obs[i].y ; obs[i+1].x=obs[i].x+1;
	}
	}


}
void savehighscore(int sc)
{
	FILE *fp;
	//getch();
	
	printf("\n The score is : %d",sc);
	delay(100);
	fp=fopen("highscore.txt","a+");
/*	
	if(fp==NULL)
	{
		printf("Cannot open file.\n");
	}
	while( fp!=EOF)
	{
	
	fp++;
	}
*/
	fprintf(fp," : %d ",sc);
	fclose(fp);
}
//inline
 bool checkbody()
{
	for(i=0;i<j;i++)
	{
		if(food.x==body[i].x||food.y==body[i].y)
		{
			return true;
		}
	}
	return false;
}
void generatefood()
{
	srand(time(NULL));
	food.x=rand()%(columns-4)+2;
    	food.y=rand()%(rows-4)+2;
for(i=0;i<500;i++)
    {
    if(food.y==obs[i].y && food.x==obs[i].x)
    generatefood();
    }
}

void checkmaze(int choice)
{
if(choice==1)
{

maze();
printarena();
}

else if(choice==2)
{
int i;
for(i=0;i<500;i++)
{
obs[i].x=0;
obs[i].y=0;
}
printarena();
}

}

/*int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
*/
/*int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
*/ 




