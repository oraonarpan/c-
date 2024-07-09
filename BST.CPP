#include <iostream.h>
#include <conio.h>
struct node {
 int info;
 struct node *left, *right;
};
//---------------------STACK----------------------
struct stack{
 struct node *data;
 struct stack *next;
};
struct stack *top = NULL;
struct stack *create_node(struct node *d)
{
 struct stack *newnode = new stack();
 newnode->data = d;
 newnode->next = NULL;
 return newnode;
}
void push(struct node *n)
{
 struct stack *node;

 node = create_node(n);
 if(top==NULL)
 top = node;
 else
 {
 node->next = top;
 top = node;
 }
}
struct node *pop()
{
 struct node *save;
 struct stack *t;
 t= top;
 save = top->data;
 top = top->next;
 delete t;
 return save;
}
int empty()
{
 if(top==NULL)
 return 1;
 else
 return 0;
}
//-------------------BST--------------------------

struct node *create_node(int i)
{
 struct node *newnode = new node();
 newnode->info = i;
 newnode->left = newnode->right = NULL;
 return newnode;
}
struct node *insert(struct node *root, int i)
{
 if(root == NULL)
 root = create_node(i);
 else if(i <= root->info)
 root->left = insert(root->left, i);
 else
 root->right = insert(root->right, i);
 return root;
}
void inorder(struct node *root)
{
 struct node *t = root;
 while(t!=NULL)
 {
 push(t);
 t= t->left;
 }
 while(!empty())
 {
 t = pop();

 cout<<t->info<<" ";
 t=t->right;
 while(t != NULL)
 {
 push(t);
 t = t->left;
 }
 }
}
void main()
{
 struct node *root = NULL;
 char ch = 'y';
 int i;
 clrscr();
 cout<<"Enter the root node \n";
 while(ch=='y' || ch == 'Y')
 {
 cout<<"\nEnter the data ";
 cin>>i;
 root = insert(root, i);
 cout<<"Do you want to crate new node(y/n) ";
 cin>>ch;
 }
 cout<<"\n\nInorder Traversal : \n";
 inorder(root);
 getch();
}
