#include<iostream.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>

int Insert_in_Q(int[],int);
void Display(int[],int,int);
int Remove(int[]);
const int size=20;
int Queue[size], front=-1, rear=-1;

void main()
{
    int Item, res;
    char ch='y';

    while(1)
    {
        clrscr();
        cout<<"\n 1. Insert an element in Queue";
        cout<<"\n 2. Delete an element from Queue";
        cout<<"\n 3. Display Queue";
        cout<<"\n 4. Exit";
        cout<<"\n\n Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case '1':
                cout<<"\n Enter ITEM for insertion : ";
                cin>>Item;
                res=Insert_in_Q(Queue, Item);
                if(res==-1)
                {
                    cout<<"OVERFLOW!!! Aborting!!\n";
                    exit(1);
                }
                cout<<"\nNow the Queue (Front ... to ... Rear) is : \n";
                Display(Queue, front, rear);
                break;

            case '2':
                res=Remove(Queue);
                if(res==-1)
                {
                    cout<<"UNDERFLOW!!! Aborting!!\n";
                    exit(1);
                }
                else
                {
                    cout<<"\nElement Deleted is "<<res<<" \n";
                    cout<<"\nNow the Queue (Front ... to ... Rear) is : \n";
                    Display(Queue, front, rear);
                }
                break;

            case '3':
                cout<<"\nNow the Queue (Front ... to ... Rear) is : \n";
                Display(Queue, front, rear);
                break;

            case '4':
                exit(1);

            default:
                cout<<"\nInvalid Choice!!";
        }
        getch();
    }
}

int Insert_in_Q(int Queue[], int ele)
{
    if(rear==size-1)
        return -1;
    else if(rear==-1)
    {
        front=rear=0;
        Queue[rear]=ele;
    }
    else
    {
        rear++;
        Queue[rear]=ele;
    }
    return 0;
}

int Remove(int Queue[])
{
    int ret;
    if(front==size-1)
        return -1;
    else
    {
        ret=Queue[front];
        if(front==rear)
            front=rear=-1;
        else
            front++;
    }
    return ret;
}

void Display(int Queue [], int front, int rear)
{
    if(front==-1)
    {
        cout<<"Queue is empty\n";
        return;
    }
    for(int i=front; i<=rear; i++)
        cout<<Queue[i]<<" <-\t";
    cout<<endl;
}