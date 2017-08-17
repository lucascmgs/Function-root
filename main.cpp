#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


const double massa = 0.25, coeficiente = 0.1, s0 = 300, gravidade = 32.17, tolerancia = 0.00001;

double funcaoDesejada(double tempo){
    return (s0 - (massa*gravidade*tempo)/coeficiente +(pow(massa, 2)*gravidade*(1-exp(((-1)*coeficiente*tempo)/massa))/pow(coeficiente, 2)));
}

double zeroFunction(double inicio, double fim){
    double meio = (fim - inicio) /2, estimativa;
    while(abs(fim - inicio) > tolerancia) {
        meio = (fim + inicio)/2;
        estimativa = funcaoDesejada(meio);
        cout << meio << endl;
        if(estimativa < 0) {
            inicio = meio;
        } else {
            fim = meio;
        }
    }
    return meio;

}



int main() {
    cout << "Insira o inicio, depois o fim do intervalo de teste" << endl;
    cout << "Exemplo: 0 100" << endl;
    cout << "É importante saber que se o resultado nao estiver dentro do intervalo a resposta nao fica correta!" << endl;
    double inicio, fim;
    cin >> inicio >> fim;

    double aproximacao = zeroFunction(inicio, fim);

    cout << "Aproximação para o zero da função: " << setprecision(20) << aproximacao << endl;
    return 0;
}
