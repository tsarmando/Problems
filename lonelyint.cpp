#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> merge( vector <int> &b,  vector <int> &c){
		vector <int> temp;
		 int i = 0, j = 0; 
		while(i < b.size() && j < c.size())
		{
			if(b[i] < c[j])
			{
				temp.push_back(b[i]);
				i++;
			}	
			else
			{
			temp.push_back(c[j]);
			j++;
			}
		}
		
		while(i < b.size())
		{
		temp.push_back(b[i]);				
				i++;
		}
		while(j < c.size())
		{
		temp.push_back(c[j]);
				j++;
		}
	return temp;
}

vector<int> mergeSort(vector < int > & a)
{    
	if(a.size() == 1)
			return a;

	std::vector<int>::iterator middle = a.begin() + (a.size() / 2);
	vector <int> b(a.begin(), middle);
	vector <int> c(middle, a.end());
   b = mergeSort(b);
   c = mergeSort(c);        
	return merge(b,c);		
}


    
int lonelyinteger(vector < int > a) {
int n = a.size();
for(int i = 0; i< n; i++)
	if(i == 0)
		if(a[i] != a[i+1])
			return a[i];
	else if(a[i] == a[n-1])
		if(a[i] != a[i-1])
			return a[i];
	else
		if(a[i] != a[i-1] && a[i] != a[i+1])
			return a[i];
}
int main() {
   int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
	
    return 0;
}
