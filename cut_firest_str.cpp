string cut_str;

string& CutFirstStr( string& s1,  string& s2)
{
	//无效输入
	if (s1.empty() || s1.size() == 0) return s1;

	
	vector<int> cut_pos(256, 0);
	//标记
	for (int i = 0; i<s2.size(); ++i)
		cut_pos[s2[i]]++;
	//导入
	for (int i = 0; i<s1.size(); ++i)
	{
		if (cut_pos[s1[i]] != 1)
			cut_str.push_back(s1[i]);
	}
	return cut_str;
}
