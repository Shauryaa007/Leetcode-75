// 649. Dota2 Senate
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int>r,d;

        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')r.push(i);
            if(senate[i]=='D')d.push(i);
        }

        while(d.size()>0&&r.size()>0)
        {
            int R_ind=r.front();
            int D_ind=d.front();

            r.pop();
            d.pop();

            if(R_ind<D_ind)
            {
                //disqualify D
                r.push(R_ind+n); // push R in the end i.e. ( ind + n);
            }
            if(D_ind<R_ind)
            {
                //disqualify R
                d.push(D_ind+n); // push D in the end i.e. ( ind + n);
            }
        }

        return d.size()>r.size()?"Dire":"Radiant";
    }
};