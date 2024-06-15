struct T{
    int profit;
    int capital;
    T(int profit,int capital):profit(profit), capital(capital){}
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto compareCapital = [](const T& a,const T& b){return a.capital>b.capital;};
        auto compareProfit = [](const T& a,const T& b){return a.profit<b.profit;};
        priority_queue<T,vector<T>, decltype(compareCapital)> minHeap(compareCapital);
        priority_queue<T,vector<T>, decltype(compareProfit)> maxHeap(compareProfit);

        for(int i=0;i<capital.size();i++){
            minHeap.emplace(profits[i],capital[i]);
        }
        while(k--){
            while(!minHeap.empty() && minHeap.top().capital <= w)
                maxHeap.push(minHeap.top()),minHeap.pop();
            if(maxHeap.empty())
                break;
            w += maxHeap.top().profit, maxHeap.pop();
        }
        return w;
    }
};