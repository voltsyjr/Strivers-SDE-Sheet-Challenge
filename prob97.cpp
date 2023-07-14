#define MOD 1000000007
long long modPower(long long a, long long b){
    if (b == 0)
        return 1;
    long long p = modPower(a, b / 2);
    if (b % 2 == 1)
        return p * p % MOD * a % MOD;
    return p * p % MOD;
}
vector<int> stringMatch(string text, string pattern)
{
    int n = text.size(), m = pattern.size();
    vector<int> ans;
    long long maxPow = modPower(26, m - 1);
    long long hashPattern = 0, hashText = 0;
    for (int i = 0; i < m; i++){
        hashPattern = hashPattern * 26 + pattern[i] - 'a';
        hashPattern %= MOD;
    }
    for (int i = 0; i < m - 1; i++){
        hashText = hashText * 26 + text[i] - 'a';
        hashText %= MOD;
    }
    for (int i = 0; i <= n - m; i++){
        hashText = hashText * 26 + text[i + m - 1] - 'a';
        hashText %= MOD;
        if (hashText == hashPattern){
            bool match = true;
            for (int j = 0; j < m; j++){
                if (text[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if (match){
                ans.push_back(i + 1);
            }
        }
        hashText = hashText - maxPow * (text[i] - 'a');
        hashText %= MOD;
        hashText = (hashText + MOD) % MOD;
    }
    return ans;
}