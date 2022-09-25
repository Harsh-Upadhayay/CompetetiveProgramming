class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> broken(brokenLetters.begin(), brokenLetters.end());
        
        int count = 0, flag = 1;
        for(char x : text) 
            if(x == ' ')
                count += flag,
                flag = 1;
            else
                flag &= !broken.count(x);
        
        
        return count + flag;
    }
};