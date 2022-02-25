#include "ListaCliente.h"
#include <Windows.h>

ListaCliente::ListaCliente()
{
	// se não passar elemento, então cabeca e cauda são NULL
	cabeca = NULL;
	cauda = NULL;
}

Cliente* ListaCliente::getCabeca() {
	return this->cabeca;
}
void ListaCliente::setCabeca(Cliente* cabeca) {
	this->cabeca = cabeca;
}

ListaCliente::ListaCliente(string nome, string endereco, int telefone, string dataNasc, int cpf, double limiteCredito, Pessoa contato)
{
	// se passar elemento, então cria novo No
	cabeca = new Cliente(nome, endereco, telefone, dataNasc, cpf, limiteCredito, contato);
	cauda = cabeca;
}

// mostra todos os elementos da lista
void ListaCliente::mostrarTodos()
{
	SetConsoleOutputCP(65001);
	int i = 0;
	
	Cliente* c = cabeca;

	if (vazia())
		cout << "\nERRO: A lista não possui pessoas!\n";
	else
	{
		cout << "\n|| Impressão de Clientes ||\n";
		while (c) // percorre a lista
		{
			cout << "\nCLIENTE " << i + 1 << endl;
			i++;
			cout << "Nome: " << c->getNome() << endl;
			cout << "Endereço: " << c->getEndereco() << endl;
			cout << "Telefone: " << c->getTelefone() << endl;
			cout << "Data de nascimento: " << c->getDataNasc() << endl;
			cout << "CPF: " << c->getCpf() << endl;
			cout << "Limite de crédito: R$" << c->getLimiteCredito() << endl;
			cout << "Nome do contato: " << c->getContato().getNome() << endl;
			cout << "Endereço do contato: " << c->getContato().getEndereco() << endl;
			cout << "Telefone do contato: " << c->getContato().getTelefone() << endl;
			cout << "Data de nascimento do contato: " << c->getContato().getDataNasc() << endl;
			cout << "CPF do contato: " << c->getContato().getCpf() << endl;

			c = c->getProxCliente();
		}
	}
}

bool ListaCliente::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaCliente::inserir_inicio(Cliente c)
{
	Cliente* novo_cliente = new Cliente(c.getNome(), c.getEndereco(), c.getTelefone(), c.getDataNasc(), c.getCpf(), c.getLimiteCredito(), c.getContato());

	if (vazia())
	{
		cabeca = novo_cliente;
		cauda = novo_cliente;
	}
	else
	{
		novo_cliente->setProxCliente(cabeca);
		cabeca = novo_cliente;
	}
}

// insere no final (semelhante a push_back)
void ListaCliente::inserir_final(Cliente c)
{
	Cliente* novo_cliente = new Cliente(c.getNome(), c.getEndereco(), c.getTelefone(), c.getDataNasc(), c.getCpf(), c.getLimiteCredito(), c.getContato());

	if (vazia())
	{
		cabeca = novo_cliente;
		cauda = novo_cliente;
	}
	else
	{
		cauda->setProxCliente(novo_cliente);
		cauda = novo_cliente;
	}
}


// retorna o tamanho da lista
int ListaCliente::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	Cliente* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxCliente();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaCliente::existe(int cpf)
{
	Cliente* c = cabeca;

	while (c)
	{
		if (c->getCpf() == cpf)
			return true;
		c = c->getProxCliente();
	}
	return false;
}

// remove da lista
int ListaCliente::remover(int cpf) {

	Cliente* ant_ant = cabeca;
	Cliente* ant = cabeca->getProxCliente();

	if (ant_ant->getCpf() == cpf) {
		cabeca = ant_ant->getProxCliente();
		ant_ant->getProxCliente() == NULL;
		cout << "\nO cliente com o CPF " << cpf << " foi encontrado e excluído com sucesso!\n";
		return cpf;
	}
	while (ant != NULL && ant->getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxCliente();
	}

	if (ant != NULL) {
		ant_ant->setProxCliente(ant->getProxCliente());
		ant == NULL;
		cout << "\nO cliente com o CPF " << cpf << " foi encontrado e excluído com sucesso!\n";
		return cpf;
	}
}