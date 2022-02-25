#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:

	string nome;
	string endereco;
	int telefone;
	string dataNasc;
	int cpf;

public:

	Pessoa();
	Pessoa(string nome, string endereco, int telefone, string dataNasc, int cpf);

	//Gets
	string getNome();
	string getEndereco();
	int getTelefone();
	string getDataNasc();
	int getCpf();

	//Sets
	void setNome(string nome);
	void setEndereco(string endereco);
	void setTelefone(int telefone);
	void setDataNasc(string dataNasc);
	void setCpf(int cpf);

};
#endif

