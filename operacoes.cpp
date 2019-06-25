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

    std::cout << "\nConta Criada!!\n";
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

unsigned int Operacoes::detalharConta(){
    unsigned int numeroTemp = 0;   
    std::cout << "Informe o número da conta: ";
    std::cin >> numeroTemp;
    
    std::cout << "\n";
    
    std::fstream arq_Conta = visualizarConta(numeroTemp, 1);
    if(arq_Conta.fail()){
        std::cout << "Você buscou por uma conta inexistente.\n";
        return 0;
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

    return numeroTemp;
}

void Operacoes::alterarConta(){
    unsigned int numeroTemp = 0;   
    std::string nomeTemp;   
    double saldoTemp = 0.0;   
    std::cout << "Informe o número da conta: ";
    std::cin >> numeroTemp;
    
    std::cout << "\n";
    
    std::fstream arq_Conta = visualizarConta(numeroTemp, 1);
    if(arq_Conta.fail()){
        std::cout << "Você buscou por uma conta inexistente.\n";
        return;
    }
    arq_Conta.close();

    std::cout << "Informe o novo nome: ";
    std::cin >> nomeTemp;
    std::cout << "Informe o novo saldo: ";
    std::cin >> saldoTemp;

    std::string nomeArquivo = std::to_string(numeroTemp) + ".txt";
    std::remove(nomeArquivo.c_str());

    std::fstream arq_NovaConta(std::to_string(numeroTemp) + ".txt", std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    arq_NovaConta << numeroTemp << "\n";
    arq_NovaConta << nomeTemp << "\n";
    arq_NovaConta << saldoTemp << "\n";

    arq_NovaConta.close();

    std::cout << "\nConta Atualizada!!\n";
}

void Operacoes::excluirConta(){
    unsigned int numeroTemp = detalharConta();

    if(numeroTemp == 0){
        return;
    }

    char op = 'n';
    do{
        std::cout << "\nDeseja realmente excluir esta conta(S/N)? ";
        std::cin >> op;
    }while(op != 'N' && op != 'S');

    if(op == 'N'){
        std::cout << "\nRetornando ao menu principal...\n";
        return;
    }

    std::string nomeArquivo = std::to_string(numeroTemp) + ".txt";
    std::remove(nomeArquivo.c_str());

    unsigned int num = 0;
    contas.open("contas.txt", std::fstream::in);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }  

    std::fstream arq_Temp("temp.txt", std::fstream::out);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }  

    while(contas >> num){
        if(num != numeroTemp){
            arq_Temp << num << "\n";
        }
    }
    contas.close();
    arq_Temp.close();

    std::remove("contas.txt");
    std::rename ("temp.txt", "contas.txt");

    std::cout << "\nA conta foi excluída!!\n";
}

void Operacoes::tranferir(){
    unsigned int origem = 0;
    unsigned int destino = 0;
    std::fstream arq_origem;
    std::fstream arq_destino;

    do{
        std::cout << "Conta de origem: ";
        std::cin >> origem;

        arq_origem = visualizarConta(origem, 1);
        if(arq_origem.fail()){
            std::cout << "Você buscou por uma conta inexistente.\n";
        }
    }while(arq_origem.fail());

    std::cout << "\n";
    do{
        std::cout << "Conta de destino: ";
        std::cin >> destino;

        arq_destino = visualizarConta(destino, 1);
        if(arq_destino.fail()){
            std::cout << "Você buscou por uma conta inexistente.\n";
            continue;
        }

        if(origem == destino){
            std::cout << "A conta de destino não pode ser a mesma que a de origem.\n";
            continue;
        }
    }while(arq_destino.fail() || origem == destino);    

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