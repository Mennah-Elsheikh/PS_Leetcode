class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        string w1 = "", w2 = ""; 
        for(int i = 0 ; i < n ; i++)
        {
            w1 += word1[i];
        }
        for(int i = 0 ; i < m ; i++)
        {
            w2 += word2[i];
        }
        if ( w1.size() != w2.size()){return false ;}
        for(int i = 0 ; i < w1.size() ; i++)
        {
            if(w1[i] != w2[i])
            {
                return false ;
            }
        }
        return true ;
    }
};