// worst O(n), average O(n), best O(n)
bool isAnagram(char * s, char * t)
{
    int cnt[26];

    for(int i = 0 ; i < 26 ; ++i)
    {
        cnt[i] = 0;
    }
    
    int n = 0, m = 0;

    while(s[n])
    {
        cnt[s[n] - 'a'] += 1;
        n += 1;
    }
    
    while(t[m])
    {
        cnt[t[m] - 'a'] -= 1;
        m += 1;
    }

    if(n != m)
    {
        return 0;
    }

    for(int i = 0 ; i < 26 ; ++i)
    {
        if(cnt[i] != 0)
        {
            return 0;
        }
    }
    
    return 1;
}
