#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <iostream>
#include <string>
#include "Pessoa.h"

class Vendedor : public Pessoa
{
private:

	int matricula;
	Vendedor* proxVendedor;

public:

	Vendedor();
	Vendedor(string nome, string endereco, int telefone, string dataNasc, int cpf, int matricula);

	//Get
	int getMatricula();
	Vendedor* getProxVendedor();

	//Set
	void setMatricula(int matricula);
	void setProxVendedor(Vendedor* proxVendedor);

};
#endif
