// Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.

// This question is very similar to version numbers on leetcode: https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i1 = 0, i2 = 0;
        while(i1<n1 && i2<n2) {
            int num1 = 0;
            int num2 = 0;
            while(i1<n1 && v1[i1]!='.') {
                num1 = num1*10 + (v1[i1]-'0');
                i1++;
            }
            while(i2<n2 && v2[i2]!='.') {
                num2 = num2*10 + (v2[i2]-'0');
                i2++;
            }
            if(num1>num2) return 1;
            if(num2>num1) return -1;
            i1++;
            i2++;
        }
        if(i1<n1) {
            while(i1<n1) {
                if(v1[i1]!='0' && v1[i1]!='.') {
                    return 1;
                }
                i1++;
            }
        }
        if(i2<n2) {
            while(i2<n2) {
                if(v2[i2]!='0' && v2[i2]!='.') {
                    return -1;
                }
                i2++;
            }
        }
        return 0;
    }
};