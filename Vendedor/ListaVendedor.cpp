#include <iostream>
#include "ListaVendedor.h"
#include <Windows.h>

using namespace std;

ListaVendedor::ListaVendedor()
{
	// se não passar elemento, então cabeca e cauda são NULL
	cabeca = NULL;
	cauda = NULL;
}

Vendedor* ListaVendedor::getCabeca() {
	return this->cabeca;
}
void ListaVendedor::setCabeca(Vendedor* cabeca) {
	this->cabeca = cabeca;
}

ListaVendedor::ListaVendedor(string nome, string endereco, int telefone, string dataNasc, int cpf, int matricula)
{
	// se passar elemento, então cria novo No
	cabeca = new Vendedor(nome, endereco, telefone, dataNasc, cpf, matricula);
	cauda = cabeca;
}

// mostra todos os elementos da lista
void ListaVendedor::mostrarTodos()
{
	SetConsoleOutputCP(65001);
	int i = 0;
	
	Vendedor* c = cabeca;

	if (vazia())
		cout << "\nERRO: A lista não possui vendedores!\n";
	else

	{
		cout << "\n|| Impressão de vendedores ||\n";
		while (c) // percorre a lista
		{
			cout << "\nVENDEDOR " << i + 1 << endl;
			i++;
			cout << "Nome: " << c->getNome() << endl;
			cout << "Endereço: " << c->getEndereco() << endl;
			cout << "Telefone: " << c->getTelefone() << endl;
			cout << "Data de nascimento: " << c->getDataNasc() << endl;
			cout << "CPF: " << c->getCpf() << endl;
			cout << "Matricula: " << c->getMatricula() << endl;
			c = c->getProxVendedor();
		}
	}
}

bool ListaVendedor::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaVendedor::inserir_inicio(Vendedor v)
{
	Vendedor* novo_vendedor = new Vendedor(v.getNome(), v.getEndereco(), v.getTelefone(), v.getDataNasc(), v.getCpf(), v.getMatricula());

	if (vazia())
	{
		cabeca = novo_vendedor;
		cauda = novo_vendedor;
	}
	else
	{
		novo_vendedor->setProxVendedor(cabeca);
		cabeca = novo_vendedor;
	}
}

// insere no final (semelhante a push_back)
void ListaVendedor::inserir_final(Vendedor v)
{
	Vendedor* novo_vendedor = new Vendedor(v.getNome(), v.getEndereco(), v.getTelefone(), v.getDataNasc(), v.getCpf(), v.getMatricula());

	if (vazia())
	{
		cabeca = novo_vendedor;
		cauda = novo_vendedor;
	}
	else
	{
		cauda->setProxVendedor(novo_vendedor);
		cauda = novo_vendedor;
	}
}


// retorna o tamanho da lista
int ListaVendedor::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	Vendedor* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxVendedor();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaVendedor::existe(int cpf)
{
	Vendedor* c = cabeca;

	while (c)
	{
		if (c->getCpf() == cpf)
			return true;
		c = c->getProxVendedor();
	}
	return false;
}

bool ListaVendedor::existeMatricula(int matricula)
{
	Vendedor* c = cabeca;

	while (c)
	{
		if (c->getMatricula() == matricula)
			return true;
		c = c->getProxVendedor();
	}
	return false;
}

// remove da lista
int ListaVendedor::remover(int cpf) {

	Vendedor* ant_ant = cabeca;
	Vendedor* ant = cabeca->getProxVendedor();

	if (ant_ant->getCpf() == cpf) {
		cabeca = ant_ant->getProxVendedor();
		ant_ant->getProxVendedor() == NULL;
		cout << "\nO vendedor com o CPF " << cpf << " foi encontrado e excluído com sucesso!\n";
		return cpf;
	}
	while (ant != NULL && ant->getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxVendedor();
	}

	if (ant != NULL) {
		ant_ant->setProxVendedor(ant->getProxVendedor());
		ant == NULL;
		cout << "\nO vendedor com o CPF " << cpf << " foi encontrado e excluído com sucesso!\n";
		return cpf;
	}
}