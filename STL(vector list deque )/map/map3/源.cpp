 #include <iostream>  
#include <iomanip>  
#include <vector>  
#include <map>  
#include <string>  
#include <algorithm>  
using namespace std;

typedef pair<string, double> PAIR;

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};

int main()
{
	//原来的map  
	map<string, int> name_score_map;
	
	name_score_map["LiMin"] = 90;
	name_score_map["ZiLinMi"] = 79;
	name_score_map["BoB"] = 92;
	name_score_map.insert(make_pair("Bing", 99));
	name_score_map.insert(make_pair("Albert", 86));

	//把map中元素转存到vector中     
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());

	//对vector排序  
	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());

	//排序前  
	map<string, int>::iterator iter_map;
	cout << "排序前:" << endl;
	for (iter_map = name_score_map.begin(); iter_map != name_score_map.end(); iter_map++)
		cout << left << setw(10) << iter_map->first << iter_map->second << endl;

	cout << "排序后:" << endl;
	for (int i = 0; i != name_score_vec.size(); ++i) {
		//可在此对按value排完序之后进行操作  
		cout << left << setw(10) << name_score_vec[i].first << name_score_vec[i].second << endl;
	}

	system("pause");
	return 0;
}