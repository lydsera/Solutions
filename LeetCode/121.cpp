#include<iostream>
#include<vector>

using namespace std;

//原方法想从两头逼中心，记录从左边记起的最小值，和右边记起的最大值
//实际上有很多问题
//例如用while(i<j)不加等号时，用例[1,4,2]过不了
//加上等号后[3,2,6,5,0,3]过不了，因为i不能比j大
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int buy=prices.front();
//         int sell=prices.back();
//         int i=0;
//         int j=prices.size()-1;
//         while(i<=j)
//         {
//             if(prices[i]<buy) buy=prices[i];
//             if(prices[j]>sell) sell=prices[j];
//             i++;
//             j--;
//         }
//         int ans=sell-buy;
//         if(ans<=0) return 0;
//         return ans;
//     }
// };

//从第一天开始，记录至今的最小价格和最大利润
//最大利润的计算是由今日价格减去至今最小价格
//如果大于最大利润，它就是至今最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=10e4+5;
        int maxprofit=0;
        for(int price : prices)
        {
            if(price-minprice>maxprofit) maxprofit=price-minprice;
            if(price<minprice) minprice=price;
        }
        return maxprofit;
    }
};

int main()
{
    vector<int> prices = {7,6,4,3,1};
    Solution s;
    cout<<s.maxProfit(prices);
}