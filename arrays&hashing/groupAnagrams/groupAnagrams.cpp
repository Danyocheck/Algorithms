#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> dict;
    for (auto &word: strs) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        dict[sorted_word].push_back(word);
    }

    for (auto &element: dict) {
        ans.push_back(element.second);
    }

    return ans;
}

int
main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto i: ans) {
        for (auto j: i) {
            std::cout << j << std::endl;
        }
        std::cout << std::endl;
    }
}