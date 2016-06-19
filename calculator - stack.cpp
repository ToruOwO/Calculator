//Calculator - stack
//inspiration from Question C
//http://icpc.iisf.or.jp/past-icpc/domestic2015/contest/all_ja.html#section_C

#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct operation
{
	char type;
	long long int priority;
};

vector<double> num;
vector<operation> op;

int main(){
	long long int i,j,k,len,count,prior,op_count,num_count,dot,max;
	double cnum, dadd;
	char str[5001];
	fgets(str, 5000, stdin);
	len = strlen(str);
	cnum = 0, op_count = 0, num_count = 0, prior = 0, dot = 0;
	num.resize(1000);
	op.resize(1000);
	for(i = 0; i < len; i++){
		//read in numbers as integer
		if(str[i] <= '9' && str[i] >= '0' && dot = 0){
			cnum *= 10;
			cnunm += str[i] - '0';
		}
		//run into dot
		else if(str[i] >= '(' && str[i] <= '/'){
			if(str[i] == '.'){
				dot++;
			}
		}
		//read in numbers as double
		else if(str[i] <= '9' && str[i] >= '0' && dot > 0){
			dadd = str[i] - '0';
			for(j = 0; j < dot; j++){
				dadd /= 10;
			}
			cnum += dadd;
			dot++;
		}
		else{ //assign priority to each operation
			if(str[i] >= '*'){
				num[num_count] = cnum;
				cnum = 0;
				def = 0;
				num_count++;
				op[op_count].type = str[i];
				op[op_count].priority = prior;
				if(str[i] == '*' || str[i] == '/'){
					op[op_count].priority++;
				}
				op_count++;
			}
			else if (str[i] == '('){
				prior += 2;
			}
			else if (str[i] == ')'){
				prior -= 2;
			}
		}

	}

	//read the priority queue and operate based on priority

	num[num_count] = cnum;
	num_count++;
	for(i = 0; i < op_count; i++){
		max = 0;
		for(j = 0; j < op_count; j++){
			if(op[j].priority > op[max].priority){
				max = j;
			}
		}
		switch(op[max].type){
			case '+': num[max] = num[max] + num[max+1]; break;
			case '-': num[max] = num[max] - num[max+1]; break;
			case '*': num[max] = num[max] * num[max+1]; break;
			case '/': num[max] = num[max] / num[max+1]; break;
		}
		num.erase(num.begin() + max + 1);
		op.erase(op.begin() + max);
	}
	cout << num[0] << endl;

}
