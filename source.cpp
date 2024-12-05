// Yaroslav Kolesnik
#include <iostream>
using namespace std;

void Add(int adding, int set[])
{
    bool add = true;
    int i = 0;
    for (i; set[i] != -1; i++)
    {
        if (adding == set[i])
        {
            add = false;
        }
    }
    if (!(adding >= 1 && adding <= 4095))
    {
        add = false;
    }
    if (add)
    {

        set[i] = adding;
        set[i + 1] = -1;
    }
}

void Create(int size, int array[], int set[])
{
    set[0] = -1;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        bool in = false;
        for (int j = 0; set[j] != -1; j++)
        {
            if (set[j] == array[i])
            {
                in = true;
            }
        }
        if (!in)
        {
            if (array[i] >= 1 && array[i] <= 4095)
            {
                set[k] = array[i];
                k++;
                set[k] = -1;
            }
        }
    }
}

void Complement(int set[], int result[])
{
    int i = 0;
    for (i; result[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set[j] != -1; j++)
        {
            if (set[j] == result[i])
            {
                in = true;
            }
        }
        if (in)
        {
            result[i] = 0;
        }
    }
    int k = 0;
    for (i = 0; result[i] != -1; i++)
    {

        if (result[i] != 0)
        {
            cout << "set[" << i - k << "] = " << set[i - k] << " ";
            cout << "result[" << i << "] = " << result[i] << " ";
            cout << "Difference: " << i - k << endl;
            set[i - k] = result[i];
        }
        else
        {
            k++;
        }
    }
    set[i - k] = -1;
}

bool Equal(int setA[], int setB[])
{
    for (int i = 0; setA[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; setB[j] != -1; j++)
        {
            if (setB[j] == setA[i])
            {
                in = true;
            }
        }
        if (!in)
        {
            return false;
        }
    }
    return true;
}

bool Empty(int setA[])
{
    for (int i = 0; setA[i] != -1; i++)
        return false;
    return true;
}

bool Nonempty(int setA[])
{
    for (int i = 0; setA[i] != -1; i++)
        return true;
    return false;
}

bool Element(int num, int set[])
{
    for (int i = 0; set[i] != -1; i++)
        if (set[i] == num)
        {
            return true;
        }
    return false;
}

double Arithmetic(int set[])
{
    double sum = 0;
    int count = 0;
    for (int i = 0; set[i] != -1; i++)
    {
        sum += set[i];
        count++;
    }
    return (count > 0) ? (sum / count) : 0.0;
}

double Harmonic(int set[])
{
    double sum = 0;
    int count = 0;
    for (int i = 0; set[i] != -1; i++)
    {
        if (set[i] != 0)
        {
            sum += 1.0 / set[i];
            count++;
        }
    }
    return (count > 0) ? count / sum : 1.0;
}

void MinMax(int set[], int *min, int &max)
{
    if (set[0] == -1)
    {
        return;
    }

    *min = set[0];
    max = set[0];
    for (int i = 1; set[i] != -1; i++)
    {
        if (set[i] < *min)
        {
            *min = set[i];
        }
        if (set[i] > max)
        {
            max = set[i];
        }
    }
}

void Cardinality(int set[], int *var)
{
    for (int i = 0; set[i] != -1; i++)
    {
        *var += 1;
    }
}

void Union(int set1[], int set2[], int result[])

{
    int k = 0;
    for (int i = 0; set1[i] != -1; i++)
    {
        result[k] = set1[i];
        k++;
    }
    for (int i = 0; set2[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set1[j] != -1; j++)
        {
            if (set1[j] == set2[i])
            {
                in = true;
            }
        }
        if (in == false)
        {

            result[k] = set2[i];
            k++;
        }
    }
    result[k] = -1;
}

void Difference(int set1[], int set2[], int result[])
{
    int k = 0;
    for (int i = 0; set1[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set2[j] != -1; j++)
        {
            if (set2[j] == set1[i])
            {
                in = true;
            }
        }
        if (in == false)
        {

            result[k] = set1[i];
            k++;
        }
    }
    result[k] = -1;
}

void Intersection(int set1[], int set2[], int result[])
{
    int k = 0;
    for (int i = 0; set1[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set2[j] != -1; j++)
        {
            if (set2[j] == set1[i])
            {
                in = true;
            }
        }
        if (in)
        {

            result[k] = set1[i];
            k++;
        }
    }
    result[k] = -1;
}

void Symmetric(int set1[], int set2[], int result[])
{
    int k = 0;
    for (int i = 0; set1[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set2[j] != -1; j++)
        {
            if (set2[j] == set1[i])
            {
                in = true;
            }
        }
        if (!in)
        {

            result[k] = set1[i];
            k++;
        }
    }
    for (int i = 0; set2[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set1[j] != -1; j++)
        {
            if (set1[j] == set2[i])
            {
                in = true;
            }
        }
        if (!in)
        {

            result[k] = set2[i];
            k++;
        }
    }
    result[k] = -1;
}

bool Subset(int set1[], int set2[])
{
    for (int i = 0; set1[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; set2[j] != -1; j++)
        {
            if (set1[i] == set2[j])
            {
                in = true;
                break;
            }
        }
        if (!in)
        {
            return false;
        }
        return true;
    }
}
