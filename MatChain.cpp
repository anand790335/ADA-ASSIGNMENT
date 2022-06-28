#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
 

int matChain(int *a, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (mat[i][j] != -1)
    {
        return mat[i][j];
    }
    mat[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        mat[i][j] = min(
            mat[i][j], matChain(a, i, k)
                     + matChain(a, k + 1, j)
                       + a[i - 1] * a[k] * a[j]);
    }
    return mat[i][j];
}
int matOrder(int *a, int n)
{
    int i = 1, j = n - 1;
    return matChain(a, i, j);
}
 
int main()
{
    int n ;
    cout<<"Enter the number of Matrices to be Multiplied: ";
    cin>>n;
    cout<<"Enter the size array of the Matrices\n";
    int a[n+1];
    for(int i=0;i<=n;i++)
    { cin>>a[i]; }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            mat[i][j]=-1;
        }
    }
    cout << "Minimum number of multiplications is "
         << matOrder(a, n+1);
return 0;
}
 