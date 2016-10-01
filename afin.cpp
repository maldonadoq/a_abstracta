#include <NTL/ZZ.h>
#include <iostream>
#include <stdio.h>
#include "../func/func.cpp"

static string alfa = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
static ZZ t = ZZ(alfa.size());

using namespace std;

class afin{
private:
	//string alfa;
	ZZ b;
	FILE *t_pl;
	FILE *t_ci;
	FILE *t_dsci;
public:
	afin(ZZ);
	void cifrado(ZZ);
	void descifrado(ZZ);
	~afin(){	};
};

afin::afin(ZZ _b){
	t_pl =fopen("sws/texto_plano.txt", "r");
	t_ci = fopen("sws/texto_cifrado.txt", "w+");
	t_dsci = fopen("sws/texto_descifrado.txt", "w");

	b = _b;
}

void afin::cifrado(ZZ c_pu){
	char c;
	ZZ aux, aux1;
	int temp;
	while((c=getc(t_pl))!=EOF){
		aux1 = modulo(c_pu,t);
		aux =  modulo(modulo(alfa.find(c)*aux1, t)+b, t);
		conv(temp,aux);
		fprintf(t_ci, "%c", alfa[temp]);
	}
	fclose(t_ci);
}

void afin::descifrado(ZZ c_pr){
	char c;
	ZZ aux, aux1;
	int temp;
	while((c=getc(t_ci))!=EOF){
		aux1 = modulo(alfa.find(c)-b,t);
		aux =  modulo(aux1*c_pr, t);
		conv(temp,aux);
		fprintf(t_dsci, "%c", alfa[temp]);
	}
	fclose(t_dsci);
}

int main(int argc, char const *argv[]){

	ZZ c_pu, c_pr, cl = ZZ(15);
    cout << "clave_publica: "; cin >> c_pu;
    c_pr = euc_ext(c_pu,t);
    if(c_pr == -1) cout << "no_genera_clave_privada" << endl;
    else{
        cout << "clave_privada_generada_es: " << c_pr << endl;
        afin emisor(cl);
        afin receptor(cl);
        emisor.cifrado(c_pu);
        receptor.descifrado(c_pr);
        cout << "compilado" << endl;
    }
	return 0;
}
