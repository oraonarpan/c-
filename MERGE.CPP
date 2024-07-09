#include <iostream.h>
#include<conio.h>

void mergeofarrays(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, temp[100], k;
  while ((i <= mid) && (j <= high)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      j++;
      index++;
    }
  } else
  {
    while (i <= mid) {
      temp[index] = a[i];
      i++;
      index++;
    }
  }
  for (k = low; k < index; k++)
  {
    a[k] = temp[k];
  }
}
void mergesort(int a[], int low, int high) {
  if (low < high) {
    int middle = (low + high) / 2;
    mergesort(a, low, middle);
    mergesort(a, middle + 1, high);
    mergeofarrays(a, low, middle, high);
  }
}
int main() {
clrscr();
  int n ;
  int a[100];
  cout<<"\n Enter the total elements in an array:\n";
  cin>>n;
  cout<<"\n Enter the element of an array:\n";
  for (int j=0;j<n;j++)
  cin>>a[j];
  mergesort(a, 0, (n-1));
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  getch();
  return 0;
}