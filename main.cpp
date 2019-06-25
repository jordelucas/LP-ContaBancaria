#include <iostream>
#include <thread>

#include "operacoes.h"
#include "contaBancaria.h"

void cabecalho();

int main() {

    int op = 0;
    Operacoes operacoes;
    do {
        cabecalho();
        std::cout << "Escolha uma das operações a seguir:\n\n";
        std::cout << "1. Criar Conta\n";
        std::cout << "2. Listar Contas\n";
        std::cout << "3. Detalhes de uma Conta\n";
        std::cout << "4. Alterar Conta\n";
        std::cout << "5. Excluir Conta\n";
        std::cout << "6. Realizar Transferência\n";
        std::cout << "7. Realizar Depósito\n";
        std::cout << "8. Realizar Saque\n";
        std::cout << "9. Sair\n\n";

        std::cout << "Escolha: ";
        std::cin >> op;

        switch (op) {
        case 1:
            operacoes.criarConta();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 2:
            operacoes.listarContas();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 3:
            operacoes.detalharConta();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 4:
            operacoes.alterarConta();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 5:
            operacoes.excluirConta();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 6:
            operacoes.tranferir();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            break;
        case 7:
            operacoes.depositar();
            std::this_thread::sleep_for(std::chrono::seconds(5));        
            break;
        case 8:
            operacoes.sacar();
            std::this_thread::sleep_for(std::chrono::seconds(5));   
            break;
        case 9:
            break;
        
        default:
            break;
        }
    }while(op != 9);
    return 0;
}

void cabecalho() {
    system("clear");
    std::cout << "#######################################\n";
    std::cout << "#####                             #####\n";
    std::cout << "#####        SIMULADOR DE         #####\n";
    std::cout << "#####     OPERAÇÕES BANCÁRIAS     #####\n";
    std::cout << "#####                             #####\n";
    std::cout << "#######################################\n";
    std::cout << "                     Por: Jordevá Lucas\n\n\n";
}