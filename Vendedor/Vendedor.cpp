#include "Vendedor.h"

using namespace std;

Vendedor::Vendedor() {
	this->matricula = 0;
}

Vendedor::Vendedor(string nome, string endereco, int telefone, string dataNasc, int cpf, int matricula) 
: Pessoa(nome, endereco, telefone, dataNasc, cpf)
{
	this->matricula = matricula;
	this->proxVendedor = NULL;
}

//Gets
int Vendedor::getMatricula() {
	return matricula;
}
Vendedor* Vendedor::getProxVendedor() {
	return proxVendedor;
}

//Sets
void Vendedor::setMatricula(int matricula) {
	this->matricula = matricula;
}
void Vendedor::setProxVendedor(Vendedor* proxVendedor) {
	this->proxVendedor = proxVendedor;
}