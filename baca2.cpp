// Yaroslav Kolesnik
#include <iostream>
using namespace std;

int main()
{
    int ile, lenght, indexing, num, indexes, sum;
    char action_type;
    cin >> ile;
    while (ile > 0)
    {
        cin >> lenght;
        indexing = 0;
        int lista[lenght];
        while (indexing < lenght)
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
            int cur_index = 0, real_index, fragment, migration, fragment_count, fragment_start, fragment_end;
            cin >> action_type;

            cin >> indexes >> fragment;
            if (action_type == 'M')
            {
                cin >> migration;
            }
            real_index = (((indexes % lenght) + lenght) % lenght);
            cur_index = real_index;
            fragment_count = 0;
            do
            {
                cout << lista[cur_index++] << ' ';
                cur_index = (cur_index == lenght) ? 0 : cur_index;
                fragment_count++;
                if (fragment_count == 1)
                {
                    fragment_start = cur_index;
                }

                if (fragment_count == fragment)
                {
                    fragment_end = cur_index - 1;
                }
                if (fragment_count == fragment) // Only for R and C
                {
                    cout << "end of fragment" << ' ';
                    fragment_count = 0;
                    cout << fragment_start - 1 << ' ' << fragment_end - 1 << ' ' << endl;
                    if (action_type == 'R')
                    {
                        int reverse_buffer1, reverse_buffer2;
                        while (fragment_start != fragment_end && (fragment_start + 1 != fragment_end && (fragment_start != 0 && fragment_end != lenght)))
                        {
                            reverse_buffer1 = lista[fragment_start];
                            reverse_buffer2 = lista[fragment_end];
                            lista[fragment_end] = reverse_buffer1;
                            lista[fragment_start] = reverse_buffer2;
                            fragment_start++;
                            fragment_start = (fragment_start == lenght) ? 0 : fragment_start;
                            fragment_end--;
                            fragment_end = (fragment_end == 0) ? lenght - 1 : fragment_end;
                        }
                    }
                }
                if (action_type == 'M')
                {
                    int buffer_migrate1, buffer_migrate2, migrate_to_index, index1, index2;
                    index1 = fragment_start;
                    migrate_to_index = 0;
                    cout << migrate_to_index << ' ' << index1 << endl;
                    cout << "result" << endl;
                    int i = 0;
                    while (i < sizeof(lista) / sizeof(lista[0]))
                    {
                        cout << lista[i] << ' ';
                        ++i;
                    }
                    cout << endl
                         << "result" << endl;
                }

            } while (cur_index != real_index);

            fragment_start = cur_index - fragment;
            fragment_end = cur_index;
            fragment_count = 0;
            cout << endl;
            cout << "end of fragment" << endl;
            cout << "result" << endl;
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
    system("pause");
    return 0;
}
