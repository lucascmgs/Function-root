#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double funcaoDesejada(double param, double numero){
    return exp(param) - numero ;
}

double zeroFunction(double inicio, double fim, double tolerancia, double numero){
    double meio = (fim - inicio) /2, estimativa;
    while(abs(fim - inicio) > tolerancia) {
        meio = (fim + inicio)/2;
        estimativa = funcaoDesejada(meio, numero);

        if(estimativa < 0) {
            inicio = meio;
        } else {
            fim = meio;
        }
    }
    return meio;

}



int main() {
    cout << "Insira o inicio, depois o fim do intervalo de teste, depois a potencia da tolerancia, depois o numero a se tirar o log " << endl;
    cout << "Exemplo: 0 100 -8 2" << endl;
    cout << "É importante saber que se o resultado nao estiver dentro do intervalo a resposta nao fica correta!" << endl;
    double inicio, fim, potencia, numero;
    cin >> inicio >> fim >> potencia >> numero;

    double aproximacao = zeroFunction(inicio, fim, pow(10, potencia), numero);

    cout << "Aproximação para o zero da função: " << setprecision(20) << aproximacao << endl;
    return 0;
}