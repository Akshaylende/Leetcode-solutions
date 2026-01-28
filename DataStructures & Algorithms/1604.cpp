/*
## 1604. Alert using same key-card Three or more times in a one hour period ##


# Problem Link - 
https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/

# Problem Statement -
LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.

# Query/ Code - 
*/

// TC - O((keys) * N log(N))
// SC - (N)

class Solution {
public:
    bool check_for_warning(vector<int>& timeStamp, string name){
        sort(timeStamp.begin(), timeStamp.end());
        int i = 0, j = 0;
        while(j < timeStamp.size()){
            while(j < timeStamp.size() && timeStamp[j] - timeStamp[i] <= 60) ++j;
            if(j - i > 2) return true;
            i++;
            j++;
        }
        return false;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> warning;
        unordered_map<string, vector<int>> record;
        for(int i=0; i<keyName.size(); i++)
            record[keyName[i]].push_back(stoi(keyTime[i].substr(0,2))*60 + stoi(keyTime[i].substr(3)));
        for(auto [x, y] : record)
            if(check_for_warning(y, x)) warning.push_back(x); 
        sort(warning.begin(), warning.end());
        return warning;
    }   
};

/*
# Explanation - 
1. using a map and vector to store names and timestamps in minutes by coverting it using slicing substrings. 
2. sorting the timestamps and checking the usage in last hour.
3. if it exceeds 3 or more times then listing out the name.
4. At last, sorting out all the names before returning. 
*/