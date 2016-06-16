#include<iostream>
#include<cassert>
#include<cctype>
#include<cmath>
using namespace std;

size_t cur = 0;

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

//足し算と引き算の実装
int expression(){
	int a = number();
	char op = s[cur];
	cur += 1;
	int b = number();
	assert(op == '+');
	return a + b;
}

int main(){
	string s;
	cin << string;
	int a = expression();
	cout << a << endl;
}