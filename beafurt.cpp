#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class beafurt{
private:
	string clave, alfa;
	int n, t_c;
public:
	beafurt(string);
	string cifrado(string);
	string descifrado(string);
	~beafurt(){		};
};

beafurt::beafurt(string _clave){
	clave = _clave;
	alfa = "abcdefghijklmnopqrstuvwxyz ";
	n = alfa.size();
	t_c = clave.size();
}

string beafurt::cifrado(string t_pl){
	int aux;
	string t_ci = "";
	for(int i=0,b=0;i<t_pl.size();i++,b++){
		if(b==t_c) b=0; //para usar solo la clave
		aux = alfa.find(clave[b]) - alfa.find(t_pl[i]); // clave - t_pl
		if(aux<0) aux += n; // negativo
		t_ci = t_ci + alfa[aux];
	}	
	return t_ci;
}

string beafurt::descifrado(string t_ci){
	return cifrado(t_ci);
}

int main(int argc, char const *argv[]){
	string clave, t_pl, t_ci, t_dsci;
	cout << "clave  :"; getline(cin,clave);
	cout << "texto_plano:  "; getline(cin,t_pl);
	beafurt emisor(clave);
	beafurt receptor(clave);

	t_ci = emisor.cifrado(t_pl);
	t_dsci = receptor.descifrado(t_ci);

	cout << t_ci << endl;
	cout << t_dsci << endl;
	return 0;
}