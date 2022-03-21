#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <pair <pair<int, int>, pair <int, int> > > ver, hor;

    int number; cin >> number;


    for(int i = 1; i <= number; i++)
    {
        int x1, y1, x2, y2;
		
		cin >> x1 >> y1 >> x2 >> y2;
        
		if(x1 == x2)
		 ver.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2))); 
        if(y1 == y2)
		 hor.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    }


    vector <pair<int, int> > staircase;

    int verticalcount = 0, horizontalcount = 0, stairCount = 0;

    vector <pair <pair<int, int>, pair <int, int> > > :: iterator itera;

    for(int i = 0; i < hor.size(); i++)
    {
        for(int j = 0; j < ver.size(); j++)
        {
            if(hor[i].second.first == ver[j].first.first && hor[i].second.second == ver[j].first.second)
            {
                if(staircase.size() == 0) 
				staircase.push_back(hor[i].first); 
				
                staircase.push_back(ver[j].first);
                staircase.push_back(ver[j].second);
            }
            if(hor[i].first.first == ver[j].first.first && hor[i].first.second == ver[j].first.second)
            {
                staircase.push_back(ver[j].second);
                staircase.push_back(ver[j].first);
            }
        }
    }
    
    for(int i = 0; i < hor.size(); i++)
    {
        if(hor[i].first.first == staircase[staircase.size() - 1].first && hor[i].first.second == staircase[staircase.size() - 1].second)
        {
            staircase.push_back(hor[i].second);
            break;
        }
    }
    for(int i = 0; i < staircase.size(); i++) 
	
	cout << staircase[i].first << "\t" << staircase[i].second << endl;
    return 0;
}