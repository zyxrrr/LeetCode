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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size() - 1; ){
            cout << "size: " << intervals.size() << endl;
            cout << "i: " << i << endl;
            Interval a = intervals[i];
            Interval b = intervals[i + 1];
            if(a.end >= b.start){
                if(a.end > b.end){
                    
                }else{
                    intervals[i].end = b.end;
                }
                intervals.erase(intervals.begin() + i + 1);
                continue;
            }
            i++;
        }
        return intervals;
    }
    
    static bool compare(Interval a, Interval b){
        if(a.start < b.start){
            return true;
        }else{
            return false;
        }
    }
};
