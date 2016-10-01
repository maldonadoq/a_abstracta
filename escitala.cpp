#include <iostream>
#include <stdio.h>
#include <string>
#include "func.cpp"

using namespace std;

class escitala{
private:
	int clave;
public:
	escitala(int );
	string cifrado(string);
	string descifrado(string);
	~escitala(){	};
};

escitala::escitala(int _clave){
	clave =_clave;
}

string escitala::cifrado(string t_pl){
	string t_ci ="";
	int t=t_pl.size();
	
	int h = t/clave;
	int mod = modulo(t,clave);
	if(mod>0) h++;
	int aux;
	for(int i=0;i<clave;i++){
		for(int j=0;j<h;j++){
			aux = i+(clave*j);
			if(aux >= t) t_ci = t_ci + "*"; 
			else t_ci = t_ci + t_pl[aux]; 
		}
	}
	return t_ci;
}

string escitala::descifrado(string t_ci){
	string t_desc="";
	int r = t_ci.size()/clave;
	for(int i=0;i<r;i++){
		for(int j=0;j<clave;j++){
			if(t_ci[i+(j*r)]=='*') ;
			else	t_desc = t_desc + t_ci[i+(j*r)];
		}
	}
	return t_desc;
}


int main(int argc, char const *argv[]){
	int clave;
	char ad;
	string t_pl="", t_ci, t_dsci;
	cout << "texto plano: "; geteline(cin,t _pl);
	cout << "numero de columnas: "; cin >> clave;

	escitala emisor(clave);
	escitala receptor(clave);

	t_ci =emisor.cifrado(t_pl);
	t_dsci = receptor.descifrado(t_ci);

	cout << t_ci << endl;
	cout << t_dsci << endl;
	return 0;
}