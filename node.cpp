#include <iostream.h>
#include <conio.h>
#include <process.h>

struct Node {
    int info;
    Node *next;
};

Node *Create_New_Node(int);
void Insert_End(Node *);
void Display(Node *);
void main_menu();

Node *start = NULL, *newptr, *save, *ptr, *rear;

void main_menu() {
    int inf;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        system("cls");
        cout << "\nMain Menu:\n";
        cout << "1. Add a node to the end of the list\n";
        cout << "2. Display the list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nEnter Information for the new node: ";
                cin >> inf;
                cout << "\nCreating New Node... ";
                system("pause");
                newptr = Create_New_Node(inf);
                if (newptr != NULL) {
                    cout << "\n\nNew Node Created Successfully. ";
                    system("pause");
                } else {
                    cout << "\nCannot Create new node!!! Aborting!!\n";
                    system("pause");
                    exit(1);
                }
                cout << "\nInserting this node in the end of the list...\n";
                system("pause");
                Insert_End(newptr);
                cout << "\nNow the list is:\n";
                Display(start);
                break;
            case 2:
                cout << "\nThe list is:\n";
                Display(start);
                cout << "\nPress any key to continue...";
                system("pause");
                break;
            case 3:
                cout << "\nExiting...\n";
                system("pause");
                exit(0);
            default:
                cout << "\nInvalid choice. Please try again.\n";
                system("pause");
                break;
        }
        cout << "\nPress Y to continue, N to exit: ";
        cin >> ch;
    }
}

Node *Create_New_Node(int n) {
    ptr = new Node;
    ptr->info = n;
    ptr->next = NULL;
    return ptr;
}

void Insert_End(Node *np) {
    if (start == NULL)
        start = rear = np;
    else {
        rear->next = np;
        rear = np;
    }
}

void Display(Node *np) {
    while (np != NULL) {
        cout << np->info << " -> ";
        np = np->next;
    }
    cout << "!!!\n";
}