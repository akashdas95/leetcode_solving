class Solution {
public:
    double HoursToTake(vector<int>& piles, int hourlyRate) {
        double totalHour = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHour += (piles[i] /hourlyRate) + ((piles[i] % hourlyRate)!=0);
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            mx = max(mx, piles[i]);
        }
        int l = 1, r = mx;
        while (l <= r) {
            int mid = (l + r) / 2;
            double hoursToTake = HoursToTake(piles, mid);
            if (hoursToTake <= h) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};