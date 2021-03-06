// LeetCode.cpp: 定义应用程序的入口点。
//

#include "LeetCode.h"

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int begin = 0, end = 0;
		for (int i = 0; i < 2 * s.length(); ++i) {
			if (i % 2 == 0) {
				for (int j = i/2; j < s.length(); ++j) {
					if (i-j>=0&&s[j] == s[i - j]) {
						if (j - i + j >= end - begin) {
							begin = i - j;
							end = j;
						}
					}
					else break;
				}
			}
			else {
				for (int j = (i+1)/2; j < s.length(); ++j) {
					if (i - j >= 0 && s[j] == s[i - j]) {
						if (j - i + j >= end - begin) {
							begin = i - j;
							end = j;
						}
					}
					else break;
				}
			}
		}
		return s.substr(begin, end - begin + 1);
	}
	int numJewelsInStones(string J, string S) {
		int count = 0;
		for (auto c : S) {
			if (J.find_first_of(c) !=string::npos) count++;
		}
		return count;
	}
	string toLowerCase(string str) {
		string res;
		for (auto c : str) {
			if (c >= 'A'&&c <= 'Z')
				res.push_back(c - 'A' + 'a');
			else res.push_back(c);
		}
		return res;
	}
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> res;
		for (auto i : A) {
			if (i % 2 == 0) res.insert(res.begin(), i);
			else res.push_back(i);
		}
		return res;
	}
	int uniqueMorseRepresentations(vector<string> words) {
		vector<string> codemaps = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		set<string> res;
		for (auto w : words) {
			string code;
			for (auto c : w) {
				code.append(codemaps[(c - 'a')]);
			}
			res.insert(code);
		}
		return res.size();
	}
	int hammingDistance(int x, int y) {
		int res = x ^ y;
		bitset<32> b(res);
		return b.count();
	}
	int hammingWeight(uint32_t n) {
		bitset<32> res(n);
		return res.count();
	}
	bool judgeCircle(string moves) {
		string steps;
		char match;
		for (auto s : moves) {
			switch (s) {
			case 'U':
				match = 'D';
				break;
			case 'D':
				match = 'U';
				break;
			case 'L':
				match = 'R';
				break;
			case 'R':
				match = 'L';
				break;
			}
			size_t pos = steps.find_first_of(match);
			if (pos != string::npos) {
				steps.erase(pos,1);
			}
			else steps.push_back(s);
		}

		return steps.length() == 0;
	}
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		vector<vector<int>> res;
		for (auto i : A) {
			vector<int> e;
			for (vector<int>::reverse_iterator it = i.rbegin(); it != i.rend();++it) {
				if (*it == 1) {
					e.push_back(0);
				}
				else
					e.push_back(1);
			}
			res.push_back(e);
		}

		return res;
	}
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode *root;

	}
};

int main()
{
	Solution s;
	cout << s.judgeCircle("LLRRR") << endl;
	//s.sortArrayByParity({ 1,2,3,4 });
	system("pause");
	return 0;
}
