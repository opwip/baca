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
    unsigned short int max_places = 0;
};

struct rack
{
    shelf shelfs[128];
    unsigned short int max_shelfs = 0;
};

struct warehouse
{
    rack racks[128];
    unsigned short int max_racks = 0;
} warehouses[128];

unsigned short int max_warehouses = 128;

// void initializePlaces(shelf &sh, unsigned short int count)
// {
//     if (sh.max_places == 0)
//     {
//         sh.max_places = count;
//         for (int i = 0; i < count; i++)
//         {
//             sh.places[i].quantity = 0;
//             sh.places[i].code[0] = '0';
//             sh.places[i].code[1] = '0';
//         }
//     }
// }

// void initializeShelfs(rack &rk, unsigned short int count)
// {
//     if (rk.max_shelfs == 0)
//     {
//         rk.max_shelfs = count;
//         for (int i = 0; i < count; i++)
//         {
//             initializePlaces(rk.shelfs[i], 128);
//         }
//     }
// }

// void initializeRacks(warehouse &wh, unsigned short int count)
// {
//     if (wh.max_racks == 0)
//     {
//         wh.max_racks = count;
//         for (int i = 0; i < count; i++)
//         {
//             initializeShelfs(wh.racks[i], 128);
//         }
//     }
// }

// void initializeWarehouses()
// {
//     for (int w = 0; w < max_warehouses; w++)
//     {
//         if (warehouses[w].max_racks == 0)
//         {
//             initializeRacks(warehouses[w], 128);
//         }
//     }
// }

void showAllPlaces()
{
    for (int w = 0; w < max_warehouses; w++)
    {
        if (warehouses[w].max_racks == 0)
            continue;

        for (int r = 0; r < warehouses[w].max_racks; r++)
        {
            if (warehouses[w].racks[r].max_shelfs == 0)
                continue;

            for (int s = 0; s < warehouses[w].racks[r].max_shelfs; s++)
            {
                if (warehouses[w].racks[r].shelfs[s].max_places == 0)
                    continue;

                for (int p = 0; p < warehouses[w].racks[r].shelfs[s].max_places; p++)
                {
                    place &current_place = warehouses[w].racks[r].shelfs[s].places[p];
                    cout << "Warehouse " << w
                         << ", Rack " << r
                         << ", Shelf " << s
                         << ", Place " << p
                         << ": Quantity = " << current_place.quantity
                         << ", Code = " << current_place.code << endl;
                }
            }
        }
    }
}

// void SET(int w, int r, int s, int P)
// {
//     if (w >= max_warehouses)
//     {
//         cout << "Error: Warehouse index out of bounds." << endl;
//         return;
//     }

//     initializeWarehouses();
//     initializeRacks(warehouses[w], 128);
//     initializeShelfs(warehouses[w].racks[r], 128);
//     initializePlaces(warehouses[w].racks[r].shelfs[s], P);

//     for (int i = 0; i < P; i++)
//     {
//         warehouses[w].racks[r].shelfs[s].places[i].quantity = 12;
//         warehouses[w].racks[r].shelfs[s].places[i].code[0] = '0';
//         warehouses[w].racks[r].shelfs[s].places[i].code[1] = '0';
//     }
// }

// int main()
// {
//     // Example: Initialize warehouse 1, rack 1, shelf 1 with 10 places
//     // SET(0, 0, 37, 111);
//     // SET2(1, 1, 1, 10);

//     // Display all places
//     // showAllPlaces();
//     return 0;
// }
