#include "Cliente.h"

using namespace std;

Cliente::Cliente() {
	this->limiteCredito = 0;
}

Cliente::Cliente(string nome, string endereco, int telefone, string dataNasc, int cpf, double limiteCredito, Pessoa contato)
	: Pessoa(nome, endereco, telefone, dataNasc, cpf)
{
	this->limiteCredito = limiteCredito;
	this->contato = contato;
	this->proxCliente = NULL;
}

//Gets
double Cliente::getLimiteCredito() {
	return limiteCredito;
}
Pessoa Cliente::getContato() {
	return contato;
}
Cliente* Cliente::getProxCliente() {
	return proxCliente;
}

//Sets
void Cliente::setLimiteCredito(double limiteCredito) {
	this->limiteCredito = limiteCredito;
}
void Cliente::setContato(Pessoa contato) {
	this->contato = contato;
}
void Cliente::setProxCliente(Cliente* proxCliente) {
	this->proxCliente=proxCliente;
}