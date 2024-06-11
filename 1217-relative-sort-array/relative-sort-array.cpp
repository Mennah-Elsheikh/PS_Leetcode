 class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
     {
        vector<int>freq(1001);
        vector<int>arr;
        for(int i = 0; i < arr1.size(); i++)
        {
            freq[arr1[i]]++;
        }
        for(int i = 0; i < arr2.size(); i++)
        {
            while(freq[arr2[i]]--)
            {
                arr.push_back(arr2[i]);
            }
        }
        sort(arr1.begin(),arr1.end());

        for(int i = 0; i < arr1.size(); i++)
        {
            if(freq[arr1[i]] > 0)
             arr.push_back(arr1[i]);
        }
        return arr;
    }
};