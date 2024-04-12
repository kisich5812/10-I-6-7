#include <iostream> 

using namespace std;

long long int shorstep(long long int n, int s) {
	int binary_s[100];
	int k = s;
	int i = -1;
	while(k>0) {
		i++;
		binary_s[i]=k%2;
		k=k/2;
	}
	long long int result = 1;
	int j = i;
	while(j>0) {
		if(binary_s[j] == 0) {
			result=result*result;
		} else {
			result=(result*n);
			result=result*result;
		}
		j--;
	}
	if(binary_s[0]==1) { 
		result=result*n;
	}
	return result;
}

int convert(string n) {
    int dec = 0;
    int s = 0;
    for (int u = n.length() - 1; u >= 0; u--) {
        int a = n[u] - '0';
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
	/*for(int i = 0; i<11; i++) 
		cout << i << " " << shorstep(2, i) << endl;*/
	return 0;
}
