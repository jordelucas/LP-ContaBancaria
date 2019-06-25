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

    do{
        std::cout << "Nº da conta: ";
        std::cin >> numero;
    }while(verificarContas(numero));
    
    std::cout << "Nome do(a) proprietário(a): ";
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

    std::fstream arq_NovaConta(std::to_string(conta.getNumero()) + ".txt", std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }
    arq_NovaConta << conta.getNumero() << "\n";
    arq_NovaConta << conta.getNome() << "\n";
    arq_NovaConta << conta.getSaldo() << "\n";
    arq_NovaConta.close();
}

void Operacoes::listarContas(){
    contas.open("contas.txt", std::fstream::in);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }    

    int numeroTemp = 0;
    std::cout << "\n";
    while(contas >> numeroTemp){
        std::cout << numeroTemp << "\n";
    }
    std::cout << "\n";
}

void Operacoes::detalharConta(){
    int numeroTemp = 0;   
    std::cout << "Informe o número da conta: ";
    std::cin >> numeroTemp;
    
    std::cout << "\n";
    
    std::fstream arq_Conta = visualizarConta(numeroTemp, 1);
    if(arq_Conta.fail()){
        std::cout << "Você buscou por uma conta inexistente.\n";
        return;
    }

    unsigned int numero = 0;
    std::string nome;
    double saldo = 0.0;

    arq_Conta >> numero;
    arq_Conta >> nome;
    arq_Conta >> saldo;

    std::cout << "Proprietário(a): " << nome << "\n";
    std::cout << "Nº da conta: " << numero << "\n";
    std::cout << "Saldo: " << saldo << "\n";
    arq_Conta.close();
}

void Operacoes::alterarConta(){
    int numeroTemp = 0;   
    std::cout << "Informe o número da conta: ";
    std::cin >> numeroTemp;
    
    std::cout << "\n";
    
    std::fstream arq_Conta = visualizarConta(numeroTemp, 1);
    if(arq_Conta.fail()){
        std::cout << "Você buscou por uma conta inexistente.\n";
        return;
    }


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
    contas.open("contas.txt", std::fstream::in);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
    }
    int numeroTemp = 0;
    while(contas >> numeroTemp){
        if(numero == numeroTemp){
            std::cout << "\nO número informado está indisponível!\nTente outro número.\n\n";
            contas.close();
            return true;
        }
    }
    contas.close();
    return false;
}

std::fstream Operacoes::visualizarConta(unsigned int numero, int op){
    std::fstream arq_Conta;
    if(op == 1){
        arq_Conta.open(std::to_string(numero) + ".txt", std::fstream::in);
    }

    if(op == 2){
        arq_Conta.open(std::to_string(numero) + ".txt", std::fstream::out);
    }

    return arq_Conta;
}