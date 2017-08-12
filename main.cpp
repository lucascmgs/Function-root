#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double funcaoDesejada(double x){
    return exp(x) - 2 ;
}

double zeroFunction(double inicio, double fim, double tolerancia){
    double meio = (fim - inicio) /2, estimativa;
    while(abs(fim - inicio) > tolerancia) {
        meio = (fim + inicio)/2;
        estimativa = funcaoDesejada(meio);

        if(estimativa < 0) {
            inicio = meio;
        } else {
            fim = meio;
        }
    }
    return meio;

}



int main() {
    cout << "Insira o inicio, depois o fim do intervalo, e então a potencia da tolerancia " << endl;
    cout << "Ex: 0 1 -8" << endl;
    double inicio, fim, potencia;
    cin >> inicio >> fim >> potencia;

    double aproximacao = zeroFunction(inicio, fim, pow(10, potencia));

    cout << "Aproximação para o zero da função: " << setprecision(20) << aproximacao << endl;
    return 0;
}