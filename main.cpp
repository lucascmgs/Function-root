#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double funcaoDesejada(double param){
    return sin(param) ;
}

double zeroFunction(double inicio, double fim, double tolerancia){
    bool crescente = funcaoDesejada(inicio) < funcaoDesejada(fim) ? true : false;
    double meio = (fim - inicio) /2, estimativa;
    while(abs(fim - inicio) > tolerancia) {
        meio = (fim + inicio)/2;
        estimativa = funcaoDesejada(meio);
	
	cout << inicio << " " << fim << " " << meio << " " << estimativa << endl;

	if((crescente && estimativa < 0) || (!crescente && estimativa > 0)){
		inicio = meio;
	} else {
		fim = meio;
	}
    }
    return meio;

}



int main() {
    
    double inicio, fim, tolerancia;
    cin >> inicio >> fim >> tolerancia;

    double aproximacao = zeroFunction(inicio, fim, pow(10, -tolerancia));
    cout << "Aproximação do zero da função: " << setprecision(10) << aproximacao << endl; 
    return 0;
}
