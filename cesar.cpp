#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "func.h"

using namespace std;

class cesar{
private:
	int clave, n;
	string alfa;
public:
	cesar(int);
	string cifrado(string);
	string descifrado(string);
	~cesar(){	}
};

cesar::cesar(int _clave){
	alfa = "abcdefghijklmnopqrstuvwxyz ";
	n = alfa.size();
	clave = modulo(_clave,n);
}

string cesar::cifrado(string t_plano){
	int aux;
	string t_ci = "";
	for(int i=0;i<t_plano.size();i++){
		aux = modulo(alfa.find(t_plano[i])+clave,n);
		t_ci = t_ci + alfa[aux];
	}
	return t_ci;
}

string cesar::descifrado(string t_ci){
	int aux;
	string t_dsci = "";
	for(int i=0;i<t_ci.size();i++){
		aux = modulo(alfa.find(t_ci[i])-clave,n);
		t_dsci = t_dsci + alfa[aux];
	}
	return t_dsci;
}

int main(int argc, char const *argv[]){
	int c;
	string t_plano = "", t_ci, t_dci;
	cout << "texto plano: "; getline(cin,t_plano);
	cout << "clave: "; cin >> c;	
	cesar emisor(c);
	cesar receptor(c);

	t_ci = emisor.cifrado(t_plano);
	t_dci = receptor.descifrado(t_ci);

	cout << t_ci << endl; 
	cout << t_dci << endl;
	return 0;
}