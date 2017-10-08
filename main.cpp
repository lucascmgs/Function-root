#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


const double tolerancia = pow(10, -6);

double funcaoDesejada(double param){
    return  201.0625*(1 - exp(-0.4 * param)) -80.425 * param + 300;
}

double derivadaDesejada(double param){
    return 80.425 * (exp(-0.4*param) - 1);
}

double bissecao(double inicio, double fim){
    bool crescente = funcaoDesejada(inicio) < funcaoDesejada(fim) ? true : false;
    double meio = abs(fim - inicio) /2, estimativa;
    int iteracoes = 0;
    while(abs(fim - inicio) > tolerancia) {
	iteracoes++;
        meio = (fim + inicio)/2;
        estimativa = funcaoDesejada(meio);

	cout << inicio << " " << fim << " " << meio << " " << estimativa << endl;

	if(crescente){
		if(estimativa < 0){
			inicio = meio;
		} else {
				fim = meio;
		}
	} else{
		if(estimativa > 0){
			inicio = meio;
		} else {
			fim = meio;
		}
	}
    }
    cout << "Numero de iteracoes por bissecao: " << iteracoes << endl;

    return meio;

}

double newton(double inicio, double fim) {
    double x0;
    double x1 = (inicio + fim)/2;
    int iteracoes = 0;
    do {
	iteracoes++;
	cout << x0 << " " << x1 << endl;
	x0 = x1;
	x1 = x0 - funcaoDesejada(x0)/derivadaDesejada(x0);
    } while(abs(x1 - x0) > tolerancia);
    cout << "Numero de iteracoes por newton: " << iteracoes << endl;

    return x1;
}



int main() {

    double inicio = 6, fim = 7;
    cout << "Usando bissecao:" << endl;
    double bissec = bissecao(inicio, fim);
    cout << "Resultado: " << setprecision(8) <<bissec << endl;;
    cout << "Usando Newton:" << endl;
    double ponto_fixo = newton(inicio, fim);
    cout << "Resultado: " << setprecision(8) << ponto_fixo  << endl;
    int x = 0;
    cin >> x;
    return 0;
}
