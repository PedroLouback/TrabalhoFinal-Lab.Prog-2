#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H
#include "Cliente.h";

using namespace std;

class ListaCliente
{
private:
	Cliente* cabeca;
	Cliente* cauda;

public:

	ListaCliente();

	ListaCliente(string nome, string endereco, int telefone, string dataNasc, int cpf, double limiteCredito, Pessoa contato);

	Cliente* getCabeca();
	void setCabeca(Cliente* cabeca);

	void mostrarTodos();

	bool vazia();

	void inserir_inicio(Cliente c);

	// insere no final (semelhante a push_back da list)
	void inserir_final(Cliente c);

	int size();

	bool existe(int cpf);

	int remover(int cpf);

};
#endif
