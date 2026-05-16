#include "Lista.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

Lista::Lista()
{
    this->quantidade = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

/**
 * @brief Destrutor da lista. Remove todos os nós alocados dinamicamente.
*/

Lista::~Lista() {
    auto aux = this->primeiro;

    while(aux != nullptr) {
        auto tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->quantidade = 0;
}

/**
 * @brief Insere um elemento no início da lista.
 * 
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
*/

bool Lista::inserirInicio(const std::string& elemento) {
    No* novoElemento = new No(elemento);

    if (this->quantidade == 0) this->ultimo = novoElemento;
    
    novoElemento->proximo = this->primeiro;
    this->primeiro = novoElemento;

    this->quantidade++;

    return true;
}

/**
 * @brief Insere um elemento no fim da lista.
 * 
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
*/

bool Lista::inserirFim(const std::string& elemento) {
    No* novoElemento = new No(elemento);

    if (this->quantidade == 0) this->primeiro = novoElemento;
    else this->ultimo->proximo = novoElemento;

    novoElemento->proximo = nullptr;
    this->ultimo = novoElemento;

    this->quantidade++;
    
    return true;
}

/**
 * @brief Insere um elemento na posição i da lista.
 * 
 * @param i Posição onde o elemento será inserido.
 * @param elemento Elemento a ser inserido.
 * @return true se a inserção for realizada com sucesso.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho+1.
*/

bool Lista::inserirNaPosicao(int i, const std::string& elemento) {
    if (i < 1 || i > this->quantidade + 1) throw std::out_of_range("Índice Inválido");
    if (i == 1) return Lista::inserirInicio(elemento);
    if (i == this->quantidade + 1) return Lista::inserirFim(elemento);
    
    No* novoElemento = new No(elemento);
    auto anterior = this->primeiro;

    for (int j = 1; j < i - 1; j++) {
        anterior = anterior->proximo;
    }

    novoElemento->proximo = anterior->proximo;
    anterior->proximo = novoElemento;

    this->quantidade++;

    return true;
}

/**
 * @brief Remove o elemento do início da lista.
 * 
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
*/

bool Lista::removerInicio() {
    if (this->quantidade == 0) throw std::underflow_error("Lista vazia");

    auto elemento = this->primeiro;

    if (this->quantidade == 1) {
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    } 
    else this->primeiro = elemento->proximo;

    delete elemento;

    this->quantidade--;

    return true;
}

/**
 * @brief Remove o elemento do fim da lista.
 * 
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
*/

bool Lista::removerFim() {
    if (this->quantidade == 0) throw std::underflow_error("Lista vazia");

    auto elemento = this->ultimo;

    if (this->quantidade == 1) {
        this->ultimo = nullptr;
        this->primeiro = nullptr;
    }
    else {
        auto anterior = this->primeiro;

        for (int i = 1; i < this->quantidade - 1; i++) {
            anterior = anterior->proximo;
        }

        anterior->proximo = nullptr;
        this->ultimo = anterior;
    }

    delete elemento;

    this->quantidade--;

    return true;
}

/**
 * @brief Remove o elemento da posição i da lista.
 * 
 * @param i Posição do elemento a ser removido.
 * @return true se o elemento for removido com sucesso.
 * * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
*/

bool Lista::removerNaPosicao(int i) {
    if (this->quantidade == 0) throw std::underflow_error("Lista vazia");
    if (i < 1 || i > this->quantidade) throw std::out_of_range("Índice Inválido");
    if (i == 1) return Lista::removerInicio();
    if (i == this->quantidade) return Lista::removerFim();
    
    auto anterior = this->primeiro;

    for (int j = 1; j < i - 1; j++) {
        anterior = anterior->proximo;
    }

    auto elemento = anterior->proximo;
    anterior->proximo = elemento->proximo;

    delete elemento;

    this->quantidade--;

    return true;
}

/**
 * @brief Retorna o primeiro elemento da lista.
 * 
 * @return Referência constante para a string armazenada no primeiro nó.
 * @throws std::out_of_range se a lista estiver vazia.
*/

const std::string& Lista::primeiroElemento() const {
    if (quantidade > 0) {
        return primeiro->valor;
    }
    else {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");
    }
}

/**
 * @brief Retorna o último elemento da lista.
 * 
 * @return Referência constante para a string armazenada no último nó.
 * @throws std::out_of_range se a lista estiver vazia.
*/

const std::string& Lista::ultimoElemento() const {
    if (quantidade > 0) {
        return ultimo->valor;
    }
    else {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");
    }
}

/**
 * @brief Retorna o elemento armazenado na posição i da lista.
 * 
 * @param i Índice do elemento a ser acessado.
 * @return Referência constante para a string armazenada na posição i.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
*/

const std::string& Lista::elementoNaPosicao(int i) const {
    if (this->quantidade == 0) throw std::underflow_error("Lista vazia");
    if (i < 1 || i > this->quantidade) throw std::out_of_range("Índice Inválido");
    if (i == 1) return Lista::primeiroElemento();
    if (i == this->quantidade) return Lista::ultimoElemento();

    auto elemento = this->primeiro;

    for (int j = 1; j < i; j++) {
        elemento = elemento->proximo;
    }
    
    return elemento->valor;
}

/**
 * @brief Retorna o número de elementos armazenados na lista.
 * 
 * @return Quantidade de elementos.
*/

unsigned long Lista::tamanho() const {
    return quantidade;
}

/**
 * @brief Imprime os elementos da lista no formato: { elem1, elem2, ... }
*/

std::string Lista::imprimir() const {
    std::ostringstream oss;
    oss << "{";
    No* atual = primeiro;
    while (atual != nullptr) {
        oss << atual->valor;
        if (atual->proximo != nullptr)
            oss << ", ";
        atual = atual->proximo;
    }
    oss << "}";
    return oss.str();
}

/**
 * @brief Remove todos os nós cujo valor é igual ao parâmetro.
 * 
 * @param valor Valor a ser removido da lista.
 * @return Quantidade de nós removidos.
*/

int Lista::removerTodos(const std::string& valor) {
    if (this->quantidade == 0) throw std::out_of_range("Lista vazia");
    if (this->quantidade == 1) {
        if (this->primeiro->valor == valor) {
            delete this->primeiro;

            this->primeiro = nullptr;
            this->ultimo = nullptr;
            this->quantidade--;

            return 1;
        }
        else return 0;
    }

    int nos_removidos = 0;
    auto atual = this->primeiro; // Nó no início da fila
    No* anterior = nullptr; // Nó antes do início, no vazio

    while (atual != nullptr) {
        if (atual->valor == valor) { // Se o valor do nó atual for igual ao valor que queremos resolver
            auto proximo = atual->proximo;

            if (anterior == nullptr) this->primeiro = proximo; // Caso o valor anterior seja nulo, o próximo elemento se torna o primeiro
            else anterior->proximo = proximo; 

            if (atual == this->ultimo) this->ultimo = anterior; // Caso o valor atual seja o último, seu anterior se torna o último

            delete atual;
            this->quantidade--;
            nos_removidos++;
            
            atual = proximo;
        }
        else {
            anterior = atual;
            atual = atual->proximo;
        } 
    }

    return nos_removidos;
}

Lista::No::No(std::string valor) {
    this->valor = valor;
    this->proximo = nullptr;
}

Lista::No::~No() {
}