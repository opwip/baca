// Yaroslav Kolesnik
#include <iostream>
using namespace std;

int main() {
    int ile, lenght, indexing, num, indexes, sum;
    char action_type;
    cin >> ile;
    while (ile > 0){
        cin >> lenght;
        indexing = 0;
        int lista[lenght];
        while (indexing < lenght){
            cout << indexing << endl;
            cin >> num;
            lista[indexing] = num;
            
            
            
            // Always have to be done nested 1
            indexing += 1;
        }
        for (int i : lista){
            cout << i << ' ';
        }
        cout << endl;

        // Always have to be done
        ile -=1;

        while (action_type != 'F') {
            int cur_index = 0,real_index, fragment, thing_for_M, fragment_count;
            cin >> action_type;
            sum = 0;
            if (action_type == 'C'){
                cin >> indexes >> fragment;
                real_index = (((indexes % lenght) + lenght) % lenght);
                cur_index = real_index;
                fragment_count = 0;
                cout << lista[cur_index] << endl;
                cur_index ++;
                fragment_count++;
                while (cur_index != real_index){
                    cur_index = (cur_index == lenght-1) ? 0: cur_index;
                    cout << lista[cur_index++] << ' ';
                    fragment_count++;
                    if (fragment_count == fragment){
                        cout << "end of fragment" << endl;
                        fragment_count = 0;
                    }

                }

            }
            cout << sum << endl;
        }
        cout << lista[1];
        



    }
    system("pause");
    return 0;
}


