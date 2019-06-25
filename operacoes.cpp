#include "operacoes.h"
        
/**
 * Implementa método construtor, onde é criado o o arquivo que contém o número das contas bancárias
 */
Operacoes::Operacoes(){
    contas.open("contas.txt", std::fstream::app);
    if (contas.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
    }
    contas.close();
}

/**
 * Implementa função que cria uma nova conta bancária a partir dos dados fornecidos pelo usuário, 
sendo necessário cumprimento de decritérios, como o fornecer o número de uma conta disponível.
As informações são guardadas em arquivos.
 */
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

/**
 * Implementa função que lista a numeração das contas criadas. 
É feita a leitura do arquivo que guarda as numerações. 
 */

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


/**
 * Implementa função que detalha os dados da conta bancária após ser solicitado o número da conta.
É feita a leitura do arquivo que consta os dados da respectiva conta 
 * @return O número da conta que foi detalhada
 */  
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

/**
 * Implementa função que altera os dados cadastrados de uma conta bancária. 
É solicitado o número da conta desejada e são oferecidos para alteraçã os campos de Nome e Saldo.
Após fornecer os dados, o arquivo anterior é excluído e um novo é criado com o mesmo nome, mas com os novos dados.
 */
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

    std::fstream arq_NovaConta(nomeArquivo, std::fstream::out);
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

/**
 * Implementa função que exclui conta bancária. Para tal, é reutilizado o bloco de código que detalha uma conta.
Após ser exibida, é conferido se o usuário deseja prosseguir. Caso positivo, o respectivo arquivo com os dados da conta
é excluído e a numeração é removida da lista.
 */
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

/**
 * Implementa função que realiza transação entre contas bancárias, simulando uma transferência. 
É feira verificação se as contas de origem e destino existem e se o saldo da conta de origem é suficiente 
para o valor solicitado. Caso positivo, o valor é debitado do saldo da conta de origem e acrescentado na de destino. 
 */
void Operacoes::tranferir(){
    unsigned int origem = 0;
    unsigned int destino = 0;
    double valor = 0.0;
    ContaBancaria contaTemp;
    std::fstream arq_origem;
    std::fstream arq_destino;

    std::cout << "Conta de origem: ";
    std::cin >> origem;

    arq_origem = visualizarConta(origem, 1);
    if(arq_origem.fail()){
        std::cout << "A conta informada não existe.\n";
        return;
    }
    arq_origem.close();

    std::cout << "\n";
    std::cout << "Valor da transação: ";
    std::cin >> valor;

    ContaBancaria * c1 = &contaTemp;
    carrecarConta(c1, origem);

    if(c1->getSaldo() < valor){
        std::cout << "Saldo insuficente.\n";
        return;
    }

    std::cout << "\n";
    std::cout << "Conta de destino: ";
    std::cin >> destino;

    arq_destino = visualizarConta(destino, 1);
    if(arq_destino.fail()){
        std::cout << "A conta informada não existe.\n";
        return;
    }
    arq_destino.close();

    if(origem == destino){
        std::cout << "A conta de destino não pode ser a mesma que a de origem.\n";
        return;
    }  

    std::string nomeArquivo = std::to_string(origem) + ".txt";
    std::remove(nomeArquivo.c_str());

    std::fstream arq_NovaConta(nomeArquivo, std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    arq_NovaConta << c1->getNumero() << "\n";
    arq_NovaConta << c1->getNome() << "\n";
    arq_NovaConta << c1->getSaldo()-valor << "\n";

    arq_NovaConta.close();

    carrecarConta(c1, destino);

    nomeArquivo = std::to_string(destino) + ".txt";
    std::remove(nomeArquivo.c_str());

    arq_NovaConta.open(nomeArquivo, std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    arq_NovaConta << c1->getNumero() << "\n";
    arq_NovaConta << c1->getNome() << "\n";
    arq_NovaConta << c1->getSaldo()+valor << "\n";

    arq_NovaConta.close();

}


/**
 * Implementa função que realiza incremento no saldo de uma conta bancária, simulando um depósito. 
É solicitado o número da conta que será depositada e o valor. Os dados são alterados no respectivo arquivo. 
 */
void Operacoes::depositar(){
    unsigned int num_deposito = 0;
    double valor = 0.0;
    ContaBancaria contaTemp;
    std::fstream arq;

    std::cout << "Informe a conta para depósito: ";
    std::cin >> num_deposito;

    arq = visualizarConta(num_deposito, 1);
    if(arq.fail()){
        std::cout << "A conta informada não existe.\n";
        return;
    }
    arq.close();

    std::cout << "\n";
    std::cout << "Valor do depósito: ";
    std::cin >> valor;

    ContaBancaria * c1 = &contaTemp;
    carrecarConta(c1, num_deposito);

    std::string nomeArquivo = std::to_string(num_deposito) + ".txt";
    std::remove(nomeArquivo.c_str());

    std::fstream arq_NovaConta(nomeArquivo, std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    arq_NovaConta << c1->getNumero() << "\n";
    arq_NovaConta << c1->getNome() << "\n";
    arq_NovaConta << c1->getSaldo()+valor << "\n";

    arq_NovaConta.close();

    std::cout << "\nDeposito realizado!\n";
}


/**
 * Implementa função que decrementa o saldo de uma conta bancária, simulando um saque 
É solicitado o número da conta que será realizado o saque e o valor. Os dados são alterados no respectivo arquivo. 
 */
void Operacoes::sacar(){
    unsigned int num_saque = 0;
    double valor = 0.0;
    ContaBancaria contaTemp;
    std::fstream arq;

    std::cout << "Informe a conta para saque: ";
    std::cin >> num_saque;

    arq = visualizarConta(num_saque, 1);
    if(arq.fail()){
        std::cout << "A conta informada não existe.\n";
        return;
    }
    arq.close();

    std::cout << "\n";
    std::cout << "Valor do saque: ";
    std::cin >> valor;

    ContaBancaria * c1 = &contaTemp;
    carrecarConta(c1, num_saque);

    if(c1->getSaldo() < valor){
        std::cout << "Saldo insuficente.\n";
        return;
    }

    std::string nomeArquivo = std::to_string(num_saque) + ".txt";
    std::remove(nomeArquivo.c_str());

    std::fstream arq_NovaConta(nomeArquivo, std::fstream::out);
    if (arq_NovaConta.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return;
    }

    arq_NovaConta << c1->getNumero() << "\n";
    arq_NovaConta << c1->getNome() << "\n";
    arq_NovaConta << c1->getSaldo()-valor << "\n";

    arq_NovaConta.close();

    std::cout << "\nSaque realizado!\n";
}

/**
 * Declara função responsável por percorrer o arquivo de contas cadastradas, verificando se o valor passado está nele ou não
 * @param numero Nº da conta bancária para verificação
 * @return True se a conta existir ou False se a conta ainda não existir
 */  
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

/**
 * Declara função que retorna a conta solicitada
 * @param numero Nº da conta bancária para verificação
 * @param op Determina se o arquivo a serretornado será para escrita ou leitura
 * @return O arquivo que contém os dados da conta bancária solicitada
 */ 
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

/**
 * Declara função responsável por carregar informações a partir de um arquivo em uma instância de um objeto do tipo ContaBancaria
 *  @param conta Ponteiro referente ao objeto que receberá os valores
 *  @param numero Nº da conta bancária para verificação
 */  
void Operacoes::carrecarConta(ContaBancaria * conta, unsigned int numero){
    std::fstream arq = visualizarConta(numero, 1);

    unsigned int numeroTemp = 0;   
    std::string nomeTemp;   
    double saldoTemp = 0.0;   

    arq >> numeroTemp;
    arq >> nomeTemp;
    arq >> saldoTemp;

    conta->setNumero(numeroTemp);
    conta->setNome(nomeTemp);
    conta->setSaldo(saldoTemp);
}