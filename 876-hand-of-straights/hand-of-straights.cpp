class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> cardCount;
        for(int card:hand)
            cardCount[card]++;
        sort(hand.begin(),hand.end());

        for(int card:hand){
            if(cardCount.count(card)){
                for(int i=card;i<card+groupSize;i++){
                    if(!cardCount.count(i))
                        return false;
                    if(--cardCount[i]==0)
                        cardCount.erase(i);
                }
            }
        }
        return true;
    }
};