#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void criba(bool v[], long int t){
	long int tm = sqrt(t);
	v[0] = false;
	v[1] = false;
	for(long int i=2; i<=tm; i++){
		if(v[i]==true){
			long int aux = t/i;
			for(long int j=i; j<=aux; j++)	v[i*j] = false;
		}
	}
}

int main(int argc, char const *argv[]){
	long int t = 999999;
	bool v[t];
	for(long int i=0; i<t; i++)	v[i] = true;
	criba(v, t);
	long int con = 0;
	for(long int i=0; i<t; i++)
		if(v[i]==true){
			cout << i << endl;
			con++;
		}
	cout << endl << con << endl;
	return 0;
}