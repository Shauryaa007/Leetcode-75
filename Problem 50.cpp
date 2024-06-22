// 2336. Smallest Number in Infinite Set

class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int>>pq;
    unordered_set<int>mp;

    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int i=pq.top();
        pq.pop();
        mp.insert(i);
        return i;
    }
    
    void addBack(int num) {
        if(mp.count(num))
        {pq.push(num);
        mp.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */