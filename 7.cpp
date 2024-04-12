#include <iostream> 

using namespace std;

double shorstep(double n, int s) {
	int binary_s[100];
	int k = s;
	int i = -1;
	while(k>0) {
		i++;
		binary_s[i]=k%2;
		k=k/2;
	}
	double result = 1;
	int j = i;
	while(j>0) {
		if(binary_s[i] == 0) {
			result=result*result;
		} else {
			result=(result*n);
			result=result*result;
		}
		j--;
	}
	if(binary_s[0]==1) { 
		result=result*result;
	}
	return result;
}

int convert(string n) {
    int dec = 0;
    int s = 0;
    for (int i = n.length() - 1; i >= 0; i--) {
        int a = n[i] - '0';
        dec += a * shorstep(2, s);
        s++;
    }
    return dec;
}


int main() {
	string n;
	cin >> n;
	int dec = convert(n);
	cout << dec << endl;
	return 0;
}
