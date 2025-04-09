// Yaroslav Kolesnik

void Insert(char* sequence, int* set)
{
    if (*sequence == '\0')
    {
        return;
    }
    if (*sequence == ' ')
    {
        Insert(sequence + 1, set);
        return;
    }

    int pos = (*sequence - '0') * 16 +
        (*(sequence + 1) - '0') * 8 +
        (*(sequence + 2) - '0') * 4 +
        (*(sequence + 3) - '0') * 2 +
        (*(sequence + 4) - '0');
    *set = *set | (1 << pos);
    Insert(sequence + 5, set);
}
void Emplace(char* sequence, int* set)
{
    *set = 0;
    Insert(sequence, set);
}

void Complement(int set1, int* set2)
{
    *set2 = ~set1;
}

void Erase(char* sequence, int* set)
{
    if (*sequence == '\0')
    {
        return;
    }
    if (*sequence == ' ')
    {
        Erase(sequence + 1, set);
        return;
    }

    int pos = (*sequence - '0') * 16 +
        (*(sequence + 1) - '0') * 8 +
        (*(sequence + 2) - '0') * 4 +
        (*(sequence + 3) - '0') * 2 +
        (*(sequence + 4) - '0');
    *set = *set & ~(1 << pos);
    Erase(sequence + 5, set);
}

void PrintElement(int set, char* output, int pos)
{
    if (pos < 0)
    {
        *output = '\0';
        return;
    }

    if (set & (1 << pos))
    {
        *output = (pos / 16) + '0';
        *(output + 1) = ((pos / 8) % 2) + '0';
        *(output + 2) = ((pos / 4) % 2) + '0';
        *(output + 3) = ((pos / 2) % 2) + '0';
        *(output + 4) = (pos % 2) + '0';
        *(output + 5) = ' ';
        PrintElement(set, output + 6, pos - 1);
    }
    else
    {
        PrintElement(set, output, pos - 1);
    }
}

void Print(int set, char* output)
{
    if (set == 0)
    {
        *output = 'e';
        *(output + 1) = 'm';
        *(output + 2) = 'p';
        *(output + 3) = 't';
        *(output + 4) = 'y';
        *(output + 5) = '\0';
        return;
    }

    PrintElement(set, output, 31);
}

bool Emptiness(int set)
{
    if (set != 0)
    {
        return false;
    }
    return true;
}

bool Nonempty(int set)
{
    if (set == 0)
    {
        return false;
    }
    return true;
}

bool Member(char* sequence, int set)
{
    int pos = 0;
    Emplace(sequence, &pos);
    return ((pos & set) == pos);
}

bool Disjoint(int set1, int set2)
{
    return ((set1 & set2) == 0);
}

bool Conjunctive(int set1, int set2)
{
    return ((set1 & set2) != 0);
}

bool Inclusion(int set1, int set2)
{
    return ((set1 & set2) == set1);
}

bool Equality(int set1, int set2)
{
    return (set1 == set2);
}

void Union(int set1, int set2, int* set3)
{
    *set3 = set1 | set2;
}

void Intersection(int set1, int set2, int* set3)
{
    *set3 = set1 & set2;
}

void Symmetric(int set1, int set2, int* set3)
{
    *set3 = set1 ^ set2;
}

void Difference(int set1, int set2, int* set3)
{
    *set3 = set1 & ~set2;
}

int Help_Cardinality(int set, int card, int pos)
{
    if (pos < 0)
    {
        return card;
    }
    if (set & (1 << pos))
    {
        return Help_Cardinality(set, card + 1, pos - 1);
    }
    else
    {
        return Help_Cardinality(set, card, pos - 1);
    }
}

int Cardinality(int set)
{
    return Help_Cardinality(set, 0, 31);
}

bool ReverseLexLessThan(int set1, int set2, int bitPos = 31) {
    if (bitPos < 0) {
        return false;
    }
    int bit1 = (set1 >> bitPos) & 1;
    int bit2 = (set2 >> bitPos) & 1;
    if (bit1 < bit2) return true;
    if (bit1 > bit2) return false;
    return ReverseLexLessThan(set1, set2, bitPos - 1);
}

bool LessThan(int set1, int set2) {
    int c1 = Cardinality(set1);
    int c2 = Cardinality(set2);
    if (c1 != c2) {
        return c1 < c2;
    }
    return ReverseLexLessThan(set1, set2);
}

bool LessEqual(int set1, int set2) {
    int c1 = Cardinality(set1);
    int c2 = Cardinality(set2);
    if (c1 != c2) {
        return c1 < c2;
    }
    return ReverseLexLessThan(set1, set2) || (set1 == set2);
}

bool GreatThan(int set1, int set2) {
    int c1 = Cardinality(set1);
    int c2 = Cardinality(set2);
    if (c1 != c2) {
        return c1 > c2;
    }
    return !ReverseLexLessThan(set1, set2) && (set1 != set2);
}

bool GreatEqual(int set1, int set2) {
    int c1 = Cardinality(set1);
    int c2 = Cardinality(set2);
    if (c1 != c2) {
        return c1 > c2;
    }
    return !ReverseLexLessThan(set1, set2);
}