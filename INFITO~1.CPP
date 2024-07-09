#include<iostream.h>
#include<conio.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char ch) {
if(top < MAX - 1) {
stack[++top] = ch;
} else {
cout << "Stack Overflow";
}
}
char pop() {
if(top > -1) {
return stack[top--];
} else {
cout << "Stack Underflow";
return -1;
}
}
int precedence(char ch) {
switch(ch) {
case '^': return 3;
case '*':
case '/': return 2;
case '+':
case '-': return 1;

default: return -1;
}
}
void InfixToPostfix(char* infix, char* postfix) {
int i = 0, j = 0;
char ch;
while((ch = infix[i++]) != '\0') {
if(ch == '(') {
push(ch);
} else if(ch == ')') {
while(stack[top] != '(') {
postfix[j++] = pop();
}
top--; // Remove '(' from stack
} else if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') {
while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
postfix[j++] = pop();
}
push(ch);
} else {
postfix[j++] = ch;
}
}
while(top != -1) {
postfix[j++] = pop();
}
postfix[j] = '\0';
}
void main() {
clrscr();

char infix[MAX], postfix[MAX];
cout << "Enter infix expression: ";
cin.getline(infix, MAX);
InfixToPostfix(infix, postfix);
cout << "Postfix expression: " << postfix;
getch();
}
