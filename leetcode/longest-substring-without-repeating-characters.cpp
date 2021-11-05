#include <map>
#include <string>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int max(int a, int b)
    {
        if(a>b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int lengthOfLongestSubstring(string s) {
        int maxSize=0;
        int len = s.size();
        std::map<char, int> charIndexArray;
        int currentSize = 0;
        int firstIndex = 1;
        
        for(int i = 0 ; i < len; i++)
        {
            char charIndex = s[i];
            int index = i+1;
            auto it = charIndexArray.find(charIndex);
            if(it == charIndexArray.end() )
            {
                charIndexArray[charIndex] = index;
                currentSize++;
            }
            else
            {
                firstIndex = max(charIndexArray[charIndex], firstIndex);
                currentSize = index - firstIndex;
                charIndexArray[charIndex] = index;
                printf("%c, %d\n", charIndex, charIndexArray[charIndex]);
                
            }
            
            maxSize = max(maxSize, currentSize);
            printf(">> %c, %d\n", s[i], maxSize);
        }
        return maxSize;
    }
};
int main()
{
    Solution s;
    s.lengthOfLongestSubstring("abba");
    return 0;
}