def groupAnagrams(strs):
    dict = {}
    for str in strs:
        sorted_str = ''.join(sorted(str))
        if sorted_str not in dict:
            dict[sorted_str] = [str]
        else:
            dict[sorted_str].append(str)
    
    ans = []
    for key in dict:
        ans.append(dict[key])
    
    return ans


print(groupAnagrams(["eat","tea","tan","ate","nat","bat"]))