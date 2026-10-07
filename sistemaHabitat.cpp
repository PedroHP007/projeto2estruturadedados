#include <iostream>
using namespace std;

struct Animal{
    string nome;
    string alimentacao;
    string pais;
    int idade;
    Animal *proximo;
};

void Cadastrar(Animal *&head, string nome, string alimentacao, string pais, int idade){

    Animal *novoAnimal = new Animal;

    novoAnimal -> nome = nome;
    novoAnimal -> alimentacao = alimentacao;
    novoAnimal -> pais = pais;
    novoAnimal -> idade = idade;
    novoAnimal -> proximo = NULL;

    if(head == NULL){
        head = novoAnimal;
        return;
    }

    Animal *aux = head;

    while(aux -> proximo != NULL){
        aux = aux -> proximo;
    }

    aux -> proximo = novoAnimal;
}

int contarAnimais(Animal *&head){

    int quantidade = 0;
    Animal *aux = head;

    while(aux != NULL){
        quantidade++;
        aux = aux -> proximo;
    }

    return quantidade;
}

void imprimirAnimais(Animal *&head){

    if(head == NULL){
        cout << "Nao tem animais cadastrados";
        return;
    }

    Animal *aux = head;

    while(aux != NULL){

        cout << aux -> nome << " ";
        cout << aux -> alimentacao << " ";
        cout << aux -> pais << " ";
        cout << aux -> idade << endl;

        aux = aux -> proximo;
    }
}

void buscarAnimal(Animal *&head, string nome){

    if(head == NULL){
        cout << "Nao tem animais cadastrados";
        return;
    }

    Animal *aux = head;

    while(aux != NULL){

        if(aux -> nome == nome){

            cout << aux -> nome << " ";
            cout << aux -> alimentacao << " ";
            cout << aux -> pais << " ";
            cout << aux -> idade << endl;

            return;
        }
        aux = aux -> proximo;
    }

    cout << "Animal nao encontrado";
}
void removerAnimal(Animal *&head, string nome){

    if(head == NULL){
        cout << "Nao tem nada para remover";
        return;
    }
    Animal *temp = head;

    if(head -> nome == nome){

        head = head -> proximo;

        delete temp;

        return;
    }
    Animal *aux = head;

    while(aux -> proximo != NULL){

        if(aux -> proximo -> nome == nome){

            temp = aux -> proximo;

            aux -> proximo = temp -> proximo;

            delete temp;

            return;
        }

        aux = aux -> proximo;
    }

    cout << "Animal nao encontrado";
}

int main(){

    Animal *aquaticos = NULL;
    Animal *terrestres = NULL;
    Animal *voadores = NULL;

    int opcao;
    int habitat;

    do{

        cout << "1 - Cadastrar" << endl;
        cout << "2 - Consultar" << endl;
        cout << "3 - Buscar" << endl;
        cout << "4 - Remover" << endl;
        cout << "5 - Aquaticos" << endl;
        cout << "6 - Terrestres" << endl;
        cout << "7 - Voadores" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        if(opcao == 1){

            string nome;
            string alimentacao;
            string pais;
            int idade;

            cout << "1 - Aquatico" << endl;
            cout << "2 - Terrestre" << endl;
            cout << "3 - Voador" << endl;

            cin >> habitat;

            cout << "Nome: ";
            cin >> nome;

            cout << "Alimentacao: ";
            cin >> alimentacao;

            cout << "Pais: ";
            cin >> pais;

            cout << "Idade: ";
            cin >> idade;

            if(habitat == 1){
                if(contarAnimais(aquaticos) < 5){
                    Cadastrar(aquaticos, nome, alimentacao, pais, idade);
                }
            }

            else if(habitat == 2){
                 if(contarAnimais(terrestres) < 5){
                    Cadastrar(terrestres, nome, alimentacao, pais, idade);
                }
            }
            else if(habitat == 3){
                if(contarAnimais(voadores) < 5){
                    Cadastrar(voadores, nome, alimentacao, pais, idade);
                }
            }
        }

        else if(opcao == 2){
            imprimirAnimais(aquaticos);

            cout << endl;
            imprimirAnimais(terrestres);

            cout << endl;
            imprimirAnimais(voadores);
        }

        else if(opcao == 3){
            string nome;

            cout << "Digite o nome: ";
            cin >> nome;

            buscarAnimal(aquaticos, nome);
            buscarAnimal(terrestres, nome);
            buscarAnimal(voadores, nome);
        }
        else if(opcao == 4){
            string nome;

            cout << "Digite o nome: ";
            cin >> nome;

            removerAnimal(aquaticos, nome);
            removerAnimal(terrestres, nome);
            removerAnimal(voadores, nome);
        }
        else if(opcao == 5){
            imprimirAnimais(aquaticos);
        }
        else if(opcao == 6){
            imprimirAnimais(terrestres);
        }
        else if(opcao == 7){
            imprimirAnimais(voadores);
        }

    }while(opcao != 0);
    return 0;
}