#include <iostream>
#include "src/kkApplication.h"

static int g_indexBitsUsed;
static int MAX_TOUCHES = 15;

int getUnUsedIndex()
{
    int i;
    int temp = g_indexBitsUsed;

    for (i = 0; i < MAX_TOUCHES; i++)
    {
        if (!(temp & 0x00000001))
        {
            g_indexBitsUsed |= (1 << i);
            return i;
        }

        temp >>= 1;
    }

    // all bits are used
    return -1;
}

int removeUsedIndex(int index)
{
    if (index < 0 || index >= MAX_TOUCHES)
    {
        return  -1;
    }

    int temp = 1 << index;
    temp = ~temp;

    g_indexBitsUsed &= temp;

    // all bits are used
    return index;
}

USING_NS_KK;

int main(int, char **)
{
    int index0 = getUnUsedIndex();
    int index1 = getUnUsedIndex();
    int index2 = getUnUsedIndex();
    printf("UnUsedIndex %d \n", index2);
    removeUsedIndex(index0);
    int index4 = getUnUsedIndex();
    removeUsedIndex(index2);
    int index5 = getUnUsedIndex();

    kkgraphic::kkApplication application;
    application.init();
}
