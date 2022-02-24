#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 100

int a[MAX][MAX];
int n;
_Bool visit[MAX];
int queue[MAX];

void show(int a[MAX][MAX])
{
   int i,j;
   putchar('\n');
   for (i=0;i<n;i++,putchar('\n'))
      for (j=0;j<n;j++)
         printf(" %2d ", a[i][j]);
}

void init(char *fname)
{
   FILE *f;
   f = fopen(fname,"r");
   printf( !f ? "\n File Cannot Read!!!" : "\n Read File Successfully!!!");
   fscanf(f,"%d",&n);
   printf("%d\n",n);

   int i,j;
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
         fscanf(f,"%d",&a[i][j]);

   show(a);
   getchar();
   fclose(f);
}

void bfs(int start)
{
   int top, bottom, k, v;
   top=bottom=1;
   visit[start]=true;
   queue[bottom++]=start;
   while(top!=bottom)
   {
      v=queue[top++];
      printf(" %2d ", v+1);
      getchar();
      for (k=0;k<n;k++)
         if (a[v][k]!=0 && !visit[k])
         {
            queue[bottom++]=k;
            visit[k]=true;
         }
   }
}

void traverse()
{
   int i,j;
   for (i=0;i<n;i++)
      visit[i]=false;
   for (i=0;i<n;i++)
      if (!visit[i])
         bfs(i);
}

int main()
{
   init("bfs.txt");
   traverse();
   getchar();
   return 0;
}
