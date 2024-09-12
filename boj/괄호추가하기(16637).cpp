#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long maximum = -3e9;

bool isNum(char c) {
	if ( c < 48 || c > 57 )
		return false;
	return true;
}

vector<char> in_to_post(vector<char> infix) {
	vector<char> result;
	stack<char> oper;
	for ( char c : infix ) {
		if ( isNum(c) ) {
			result.push_back(c);
		} else if ( c == '(' ) {
			oper.push('(');
		} else if ( c == ')' ) {
			while ( oper.top() != '(' ) {
				result.push_back(oper.top());
				oper.pop();
			}
			oper.pop();
		} else {
			if ( !oper.empty() && oper.top() != '(' ) {
				result.push_back(oper.top());
				oper.pop();
			}
			oper.push(c);
		}
	}
	while ( !oper.empty() ) {
		result.push_back(oper.top());
		oper.pop();
	}
	return result;
}

long long calc(vector<char> post_expr) {
	stack<long long> num;
	for ( char c : post_expr ) {
		if ( isNum(c) )
			num.push(c - 48);
		else {
			long long operand2 = num.top();	num.pop();
			long long operand1 = num.top();	num.pop();
			if ( c == '+' )
				num.push(operand1 + operand2);
			else if ( c == '-' )
				num.push(operand1 - operand2);
			else
				num.push(operand1 * operand2);
		}
	}
	return num.top();
}

void makepair(int idx, int count, vector<char> expr, vector<char> record) {
	if ( count % 2 == 0 ) {
		vector<char> infix;
		for ( int i = 0; i < expr.size(); i++ ) {
			if ( record[i] == '(' )
				infix.push_back(record[i]);
			infix.push_back(expr[i]);
			if ( record[i] == ')' )
				infix.push_back(record[i]);
		}
		
		vector<char> postfix = in_to_post(infix);
		maximum = max(maximum, calc(postfix));
	}
	for ( int i = idx+2; i < expr.size(); i+=2 ) {
		if ( count % 2 == 0 ) {
			record[i] = '(';
			makepair(i, count+1, expr, record);
			record[i] = ' ';
		} else {
			if ( record[i-2] == '(' ) {
				record[i] = ')';
				makepair(i, count+1, expr, record);
				record[i] = ' ';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	cin.get();
	
	vector<char> expr;
	for ( int i = 0; i < N; i++ )
		expr.push_back(cin.get());
	vector<char> record(N, ' ');
	
	makepair(-2, 0, expr, record);
	
	cout << maximum;
}
