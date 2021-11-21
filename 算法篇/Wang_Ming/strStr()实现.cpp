class Solution {
private:
    void getNext(vector<int>&next, const string&s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if (s[i] == s[j + 1]) j++;
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() < 1) return 0;
        if (needle.size() > haystack.size()) return -1;
        vector<int> next(needle.size(), -1);
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++){
            while (j >= 0 && haystack[i] != needle[j + 1]){
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) j++;
            if(j == needle.size() - 1) return i - needle.size() + 1;

        }
        return -1;
    }
};