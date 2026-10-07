#include <iostream>
using namespace std;

struct Comprador{
    string nome;
    int idade;
    string cidade;
    string ingresso;
    Comprador *proximo;
    Comprador *anterior;
};

void cadastrar(Comprador *&head, string nome, int idade, string cidade, string ingresso){

    Comprador *novo = new Comprador;

    novo -> nome = nome;
    novo -> idade = idade;
    novo -> cidade = cidade;
    novo -> ingresso = ingresso;
    novo -> proximo = NULL;
    novo -> anterior = NULL;

    if(head == NULL){
        head = novo;
        return;
    }
    Comprador *aux = head;

    while(aux -> proximo != NULL){
        aux = aux -> proximo;
    }
    aux -> proximo = novo;
    novo -> anterior = aux;
}

void imprimirInicio(Comprador *&head){

    if(head == NULL){
        cout << "Nao tem compradores";
        return;
    }

    Comprador *aux = head;

    while(aux != NULL){

        cout << aux -> nome << " ";
        cout << aux -> idade << " ";
        cout << aux -> cidade << " ";
        cout << aux -> ingresso << endl;

        aux = aux -> proximo;
    }
}

void imprimirFinal(Comprador *&head){

    if(head == NULL){
        cout << "Nao tem compradores";
        return;
    }

    Comprador *aux = head;

    while(aux -> proximo != NULL){
        aux = aux -> proximo;
    }

    while(aux != NULL){

        cout << aux -> nome << " ";
        cout << aux -> idade << " ";
        cout << aux -> cidade << " ";
        cout << aux -> ingresso << endl;

        aux = aux -> anterior;
    }
}

void buscar(Comprador *&head, string nome){

    Comprador *aux = head;

    while(aux != NULL){

        if(aux -> nome == nome){

            cout << aux -> nome << " ";
            cout << aux -> idade << " ";
            cout << aux -> cidade << " ";
            cout << aux -> ingresso << endl;

            return;
        }

        aux = aux -> proximo;
    }

    cout << "Comprador nao encontrado";
}
void remover(Comprador *&head, string nome){

    if(head == NULL){
        cout << "Nao tem compradores";
        return;
    }

    Comprador *temp = head;
    if(head -> nome == nome){

        head = head -> proximo;

        if(head != NULL){
            head -> anterior = NULL;
        }

        delete temp;

        return;
    }

    Comprador *aux = head;
    while(aux -> proximo != NULL){

        if(aux -> proximo -> nome == nome){

            temp = aux -> proximo;

            aux -> proximo = temp -> proximo;

            if(temp -> proximo != NULL){
                temp -> proximo -> anterior = aux;
            }

            delete temp;
            return;
        }

        aux = aux -> proximo;
    }
    cout << "Comprador nao encontrado";
}
int main(){

    Comprador *head = NULL;

    int opcao;

    do{

        cout << "1 - Cadastrar" << endl;
        cout << "2 - Buscar" << endl;
        cout << "3 - Remover" << endl;
        cout << "4 - Visualizar" << endl;
        cout << "5 - Ordem inversa" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        if(opcao == 1){

            string nome;
            int idade;
            string cidade;
            string ingresso;

            cout << "Nome: ";
            cin >> nome;

            cout << "Idade: ";
            cin >> idade;

            cout << "Cidade: ";
            cin >> cidade;

            cout << "Ingresso: ";
            cin >> ingresso;

            cadastrar(head, nome, idade, cidade, ingresso);
        }
        else if(opcao == 2){
            string nome;

            cout << "Nome: ";
            cin >> nome;

            buscar(head, nome);
        }
        else if(opcao == 3){

            string nome;

            cout << "Nome: ";
            cin >> nome;

            remover(head, nome);
        }
        else if(opcao == 4){

            imprimirInicio(head);
        }
        else if(opcao == 5){

            imprimirFinal(head);
        }

    }while(opcao != 0);

    return 0;
}