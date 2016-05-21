/* merges a vector of intervals and returns a set of disjoint intervals
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// 'first' is the left boundary and 'second' is the right boundary of the
// interval; this class overrides the comparison iterator
class Interval{
public:
	int first;
	int second;
	 
	// friend bool operator>(Interval& one, Interval& two);
	// friend bool operator<(Interval& one, Interval& two);
    // friend bool operator>=(Interval& one, Interval& two);
    // friend bool operator<=(Interval& one, Interval& two);
							      
    bool operator>(const Interval& other){
	    return (first>other.first);
    }
												      
    // constructor
    Interval(int firstNum, int secondNum): first(firstNum), second(secondNum){}
};

void printVector(vector<Interval>& myVector);
// functor to compare intervals
struct less_than_Interval{
	inline bool operator()(const Interval& one, const Interval& two){
	    return one.first<two.first;
	}
};

void mergeIntervals(vector<Interval>& intervals){
	// sort intervals by first element
	sort(intervals.begin(), intervals.end(),less_than_Interval());
						      
	// create vector for new intervals (after merging)
	vector<Interval> newIntervals;
	
	// loop through arrays
	for (vector<Interval>::iterator iter = intervals.begin();\
		iter != intervals.end(); iter++){
		// if there is no overlap, or if we have reached the end, push the
		// interval into our new vector
		if (iter + 1 == intervals.end() || iter->second < (iter+1)->first){
			newIntervals.push_back(*iter);
		}
		else{
			// otherwise merge this interval and the next interval
		    (iter+1)->first = iter->first;
		    if ((iter+1)->second < iter->second){
			    (iter+1)->second = iter->second;
			}
		}
	}
	
	// clear the original array
	intervals.clear();
	// copy the new array into the original array
	copy(newIntervals.begin(),newIntervals.end(),back_inserter(intervals));
	return;
}

// function to print vector
void printVector(vector<Interval>& myVector){
	for (auto iter = myVector.begin(); iter != myVector.end(); iter++){
		cout<<iter->first<< " "<<iter->second<<endl;
	}
}

int main(){
	vector<Interval> myVector;
	myVector.push_back(Interval(1,5));
	myVector.push_back(Interval(2,7));
	myVector.push_back(Interval(12,16));
	myVector.push_back(Interval(10,18));
	myVector.push_back(Interval(22,23));
	myVector.push_back(Interval(22,24));
	myVector.push_back(Interval(30,30));
	mergeIntervals(myVector);
	printVector(myVector);
	return 0;
}
