// Yaroslav Kolesnik
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short int byte2;

typedef enum {
    AFR = 0,
    ALR,
    AFC,
    ALC,
    IBR,
    IAR,
    IBC,
    IAC,
    SWR,
    SWC,
    DFR,
    DLR,
    DFC,
    DLC,
    RMR,
    RMC,
    RMB,
    ISB,
    WRF,
    RDF,
    PRT,
    END,
    nothing = -1
} Command;


Command GetCommand(const char* str)
{
    if (strcmp(str, "AFR") == 0)
        return AFR;
    if (strcmp(str, "ALR") == 0)
        return ALR;
    if (strcmp(str, "ALR") == 0)
        return ALR;
    if (strcmp(str, "AFC") == 0)
        return AFC;
    if (strcmp(str, "ALC") == 0)
        return ALC;
    if (strcmp(str, "IBR") == 0)
        return IBR;
    if (strcmp(str, "IAR") == 0)
        return IAR;
    if (strcmp(str, "IBC") == 0)
        return IBC;
    if (strcmp(str, "IAC") == 0)
        return IAC;
    if (strcmp(str, "SWR") == 0)
        return SWR;
    if (strcmp(str, "SWC") == 0)
        return SWC;
    if (strcmp(str, "DFR") == 0)
        return DFR;
    if (strcmp(str, "DLR") == 0)
        return DLR;
    if (strcmp(str, "DFC") == 0)
        return DFC;
    if (strcmp(str, "DLC") == 0)
        return DLC;
    if (strcmp(str, "RMR") == 0)
        return RMR;
    if (strcmp(str, "RMC") == 0)
        return RMC;
    if (strcmp(str, "RMB") == 0)
        return RMB;
    if (strcmp(str, "ISB") == 0)
        return ISB;
    if (strcmp(str, "WRF") == 0)
        return WRF;
    if (strcmp(str, "RDF") == 0)
        return RDF;
    if (strcmp(str, "PRT") == 0)
        return PRT;
    return END;
}
int* getArrInfo(int* arr, const byte2 rowLen)
{
    int i = 0;
    for (i = 0; i < rowLen; i++)
    {
        int num;
        scanf("%d", &num);
        *(arr + i) = num;
    }
    return arr;
}
int** MatrixDownShift(int** const matrix, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = end; i > start; i--)
    {
        *(matrix + i - 1 + offset) = *(matrix + i - 1);
    }
    return matrix;
}
int** MatrixUpShift(int** const matrix, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = start; i < end - offset; i++)
    {
        *(matrix + i) = *(matrix + i + offset);
    }
    return matrix;
}
byte2* ArrDownShift(byte2* const arr, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = end; i > start; i--)
    {
        *(arr + i - 1 + offset) = *(arr + i - 1);
    }
    return arr;
}
byte2* ArrUpShift(byte2* const arr, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = start; i < end - offset; i++)
    {
        *(arr + i) = *(arr + i + offset);
    }
    return arr;
}
int* ArrRightShift(int* const arr, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = end - 1; i > start - 1; i--)
    {
        *(arr + i + offset) = *(arr + i);
    }
    return arr;
}
int* ArrLeftShift(int* const arr, const byte2 start, const byte2 end, const byte2 offset)
{
    int i = 0;
    for (i = start; i < end - offset; i++)
    {
        *(arr + i) = *(arr + i + offset);
    }
    return arr;
}


void IRB4(int*** matrix, byte2* const rowCount, byte2** rowWidth, byte2 newRowWidth, const byte2 offset)
{
    if (newRowWidth <= 0)
    {
        return;
    }
    if (*matrix == NULL)
    {
        *matrix = malloc(((*rowCount) + 1) * sizeof(**matrix));
    }
    else
    {
        *matrix = realloc(*matrix, ((*rowCount) + 1) * sizeof(**matrix));
    }
    if (*rowWidth == NULL)
    {
        *rowWidth = malloc((*rowCount + 1) * sizeof(**rowWidth));
    }
    else
    {
        *rowWidth = realloc(*rowWidth, (*rowCount + 1) * sizeof(**rowWidth));
    }

    int* newRow = malloc(newRowWidth * sizeof(*newRow));
    newRow = getArrInfo(newRow, newRowWidth);

    *matrix = MatrixDownShift(*matrix, offset, *rowCount, 1);
    *rowWidth = ArrDownShift(*rowWidth, offset, *rowCount, 1);
    *(*matrix + offset) = newRow;
    *(*rowWidth + offset) = newRowWidth;

    *rowCount = *rowCount + 1;
}

void ICB4(int** array, byte2* rowWidth, const byte2 insertedWidth, byte2 before, int** insertedArr)
{
    *array = realloc(*array, (*rowWidth + insertedWidth) * sizeof(**array));
    *array = ArrRightShift(*array, before, *rowWidth, insertedWidth);

    int i = 0;
    if (before >= *rowWidth)
    {
        before = *rowWidth;
    }
    for (i = 0; i < insertedWidth; i++)
    {
        *(*array + i + before) = *(*insertedArr + i);
    }

    *rowWidth += insertedWidth;
}

void IRB4FromArr(int*** matrix, byte2* rowCount, byte2** rowWidth, byte2 newRowWidth, byte2 offset, int** insertedArray)
{
    if (*matrix == NULL)
    {
        *matrix = malloc(((*rowCount) + 1) * sizeof(**matrix));
    }
    else
    {
        *matrix = realloc(*matrix, ((*rowCount) + 1) * sizeof(**matrix));
    }
    if (*rowWidth == NULL)
    {
        *rowWidth = malloc((*rowCount + 1) * sizeof(**rowWidth));
    }
    else
    {
        *rowWidth = realloc(*rowWidth, (*rowCount + 1) * sizeof(**rowWidth));
    }

    int* newRow = malloc(newRowWidth * sizeof(*newRow));
    int i = 0;
    for (i = 0; i < newRowWidth; i++)
    {
        *(newRow + i) = *(*insertedArray + i);
    }

    *matrix = MatrixDownShift(*matrix, offset, *rowCount, 1);
    *rowWidth = ArrDownShift(*rowWidth, offset, *rowCount, 1);
    *(*matrix + offset) = newRow;
    *(*rowWidth + offset) = newRowWidth;

    *rowCount = *rowCount + 1;
}

void freeAll(int*** matrix, byte2* const rowCount, byte2** rowWidth)
{
    if (*rowCount == 0)
    {
        return;
    }
    int i = 0;
    for (i = 0; i < *rowCount; i++)
    {
        free(*(*matrix + i));
    }
    free(*rowWidth);
    free(*matrix);
    *rowWidth = NULL;
    *matrix = NULL;
    *rowCount = 0;
}

void BlockInsert(int*** matrix, byte2* const rowCount, byte2** rowWidth, const byte2 rowOffset, const byte2 colOffset, const byte2 blockHeight, const byte2 blockWidth)
{
    int** insertedBlock = NULL;
    byte2* insertedBlockWidth = NULL;
    byte2 curBlockHeight = 0;

    int i = 0;
    for (i = 0; i < blockHeight; i++)
    {
        IRB4(&insertedBlock, &curBlockHeight, &insertedBlockWidth, blockWidth, curBlockHeight);
    }
    for (i = 0; i < blockHeight && i < *rowCount - rowOffset; i++)
    {
        ICB4(&*(*matrix + i + rowOffset), &*(*rowWidth + i + rowOffset), blockWidth, colOffset, &*(insertedBlock + i));
    }
    while (i < blockHeight)
    {
        IRB4FromArr(matrix, rowCount, rowWidth, blockWidth, *rowCount, &*(insertedBlock + i));
        i++;
    }
    freeAll(&insertedBlock, &curBlockHeight, &insertedBlockWidth);
}

void LineSkip(const byte2 skipCount)
{
    int dummy = 0;
    int i = 0;
    for (i = 0; i < skipCount; i++)
    {
        scanf("%d", &dummy);
    }
}

void RemoveRow(int*** matrix, byte2* const rowCount, byte2** rowWidth, const byte2 removedAt)
{
    if (removedAt >= *rowCount)
    {
        return;
    }
    free(*(*matrix + removedAt));
    *matrix = MatrixUpShift(*matrix, removedAt, *rowCount, 1);
    *rowWidth = ArrUpShift(*rowWidth, removedAt, *rowCount, 1);

    *matrix = realloc(*matrix, (*rowCount - 1) * sizeof(**matrix));
    *rowWidth = realloc(*rowWidth, (*rowCount - 1) * sizeof(**rowWidth));

    *rowCount = *rowCount - 1;
}
void removeblock(int*** matrix, byte2* const rowCount, byte2** colCount, const byte2 rowStart, const byte2 rowOffset, const byte2 columnStart, const byte2 colOffset)
{
    byte2 rowEnd = rowStart + rowOffset;
    if (rowEnd > *rowCount)
    {
        rowEnd = *rowCount;
    }
    int rowChanges = rowStart;
    int i = 0;
    for (i = rowStart; rowChanges < rowEnd; i++, rowChanges++)
    {
        byte2 curColCount = *(*colCount + i);
        if (columnStart >= curColCount)
        {
            continue;
        }
        int columnEnd = columnStart + colOffset;
        if (columnEnd > curColCount)
        {
            columnEnd = curColCount;
        }
        int removedColsCount = columnEnd - columnStart;
        if (curColCount <= removedColsCount)
        {
            RemoveRow(matrix, rowCount, colCount, i);
            i--;
            continue;
        }
        *(*matrix + i) = ArrLeftShift(*(*matrix + i), columnStart, curColCount, removedColsCount);
        *(*matrix + i) = realloc(*(*matrix + i), (curColCount - removedColsCount) * sizeof(**matrix));
        *(*colCount + i) = curColCount - removedColsCount;
    }
}

void removeColLast(int*** matrix, byte2* const rowCount, byte2** colCount)
{
    byte2 rowStart = 0;
    byte2 rowOffset = *rowCount;

    byte2 rowEnd = rowStart + rowOffset;
    if (rowEnd > *rowCount)
    {
        rowEnd = *rowCount;
    }
    int rowChanges = rowStart;
    int i = 0;
    for (i = rowStart; rowChanges < rowEnd; i++, rowChanges++)
    {
        byte2 curColCount = *(*colCount + i);

        if (curColCount <= 1)
        {
            RemoveRow(matrix, rowCount, colCount, i);
            i--;
            continue;
        }

        *(*matrix + i) = ArrLeftShift(*(*matrix + i), curColCount - 1, curColCount, 1);
        *(*matrix + i) = realloc(*(*matrix + i), (curColCount - 1) * sizeof(**matrix));
        *(*colCount + i) = curColCount - 1;
    }
}

void swapRows(int*** matrix, byte2* const rowCount, byte2** colCount, const byte2 rowA, const byte2 rowB)
{
    if (rowA >= *rowCount || rowB >= *rowCount)
    {
        return;
    }
    int* tmp = *(*matrix + rowA);
    *(*matrix + rowA) = *(*matrix + rowB);
    *(*matrix + rowB) = tmp;

    byte2 tmp1 = *(*colCount + rowA);
    *(*colCount + rowA) = *(*colCount + rowB);
    *(*colCount + rowB) = tmp1;
}
void swapCol(int*** matrix, byte2* const rowCount, byte2** colCount, const byte2 colA, const byte2 colB)
{
    int i = 0;
    for (i = 0; i < *rowCount; i++)
    {
        byte2 curColCount = *(*colCount + i);
        if (colA < curColCount && colB < curColCount)
        {
            int tmp = *(*(*matrix + i) + colA);
            *(*(*matrix + i) + colA) = *(*(*matrix + i) + colB);
            *(*(*matrix + i) + colB) = tmp;
        }
    }
}
int checkint(const int num)
{
    return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}
byte2 checkbyte2(const byte2 num)
{
    return (num >> 8) | (num << 8);
}

void FileWrite(int*** matrix, byte2* const rowCount, byte2** rowWidth, const char* fileName)
{
    FILE* destFile = fopen(fileName, "wb");
    fprintf(destFile, "%hu\n", *rowCount);
    int i = 0;
    for (i = 0; i < *rowCount; i++)
    {
        byte2 curRowWidth = checkbyte2(*(*rowWidth + i));
        fwrite(&curRowWidth, sizeof(byte2), 1, destFile);
        curRowWidth = *(*rowWidth + i);
        int j = 0;
        for (j = 0; j < curRowWidth; j++)
        {
            int curValue = checkint(*(*(*matrix + i) + j));
            fwrite(&curValue, sizeof(int), 1, destFile);
        }
    }
    fclose(destFile);
}

void FileRead(int*** matrix, byte2* const rowCount, byte2** colCount, const char* fileName)
{
    FILE* sourceFile = fopen(fileName, "rb");
    freeAll(matrix, rowCount, colCount);
    byte2 newRowCount = 0;
    fscanf(sourceFile, "%hu\n", &newRowCount);

    int i = 0;
    for (i = 0; i < newRowCount; i++)
    {
        byte2 curRowWidth = 0;

        fread(&curRowWidth, sizeof(byte2), 1, sourceFile);
        curRowWidth = checkbyte2(curRowWidth);
        int* newRow = malloc(curRowWidth * sizeof(*newRow));

        int j = 0;
        for (j = 0; j < curRowWidth; j++)
        {
            int curValue = 0;
            fread(&curValue, sizeof(int), 1, sourceFile);
            curValue = checkint(curValue);
            *(newRow + j) = curValue;
        }

        IRB4FromArr(matrix, rowCount, colCount, curRowWidth, *rowCount, &newRow);
        free(newRow);
    }
    fclose(sourceFile);
}



void printMatrix(int** const matrix, const byte2 rowCount, byte2* const rowWidth) {
    printf("%hu\n", rowCount);
    int i = 0;
    for (i = 0; i < rowCount; i++) {
        int rowLen = *(rowWidth + i);
        printf("%hu", rowLen);
        int j = 0;
        for (j = 0; j < rowLen; j++) {
            printf(" %d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    char* CommandStr = malloc(4 * sizeof(*CommandStr));

    int** matrix = NULL;	// Master array, contatins pointers to arrays of variable size
    byte2 rowCount = 0;		// length a.k.a number of rows
    byte2* colCount = NULL; // Array of row lengths a.k.a column count for each row

    Command Command = nothing;
    while (Command != END)
    {
        scanf("%s", CommandStr);
        *(CommandStr + 3) = '\0';
        Command = GetCommand(CommandStr);

        byte2 rowOStart = 0;
        byte2 colStart = 0;
        byte2 blockHeight = 0;
        byte2 blockWidth = 0;

        switch (Command)
        {
        case AFR:
        {
            scanf("%hu", &blockWidth);

            IRB4(&matrix, &rowCount, &colCount, blockWidth, 0);
            break;
        }
        case ALR:
        {
            scanf(" %hu", &blockWidth);

            IRB4(&matrix, &rowCount, &colCount, blockWidth, rowCount);
            break;
        }
        case AFC:
        {
            scanf(" %hu", &blockHeight);

            BlockInsert(&matrix, &rowCount, &colCount, 0, 0, blockHeight, 1);
            break;
        }
        case ALC:
        {
            scanf(" %hu", &blockHeight);

            BlockInsert(&matrix, &rowCount, &colCount, 0, 65535, blockHeight, 1);
            break;
        }
        case IBR:
        {
            scanf(" %hu %hu", &rowOStart, &blockWidth);
            if (rowOStart >= rowCount)
            {
                LineSkip(blockWidth);
                break;
            }

            IRB4(&matrix, &rowCount, &colCount, blockWidth, rowOStart);
            break;
        }
        case IAR:
        {
            scanf(" %hu %hu", &rowOStart, &blockWidth);
            if (rowOStart >= rowCount)
            {
                LineSkip(blockWidth);
                break;
            }

            IRB4(&matrix, &rowCount, &colCount, blockWidth, rowOStart + 1);
            break;
        }
        case IBC:
        {
            scanf(" %hu %hu", &colStart, &blockHeight);
            BlockInsert(&matrix, &rowCount, &colCount, 0, colStart, blockHeight, 1);
            break;
        }
        case IAC:
        {
            scanf(" %hu %hu", &colStart, &blockHeight);
            BlockInsert(&matrix, &rowCount, &colCount, 0, colStart + 1, blockHeight, 1);
            break;
        }
        case SWR:
        {
            byte2 rowA;
            byte2 rowB;

            scanf(" %hu %hu", &rowA, &rowB);
            swapRows(&matrix, &rowCount, &colCount, rowA, rowB);
            break;
        }
        case SWC:
        {
            byte2 colA;
            byte2 colB;

            scanf(" %hu %hu", &colA, &colB);
            swapCol(&matrix, &rowCount, &colCount, colA, colB);
            break;
        }
        case DFR:
        {
            RemoveRow(&matrix, &rowCount, &colCount, 0);

            break;
        }
        case DLR:
        {
            if (rowCount <= 0)
            {
                break;
            }
            RemoveRow(&matrix, &rowCount, &colCount, rowCount - 1);
            break;
        }
        case DFC:
        {
            removeblock(&matrix, &rowCount, &colCount, 0, rowCount, 0, 1);
            break;
        }
        case DLC:
        {
            removeColLast(&matrix, &rowCount, &colCount);
            break;
        }
        case RMR:
        {
            scanf(" %hu", &rowOStart);
            RemoveRow(&matrix, &rowCount, &colCount, rowOStart);
            break;
        }
        case RMC:
        {
            scanf(" %hu", &colStart);
            removeblock(&matrix, &rowCount, &colCount, 0, rowCount, colStart, 1);
            break;
        }
        case RMB:
        {
            scanf(" %hu %hu %hu %hu", &rowOStart, &blockHeight, &colStart, &blockWidth);

            removeblock(&matrix, &rowCount, &colCount, rowOStart, blockHeight, colStart, blockWidth);
            break;
        }
        case ISB:
        {
            scanf(" %hu %hu %hu %hu", &rowOStart, &colStart, &blockHeight, &blockWidth);

            BlockInsert(&matrix, &rowCount, &colCount, rowOStart, colStart, blockHeight, blockWidth);
            break;
        }
        case WRF:
        {
            char* fileName = malloc(16 * sizeof(*fileName));
            scanf(" %s", fileName);

            FileWrite(&matrix, &rowCount, &colCount, fileName);
            free(fileName);
            break;
        }
        case RDF:
        {
            char* fileName = malloc(16 * sizeof(*fileName));
            scanf(" %s", fileName);
            FileRead
            (&matrix, &rowCount, &colCount, fileName);

            free(fileName);
            break;
        }
        case PRT:
        {
            printMatrix(matrix, rowCount, colCount);
            break;
        }
        case END:
        {
            break;
        }
        case nothing:
            break;
        }
    }
    freeAll(&matrix, &rowCount, &colCount);
    free(CommandStr);
    return 0;
}