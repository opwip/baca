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

            // Always have to be done nested 1
            indexing += 1;
        }
        int i = 0;
        while (i < sizeof(lista) / sizeof(lista[0]))
        {
            cout << lista[i] << ' ';
            ++i;
        }
        cout << endl;

        // Always have to be done
        ile -= 1;

        while (action_type != 'F')
        {
            int cur_index = 0, real_index, fragment, thing_for_M, fragment_count, fragment_start, fragment_end;
            cin >> action_type;
            if (action_type == 'R')
            {
                cin >> indexes >> fragment;
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
                        fragment_start = cur_index - 1;
                    }

                    if (fragment_count == fragment)
                    {
                        fragment_end = cur_index - 1;
                    }
                    if (fragment_count == fragment)
                    {
                        cout << "end of fragment" << ' ';
                        fragment_count = 0;
                        cout << fragment_start << ' ' << fragment_end << ' ' << endl;
                        if (action_type == 'R')
                        {
                            cout << "Odwracanie" << endl;
                            int reverse_buffer1, reverse_buffer2;
                            while (fragment_start != fragment_end && (fragment_start + 1 != fragment_end && (fragment_start != 0 && fragment_end != lenght)))
                            {
                                cout << fragment_start << ' ' << fragment_end << endl;
                                reverse_buffer1 = lista[fragment_start];
                                reverse_buffer2 = lista[fragment_end];
                                lista[fragment_end] = reverse_buffer1;
                                lista[fragment_start] = reverse_buffer2;
                                fragment_start++;
                                fragment_start = (fragment_start == lenght) ? 0 : fragment_start;
                                fragment_end--;
                                fragment_end = (fragment_end == 0) ? lenght - 1 : fragment_end;
                            }
                            cout << fragment_start << ' ' << fragment_end << endl;

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
                    }
                } while (cur_index != real_index);

                fragment_start = cur_index - fragment;
                fragment_end = cur_index;
                fragment_count = 0;
                cout << endl;
                cout << "end of fragment" << endl;
            }
        }
    }
    system("pause");
    return 0;
}
