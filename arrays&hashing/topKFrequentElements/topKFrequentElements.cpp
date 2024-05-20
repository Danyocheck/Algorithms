#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<pair<int, int> >  sort(map<int, int>& M) {
    vector<pair<int, int> > Ans;

    for (auto& i : M) {
        Ans.push_back(i);
    }

    sort(Ans.begin(), Ans.end(), compare);
    return Ans;
}

int
main()
{
    vector<int> nums = {1,1,1,2,2,3,4,4,4,4,4,4,5,5,5,5};
    int k = 2;
    map<int, int> unique_nums;
    vector<int> res;
    for (auto num: nums) {
        ++unique_nums[num];
    }

    vector<pair<int, int> > ans = sort(unique_nums);
    
    for (auto num: ans) {
        if (k == 0) break;
        res.push_back(num.first);
        cout << num.first << " ";
        --k;
    }

    cout << endl;
}