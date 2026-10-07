#include <iostream>
using namespace std;

struct Jogador{
    string nome;
    int id;
    Jogador *proximo;
};

void cadastrar(Jogador *&head, string nome, int id){

    Jogador *novoJogador = new Jogador;

    novoJogador -> nome = nome;
    novoJogador -> id = id;

    if(head == NULL){

        head = novoJogador;
        novoJogador -> proximo = head;

        return;
    }

    Jogador *aux = head;

    while(aux -> proximo != head){
        aux = aux -> proximo;
    }

    aux -> proximo = novoJogador;
    novoJogador -> proximo = head;
}

void imprimir(Jogador *&head){

    if(head == NULL){
        cout << "Lista vazia";
        return;
    }

    Jogador *aux = head;

    do{

        cout << aux -> nome << " " << aux -> id << endl;

        aux = aux -> proximo;

    }while(aux != head);
}

void remover(Jogador *&head, int id){

    if(head == NULL){
        cout << "Lista vazia";
        return;
    }

    Jogador *temp = head;

    if(head -> id == id){

        if(head -> proximo == head){

            head = NULL;
            delete temp;

            return;
        }

        Jogador *aux = head;

        while(aux -> proximo != head){
            aux = aux -> proximo;
        }

        head = head -> proximo;
        aux -> proximo = head;

        delete temp;

        return;
    }

    Jogador *aux = head;

    while(aux -> proximo != head){

        if(aux -> proximo -> id == id){

            temp = aux -> proximo;

            aux -> proximo = temp -> proximo;

            delete temp;

            return;
        }

        aux = aux -> proximo;
    }

    cout << "Jogador nao encontrado";
}

void vez(Jogador *&head){

    if(head == NULL){
        cout << "Lista vazia";
        return;
    }

    cout << head -> nome << " " << head -> id << endl;
}

void proximoJogador(Jogador *&head){

    if(head == NULL){
        cout << "Lista vazia";
        return;
    }

    head = head -> proximo;
}

int main(){

    Jogador *head = NULL;

    int opcao;

    do{

        cout << "1 - Cadastrar" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Exibir" << endl;
        cout << "4 - Vez" << endl;
        cout << "5 - Proximo" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        if(opcao == 1){

            string nome;
            int id;

            cout << "Nome: ";
            cin >> nome;

            cout << "ID: ";
            cin >> id;

            cadastrar(head, nome, id);
        }

        else if(opcao == 2){
            int id;

            cout << "ID: ";
            cin >> id;

            remover(head, id);
        }
        else if(opcao == 3){

            imprimir(head);
        }
        else if(opcao == 4){

            vez(head);
        }
        else if(opcao == 5){

            proximoJogador(head);
        }
    }while(opcao != 0);

    return 0;
}