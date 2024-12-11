class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        int consumed = numBottles;
        while (emptyBottles >= numExchange) {
            int extraBottles = emptyBottles / numExchange;
            int remainBottles = emptyBottles % numExchange;
            consumed += extraBottles;
            emptyBottles = remainBottles + extraBottles;
        }
        return consumed;
    }
};