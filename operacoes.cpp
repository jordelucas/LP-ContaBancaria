#include "operacoes.h"

Operacoes::Operacoes(){
    contas.open("contas.txt", std::fstream::app);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
    }
    contas.close();
}

void Operacoes::criarConta(){
    unsigned int numero;
    std::string nome;
    double saldo;

    std::cout << "Nº da conta: ";
    std::cin >> numero;
    std::cout << "Nome do proprietário: ";
    std::cin >> nome;
    std::cout << "Saldo inicial: ";
    std::cin >> saldo;

    ContaBancaria conta;
    conta.setNumero(numero);
    conta.setNome(nome);
    conta.setSaldo(saldo);

    contas.open("contas.txt", std::fstream::app);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    contas << conta.getNumero() << "\n";
    contas.close();

}

void Operacoes::listarContas(){

}

void Operacoes::detalharConta(){

}

void Operacoes::alterarConta(){

}

void Operacoes::excluirConta(){

}

void Operacoes::tranferir(){

}

void Operacoes::depositar(){

}

void Operacoes::sacar(){

}

bool Operacoes::verificarContas(unsigned int numero){
    return true;
}
