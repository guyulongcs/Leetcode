#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices);

int main() {
    vector<int> prices = new vector<int>(3,2,4);
    int profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}


int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i=1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i-1];
        if(diff > 0) {
            profit += diff;
        }
    }
    return profit;
}
