/* Minimum Amount of Time to Collect Garbage
You are given a list of strings where each string represents a location, and the characters in the 
string represent types of garbage (e.g., "G" for glass, "P" for paper, and "M" for metal).You are also given a specific list indicating how 
long it takes to pick up each type of garbage (e.g., glass, paper, metal). You need to find out how much time it will take to collect all the garbage 
from all the locations, including the time taken to travel between locations. You must minimize the travel time while collecting the garbage.
In essence, the problem asks you to determine how much time is needed to pick up all the garbage while considering both the
garbage collection time and the time needed to travel across locations.
 Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21*/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int tsum = 0;
        for (int i = 0; i < travel.size(); i++) {
            tsum += travel[i];
        }
        
        return gargbage(garbage, tsum, travel);
    }

private:
    int gargbage(vector<string>& st, int tsum, vector<int>& travel) {
        int i = st.size() - 1, k = travel.size() - 1, totalsum = 0, p1 = 0, m1 = 0, g1 = 0;
        int tempsum = 0;

        while (i >= 0) {
            int j = 0;
            string temp = st[i];
            totalsum += temp.size();

            while (j < temp.size()) {
                if (p1 == 0 && temp[j] == 'P') {
                    p1 = 1;
                    tempsum += tsum;
                } else if (m1 == 0 && temp[j] == 'M') {
                    m1 = 1;
                    tempsum += tsum;
                } else if (g1 == 0 && temp[j] == 'G') {
                    g1 = 1;
                    tempsum += tsum;
                }
                j++;
            }
            i--;
            if (k >= 0) {
                tsum -= travel[k];
            } else {
                tsum = 0;
            }
            k--;
        }
        return totalsum + tempsum;
    }
};

