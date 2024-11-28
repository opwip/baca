// Yaroslav Kolesnik
#include <iostream>
using namespace std;

int main()
{
    int ile, length, indexing, num, indexes;
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

            indexing = indexing + 1;
        }
        int i = 0;
        while (i < length)
        {
            cout << lista[i] << ' ';
            i = i + 1;
        }
        cout << endl;
        ile = ile - 1;
        action_type = 'N';
        while (action_type != 'F')
        {
            int cur_index = 0, real_index, real_fragment, fragment, migration, fragment_count, fragment_start, fragment_end, is_fragment_full = 0, counter_pairs = 0; // 0 - undefined state, 1 - full segment state, 2 - not full segment state
            cin >> action_type;
            bool do_once = false;
            bool make_it = true;
            bool sort_type = false;
            bool migration_type = false;
            if (action_type != 'F')
            {

                cin >> indexes >> fragment;
                migration_type = (fragment < 0) ? true : false;
                sort_type = (fragment < 0) ? true : false;
                fragment = (fragment < 0) ? (fragment * -1) : fragment;
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
                fragment_count = fragment_count + 1;
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
                else if (((cur_index + 1) % length) == real_index && fragment_count < fragment)
                {
                    is_fragment_full = 2;
                    fragment_end = cur_index;
                    real_fragment = fragment_count;
                }

                if (is_fragment_full == 1) // R and C
                {

                    if (action_type == 'R' && sort_type == false)
                    {
                        int left = fragment_start;
                        int right = fragment_end;
                        int last_left = left;
                        int last_right = right;
                        while (left != right && left != last_right && right != last_left)
                        {

                            int temp = lista[left];
                            lista[left] = lista[right];
                            lista[right] = temp;
                            last_left == left;
                            left = (left + 1) % length;
                            last_right = right;
                            right = (right - 1 + length) % length;
                        }
                    }
                    if (action_type == 'C')
                    {

                        int last_frag_start, cur_frag_start = fragment_start;
                        if (counter_pairs % 2)
                        {
                            int k = 0;
                            while (k < real_fragment)
                            {
                                int temp = lista[last_frag_start];
                                lista[last_frag_start] = lista[cur_frag_start];
                                lista[cur_frag_start] = temp;

                                last_frag_start = (last_frag_start + 1) % length;

                                cur_frag_start = (cur_frag_start + 1) % length;

                                k = k + 1;
                            }
                            counter_pairs = 0;
                        }
                        else
                        {
                            last_frag_start = cur_frag_start;
                            counter_pairs = counter_pairs + 1;
                        }
                    }
                }
                if (is_fragment_full == 1 || is_fragment_full == 2) // M and S
                {
                    if (action_type == 'M')
                    {
                        int left = fragment_start;
                        int right = fragment_end;
                        int migrations_counter = 0;
                        int save_migration = migration;
                        migration = migration % real_fragment;

                        if (migration < 0)
                        {
                            migration = migration + real_fragment;
                        }

                        while (migrations_counter < migration)
                        {
                            if (migration_type == false)
                            {
                                int k = 0;

                                int current_index_migrate = right;
                                int temp = lista[right];
                                while (k < real_fragment)
                                {

                                    lista[current_index_migrate] = lista[(current_index_migrate - 1 + length) % length];
                                    current_index_migrate = (current_index_migrate - 1 + length) % length;

                                    k = k + 1;
                                }

                                lista[(left) % length] = temp;

                                migrations_counter = migrations_counter + 1;
                            }
                            else if (migration_type == true)
                            {
                                int k = 0;

                                int current_index_migrate = left;
                                int temp = lista[left];
                                while (k < real_fragment)
                                {

                                    lista[current_index_migrate] = lista[(current_index_migrate + 1) % length];
                                    current_index_migrate = (current_index_migrate + 1) % length;

                                    k = k + 1;
                                }

                                lista[(right + length) % length] = temp;

                                migrations_counter = migrations_counter + 1;
                            }
                        }
                        migration = save_migration;
                    }

                    if (action_type == 'S')
                    {
                        int i = 0;
                        while (i < real_fragment - 1)
                        {
                            int left1 = fragment_start;
                            int j = 0;

                            while (j < real_fragment - i - 1)
                            {
                                int next = (left1 + 1) % length;
                                if (sort_type)
                                {
                                    if (lista[left1] < lista[next])
                                    {

                                        int temp = lista[left1];
                                        lista[left1] = lista[next];
                                        lista[next] = temp;
                                    }
                                }
                                else
                                {
                                    if (lista[left1] > lista[next])
                                    {

                                        int temp = lista[left1];
                                        lista[left1] = lista[next];
                                        lista[next] = temp;
                                    }
                                }

                                left1 = (left1 + 1) % length;
                                j = j + 1;
                            }

                            i = i + 1;
                        }
                    }
                }
                if (is_fragment_full == 1)
                {
                    fragment_count = 0;
                    is_fragment_full = 0;
                }
                if (is_fragment_full == 2)
                {
                    fragment_count = 0;
                    is_fragment_full = 0;
                }

                cur_index = (cur_index + 1) % length;
            } while (cur_index != real_index);
        }
        i = 0;
        while (i < length)
        {
            cout << lista[i] << ' ';
            i = i + 1;
        }
        cout << endl;
        action_type = 'N';
    }
    return 0;
}
