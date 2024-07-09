#include <iostream.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>


const int size = 4;

int Push(int[], int&, int);
void Display(int[], int);
int Pop(int[], int&);

int main()
{
    int Stack[size], Item, top = -1, res;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nMenu:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Display the stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter ITEM for insertion: ";
                cin >> Item;
                res = Push(Stack, top, Item);
                if (res == -1)
                {
                    cout << "OVERFLOW!!! Aborting!!\n";
                    exit(1);
                }
                break;

            case 2:
                res = Pop(Stack, top);
                if (res == -1)
                {
                    cout << "UNDERFLOW!!! Aborting!!\n";
                    exit(1);
                }
                else
                    cout << "Element Deleted is " << res << "\n";
                break;

            case 3:
                cout << "The Stack is:\n";
                Display(Stack, top);
                break;

            case 4:
                cout << "Exiting the program.\n";
                exit(0);

            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ch;
    }

    return 0;
}

int Push(int Stack[], int &top, int ele)
{
    if (top == size - 1)
        return -1;
    else
    {
        top++;
        Stack[top] = ele;
    }
    return 0;
}

int Pop(int Stack[], int &top)
{
    int ret;
    if (top == -1)
        return -1;
    else
    {
        ret = Stack[top];
        top--;
    }
    return ret;
}

void Display(int Stack[], int top)
{
    for (int i = top; i >= 0; i--)
        cout << Stack[i] << " <--\n";
}