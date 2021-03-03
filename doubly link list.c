# include <stdio.h>
void main()
{

    int ch;
    printf("\t\tWELCOME TO THE PROGRAM OF DOUBLE LINK LIST\n\n\n");

    while(1)
    {
         printf("\n1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT");

        printf("\n\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
                      case 1:insert();break;
                      case 2:del();break;
                      case 3:display();break;
                      case 4:exit(0);break;
                      default:printf("Wrong choice");
        }
    }
}
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node* createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return(temp);
}
void insert()
{
    int item;
    struct node *temp,*q;
    temp=createnode();
    if(start==NULL)
    {
        temp->prev=NULL;
        scanf("%d",&item);
        temp->data=item;
        temp->next=NULL;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
        scanf("%d",&item);
        temp->data=item;
        temp->prev=q;
        temp->next=NULL;
    }

}
void display()
{
    struct node *p;
    p=start;
    if(p==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
    while(p->next!=NULL)
    {
        printf("\t%d",p->data);
        p=p->next;
    }
    printf("\t %d\n\n",p->data);
    }
}
void del()
{
   struct node *temp;
   if(start==NULL)
   {
       printf("List is Empty");
   }
   else
   {
       temp=start;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->prev->next=NULL;
       free(temp);
   }
}
