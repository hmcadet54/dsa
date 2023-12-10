// Question 01: [CLO 3 – 20 Points, 30 Min ]
// The luxuryCo. is a popular hotel among tourists going to Hunza. During this Fall, the hotel has
// experienced an unexpected influx of tourists and has decided to accommodate more people in a single
// room than usual. Given a 2d array arr[][] with each row representing a pair of the entry and exit times
// of guests at the LuxuryCo, find the maximum number of tourists that can be accommodated in the same
// room.
// Input: arr[][] = {{1120, 1159}, {1508, 1529}, {1508, 1527}, {1503, 1600}, {1458, 1629},
// {1224, 1313}}
// Output: 4
// Explanation: 2nd, 3rd, 4th and 5th guest can be accomodated in the same room..
#include <iostream>
#include <vector>
using namespace std;

pair<int,int>extract_largest(pair<int,int>array[],int size)
{
    int diff=array[0].second-array[0].first;
    pair<int,int>large;
    for(int i=0;i<size;i++)
    {
        int new_diff=array[i].second-array[i].first;
        if(new_diff>diff)
        {
            diff=new_diff;
            large=make_pair(array[i].first,array[i].second);
        }
    }
    // cout<<diff<<endl;
    return large;
}

vector<int> alloc(pair<int,int>array[],pair<int,int>large, int size)
{
    vector<int>answer;
    for (int i=0;i<size;i++)
    {
        if((array[i].first>=large.first&&array[i].first<=large.second)&&(array[i].second>=large.first&&array[i].second<=large.second))
        {
            answer.push_back(i+1);
        }
    }
    return answer;
}



int main()
{
    pair<int, int> array[6] = { {1120, 1159},
                                {1508, 1529},
                                {1508, 1527},
                                {1503, 1600},
                                {1458, 1629},
                                {1224, 1313} };
    pair<int,int>large=extract_largest(array,6);
    // cout<<large.first<<" "<<large.second;
    vector<int>answer=alloc(array,large,6);
    int size=answer.size();
    cout<<endl<<"following pairs can be accomodate in a single room: ";
    for (int i=0;i<size;i++)
    {
        cout<<answer[i]<<" ";
    }
}