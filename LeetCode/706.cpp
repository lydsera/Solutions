#include<iostream>
#include<vector>

using namespace std;

//最简单的一种hash表
//取余作为索引
//位置被占用就按顺序找下一位
//感觉有个bug
//比如取余5时，插入(10,1)，插入到10%5=0的位置
//插入(15,11)，15%5=0被占了，++，插入到1处
//此时remove(10,1)，再插入(15,12)就会插到0处而不是更改1处
//这种情况下，查找还是没问题的，会优先找到更新后的值
//但是remove(15,2)后在查找15，应该找不到，但是能找到
class MyHashMap {
public:
    vector<vector<int>> hm;
    MyHashMap() {
        hm=vector<vector<int>>(10005,vector<int>{-1,-1});
    }
    
    void put(int key, int value) {
        int index=key%10000;
        for(int i=0;i<10000;i++)
        {
            if(hm[index][0]==-1)
            {
                hm[index][0]=key;
                hm[index][1]=value;
                break;
            }
            else if(hm[index][0]==key)
            {
                hm[index][1]=value;
                break;
            }
            index++;
            index%=10000;
        }
    }
    
    int get(int key) {
        int index=key%10000;
        for(int i=0;i<10000;i++)
        {
            if(hm[index][0]==key) return hm[index][1];
            index++;
            index%=10000;
        }
        return -1;
    }
    
    void remove(int key) {
        int index=key%10000;
        for(int i=0;i<10000;i++)
        {
            if(hm[index][0]==key)
            {
                hm[index][0]=-1;
                hm[index][1]=-1;
            }
            index++;
            index%=10000;
        }
    }
};

int main()
{
    MyHashMap myHashMap ;
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
    
}