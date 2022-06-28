#include <bits/stdc++.h>
using namespace std;
bool bipartiteMatch(int **bipartiteGraph, int u, bool Recruited[], int assign[], int n)
{
    for (int v = 0; v < n; v++)
    {
        if (bipartiteGraph[u][v] && !Recruited[v])
        {
            Recruited[v] = true;
            if (assign[v] < 0 || bipartiteMatch(bipartiteGraph, assign[v], Recruited, assign, n))
            { assign[v] = u;
                return true;}
        }
    }
    return false;
}
int maxMatching(int **bipartiteGraph, int m, int n)
{
    int assign[n];
    for (int i = 0; i < n; i++)
        assign[i] = -1;
    int match = 0;
    for (int u = 0; u < m; u++)
    {
        bool Recruited[n];
        for (int i = 0; i < n; i++)
          Recruited[i] = false;
        if (bipartiteMatch(bipartiteGraph, u, Recruited, assign, n))
            match++;
    }
    return match;
}
int main()
{
    int m, n;
    cout << "Enter the no of job applicants: ";
    cin >> m;
    cout << "Enter the total number of jobs: ";
    cin >> n;
    int **bipartiteGraph = new int *[m];
    cout << "Enter the matrix for jobs and applicant:\n";
    for (int i = 0; i < m; i++)
    {bipartiteGraph[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> bipartiteGraph[i][j];}
    int a = maxMatching(bipartiteGraph, m, n);
    cout << "\nMaximum number of applicants matching for job is: " << a;
    return 0;
}