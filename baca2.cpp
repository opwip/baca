// Yaroslav Kolesnik
#include <iostream>
using namespace std;

int main()
{
    int ile, length, indexing, num, indexes, sum;
    char action_type;
    cin >> ile;
    while (ile > 0)
    {
        cin >> length;
        indexing = 0;
        int lista[length];
        while (indexing < length)
        {
            cin >> num;
            lista[indexing] = num;

            indexing++;
        }
        int i = 0;
        while (i < sizeof(lista) / sizeof(lista[0]))
        {
            cout << lista[i] << ' ';
            ++i;
        }
        cout << endl;

        // Always has to be done
        ile--;

        while (action_type != 'F')
        {
            int cur_index = 0, real_index, real_fragment, fragment, migration, fragment_count, fragment_start, fragment_end, is_fragment_full = 0; // 0 - undefined state, 1 - full segment state, 2 - not full segment state
            cin >> action_type;
            if (action_type != 'F')
            {
                cin >> indexes >> fragment;
            }
            if (action_type == 'M')
            {
                cin >> migration;
            }
            real_index = (((indexes % length) + length) % length);
            cur_index = real_index;
            fragment_count = 0;
            do
            {

                cur_index = (cur_index == length) ? 0 : cur_index;
                fragment_count++;
                if (fragment_count == 1)
                {
                    fragment_start = cur_index;
                }
                if (fragment_count == fragment)
                {
                    is_fragment_full = 1;
                    fragment_end = cur_index;
                    real_fragment = fragment_count;
                }
                else if (cur_index + 1 == real_index)
                {
                    is_fragment_full = 2;
                    fragment_end = cur_index;
                    real_fragment = fragment_count;
                }

                cur_index++;
                if (is_fragment_full == 1) // R and S
                {
                    if (action_type == 'R')
                    {
                        int left = fragment_start;
                        int right = fragment_end;
                        while (left != right && (left + length - 1) % length != right)
                        {

                            int temp = lista[left];
                            lista[left] = lista[right];
                            lista[right] = temp;

                            left = (left + 1) % length;

                            right = (right - 1 + length) % length;
                        }
                    }
                }
                if (is_fragment_full == 1 || is_fragment_full == 2) // M and C
                {
                    if (action_type == 'M')
                    {
                        int left = fragment_start;
                        int right = fragment_end;
                        int temp, migrate_to;
                        migration = migration % real_fragment;
                        if (migration < 0)
                        {
                            migration += real_fragment;
                        }
                        cout
                            << migration << endl;
                        int k = 0;
                        while (k < real_fragment)
                        {

                            int current_index = (fragment_start + k) % length;
                            int new_index = (current_index + migration) % real_fragment + fragment_start;
                            new_index %= length;
                            cout << "Element at index " << current_index << " migrates to index " << new_index << endl;
                            k++;
                        }
                    }
                }
                if (is_fragment_full == 1)
                {
                    cout << "end of fragment" << ' ';
                    fragment_count = 0;
                    cout << fragment_start << ' ' << fragment_end << ' ' << endl;
                    is_fragment_full = 0;
                }
                if (is_fragment_full == 2)
                {
                    cout << "end of fragment" << ' ';
                    fragment_count = 0;
                    cout << fragment_start << ' ' << fragment_end << ' ' << endl;
                    is_fragment_full = 0;
                }
            } while (cur_index != real_index);
            i = 0;
            while (i < sizeof(lista) / sizeof(lista[0]))
            {
                cout << lista[i] << ' ';
                ++i;
            }
            cout << endl
                 << "result" << endl;
        }
        action_type = 'N';
    }
    return 0;
}
