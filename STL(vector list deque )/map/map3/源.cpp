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
	//ԭ����map  
	map<string, int> name_score_map;
	
	name_score_map["LiMin"] = 90;
	name_score_map["ZiLinMi"] = 79;
	name_score_map["BoB"] = 92;
	name_score_map.insert(make_pair("Bing", 99));
	name_score_map.insert(make_pair("Albert", 86));

	//��map��Ԫ��ת�浽vector��     
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());

	//��vector����  
	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());

	//����ǰ  
	map<string, int>::iterator iter_map;
	cout << "����ǰ:" << endl;
	for (iter_map = name_score_map.begin(); iter_map != name_score_map.end(); iter_map++)
		cout << left << setw(10) << iter_map->first << iter_map->second << endl;

	cout << "�����:" << endl;
	for (int i = 0; i != name_score_vec.size(); ++i) {
		//���ڴ˶԰�value������֮����в���  
		cout << left << setw(10) << name_score_vec[i].first << name_score_vec[i].second << endl;
	}

	system("pause");
	return 0;
}