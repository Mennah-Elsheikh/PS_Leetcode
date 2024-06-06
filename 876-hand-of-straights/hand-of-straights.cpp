class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0 )
        {
            return false ; 
        }
        map<int, int> hand_map;
        for (int card : hand) {
            hand_map[card]++;
        }
        
         for (auto it = hand_map.begin(); it != hand_map.end(); ++it) {
            int current_card = it->first;
            int count = it->second;    
            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    int card_needed = current_card + i;
                    if (hand_map[card_needed] < count) {
                        return false;
                    }
                    hand_map[card_needed] -= count;
                }
            }
        }
        
        return true;
    }
};