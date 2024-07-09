#include<iostream.h>
#include<conio.h>

int main()
{    clrscr();
    int a[10][10], b[10][10], mul[10][10];
    int p, q, r, s, i, j, k;

    cout << "Enter number of rows for 1st matrix: ";
    cin >> p;
    cout << "Enter number of columns for 1st matrix: ";
    cin >> q;

    cout << "Enter elements of 1st matrix: ";
    for(i=0; i<p; i++)
    {
	for(j=0; j<q; j++)
	{
	    cin >> a[i][j];
	}
    }

    cout << "Enter number of rows for 2nd matrix: ";
    cin >> r;
    cout << "Enter number of columns for 2nd matrix: ";
    cin >> s;

    if(q!=r)
    {
	cout << "Matrix multiplication is not possible.";
	return 0;
    }
cout << "Enter elements of 2nd matrix: ";
    for(i=0; i<r; i++)
    {
	for(j=0; j<s; j++)
	{
	    cin >> b[i][j];
	}
    }

    for(i=0; i<p; i++)
    {
	for(j=0; j<s; j++)
	{
	    mul[i][j] = 0;
	}
    }

    for(i=0; i<p; i++)
    {
	for(j=0; j<s; j++)
	{
	    for(k=0; k<q; k++)
	    {
		mul[i][j] += a[i][k]*b[k][j];
	    }
	}
    }
cout << "Multiplication of matrices is: " << endl;
    for(i=0; i<p; i++)
    {
	for(j=0; j<s; j++)
	{
	    cout << mul[i][j] << " ";
	}
	cout << endl;
    }
    getch();
    return 0;
}

