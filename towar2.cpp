// Yaroslav Kolesnik
#include <iostream>
using namespace std;

struct place
{
    unsigned short int quantity;
    unsigned char code[2];
};

struct shelf
{
    place places[128];
    unsigned short int max_places;
};

struct rack
{
    shelf shelfs[128];
    unsigned short int max_shelfs;
};

struct warehouse
{
    rack racks[128];
    shelf handy_shelf;
    unsigned short int max_racks;
} warehouses[128];
rack handy_rack;
shelf handy_shelf;
unsigned short int max_warehouses;

void SETAP(int w, int r, int s, int P)
{
    if (w >= max_warehouses || w < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (r >= warehouses[w].max_racks || r < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (s >= warehouses[w].racks[r].max_shelfs || s < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (P > 128 || P < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].racks[r].shelfs[s].max_places = P;
    for (int i = 0; i < warehouses[w].racks[r].shelfs[s].max_places; i++)
    {
        warehouses[w].racks[r].shelfs[s].places[i].quantity = 0;
        warehouses[w].racks[r].shelfs[s].places[i].code[0] = '0';
        warehouses[w].racks[r].shelfs[s].places[i].code[1] = '0';
    }
}

void SETAS(int w, int r, int S, int P)
{
    if (w >= max_warehouses || w < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (r >= warehouses[w].max_racks || r < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (S > 128 || S < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].racks[r].max_shelfs = S;
    for (int i = 0; i < warehouses[w].racks[r].max_shelfs; i++)
    {
        SETAP(w, r, i, P);
    }
}

void SETAR(int w, int R, int S, int P)
{
    if (w >= max_warehouses || w < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (R > 128 || R < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].max_racks = R;
    for (int i = 0; i < warehouses[w].max_racks; i++)
    {
        SETAS(w, i, S, P);
    }
}

void SETAW(int W, int R, int S, int P)
{
    if (W > 128 || W < 0)
    {
        cout << "error" << endl;
        return;
    }
    max_warehouses = W;
    for (int i = 0; i < max_warehouses; i++)
    {
        SETAR(i, R, S, P);
    }
}

void SETHW(int w, int P)
{
    if (w >= max_warehouses || w < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (P > 128 || P < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].handy_shelf.max_places = P;
    for (int i = 0; i < warehouses[w].handy_shelf.max_places; i++)
    {
        warehouses[w].handy_shelf.places[i].quantity = 0;
        warehouses[w].handy_shelf.places[i].code[0] = '0';
        warehouses[w].handy_shelf.places[i].code[1] = '0';
    }
}

void SETHR(int S, int P)
{
    if (S > 128 || S < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_rack.max_shelfs = S;
    for (int i = 0; i < handy_rack.max_shelfs; i++)
    {
        if (P > 128 || P < 0)
        {
            cout << "error" << endl;
            return;
        }
        handy_rack.shelfs[i].max_places = P;
        for (int j = 0; j < handy_rack.shelfs[i].max_places; j++)
        {
            handy_rack.shelfs[i].places[j].quantity = 0;
            handy_rack.shelfs[i].places[j].code[0] = '0';
            handy_rack.shelfs[i].places[j].code[1] = '0';
        }
    }
}

void SETHS(int P)
{
    if (P > 128 || P < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_shelf.max_places = P;
    for (int j = 0; j < handy_shelf.max_places; j++)
    {
        handy_shelf.places[j].quantity = 0;
        handy_shelf.places[j].code[0] = '0';
        handy_shelf.places[j].code[1] = '0';
    }
}

void PUTW(int w, int r, int s, int p, int A)
{
    if (A < 0 || w >= max_warehouses || w < 0 || r >= warehouses[w].max_racks || r < 0 || s >= warehouses[w].racks[r].max_shelfs || p >= warehouses[w].racks[r].shelfs[s].max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].racks[r].shelfs[s].places[p].quantity +=
        ((warehouses[w].racks[r].shelfs[s].places[p].quantity + A) <= 65535)
            ? A
            : (65535 - warehouses[w].racks[r].shelfs[s].places[p].quantity);
}

void PUTH(int w, int p, int A)
{
    if (A < 0 || w >= max_warehouses || w < 0 || p >= warehouses[w].handy_shelf.max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].handy_shelf.places[p].quantity +=
        ((warehouses[w].handy_shelf.places[p].quantity + A) <= 65535)
            ? A
            : (65535 - warehouses[w].handy_shelf.places[p].quantity);
}

void PUTR(int s, int p, int A)
{
    if (A < 0 || s >= handy_rack.max_shelfs || s < 0 || p >= handy_rack.shelfs[s].max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_rack.shelfs[s].places[p].quantity +=
        ((handy_rack.shelfs[s].places[p].quantity + A) <= 65535)
            ? A
            : (65535 - handy_rack.shelfs[s].places[p].quantity);
}

void PUTS(int p, int A)
{
    if (A < 0 || p >= handy_shelf.max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_shelf.places[p].quantity +=
        ((handy_shelf.places[p].quantity + A) <= 65535)
            ? A
            : (65535 - handy_shelf.places[p].quantity);
}

void POPW(int w, int r, int s, int p, int A)
{
    if (A < 0 || w >= max_warehouses || w < 0 || r >= warehouses[w].max_racks || r < 0 || s >= warehouses[w].racks[r].max_shelfs || s < 0 || p >= warehouses[w].racks[r].shelfs[s].max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].racks[r].shelfs[s].places[p].quantity -=
        ((warehouses[w].racks[r].shelfs[s].places[p].quantity + A) >= 0)
            ? A
            : warehouses[w].racks[r].shelfs[s].places[p].quantity;
}

void POPH(int w, int p, int A)
{
    if (A < 0 || w >= max_warehouses || w < 0 || p >= warehouses[w].handy_shelf.max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    warehouses[w].handy_shelf.places[p].quantity -=
        ((warehouses[w].handy_shelf.places[p].quantity + A) >= 0)
            ? A
            : warehouses[w].handy_shelf.places[p].quantity;
}

void POPR(int s, int p, int A)
{
    if (A < 0 || s >= handy_rack.max_shelfs || s < 0 || p >= handy_rack.shelfs[s].max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_rack.shelfs[s].places[p].quantity -=
        ((handy_rack.shelfs[s].places[p].quantity + A) >= 0)
            ? A
            : handy_rack.shelfs[s].places[p].quantity;
}

void POPS(int p, int A)
{
    if (A < 0 || p >= handy_shelf.max_places || p < 0)
    {
        cout << "error" << endl;
        return;
    }
    handy_shelf.places[p].quantity -=
        ((handy_shelf.places[p].quantity - A) >= 0)
            ? A
            : handy_shelf.places[p].quantity;
}

void FILL(int W, int R, int S, int P, int A)
{
    if (W > 128 || W < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (R > 128 || R < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (S > 128 || S < 0)
    {
        cout << "error" << endl;
        return;
    }
    if (P > 128 || P < 0)
    {
        cout << "error" << endl;
        return;
    }

    max_warehouses = W;

    handy_rack.max_shelfs = S;
    for (int i = 0; i < handy_rack.max_shelfs; i++)
    {
        handy_rack.shelfs[i].max_places = S;
        for (int j = 0; j < handy_rack.shelfs[i].max_places; j++)
        {
            handy_rack.shelfs[i].places[j].quantity = 0;
            handy_rack.shelfs[i].places[j].code[0] = '0';
            handy_rack.shelfs[i].places[j].code[1] = '0';
        }
    }

    handy_shelf.max_places = P;
    for (int j = 0; j < handy_shelf.max_places; j++)
    {
        handy_shelf.places[j].quantity = 0;
        handy_shelf.places[j].code[0] = '0';
        handy_shelf.places[j].code[1] = '0';
    }

    for (int w = 0; w < max_warehouses; w++)
    {
        if (w >= max_warehouses)
        {
            cout << "error" << endl;
            return;
        }
        if (R > 128)
        {
            cout << "error" << endl;
            return;
        }
        warehouses[w].max_racks = R;
        warehouses[w].handy_shelf.max_places = P;
        for (int i = 0; i < warehouses[w].handy_shelf.max_places; i++)
        {
            warehouses[w].handy_shelf.places[i].quantity = 0;
            warehouses[w].handy_shelf.places[i].code[0] = '0';
            warehouses[w].handy_shelf.places[i].code[1] = '0';
        }
        for (int r = 0; r < warehouses[w].max_racks; r++)
        {
            if (w >= max_warehouses)
            {
                cout << "error" << endl;
                return;
            }
            if (r >= warehouses[w].max_racks)
            {
                cout << "error" << endl;
                return;
            }
            if (S > 128)
            {
                cout << "error" << endl;
                return;
            }
            warehouses[w].racks[r].max_shelfs = S;
            for (int s = 0; s < warehouses[w].racks[r].max_shelfs; s++)
            {
                if (w >= max_warehouses)
                {
                    cout << "error" << endl;
                    return;
                }
                if (r >= warehouses[w].max_racks)
                {
                    cout << "error" << endl;
                    return;
                }
                if (s >= warehouses[w].racks[r].max_shelfs)
                {
                    cout << "error" << endl;
                    return;
                }
                warehouses[w].racks[r].shelfs[s].max_places = P;
                for (int i = 0; i < warehouses[w].racks[r].shelfs[s].max_places; i++)
                {
                    PUTW(w, r, s, i, A);
                    warehouses[w].racks[r].shelfs[s].places[i].code[0] = '0';
                    warehouses[w].racks[r].shelfs[s].places[i].code[1] = '0';
                }
            }
        }
    }
}

void GETE()
{
    unsigned qua = 0;
    for (int w = 0; w < max_warehouses; w++)
    {

        for (int r = 0; r < warehouses[w].max_racks; r++)
        {

            for (int s = 0; s < warehouses[w].racks[r].max_shelfs; s++)
            {

                for (int p = 0; p < warehouses[w].racks[r].shelfs[s].max_places; p++)
                {
                    qua += warehouses[w].racks[r].shelfs[s].places[p].quantity;
                }
            }
        }
    }
    cout << qua << endl;
}

int main()
{
    char input[7];
    bool end = false;
    int count_input = 0;
    while (!end)
    {
        cin >> input;
        // for (char i : input)
        //     cout << i << endl;
        if (input[0] == 'E' && input[1] == 'N' && input[2] == 'D')
        {
            end = true;
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'A' && input[5] == 'P')
        {
            int l, v, p, h;
            cin >> l >> v >> p >> h;
            SETAP(l, v, p, h);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'A' && input[5] == 'S')
        {
            int l, v, p, h;
            cin >> l >> v >> p >> h;
            SETAS(l, v, p, h);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'A' && input[5] == 'R')
        {
            int l, v, p, h;
            cin >> l >> v >> p >> h;
            SETAR(l, v, p, h);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'A' && input[5] == 'W')
        {
            int l, v, p, h;
            cin >> l >> v >> p >> h;
            SETAW(l, v, p, h);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'H' && input[5] == 'W')
        {
            int l, v, p, h;
            cin >> l >> v;
            SETHW(l, v);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'H' && input[5] == 'R')
        {
            int l, v;
            cin >> l >> v;
            SETHR(l, v);
        }
        if (input[0] == 'S' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'H' && input[5] == 'S')
        {
            int l;
            cin >> l;
            SETHS(l);
        }
        if (input[0] == 'P' && input[1] == 'U' && input[2] == 'T' && input[3] == '-' && input[4] == 'W')
        {

            int W, R, S, P, A;
            cin >> W >> R >> S >> P >> A;
            PUTW(W, R, S, P, A);
        }
        if (input[0] == 'P' && input[1] == 'U' && input[2] == 'T' && input[3] == '-' && input[4] == 'H')
        {

            int W, P, A;
            cin >> W >> P >> A;
            PUTH(W, P, A);
        }
        if (input[0] == 'P' && input[1] == 'U' && input[2] == 'T' && input[3] == '-' && input[4] == 'R')
        {

            int S, P, A;
            cin >> S >> P >> A;
            PUTR(S, P, A);
        }
        if (input[0] == 'P' && input[1] == 'U' && input[2] == 'T' && input[3] == '-' && input[4] == 'S')
        {

            int P, A;
            cin >> P >> A;
            PUTS(P, A);
        }
        if (input[0] == 'F' && input[1] == 'I' && input[2] == 'L' && input[3] == 'L')
        {

            int W, R, S, P, A;
            cin >> W >> R >> S >> P >> A;
            FILL(W, R, S, P, A);
        }
        if (input[0] == 'G' && input[1] == 'E' && input[2] == 'T' && input[3] == '-' && input[4] == 'E')
        {
            GETE();
        }
    }

    // showAllPlaces();

    // system("Pause");
    return 0;
}
