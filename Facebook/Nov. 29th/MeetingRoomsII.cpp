/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> timeMap;
        for (int i = 0; i < intervals.size(); i++) {
            timeMap[intervals[i].start]++;
            timeMap[intervals[i].end]--;
        }
        
        int count = 0;
        int maxCount = 0;
        map<int, int>::iterator it;
        it = timeMap.begin();
        while (it != timeMap.end()) {
            count += (*it).second;
            maxCount = max(count, maxCount);
            it++;
        }
        
        return maxCount;
    }
};