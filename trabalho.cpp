#include <iostream>
#include <string>
using namespace std;
//Função de separação das notas por valor
void contaNotas(int qtdNotas[4], int valNotas[4], int saque) {
qtdNotas[0] = (saque / valNotas[0]);
qtdNotas[1] = ((saque % valNotas[0]) / valNotas[1]);
qtdNotas[2] = (((saque % valNotas[0]) % valNotas[1]) / valNotas[2]);
qtdNotas[3] = ((((saque % valNotas[0]) % valNotas[1]) % valNotas[2]) /
valNotas[3]);
qtdNotas[4] = (((((saque % valNotas[0]) % valNotas[1]) % valNotas[2]) %
valNotas[3]) / valNotas[4]);
}
void cadastraNotas(int valNotas[4]) {
cout << "=================================\n";
cout << "Registro dos 4 valores de notas\n";
cout << "=================================\n";
for (int i = 0; i <= 4; i++){
cout << "Digite o valor da nota:" ;
cin >> valNotas[i];
}
cout << "=================================\n";
}
void simulaSaida(int qtdNotas[4], int valNotas[4]) {
string mensagem = "";
cout << "=================================\n";
for (int i = 0; i <= 4; i++){
mensagem = "Qtd. Notas de"  + to_string(valNotas[i]) + ":" ;
cout << mensagem + to_string(qtdNotas[i]) + "\n";
}
cout << "=================================\n";
}
//Fluxo principal do codigo
int main() {
//Declara variaveis
int saque = 0;

int exitSystem = 0;
//Declara ponteiros para arrays
int *qtdNotas = new int[4];
int *valNotas = new int[4];
//Inicializa notas
cadastraNotas(valNotas); //Cadastra valores de 5 notas diferentes
//Laço principal do simulador
while (exitSystem != 1){
//Le valor a ser sacado do Caixa Eletronico
cout << "\n=================================\n";
cout << "Digite o valor a ser sacado:" ;
cin >> saque;
if (saque == 9999){
exitSystem = 1;
cout << "=================================\n";
cout << "SISTEMA INTERROMPIDO - COD.9999\n";
cout << "=================================\n";
break;
}
//Executa funções para separar quantidade de notas por seu valor
contaNotas(qtdNotas, valNotas, saque); //Conta notas por valor
simulaSaida(qtdNotas, valNotas); //Simula saida de notas
}
//Limpa memoria
delete qtdNotas;
delete valNotas;
//Final do main
return 0;
}