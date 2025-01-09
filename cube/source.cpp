// Yaroslav Kolesnik
#include <iostream>
using namespace std;

const int MAX_EDGE = 32;

int cube[MAX_EDGE][MAX_EDGE][MAX_EDGE];
int edge_length;

void intersectCuboid(int l, int v, int p, int h, int w, int d)
{

    int intersection = 0;

    int start_l = (l < (edge_length - 1)) ? l : l - h;
    int end_l = (l < (edge_length - 1)) ? l + h : l;

    int start_v = (v < (edge_length - 1)) ? v : v - w;
    int end_v = (v < (edge_length - 1)) ? v + w : v;

    int start_p = (p < (edge_length - 1)) ? p : p - d;
    int end_p = (p < (edge_length - 1)) ? p + d : p;

    // Debugging output
    // cout << "start_l: " << start_l << ", end_l: " << end_l << endl;
    // cout << "start_v: " << start_v << ", end_v: " << end_v << endl;
    // cout << "start_p: " << start_p << ", end_p: " << end_p << endl;

    for (int x = start_p; x <= end_p; x++)
    {
        if (!(x < 0 || x > 31))
        {

            for (int y = start_l; y <= end_l; y++)
            {
                if (!(y < 0 || y > 31))
                {

                    for (int z = start_v; z <= end_v; z++)
                    {
                        if (!(z < 0 || z > 31))
                        {

                            intersection += cube[x][y][z];
                        }
                    }
                }
            }
        }
    }

    cout << intersection << endl;
}

void Tetra(int l, int v, int p, int e)
{
    int intersection = 0;

    // l /= 2;
    // v /= 2;
    // p /= 2;
    int start_l = (l < (edge_length - 1)) ? l : l - e;
    int end_l = (l < (edge_length - 1)) ? l + e : l;

    int start_v = (v < (edge_length - 1)) ? v : v - e;
    int end_v = (v < (edge_length - 1)) ? v + e : v;

    int start_p = (p < (edge_length - 1)) ? p : p - e;
    int end_p = (p < (edge_length - 1)) ? p + e : p;

    // Debugging output
    // cout << "start_l: " << start_l << ", end_l: " << end_l << endl;
    // cout << "start_v: " << start_v << ", end_v: " << end_v << endl;
    // cout << "start_p: " << start_p << ", end_p: " << end_p << endl;

    for (int x = start_p; x <= end_p; x++)
    {
        if (!(x < 0 || x > 32))
        {

            for (int y = start_l; y <= end_l; y++)
            {
                if (!(y < 0 || y > 32))
                {

                    for (int z = start_v; z <= end_v; z++)
                    {
                        if (!(z < 0 || z > 32))
                        {
                            // cout << x << ' ' << y << ' ' << z << endl;
                            if ((x + y + z <= p + l + v + e) &&
                                (x >= p) &&
                                (y >= l) &&
                                (z >= v) &&
                                (x + y + z >= p + l + v))
                            {
                                // cout << cube[x][y][z] << endl;

                                intersection += cube[x][y][z];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << intersection << endl;
}
void Octal(int l, int v, int p, int r)
{
    int intersection = 0;

    // l /= 2;
    // v /= 2;
    // p /= 2;
    int start_l = (l < (edge_length - 1)) ? l : l - r;
    int end_l = (l < (edge_length - 1)) ? l + r : l;

    int start_v = (v < (edge_length - 1)) ? v : v - r;
    int end_v = (v < (edge_length - 1)) ? v + r : v;

    int start_p = (p < (edge_length - 1)) ? p : p - r;
    int end_p = (p < (edge_length - 1)) ? p + r : p;

    // Debugging output
    // cout << "start_l: " << start_l << ", end_l: " << end_l << endl;
    // cout << "start_v: " << start_v << ", end_v: " << end_v << endl;
    // cout << "start_p: " << start_p << ", end_p: " << end_p << endl;

    for (int x = start_p; x <= end_p; x++)
    {
        if (!(x < 0 || x > 32))
        {

            for (int y = start_l; y <= end_l; y++)
            {
                if (!(y < 0 || y > 32))
                {

                    for (int z = start_v; z <= end_v; z++)
                    {
                        if (!(z < 0 || z > 32))
                        {
                            // cout << x << ' ' << y << ' ' << z << endl;
                            if (x * x + y * y + z * z <= r * r)
                            {
                                // cout << cube[x][y][z] << endl;

                                intersection += cube[x][y][z];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << intersection << endl;
}

int main()
{
    cin >> edge_length;

    for (int i = 0; i < edge_length; i++)
    {
        for (int j = 0; j < edge_length; j++)
        {
            for (int k = 0; k < edge_length; k++)
            {
                cin >> cube[i][j][k];
                // cout << '(' << i << ',' << j << ',' << k << ')' << endl;
            }
        }
    }

    string operation;
    while (cin >> operation)
    {
        if (operation == "E")
        {
            break;
        }
        else if (operation[0] == 'C')
        {
            int l, v, p, h, w, d;
            cin >> l >> v >> p >> h >> w >> d;
            intersectCuboid(l, v, p, h, w, d);
            // cout << intersectCuboid(l, v, p, h, w, d) << endl;
        }
        else if (operation[0] == 'T')
        {
            int l, v, p, e;
            cin >> l >> v >> p >> e;
            Tetra(l, v, p, e);
            // cout << intersectTetrahedron(l, v, p, e) << endl;
        }
        else if (operation[0] == 'O')
        {
            int l, v, p, r;
            cin >> l >> v >> p >> r;
            Octal(l, v, p, r);
            // cout << intersectOctal(l, v, p, r) << endl;
        }
        else if (operation[0] == 'D')
        {
            char axis;
            int i;
            cin >> axis >> i;
            // cout << determinant(axis, i) << endl;
        }
    }

    return 0;
}