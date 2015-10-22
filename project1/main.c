#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int place_z;
    int place_x;
    int place_y;
} stack;
int maze[2][101][101],maze_A[2][101][101],maze_B[2][101][101];
stack rat_A[20000],rat_B[20000];
void maze_set()//This funtion is used for setting maze.
{
  char temp_maze;
  for(int i=0; i<2; i++)
  {
      int temp;
      scanf("%d",&temp);
      getchar();
      for(int j=0; j<101; j++)
      {
          for(int k=0; k<101; k++)
          {
              scanf("%c",&temp_maze);
              if(temp_maze == 'X')
              {
                  maze[i][j][k]=1;
                  maze_A[i][j][k]=1;
                  maze_B[i][j][k]=1;
              }
              else if(temp_maze == '.')
              {
                  maze[i][j][k]=0;
                  maze_A[i][j][k]=0;
                  maze_B[i][j][k]=0;
              }
              else if(temp_maze == 'o')
              {
                  maze[i][j][k]=2;
                  maze_A[i][j][k]=2;
                  maze_B[i][j][k]=2;
              }
              printf("%c", temp_maze);
          }
          printf("\n");
          getchar();
      }
  }
}
void rat_A_set()//This funtion is used for setting rat_A's start.
{
  rat_A[0].place_z=0;
  rat_A[0].place_x=1;
  rat_A[0].place_y=1;
}
void rat_B_set()//This funtion is used for setting rat_B's start.
{
  rat_B[0].place_z=1;
  rat_B[0].place_x=99;
  rat_B[0].place_y=99;
}
int rat_A_path(int top_A)//Decide direction of rat_A.
{
  int dir_A[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
  for(int i=0;i<5;i++)
  {
   if(i == 4)
  {
      top_A--;
      break;
  }
  if((maze[rat_A[top_A].place_z][rat_A[top_A].place_x+dir_A[i][0]][rat_A[top_A].place_y+dir_A[i][1]] == 0 ||
      maze[rat_B[top_A].place_z][rat_A[top_A].place_x+dir_A[i][0]][rat_A[top_A].place_y+dir_A[i][1]] == 2)&&
     maze_A[rat_A[top_A].place_z][rat_A[top_A].place_x+dir_A[i][0]][rat_A[top_A].place_y+dir_A[i][1]] != -1)
  {
      maze_A[rat_A[top_A].place_z][rat_A[top_A].place_x+dir_A[i][0]][rat_A[top_A].place_y+dir_A[i][1]]=-1;
      top_A++;
      rat_A[top_A].place_z=rat_A[top_A-1].place_z;
      rat_A[top_A].place_x=rat_A[top_A-1].place_x+dir_A[i][0];
      rat_A[top_A].place_y=rat_A[top_A-1].place_y+dir_A[i][1];
      break;
  }
  }
   if(maze[rat_A[top_A].place_z][rat_A[top_A].place_x][rat_A[top_A].place_y] == 2 && rat_A[top_A].place_z == 0)
   {
       rat_A[top_A].place_z++;
       maze_A[rat_A[top_A].place_z][rat_A[top_A].place_x][rat_A[top_A].place_y]=-1;
   }
   return top_A;
}
int rat_A_contion_decide(int top_A,int top_B)//Decide ending condition.
{
  if(rat_A[top_A].place_z==1&&rat_A[top_A].place_x==99&&rat_A[top_A].place_y==99)
      {
        printf("rats didn't encounter each other in this maze\n");
        return 0;
      }
  else if(rat_A[top_A].place_z == rat_B[top_B].place_z&&rat_A[top_A].place_x == rat_B[top_B].place_x&&rat_A[top_A].place_y == rat_B[top_B].place_y)
  {
      printf("rats encounter each other in (%d,%d,%d)\n",rat_A[top_A].place_z,rat_A[top_A].place_x,rat_A[top_A].place_y);
      return 0;
  }
  else
  {
    printf("ratA(%d,%d,%d)\n",rat_A[top_A].place_z,rat_A[top_A].place_x,rat_A[top_A].place_y);
    return 1;
  }
}
int rat_B_path(int top_B)//Decide direction of rat_B.
{
  int dir_B[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
  for(int i=0; i<5; i++)
        {
            if(i == 4)
            {
                top_B--;
                break;
            }
            if((maze[rat_B[top_B].place_z][rat_B[top_B].place_x+dir_B[i][0]][rat_B[top_B].place_y+dir_B[i][1]] == 0 ||
                maze[rat_B[top_B].place_z][rat_B[top_B].place_x+dir_B[i][0]][rat_B[top_B].place_y+dir_B[i][1]] == 2)&&
                maze_B[rat_B[top_B].place_z][rat_B[top_B].place_x+dir_B[i][0]][rat_B[top_B].place_y+dir_B[i][1]] != -1)
            {
                maze_B[rat_B[top_B].place_z][rat_B[top_B].place_x+dir_B[i][0]][rat_B[top_B].place_y+dir_B[i][1]]=-1;
                top_B++;
                rat_B[top_B].place_z=rat_B[top_B-1].place_z;
                rat_B[top_B].place_x=rat_B[top_B-1].place_x+dir_B[i][0];
                rat_B[top_B].place_y=rat_B[top_B-1].place_y+dir_B[i][1];
                break;
            }
        }
        if(maze[rat_B[top_B].place_z][rat_B[top_B].place_x][rat_B[top_B].place_y] == 2 && rat_B[top_B].place_z == 1)
        {
            rat_B[top_B].place_z--;
            maze_B[rat_B[top_B].place_z][rat_B[top_B].place_x][rat_B[top_B].place_y]=-1;
        }
  return top_B;
}
int rat_B_condition_decide(int top_A,int top_B)//Decide ending condition.
{
        if(rat_B[top_B].place_z==0&&rat_B[top_B].place_x==1&&rat_B[top_B].place_y==1)
        {
            printf("rats didn't encounter each other in this maze\n");
            return 0;
        }
        else if(rat_A[top_A].place_z == rat_B[top_B].place_z&&rat_A[top_A].place_x == rat_B[top_B].place_x&&rat_A[top_A].place_y == rat_B[top_B].place_y)
        {
            printf("rats encounter each other in (%d,%d,%d)\n",rat_A[top_A].place_z,rat_A[top_A].place_x,rat_A[top_A].place_y);
            return 0;
        }
        else
        {
            printf("ratB(%d,%d,%d)\n",rat_B[top_B].place_z,rat_B[top_B].place_x,rat_B[top_B].place_y);
            return 1;
        }
}
int main()
{
    freopen("maze.txt", "r", stdin);
    freopen("result.txt", "w", stdout);

    maze_set();
    rat_A_set();
    rat_B_set();
    int top_A=0,top_B=0;
    while(1)
    {
        top_A = rat_A_path(top_A);
        if(rat_A_contion_decide(top_A,top_B) == 0)
           break;
        top_B = rat_B_path(top_B);
        if(rat_B_condition_decide(top_A,top_B) == 0)
           break;
    }
    return 0;
}
