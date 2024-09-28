class Solution {
public:
  
    int covertCharIntoIndex(char c)
    {
        return 1+(c-'a');
    }
    int firstUniqChar(string s) 
    {
       
        int prev[28], next[28],firstOccur[28];
        int current,head,tail;
        current=head=0;
        tail=27;
        prev[head]=-1;
        next[head]=tail;
        prev[tail]=head;
        next[tail]=-1;
        for(int i=0;i<s.length();i++)
        {
            int tmp=covertCharIntoIndex(s[i]);
            if(firstOccur[tmp]==0)firstOccur[tmp]=i;
            if(prev[tmp]==-2 && next[tmp]==-2)
                continue;
   
            if(prev[tmp]==0 and next[tmp]==0)
            {
                prev[tmp]=current;
                next[tmp]=next[current];
                next[current]=tmp;
               current=tmp;
            }
            else
            {
                if(current==tmp)
                    current=prev[tmp];
                int tmpNext=next[tmp];
                int tmpPrev=prev[tmp];
                prev[tmpNext]=tmpPrev;
                next[tmpPrev]=tmpNext;
                prev[tmp]=-2;
                next[tmp]=-2;
                cout<<next[head]<<endl;
            }
        }
        if(next[head]==27)
            return -1;

        return firstOccur[next[head]];
    }
};