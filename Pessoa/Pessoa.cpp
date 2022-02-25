#include "Pessoa.h"

Pessoa::Pessoa() {
    this->telefone = 0;
    this->cpf = 0;
}

Pessoa::Pessoa(string nome, string endereco, int telefone, string dataNasc, int cpf)
{
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataNasc = dataNasc;
    this->cpf = cpf;
}

string Pessoa::getNome()
{
    return this->nome;
}
string Pessoa::getEndereco()
{
    return this->endereco;
}
int Pessoa::getTelefone() {
    return this->telefone;
}
string Pessoa::getDataNasc() {
    return this->dataNasc;
}
int Pessoa::getCpf() {
    return this->cpf;
}

//Sets
void Pessoa::setNome(string nome)
{
    this->nome = nome;
}
void Pessoa::setEndereco(string endereco)
{
    this->endereco = endereco;
}
void Pessoa::setTelefone(int telefone) {
    this->telefone = telefone;
}
void Pessoa::setDataNasc(string dataNasc) {
    this->dataNasc = dataNasc;
}
void Pessoa::setCpf(int cpf) {
    this->cpf = cpf;
}
