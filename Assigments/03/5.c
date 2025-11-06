// worst O(n), average O(n), best O(n)
void sortColors(int* nums, int numsSize)
{
    int red = 0, white = 0, blue = 0;

    for(int i = 0 ; i < numsSize ; ++i)
    {
        if(nums[i] == 0)
        {
            red += 1;
        }
        else if(nums[i] == 1)
        {
            white += 1;
        }
        else
        {
            blue += 1;
        }
    }

    for(int i = 0 ; i < numsSize ; ++i)
    {
        if(red)
        {
            nums[i] = 0;
            red -= 1;
        }
        else if(white)
        {
            nums[i] = 1;
            white -= 1;
        }
        else
        {
            nums[i] = 2;
        }
    }
}