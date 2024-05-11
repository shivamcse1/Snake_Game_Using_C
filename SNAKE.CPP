#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
  int x[100],i,g,f,n=1;
  int y[100],s=2;
  f=12,g=20;
  char ch;
  x[0]=5;
  y[0]=8;
  clrscr();
  int flag=0;
  gotoxy(f,g);
  cprintf("o");
  step1:

  for(;!kbhit();)
 {
   switch(ch)
 {
   case 'a':
   x[0]--;
   break;
   case 'd':
   x[0]++;
   break;
   case 'w':
   y[0]--;
   break;
   case 's':
   y[0]++;
   break;
   case ' ':
   exit(0);
 }
   clrscr();

//ASSIGN PART ANOTHER

  if(x[0]==f && y[0]==g)
  {
    n=n+1;
    food:
    f=rand()%70;
    if(f>=0&&f<=7)
    {goto food;
    }
    g=rand()%20;
    flag=1;
  }
    gotoxy(f,g);
    printf("o");

 //EXTEND HEIGHT SNAKE

     for(i=n;i>0;i--)
   {
     x[i]=x[i-1];
     y[i]=y[i-1];

   }

   for(i=0;i<=n;i++)
 {
   gotoxy(x[i],y[i]);
   printf("%c",s);
 }
  /// WHen Snake IS collide itself then Game Over

   for(i=n;i>0;i--)
 {
   if(x[n]==x[i-1]&& y[n]==y[i-1]&&flag==1)
  {
    clrscr();
    printf("\tYour Score = %d",n-1);
    printf("\n\tGame Over");
    getch();
    exit(0);
  }
  /// Border Condition

    if(x[0]==80 ||y[0]==26||x[0]==0||y[0]==0)
   {
     clrscr();
     printf("\tYour Score = %d",n-1);
     printf("\n\tGame Over");
     getch();
     exit(0);
   }

 }

   delay(250);
}
   ch=getch();
   goto step1;
}