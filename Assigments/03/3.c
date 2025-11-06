// worst O(n log n), average O(n log n), best O(n log n)
void divide(int * arr, int l, int r)
{
    if(l >= r)
    {
        return;
    }

    int m = (l + r) / 2;
    divide(arr, l, m); divide(arr, m + 1, r);

    int lSize = m - l + 1;
    int rSize = r - m;

    int * lArr = malloc(lSize * sizeof(int));
    int * rArr = malloc(rSize * sizeof(int));

    for(int i = 0 ; i < lSize ; ++i)
    {
        lArr[i] = arr[l + i];
    }

    for(int i = 0 ; i < rSize ; ++i)
    {
        rArr[i] = arr[m + 1 + i];
    }

    int lPtr = 0, rPtr = 0;
    for(int i = 0 ; i < lSize + rSize ; ++i)
    {
        if(lPtr == lSize)
        {
            arr[l + i] = rArr[rPtr++];
            continue;
        }

        if(rPtr == rSize)
        {
            arr[l + i] = lArr[lPtr++];
            continue;
        }

        if(lArr[lPtr] < rArr[rPtr])
        {
            arr[l + i] = lArr[lPtr++];
        }
        else
        {
            arr[l + i] = rArr[rPtr++];
        }
    }

    free(lArr);
    free(rArr);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    divide(g, 0, gSize - 1);
    divide(s, 0, sSize - 1);

    int i = 0, j = 0, ans = 0;
    while(i < gSize && j < sSize)
    {
        if(s[j] >= g[i])
        {
            i += 1;
            j += 1;
            ans += 1;
        }
        else
        {
            j += 1;
        }
    }    

    return ans;
}