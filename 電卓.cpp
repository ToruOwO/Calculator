#include<iostream>
#include<cassert>
#include<cctype>
#include<cmath>
using namespace std;

size_t cur = 0;
string s;

//文字の数字への変換
int digit(){
	assert(isdigit(s[cur]));
	int n = s[cur] - '0';
	cur = cur + 1;
	return n;
}

//digit読み取りの繰り返し→digitの整数への変換
int number(){
	int n = digit();
	while(cur < s.length() && isdigit(s[cur])) n = n*10 + digit();
	return n;
}

int term(){
	int a = number();
	while(cur < s.length() && (s[cur] == '*' || s[cur] == '/')){
		char sign = s[cur++];
		int b = number();
		if(sign == '*') a *= b;
		else a /= b;
	}
	return a;
}

//足し算と引き算の実装
int expression(){
	int sum = term();
	while(s[cur] == '+' || s[cur] == '-'){
		char sign = s[cur];
		cur += 1;
		int b = term();
		if(sign == '+') sum += b;
		else sum -= b;
	}

	return sum;
}

int main(){
	cin >> s;
	int a = expression();
	cout << a << endl;
	return 0;
}