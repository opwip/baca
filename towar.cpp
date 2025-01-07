// Yaroslav Kolesnik
#include <iostream>
using namespace std;

struct place {
    unsigned int quantity;
    char code[2];
};

struct shelf {
    place places[128];
    unsigned int max_places = 128;
};

struct rack {
    shelf shelfs[128];
    unsigned int max_shelfs = 128;
};

struct warehouse {
    rack racks[128];
    shelf handy_shelf;
    unsigned int max_racks = 128;
};

struct storage {
    warehouse warehouses[128];
    rack handy_rack;
    unsigned int max_warehouses = 128;
};

storage main_storage;

void showAllPlaces() {
    for (int w = 0; w < main_storage.max_warehouses; w++) { // Loop through warehouses
        for (int r = 0; r < main_storage.warehouses[w].max_racks; r++) { // Loop through racks
            for (int s = 0; s < main_storage.warehouses[w].racks[r].max_shelfs; s++) { // Loop through shelves
                for (int p = 0; p < main_storage.warehouses[w].racks[r].shelfs[s].max_places; p++) { // Loop through places
                    place& current_place = main_storage.warehouses[w].racks[r].shelfs[s].places[p];
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

void SET(char type[3], int w, int r, int s, int P){
    main_storage.warehouses[w].racks[r].shelfs[s].max_places = P;
    for (int i = 0; i < P; i++){
        main_storage.warehouses[w].racks[r].shelfs[s].places[i].quantity = 0;
        main_storage.warehouses[w].racks[r].shelfs[s].places[i].code[0] = '0';
        main_storage.warehouses[w].racks[r].shelfs[s].places[i].code[1] = '0';
    }
}

int main(){
    char type[3] = {'-','A','P'};
    SET(type, 1, 1, 1, 10);
    showAllPlaces();
    return 0;
}



