// worst O(n log n), average O(n log n), best O(n log n)
struct Pair
{
    int val;
    int idx;
};

typedef struct Pair Pair;

void divide(Pair * arr, int l, int r)
{
    if(l >= r)
    {
        return;
    }

    int m = (l + r) / 2;
    divide(arr, l, m); divide(arr, m + 1, r);

    int left = m - l + 1;
    int right = r - m;

    Pair * lArr = malloc(left * sizeof(Pair));
    Pair * rArr = malloc(right * sizeof(Pair));

    for(int i = 0 ; i < left ; ++i)
    {
        lArr[i] = arr[i + l];
    }

    for(int i = 0 ; i < right ; ++i)
    {
        rArr[i] = arr[i + m + 1];
    }

    int lPtr = 0, rPtr = 0;
    for(int i = 0 ; i < left + right ; ++i)
    {
        if(lPtr == left)
        {
            arr[i + l] = rArr[rPtr++];
            continue;
        }

        if(rPtr == right)
        {
            arr[i + l] = lArr[lPtr++];
            continue;
        }

        if(lArr[lPtr].val < rArr[rPtr].val)
        {
            arr[i + l] = lArr[lPtr++];
        }
        else if(lArr[lPtr].val > rArr[rPtr].val)
        {
            arr[i + l] = rArr[rPtr++];
        }
        else
        {
            if(lArr[lPtr].idx > rArr[rPtr].idx)
            {
                arr[i + l] = lArr[lPtr++];
            }
            else
            {
                arr[i + l] = rArr[rPtr++];
            }
        }
    }

    free(lArr);
    free(rArr);
}

int * maxSubsequence(int * nums, int numsSize, int k, int * returnSize)
{
    Pair * a = malloc(numsSize * sizeof(Pair));
    for(int i = 0 ; i < numsSize ; ++i)
    {
        a[i].val = nums[i];
        a[i].idx = i;
    }

    divide(a, 0, numsSize - 1);

    int * used = malloc(numsSize * sizeof(int));
    for(int i = 0 ; i < numsSize ; ++i) used[i] = 0;

    for(int i = numsSize - 1, j = 0 ; j < k ; --i, ++j)
    {
        used[a[i].idx] = 1;
    }

    int * res = malloc(k * sizeof(int));
    for(int i = 0, j = 0 ; i < numsSize && j < k ; ++i)
    {
        if(used[i])
        {
            res[j++] = nums[i];
        }
    }

    *returnSize = k;

    free(a);
    free(used);
    return res;
}
