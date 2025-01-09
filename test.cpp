// source.cpp
// Name: [Your Name and Surname]

#include <iostream>
using namespace std;

// Function to calculate the sum of elements within a cuboid
int cuboid_sum(int ***cube, int l, int v, int p, int h, int w, int d, int edge_length)
{
    int sum = 0;
    for (int i = max(0, l); i < min(edge_length, l + h); i++)
    {
        for (int j = max(0, v); j < min(edge_length, v + w); j++)
        {
            for (int k = max(0, p); k < min(edge_length, p + d); k++)
            {
                sum += cube[i][j][k];
            }
        }
    }
    return sum;
}

// Function to calculate the sum of elements within a tetrahedron
int tetrahedron_sum(int ***cube, int l, int v, int p, int e, int edge_length)
{
    int sum = 0;
    for (int i = max(0, l); i < min(edge_length, l + e); i++)
    {
        for (int j = max(0, v); j <= i - l + v && j < edge_length; j++)
        {
            for (int k = max(0, p); k <= i - l + p && k < edge_length; k++)
            {
                sum += cube[i][j][k];
            }
        }
    }
    return sum;
}

// Function to calculate the sum of elements within an octal
int octal_sum(int ***cube, int l, int v, int p, int r, int edge_length)
{
    int sum = 0;
    for (int i = max(0, l - r); i <= min(edge_length - 1, l + r); i++)
    {
        for (int j = max(0, v - r); j <= min(edge_length - 1, v + r); j++)
        {
            for (int k = max(0, p - r); k <= min(edge_length - 1, p + r); k++)
            {
                if ((i - l) * (i - l) + (j - v) * (j - v) + (k - p) * (k - p) <= r * r)
                {
                    sum += cube[i][j][k];
                }
            }
        }
    }
    return sum;
}

// Function to calculate the determinant
int determinant(int ***cube, char k, int i, int edge_length)
{
    int det = 0;
    if (k == '1')
    { // Level determinant
        for (int j = 0; j < edge_length; j++)
        {
            for (int p = 0; p < edge_length; p++)
            {
                det += cube[i][j][p];
            }
        }
    }
    else if (k == 'v')
    { // Vertical determinant
        for (int l = 0; l < edge_length; l++)
        {
            for (int p = 0; p < edge_length; p++)
            {
                det += cube[l][i][p];
            }
        }
    }
    else if (k == 'p')
    { // Panel determinant
        for (int l = 0; l < edge_length; l++)
        {
            for (int j = 0; j < edge_length; j++)
            {
                det += cube[l][j][i];
            }
        }
    }
    return det;
}

int main()
{
    int edge_length;
    cin >> edge_length;

    // Allocating and initializing the data cube
    int ***cube = new int **[edge_length];
    for (int i = 0; i < edge_length; i++)
    {
        cube[i] = new int *[edge_length];
        for (int j = 0; j < edge_length; j++)
        {
            cube[i][j] = new int[edge_length];
            for (int k = 0; k < edge_length; k++)
            {
                cin >> cube[i][j][k];
            }
        }
    }

    string command;
    while (cin >> command && command != "E")
    {
        if (command[0] == 'C')
        {
            int l, v, p, h, w, d;
            cin >> l >> v >> p >> h >> w >> d;
            cout << cuboid_sum(cube, l, v, p, h, w, d, edge_length) << endl;
        }
        else if (command[0] == 'T')
        {
            int l, v, p, e;
            cin >> l >> v >> p >> e;
            cout << tetrahedron_sum(cube, l, v, p, e, edge_length) << endl;
        }
        else if (command[0] == 'O')
        {
            int l, v, p, r;
            cin >> l >> v >> p >> r;
            cout << octal_sum(cube, l, v, p, r, edge_length) << endl;
        }
        else if (command[0] == 'D')
        {
            char k;
            int i;
            cin >> k >> i;
            cout << determinant(cube, k, i, edge_length) << endl;
        }
    }

    // Deallocating the data cube
    for (int i = 0; i < edge_length; i++)
    {
        for (int j = 0; j < edge_length; j++)
        {
            delete[] cube[i][j];
        }
        delete[] cube[i];
    }
    delete[] cube;

    return 0;
}