class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0;    //innner pointers
     int w1=0,w2=0;  //outer pointers 
     while( w1<word1.size()  &&   w2<word2.size())
     {
         if(word1[w1][i]!=word2[w2][j])
         {
             return false;
         }
         if(i<word1[w1].length()-1)
         {
             i++;
         }
         else
         {
             i=0;
             w1++;
         }
         if(j<word2[w2].length()-1)
         {
             j++;
         }
         else
         {
             j=0;
             w2++;
         }        
     }
        return ( w1==word1.size()  &&   w2==word2.size());
    }
};