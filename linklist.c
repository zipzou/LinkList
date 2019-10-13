#include<stdio.h>
struct node
{
    int data;
    struct node *link;
}*head,*ptr;

void inf()
{
    int item;
    struct node *temp;
    temp=(struct node *)malloc(1*sizeof(struct node));
    printf("enter item:");
    scanf("%d",&item);

    if(temp==NULL)
    {
        printf("no memory");
        return;
    }

    else
    {
        temp->data=item;
        temp->link=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->link=head;
            head=temp;
        }
    }

}

void inb()
{
    int item;
    struct node *temp;
    temp=(struct node *)malloc(1*sizeof(struct node));
    printf("enter item:");
    scanf("%d",&item);

    if(temp==NULL)
    {
        printf("no memory");
        return;
    }

    else
    {
        temp->data=item;
        temp->link=NULL;
        if(head==NULL)
        {
            head=temp;
            return;
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
        }

    }

}

void disp()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }printf("%d ",ptr->data);
}

void ins()
{
    int key,item;
    struct node *temp;
    temp=(struct node *)malloc(1*sizeof(struct node));
    if(temp==NULL)
    {
        printf("No memory");
        return;
    }
    else if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr=head;
        printf("enter key:");
        scanf("%d",&key);
        printf("enter item");
        scanf("%d",&item);
        temp->data=item;
        temp->link=NULL;
        while(ptr->data!=key && ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        if(ptr->data==key)
        {
            temp->link=ptr->link;
            ptr->link=temp;
        }
        else
        {
            if(ptr->link==NULL)
            {
                printf("no key found");
            }
        }
    }
}

void main()
{
    int ch;

    head=NULL;
    do
    {
        printf("\n\n1.Insertion at front\n2.Display\n3.Insertion at end\n4.Insertion at a specific position\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:inf();
            break;
            case 2:disp();
            break;
            case 3:inb();
            break;
            case 4:ins();
            break;

        }
    }
    while(ch<=4);


    }




