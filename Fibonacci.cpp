#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;
using namespace std::chrono;

const int INDICE = 25;

int FibonacciR(int indiceFib)
{ 
    //Casos-base da sequencia de fibonacci
    if (indiceFib == 0)
        return 0;

    else if (indiceFib == 1 || indiceFib == 2)
        return 1;

    //Chama recursivamente a função de acordo com a regra da sequencia até que um caso-base seja encontrado
    else
        return FibonacciR(indiceFib - 1) + FibonacciR(indiceFib - 2);
}

int FibonacciB(int indiceFib)
{
    //Inicia os três elementos conhecido
    int aux1 = 0, aux2 = 1, prox = 1;

    //Loop para calcular os elementos seguintes usando a regra da sequência de fibonacci
    for (int i = 0; i < indiceFib - 1; ++i)
    {
        prox = aux1 + aux2;
        aux1 = aux2;
        aux2 = prox;
    }
    return prox;
}

int main()
{
    //Marca o tempo antes e depois da execução e imprime o resultado da chamada no console
    auto inicioRecursivo = std::chrono::high_resolution_clock::now();
    cout << "Fatorial recursivo: " << FibonacciR(INDICE) << endl;
    auto finalRecursivo = std::chrono::high_resolution_clock::now();

    //Imprime o tempo de execução no console
    auto duration1 = duration_cast<microseconds>(finalRecursivo - inicioRecursivo);
    cout << "Tempo de execucao da forma recursiva: "
        << duration1.count() << " microsegundos" << endl << endl;

    //Marca o tempo antes e depois da execução e imprime o resultado da chamada no console
    auto inicioForcabruta = std::chrono::high_resolution_clock::now();
    cout << "Fatorial forca bruta: " << FibonacciB(INDICE) << endl;
    auto finalForcaBruta = std::chrono::high_resolution_clock::now();

    //Imprime o tempo de execução no console
    auto duration = duration_cast<microseconds>(finalForcaBruta - inicioForcabruta);
    cout << "Tempo de execucao da forma usando forca bruta: "
        << duration.count() << " microsegundos" << endl;
}
