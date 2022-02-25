#ifndef LISTAVENDEDOR_H
#define LISTAVENDEDOR_H
#include "Vendedor.h"

using namespace std;

class ListaVendedor
{
private:

	Vendedor* cabeca;
	Vendedor* cauda;

public:

	ListaVendedor();

	ListaVendedor(string nome, string endereco, int telefone, string dataNasc, int cpf, int matricula);

	Vendedor* getCabeca();
	void setCabeca(Vendedor* cabeca);

	void mostrarTodos();

	bool vazia();

	void inserir_inicio(Vendedor v);

	// insere no final (semelhante a push_back da list)
	void inserir_final(Vendedor v);

	int size();

	bool existe(int cpf);
	bool existeMatricula(int matricula);

	int remover(int cpf);
};
#endif
