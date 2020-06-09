#include <iostream>

using namespace std;

class Pilha{
    private:
        int* arr;
        int max_tam;
        int topo;
    public:
        Pilha(){
            arr = new int[100];
            max_tam = 99;
            topo = -1;
        }

        ~Pilha(){
            delete[] arr;
        }

        void empilhar(int e) {
            if(topo == max_tam)
                cout << "Pilha cheia!" << endl;
            else
                arr[++topo] = e;
        }

        void desempilhar() {
            if(topo == -1)
                cout << "Pilha vazia!" << endl;
            else
                topo--;
        }

        int getTopo() {
            if(topo != -1)
                return arr[topo];
            return -1;
        }

        int vazia() {
            return (topo == -1);
        }
};

int main(){
    Pilha p;

    p.empilhar(10);
    p.empilhar(11);
    p.empilhar(12);
    p.desempilhar();

    cout << "Pilha vazia: " << p.vazia() << endl;
    cout << "Topo: " << p.getTopo() << endl;

    return 0;
}

// SAIDA DO PROGRAMA
/* 
  Pilha vazia: 0
  Topo: 11 
*/
