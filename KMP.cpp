#include<iostream>
#include<vector>
using namespace std;


vector<int> preprocessing(string str){

		std::vector<int> lps(str.length(), 0);
		int j=0;
		lps[0] = 0;
		for (int i = 1; i < str.length(); )
		{
			if( str[i] == str[j] ){
				lps[i] = j+1;
				i++;
				j++;
			}
			else{

				if( j != 0 ){
					j = lps[j-1];
				}
				else{
					lps[i]=0;
					i++;
				}
			}
		}
		return lps;
}
bool KMP(string str, string pattern , vector<int> lps){

	int n = str.length();
	int m = pattern.length();
	int i=0,j=0;
	while(i<n && j<m){

		if(str[i]==pattern[j]){
			i++;
			j++;
		}
		else
		{
			if(j!=0){
				j=lps[j-1];
				
			}
			else{
				i++;
			}
		}

	}
	if(j==m && i==n) return true;
	return false;

}

int main(){

		string str = "abcxabcdabcdabcy";
        string subString = "abcdabcy";

		vector<int> lps = preprocessing(subString);

		cout<<KMP(str,subString,lps);

}
