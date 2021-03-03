# include <stdio.h>
void main()
{

    int ch;
    printf("\t\tWELCOME TO THE PROGRAM OF LINK LIST\n\n\n");
    printf("1.INSERT VALUE IN LIST \n\n 2.VIEW LIST \n\n3.Delete a node of the list \n\n4.SEARCH AN ELEMENT IN THE LIST");
   printf("\n\n 5.COUNT NO. OF NODES\n\n6.EXIT\n\n7.INSERT AT THE BEGINING\n\n8.INSERT AT ANY POSITION\n\n9.DELETE FROM BEGINING\n\n10.DELETE FROM ANY POSITION");
   printf("\n\n11.REVERSE OF A FUNCTION\n\n");
    while(1)
    {
        printf("\n\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 11:reverse();break;
            case 10:danyposition();break;
            case 9:dbegining();break;
         case 8:ianyposition();break;
         case 1:insert();break;
         case 2:display();break;
        case 5:count();break;
         case 4:search();break;
         case 3:deletelist();break;
         case 6:printf("THANK YOU,VISIT AGAIN");exit(0);break;
         case 7:ibegining();break;
         default:printf("Wrong choice");
        }
    }
}
struct node
{
    int data;
  struct node *link;
};
struct node* createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
}
struct node *start=NULL;
void insert()
{
    printf("\n \tINSERTION FUNCTION\n");
    int item;
  struct node *temp,*p;
  temp=createnode();
 // printf("\n Enter the data\n");
  scanf("%d",&item);
  temp->data=item;
  if(start==NULL)
  {
      temp->link=NULL;
      start=temp;
  }
  else
  {
      p=start;
      while(p->link!=NULL)
      {
          p=p->link;
      }
      p->link=temp;
      temp->link=NULL;
  }
}
void display()
{
    printf("\n \t DISPLAY FUNCTION\n\n");
    struct node *p;
    p=start;
    if(p==NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        printf("\n");
    while(p->link!=NULL)
    {

        printf("%d\t",p->data);
        p=p->link;
    }
    printf("%d\t",p->data);
    }
//count();
}
void count()
{
    printf("\n\t COUNTING FUNCTION\n\n");
    struct node *p;p=start;
    int c=0;
    if(p==NULL)
    {
        printf("\nNo. of nodes is %d\n",c);
    }
    else
    {
    while(p->link!=NULL)
    {

        c=c+1;
        p=p->link;
    }
    c=c+1;
    printf("\nNo. of nodes is %d\n",c);
    }
}
void search()
{
    printf("\n\t SEARCHING FUNCTION\n");
    int s,c=0,flag=0;
    struct node *p;
    printf("\nEnter the item to be searched\n");
    scanf("%d",&s);
    p=start;
    while(p->link!=NULL)
    {
        c++;
        if(s==p->data)
        {

            flag=1;
            break;
        }
        p=p->link;

    }
    if(flag==0)
    {
     printf("\nITEM STATUS\t NODE NO.\n");
        printf("\n NOT Found\t\t NULL\n");
    }
    else
    {
        printf("\nITEM STATUS\t NODE NO.\n");
        printf("\n Found\t\t %d",c);

    }

}
void deletelist()
{
    printf("\n\t DELETION FUNCTION\n");
    struct node *temp,*del;
    temp=start;
    if(temp==NULL)
    {
        printf("List is Empty");
    }
    else
    {
    while(temp->link->link!=NULL)
    {
        temp=temp->link;
    }
    del=temp->link;
    printf("Item deleted is %d",del->data);
    free(del);
    temp->link=NULL;

    }
}
void ibegining()
{
    printf("\n\tinsert FROM BEGINING FUNCTION\n");
    struct node *p,*temp;
    p=start;
    temp=createnode();
    printf("\nEnter the data\n");int item;
    scanf("%d",&item);
    temp->data=item;
    temp->link=start;
    start=temp;

}
void ianyposition()
{
    printf("\n\t INSERT AT ANY POSITION\n\n");
    struct node *temp,*p=start;
    int pos,item,i;
    printf("Enter the position");
    scanf("%d",&pos);
    temp=createnode();
    printf("\nEnter the data\n");
    scanf("%d",&item);
    temp->data=item;
    for(i=1;i<pos-1;i++)
    {
        p=p->link;

    }
    temp->link=p->link;
    p->link=temp;
}
 void dbegining()
{
    printf("\nDELETE FROM BEGINING FUNCTION\n");
    struct node *p;
    if(start==NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        p=start;
        start=p->link;
        free(p);
    }
}
void danyposition()
{
    printf("\n\n\t DELETE FROM ANY POSITION\n");
    struct node *p=start,*del;
    int i,pos;
    if(p==NULL)
    {
        printf("\n\nList is Empty");
    }
    else
    {
      printf("\n Position=");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++)
    {
       p=p->link;
    }
    del=p->link;
    printf("\n\nDeleted Element is %d\n\n",p->link->data);
    count();
    p->link=p->link->link;
    free(del);
    }
}
void reverse()
{
    printf("\n \tREVERSE FUNCTION\n");
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->link;
    p3=p2->link;
    p2->link=p1;
    p1->link=NULL;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    start=p2;
}
