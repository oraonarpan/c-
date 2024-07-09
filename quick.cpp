#include <iostream.h>
#include <conio.h>
template <class T>
void insert_elements(T a[], int len)
{
 for(int i=0;i<len;i++)
 cin>>a[i];
}
template <class T>
void swap(T a[], int i, int j)
{
 int t = a[i];
 a[i] = a[j];
 a[j] = t;
}
template <class T>
int partition(T a[], int lb, int ub)
{
 int pivot = a[lb];
 int start = lb;
 int end = ub;
 while(start<end)
 {
 while(a[start]<=pivot)
 {
 start++;
 }
 while(a[end]>pivot)
16
 {
 end--;
 }
 if(start<end)
 swap(a, start, end);
 }
 swap(a, lb, end);
 return end;
}
template <class T>
void quick_sort(T a[], int lb, int ub)
{
 int index;
 if(lb<ub)
 {
 index = partition(a,lb,ub);
 quick_sort(a,lb,index-1);
 quick_sort(a,index+1,ub);
 }
}
template <class T>
void display(T a[], int len)
{
 for(int i=0;i<len;i++)
 cout<<a[i]<<" ";
}
void main()
17
{
 clrscr();
 int ar[100];
 int l;
 cout<<"Enter the length of the array ";
 cin>>l;
 cout<<"Enter the elements of the array \n";
 insert_elements(ar,l);
 cout<<"Array before sorting \n";
 display(ar,l);
 quick_sort(ar,0,l-1);
 cout<<"\nArray after sorting \n";
 display(ar, l);
 getch();
}
