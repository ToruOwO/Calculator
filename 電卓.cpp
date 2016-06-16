#include<iostream>
#include<cassert> //assert
#include<cctype> //isdigit
#include<cmath> //powを使って"^"の機能を追加したい…
using namespace std;

size_t cur = 0;
string s;

//文字の数字への変換
int digit(){
	assert(isdigit(s[cur]));
	int n = s[cur] - '0';
	cur++;
	return n;
}

//digit読み取りの繰り返し→digitの数への変換
double number(){
	double n = digit();
	while(cur < s.length() && (isdigit(s[cur]) || s[cur] == '.')){
		if(isdigit(s[cur])) {
			n = n*10 + digit();
			cur++;
		}
		
		if (s[cur] == '.') {
			cur++;
			double m = 0.1;
			while(isdigit(s[cur])){
				n += digit()*m;
				m *= 0.1;
			}
		}
	} 
	return n;
}

double factor();

//掛け算と割り算の実装
//優先度は＋ーより高いので、先にtermとして計算しておきます
double term(){
	double a = factor(); //カッコがあれば、カッコの中身を先に計算する
	while(cur < s.length() && (s[cur] == '*' || s[cur] == '/')){
		char sign = s[cur++];
		double b = factor();
		if(sign == '*') a *= b;
		else a /= b;
	}
	return a;
}

double expression();

double factor(){
	if(s[cur] != '(') return number();
	cur++; double n = expression(); //カッコの中は必ずexpressionである
	assert(s[cur] == ')');
	cur += 1;
	return n;
}

//足し算と引き算の実装
double expression(){
	double sum = term(); //掛け算と割り算（もしあれば）のreturn値を使う
	while(s[cur] == '+' || s[cur] == '-'){
		char sign = s[cur];
		cur += 1;
		double b = term();
		if(sign == '+') sum += b;
		else sum -= b;
	}

	return sum;
}

int main(){
	cin >> s;
	double a = expression();
	cout << a << endl;
	return 0;
}