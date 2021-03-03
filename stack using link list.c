# include <stdio.h>
void main()
{

    int ch;
    printf("\t\tWELCOME TO THE PROGRAM OF STACK USING LINK LIST\n\n\n");

    while(1)
    {
         printf("\n\n1.PUSH\t2.POP\t3.PEEK\t4.EXIT");

        printf("\n\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
                      case 1:push();break;
                      case 2:pop();break;
                      case 3:peek();break;
                      case 4:exit(0);break;
                      default:printf("Wrong choice");
        }
    }
}
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL,*start=NULL;
struct node *createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return(temp);
}
void push()
{
    int item;
    struct node *temp,*q;
    temp=createnode();
    if(start==NULL)
    {
     printf("ITEM:\n");
     scanf("%d",&item);
     temp->data=item;
     temp->link=NULL;
      top=temp;
      start=temp;
    }
    else
        {
            q=start;
           printf("ITEM:\n");
        scanf("%d",&item);
        temp->data=item;
        while(q->link!=NULL)
            q=q->link;
        q->link=temp;
         temp->link=NULL;
        top=temp;
        }
}
void pop()
{
    struct node *p,*q;
    p=start;
    while(p->link->link!=NULL)
    {
        p=p->link;
    }
    q=top;
    top=p;
    p->link=NULL;
    free(q);
}
void peek()
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->link;
    }
    printf("\t%d\n\n",ptr->data);
}


