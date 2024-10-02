#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}
	topo = NULL;
	cout << "Pilha inicializada \n";
}


void push()
{
    // Aloca memória dinamicamente para o novo nó (elemento)
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)  // Verifica se a alocação de memória falhou
    {
        cout << "Erro de alocacao de memoria\n";
        return;
    }
	
    // Recebe o valor do usuário
    cout << "Digite o elemento: ";
    cin >> novo->valor;

    // O novo nó agora aponta para o nó que atualmente está no topo
    novo->prox = topo;

    // Atualiza o topo da pilha para ser o novo nó
    topo = novo;

    cout << "Elemento adicionado \n";
}

// Função que remove o elemento do topo da pilha
void pop()
{
    // Verifica se a pilha está vazia
    if (topo == NULL) 
    {
        cout << "Pilha Vazia\n";
        return;
    }

    // Armazena o nó atual (topo) temporariamente
    NO* temp = topo;

    // Move o topo para o próximo elemento da pilha
    topo = topo->prox;

    // Exibe o valor removido e libera a memória do nó antigo
    cout << "Elemento removido: " << temp->valor << endl;
    free(temp);  // Libera a memória do nó removido
}
