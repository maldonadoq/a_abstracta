#include <iostream>
#include <stdio.h>
#include "func.cpp"

using namespace std;

class inverso{
public:
	//inverso();
	string cifrado(string t_pl){
		int t = t_pl.size();
		string t_ci="";
		for(int i=t;i>0;i--)
			t_ci+=t_pl[i-1];
		return t_ci;
	}
	string descifrado(string t_ci){
		return cifrado(t_ci);
	}
	~inverso(){		};
};

class simple{
public:
	string cifrado(string t_pl){
		string t_ci1="";
		string t_ci2="";
		for(int i=0;i<t_pl.size();i++){
			if(modulo(i,2) == 0)	t_ci1+=t_pl[i];
			else t_ci2+=t_pl[i];  
		}
		return t_ci1+t_ci2;
	}
	string descifrado(string t_ci){
		string t_desc = "";
		int t = t_ci.size()/2;
		int aux = t;
		int r = modulo(t_ci.size(),2);
		if(r!=0) t++; 
		for(int i=0;i<t;i++){
			if(i<aux and r!=0) t_desc = t_desc + t_ci[i] + t_ci[i+aux+1];
			else if(i<aux) t_desc = t_desc + t_ci[i] + t_ci[i+aux];
			else t_desc += t_ci[i];
		}
		return t_desc;
	}
};

int main(int argc, char const *argv[]){
	simple asd;
	cout << asd.cifrado("hola mundo como estas") << endl;
	cout << asd.descifrado("hl ud ooetsoamnocm sa") << endl;
	return 0;
}