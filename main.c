#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RESET "\e[0m"
#define URED "\e[4;31m"

void print_board();
int system();
int check_win();
int with_player();
int with_smart_computer();
int Evil_computer();
char board[9],name1[30],name2[30];

int main()
{
    int menu,status=1,play;
    char j;
    system("cls");
    printf(YEL"                            WELL COME TO TIC TAC TOE GAME\n\n\n"RESET);
    printf(URED "Enter your choice.\n\n" RESET);
    printf(GRN"1.Want to play with smart computer.\n"RESET);
    printf(GRN"2.Want to play with Evil computer.\n"RESET);
    printf(GRN"3.Want to play with player.\n"RESET);

    while(status==1)
    {
      scanf("%d",&menu);
       if(menu>=1&&menu<=3)
            break;
       else
       printf(RED"Enter correct menu!!\n"RESET);
    }
    if(menu==1)
     {
        printf(GRN"Please enter player name 1:"RESET);
        fflush(stdin);
        fgets(name1,30,stdin);
      }

     if(menu==2)
     {
        printf(GRN"Please enter player name 1:"RESET);
        fflush(stdin);
        fgets(name1,30,stdin);
     }
    if(menu==3)
      {
        printf(GRN"Please enter player name 1:"RESET);
        fflush(stdin);
        fgets(name1,30,stdin);
        printf(GRN"\nPlease enter player name 2:"RESET);
        fflush(stdin);
        fgets(name2,30,stdin);
      }

    while(status==1)
    {
        j='1';
        for(int i=0;i<9;i++)
        {
           board[i]=j;
           j++;
        }
        switch(menu)
    {
        case 1:
            {
              play=with_smart_computer();
              break;

            }
        case 2:
            {
              play=Evil_computer();
              break;
            }
        case 3:
            {
              play=with_player();
                break;
            }
    }
    if(play==0)
    {
        break;
    }

    }


    return 0;
}
void print_board()
{
    system("cls");
   printf("\n\n");
   printf("      ******Tic Tac Toe*******        \n\n");
   printf("            |       |      \n");
   printf("        %c   |  %c    |  %c  \n",board[0],board[1],board[2]);
   printf("            |       |      \n");
   printf("      ______|_______|______\n");
   printf("            |       |      \n");
   printf("        %c   |  %c    |  %c  \n",board[3],board[4],board[5]);
   printf("            |       |      \n");
   printf("      ______|_______|______\n");
   printf("            |       |      \n");
   printf("        %c   |  %c    |  %c  \n",board[6],board[7],board[8]);
   printf("            |       |      \n");
   printf("      ______|_______|______\n");
   printf("            |       |      \n");
   printf("            |       |      \n");

}

int Evil_computer()
{
    int player=1,input,status=-1,result,check=1,che[9]={10},c,j=0,i,c1,t;
    char play;
    system("cls");
    print_board();
    while(status=-1)
    {
        player=(player%2==0)?2:1;
        char mark=(player==1)?'x':'o';
        if(player==1)
        {
          printf("Player ");
          printf(BLU"%s" RESET,name1);
          printf("Enter a number on marking place:");
        }
        if(player==1)
        {
            while(check==1)
             {
               scanf("%d",&input);
               if(input<1||input>9)
                {
                  printf(RED"Invalid input"RESET);
                }
               else
               {
                 c=0;
                 for(int i=0;i<9;i++)
                    {
                      if(che[i]==input)
                        {
                         c++;
                        }
                     }
                if(c==0)
                 {
                   che[j]=input;
                   board[input-1]=mark;
                   j++;
                   break;
                 }
                else
                printf(RED"Can not mark in same place !!!"RESET);
               }

              }
          }
          if(player==2)
          {
            while(status=-1)
            {
                 //to win for computer.
                if(board[0]=='o'&&board[1]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[1]=='o'&&board[2]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[2]=='o'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[3]=='o'&&board[4]=='o'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }
                if(board[4]=='o'&&board[5]=='o'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[3]=='o'&&board[5]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[6]=='o'&&board[7]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[7]=='o'&&board[8]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='o'&&board[8]=='o'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[6]=='o'&&board[4]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[4]=='o'&&board[2]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='o'&&board[2]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='o'&&board[4]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[4]=='o'&&board[8]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[8]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='o'&&board[3]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[3]=='o'&&board[6]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[6]=='o'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[1]=='o'&&board[4]=='o'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[4]=='o'&&board[7]=='o'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[1]=='o'&&board[7]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[2]=='o'&&board[5]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[5]=='o'&&board[8]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[2]=='o'&&board[8]=='o'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }

                //to resist to win player
                c=0;

                if(board[0]=='x'&&board[1]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    c++;
                }
                if(board[1]=='x'&&board[2]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    c++;
                }
                if(board[0]=='x'&&board[2]=='x'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    c++;
                }
                if(board[3]=='x'&&board[4]=='x'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    c++;
                }
                if(board[4]=='x'&&board[5]=='x'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    c++;
                }
                if(board[3]=='x'&&board[5]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    c++;
                }
                if(board[6]=='x'&&board[7]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    c++;
                }
                if(board[7]=='x'&&board[8]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    c++;
                }
                if(board[6]=='x'&&board[8]=='x'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    c++;
                }
                if(board[6]=='x'&&board[4]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    c++;
                }
                if(board[4]=='x'&&board[2]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    c++;
                }
                if(board[6]=='x'&&board[2]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    c++;
                }
                if(board[0]=='x'&&board[4]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    c++;
                }
                if(board[4]=='x'&&board[8]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    c++;
                }
                if(board[0]=='x'&&board[8]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    c++;
                }
                if(board[0]=='x'&&board[3]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    c++;
                }
                if(board[3]=='x'&&board[6]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    c++;
                }
                if(board[0]=='x'&&board[6]=='x'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    c++;
                }
                if(board[1]=='x'&&board[4]=='x'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    c++;
                }
                if(board[4]=='x'&&board[7]=='x'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    c++;
                }
                if(board[1]=='x'&&board[7]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    c++;
                }
                if(board[2]=='x'&&board[5]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    c++;
                }
                if(board[5]=='x'&&board[8]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    c++;
                }
                if(board[2]=='x'&&board[8]=='x'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    c++;
                }

                 if(c>0)
                 {
                     break;
                 }


                //for enter next number of computer
                c=0;

                 for(i=0;i<9;i++)
                {

                    if(board[i]!='x'&&board[i]!='o')
                    {

                        board[i]=mark;
                        c++;
                        break;
                    }
                }

                if(c==1)
                {
                    break;
                }
            }

          }
     print_board();
    result=check_win();
    if(result==1)
    {
        if(player==1)
        {
            printf(GRN"congratulation!! winner is player %s \n\n\n"RESET,name1);
            printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
           printf(GRN"Congratulation!! winner is player: computer \n\n\n"RESET);
           printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(result==0)
    {
        printf(RED"match is draw\n\n\n"RESET);
        printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }


       player++;
    }


}





//function for smart computer.
int with_smart_computer()
{
    int player=1,input,status=-1,result,check=1,che[9]={10},c,j=0,i;
    char play;
    system("cls");
    print_board();
    while(status=-1)
    {
        player=(player%2==0)?2:1;
        char mark=(player==1)?'x':'o';
        if(player==1)
        {
          printf("Player ");
          printf(BLU"%s" RESET,name1);
          printf("Enter a number on marking place:");
        }
        if(player==1)
        {
            while(check==1)
             {
               scanf("%d",&input);
               if(input<1||input>9)
                {
                  printf(RED"Invalid input"RESET);
                }
               else
               {
                 c=0;
                 for(int i=0;i<9;i++)
                    {
                      if(che[i]==input)
                        {
                         c++;
                        }
                     }
                if(c==0)
                 {
                   che[j]=input;
                   board[input-1]=mark;
                   j++;
                   break;
                 }
                else
                printf(RED"Can not mark in same place !!!"RESET);
               }

              }
          }
          if(player==2)
          {
            while(status=-1)
            {
                 //to win for computer.
                if(board[0]=='o'&&board[1]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[1]=='o'&&board[2]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[2]=='o'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[3]=='o'&&board[4]=='o'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }
                if(board[4]=='o'&&board[5]=='o'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[3]=='o'&&board[5]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[6]=='o'&&board[7]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[7]=='o'&&board[8]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='o'&&board[8]=='o'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[6]=='o'&&board[4]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[4]=='o'&&board[2]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='o'&&board[2]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='o'&&board[4]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[4]=='o'&&board[8]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[8]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='o'&&board[3]=='o'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[3]=='o'&&board[6]=='o'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='o'&&board[6]=='o'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[1]=='o'&&board[4]=='o'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[4]=='o'&&board[7]=='o'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[1]=='o'&&board[7]=='o'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[2]=='o'&&board[5]=='o'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[5]=='o'&&board[8]=='o'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[2]=='o'&&board[8]=='o'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }

                //to resist to win player

                if(board[0]=='x'&&board[1]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[1]=='x'&&board[2]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='x'&&board[2]=='x'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[3]=='x'&&board[4]=='x'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }
                if(board[4]=='x'&&board[5]=='x'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[3]=='x'&&board[5]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[6]=='x'&&board[7]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[7]=='x'&&board[8]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='x'&&board[8]=='x'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[6]=='x'&&board[4]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[4]=='x'&&board[2]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[6]=='x'&&board[2]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='x'&&board[4]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[4]=='x'&&board[8]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='x'&&board[8]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[0]=='x'&&board[3]=='x'&&board[6]!='x'&&board[6]!='o')
                {
                    board[6]=mark;
                    break;
                }
                if(board[3]=='x'&&board[6]=='x'&&board[0]!='x'&&board[0]!='o')
                {
                    board[0]=mark;
                    break;
                }
                if(board[0]=='x'&&board[6]=='x'&&board[3]!='x'&&board[3]!='o')
                {
                    board[3]=mark;
                    break;
                }
                if(board[1]=='x'&&board[4]=='x'&&board[7]!='x'&&board[7]!='o')
                {
                    board[7]=mark;
                    break;
                }
                if(board[4]=='x'&&board[7]=='x'&&board[1]!='x'&&board[1]!='o')
                {
                    board[1]=mark;
                    break;
                }
                if(board[1]=='x'&&board[7]=='x'&&board[4]!='x'&&board[4]!='o')
                {
                    board[4]=mark;
                    break;
                }
                if(board[2]=='x'&&board[5]=='x'&&board[8]!='x'&&board[8]!='o')
                {
                    board[8]=mark;
                    break;
                }
                if(board[5]=='x'&&board[8]=='x'&&board[2]!='x'&&board[2]!='o')
                {
                    board[2]=mark;
                    break;
                }
                if(board[2]=='x'&&board[8]=='x'&&board[5]!='x'&&board[5]!='o')
                {
                    board[5]=mark;
                    break;
                }


                //for enter next number of computer
                c=0;
                for(i=0;i<9;i++)
                {

                    if(board[i]!='x'&&board[i]!='o')
                    {

                        board[i]=mark;
                        c++;
                        break;
                    }
                }
                if(c==1)
                {
                    break;
                }
            }

          }
     print_board();
    result=check_win();
    if(result==1)
    {
        if(player==1)
        {
            printf(GRN"congratulation!! winner is player %s \n\n\n"RESET,name1);
            printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
           printf(GRN"Congratulation!! winner is player: computer \n\n\n"RESET);
           printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(result==0)
    {
        printf(RED"match is draw\n\n\n"RESET);
        printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }


       player++;
    }


}
//function for two player
int with_player()
{
   int player=1,input,status=-1,result,check=1,che[9]={10},c,j=0;
   char play;
   system("cls");
   print_board();
    while(status=-1)
    {
        player=(player%2==0)?2:1;
      char mark=(player==1)?'x':'o';
      if(player==1)
      {
          printf("Player ");
          printf(BLU"%s" RESET,name1);
          printf("Enter a number on marking place:");
      }
      else
      {
          printf("Player ");
          printf(BLU"%s" RESET,name2);
          printf("Enter a number on marking place:");
      }
      while(check==1)
      {
          scanf("%d",&input);
          if(input<1||input>9)
             {
              printf(RED"Invalid input"RESET);
             }
           else
           {
             c=0;
              for(int i=0;i<9;i++)
              {
                  if(che[i]==input)
                  {
                      c++;
                  }
              }
              if(c==0)
              {
                 che[j]=input;
                 j++;
                 break;
              }
              else
               printf(RED"Can not mark in same place !!!"RESET);
           }


      }
    board[input-1]=mark;
    print_board();
    result=check_win();
    if(result==1)
    {
        if(player==1)
        {
            printf(GRN"congratulation!! winner is player %s \n\n\n"RESET,name1);
            printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
           printf(GRN"Congratulation!! winner is player %s \n\n\n",name2);
           printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(result==0)
    {
        printf(RED"match is draw\n\n\n"RESET);
        printf(BLU"enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  "RESET);
            fflush(stdin);
            scanf("%c",&play);
            if(play=='y'||play=='Y')
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }

   player++;
    }
   return 0;

}
int check_win()
{
    int c=0,i;

    if(board[0]==board[1]&&board[1]==board[2])
        return 1;
    if(board[3]==board[4]&&board[4]==board[5])
        return 1;
    if(board[6]==board[7]&&board[7]==board[8])
        return 1;
    if(board[0]==board[3]&&board[3]==board[6])
        return 1;
    if(board[1]==board[4]&&board[4]==board[7])
        return 1;
    if(board[2]==board[5]&&board[5]==board[8])
        return 1;
    if(board[0]==board[4]&&board[4]==board[8])
        return 1;
    if(board[2]==board[4]&&board[4]==board[6])
        return 1;
    for(i=0;i<9;i++)
    {
        if(board[i]=='x'||board[i]=='o')
        c++;
    }
    if(c==9)
    {
       return 0;
    }

    return -1 ;         //default -1
}
