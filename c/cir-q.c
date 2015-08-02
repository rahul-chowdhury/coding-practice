//WAP TO IMPLEMENT INSERTION DELETION DISPLAY ON LINEAR QUEUE

#include<stdio.h>
#include<stdlib.h>

int Q[10], front=-1, rear=-1, size=10;

void insert();
void display();
void delete();

void main()
{
  int ch;
  while(1)
  {
    printf("\nMENU\n1.INSERTION\n2.DELETION\n3.DISPLAY\nEnter Choice\n");
    scanf("%d", &ch);
    switch (ch)
    {
      case 1: insert();
      break;
      case 2: delete();
      break;
      case 3: display();
      break;
      default : exit(1);
    }
  }
}

void insert()
{
  int item;
  if ((front==(rear)+1) || (front==0 &&(rear==(size-1))))
  {
    printf("QUEUE OVERFLOW\n");
    return;
  }
  else
  {
    printf("Enter the number to be inserted:\n");
    scanf("%d", &item);
    if (front==-1)
    {
      front=0;
      rear=0;
    }
    else if (rear==(size-1))
    {
      rear=0;
    }
    else
    {
      rear=rear+1;
    }
    Q[rear]=item;
  }
}

void delete()
{
  int item;
  item=Q[front];
  if (front==-1)
  {
    printf("QUEUE UNDERFLOW\n");
    return;
  }
  if (front==rear)
  {
    front=-1;
    rear=-1;
  }
  else if (front==(size-1))
  {
    front=0;
  }
  else
  {
    front=front+1;
  }
  printf("DELETED VALUE: %d", item);
}

void display()
{
  int i;
  if (front==-1)
  {
    printf("QUEUE EMPTY\n");
    return;
  }
  else if (front==rear+1)
  {
    for (i=front;i<=size-1;i++)
    {
      printf("%d\t", Q[i]);
    }
    for (i=0;i<=rear;i++)
    {
      printf("%d\t", Q[i]);
    }
  }
  else
  {
    for (i=front;i<=rear;i++)
    {
      printf("%d\t", Q[i]);
    }
  }
  printf("\n");
}
