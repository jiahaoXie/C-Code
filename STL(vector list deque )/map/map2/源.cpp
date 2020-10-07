#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using std::map;


typedef pair<string, int> PAIR;

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second > rhs.second;
	}
};


int main() 
{
	map<string, int> name_score_map;
	name_score_map["LiMin"] = 90;
	name_score_map["ZiLinMi"] = 79;
	name_score_map["BoB"] = 92;
	name_score_map["Bing"]= 99;
	name_score_map["Albert"]= 86;
	//把map中元素转存到vector中   
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
	// sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);  
	for (int i = 0; i != name_score_vec.size(); ++i) {
		cout << name_score_vec[i].first<<": "<<name_score_vec[i].second << endl;
	}

	system("pause");
	return 0;
}