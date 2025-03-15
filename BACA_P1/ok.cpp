// Yaroslav Kolesnik
#include <iostream>
using namespace std;


void SortSet(int set[])
{
    int size = 0;
    while (set[size] != -1)
        size++;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (set[j] > set[j + 1])
            {
                int temp = set[j];
                set[j] = set[j + 1];
                set[j + 1] = temp;
            }
        }
    }
}
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
    if (adding < 1 || adding > 4095)
    {
        add = false;
    }
    if (add)
    {

        set[i] = adding;
        set[i + 1] = -1;
        SortSet(set);
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
    SortSet(set);
}

void Complement(int set[], int result[])
{
    int k = 0;

    for (int num = 1; num <= 4095; num++)
    {
        bool in = false;

        for (int i = 0; set[i] != -1; i++)
        {
            if (set[i] == num)
            {
                in = true;
                break;
            }
        }

        if (!in)
        {
            result[k] = num;
            k++;
        }
    }

    result[k] = -1;

    SortSet(result);
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
    for (int i = 0; setB[i] != -1; i++)
    {
        bool in = false;
        for (int j = 0; setA[j] != -1; j++)
        {
            if (setA[j] == setB[i])
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
    int counter = 0;
    for (int i = 0; set[i] != -1; i++)
    {
        counter += 1;
    }
    *var = counter;
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
            }
        }
        if (!in)
        {
            return false;
        }
    }
    return true;
}

void Properties(int set[], char inions[], double &arith, double *harmo, int &min, int *max, int &moc){
    bool stop = false;
    for (int i = 0; !stop; i++){
        if (inions[i] == 'a')
        
        {
            arith = Arithmetic(set);}
        else if (inions[i] == 'h')
        {*harmo = Harmonic(set);}
        else if (inions[i] == 'm')
        {MinMax(set,&min,*max);}
        else if (inions[i] == 'c')
        {Cardinality(set, &moc);}
        else {stop = true;}
    }
}


void printArray(int set[])
{
    int i = 0;
    for (i; set[i] != -1; i++)
    {
        cout << set[i] << " ";
    }
}

int main()
{
    // int arr1[] = {13, 13, 2, 3, 5};
    // int arr[] = {1, 2, 6, 3, -1, 0};
    // int res[] = {1, 2, 3, 4, 5, 6, -1};
    int kola[] = {1,2,-1};
    int kola2[] = {1,2,-1};
    // int res1[7];
    // int mix = 1, nim = 2;
    // int *mixp = &mix, &nimp = nim;
    // // Add(5, arr);
    // // Complement(arr, res);
    // // PrintSet(res);
    // // PrintSet(arr);
    // // MinMax(kola, mixp, nim);
    // // cout << mix << ' ' << nim;
    // // Create(6, arr1, ko);
    // Cardinality(kola2, mixp);
    // Subset(kola, kola2);
    Add(1, kola2);
    printArray(kola2);
    int firstSet[] = {2, 3, 4, 8, 5, 77, 77, 77, 77, 4342, 5552, 41241, 9};

    int sizeFirst = 13;
    int setFromFirst[sizeFirst + 1];

    cout << "Create: ";
    Create(sizeFirst, firstSet, setFromFirst);
    printArray(setFromFirst);
    cout << "\n";

    Add(3999, setFromFirst);
    Add(77, setFromFirst);
    Add(4095, setFromFirst);
    Add(4096, setFromFirst);
    Add(1, setFromFirst);
    Add(0, setFromFirst);
    cout << "Add: 3999, 77, 4095, 4096, 1, 0\n";
    printArray(setFromFirst);
    cout << "\n";

    char inions[] = {'a', 'h', 'm', 'c'};  // Instructions array
    
    // Variables to hold results
    double arith = 0.0;
    double harmo = 0.0;
    int min = 0;
    int max = 0;
    int moc = 0;

    // Call the function
    Properties(setFromFirst, inions, arith, &harmo, min, &max, moc);

    // Display results
    cout << "Arithmetic Mean: " << arith << endl;
    cout << "Harmonic Mean: " << harmo << endl;
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    cout << "Cardinality: " << moc << endl;

    // cout << "Empty: " << Empty(setFromFirst);
    // cout << "\n";
    // printArray(setFromFirst);
    // cout << "\n";

    // cout << "Nonempty: " << Nonempty(setFromFirst);
    // cout << "\n";
    // printArray(setFromFirst);
    // cout << "\n";

    // cout << "Element (14): " << Element(14, setFromFirst);
    // cout << "\n";
    // cout << "Element (3999): " << Element(3999, setFromFirst);
    // cout << "\n";
    // cout << "Element (-1): " << Element(-1, setFromFirst);
    // cout << "\n";
    // cout << "Element (8): " << Element(8, setFromFirst);
    // cout << "\n";
    // printArray(setFromFirst);
    // cout << "\n";

    cout << "Arithmetic: " << Arithmetic(setFromFirst);
    cout << "\n";
    cout << "Harmonic: " << Harmonic(setFromFirst);
    cout << "\n";
    printArray(setFromFirst);
    cout << "\n";

    int min1, max1;
    MinMax(setFromFirst, &min1, max1);
    cout << "MinMax: " << min1 << " " << max1;
    cout << "\n";
    printArray(setFromFirst);
    cout << "\n";

    int power;
    Cardinality(setFromFirst, &power);
    cout << "Cardinality: " << power;
    cout << "\n";
    printArray(setFromFirst);
    cout << "\n";

    // int secondArray[] = {432, 41, 644, 6, 26, 99, 35362, 34, 77, 2, 3, 4};

    // int sizeSecond = 12;
    // int setFromSecond[sizeSecond + 1];

    // cout << "Create: ";
    // Create(sizeSecond, secondArray, setFromSecond);
    // printArray(setFromSecond);
    // cout << "\n";

    // int setOfUnions[10000];
    // Union(setFromFirst, setFromSecond, setOfUnions);
    // cout << "Union: ";
    // printArray(setOfUnions);
    // cout << "\n";

    // int tarr[] = {-1};
    // int farr[] = {-1};
    // int uarr[10];
    // Union(tarr, farr, uarr);
    // cout << "uarr: ";
    // printArray(uarr);
    // cout << "\n";

    // cout << "\n";
    return 0;
}