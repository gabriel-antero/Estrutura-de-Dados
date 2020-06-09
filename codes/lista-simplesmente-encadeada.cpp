#include <iostream>

using namespace std;

class No{
    private:
        int valor;
        No* prox;
    public:
        No(int valor){
            this->valor = valor;
            this->prox = NULL;
        }

        int obterValor(){
            return valor;
        }

        No* obterProx(){
            return prox;
        }

        void setProx(No* p){
            prox = p;
        }
};

class Lista{
    private:
        No* cabeca;
        No* cauda;

    public:
        Lista(){
            cabeca = NULL;
            cauda = NULL;
        }

        Lista(int valor){
            cabeca = new No(valor);
            cauda = cabeca;
        }

        virtual ~Lista(){
            delete cabeca;
        }

        void mostrar(){
            cout << "Imprimindo todos os elementos da lista" << endl;
            No* c = cabeca;

            if(vazia())
                cout << "A lista não possui elementos!" << endl;
            else {
                while(c){
                    cout << c->obterValor() << endl;
                    c = c->obterProx();
                }
                cout << endl;
            }
        }

        bool vazia(){
            return (cabeca == NULL);
        }

        void inserir_inicio(int valor){
            No* novo_no = new No(valor);

            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }

        void inserir_final(int valor){
            No* novo_no = new No(valor);

            if(vazia()){
                cabeca = novo_no;
                cauda = novo_no;
            } else {
                cauda->setProx(novo_no);
                cauda = novo_no;
            }
        }

        int tamanho(){
            if(vazia())
                return 0;

            No* c = cabeca;
            int tam = 0;
            do{
                c = c->obterProx();
                tam++;
            } while(c);

            return tam;
        }

        bool existe(int valor){
            No* c = cabeca;
            while(c){
                if(c->obterValor() == valor)
                    return true;
                c = c->obterProx();
            }
            return false;
        }

        void remover_final(){
            if(!vazia()){
                if(cabeca->obterProx() == NULL)
                    cabeca = NULL; // Se houver apenas 1 elemento na lista

                else if(cabeca->obterProx()->obterProx() == NULL) // Se houver apenas 2 elemento na lista
                    cabeca->setProx(NULL);

                else { // Se houver mais de 2 elementos
                    No* ant_ant = cabeca;
                    No* ant = cabeca->obterProx();
                    No* corrente = cabeca->obterProx()->obterProx();

                    while(corrente){
                        No* aux = ant;
                        ant = corrente;
                        ant_ant = aux;
                        corrente = corrente->obterProx();
                    }

                    delete ant_ant->obterProx();
                    ant_ant->setProx(NULL);
                    cauda = ant_ant;
                }
            }
        }
};

int main () {
    Lista l;

    if(l.vazia())
        cout << "Lista vazia" << endl;
    else
        cout << "Lista não vazia" << endl;

    l.mostrar();

    if(l.existe(10))
        cout << "\nO elemento 10 existe na listaa" << endl;
    else
        cout << "\nO elemento 10 não existe na lista" << endl;

    l.inserir_final(10);
    l.inserir_final(20);
    l.inserir_final(30);
    l.inserir_final(40);
    l.inserir_inicio(50);

    l.mostrar();

    if(l.vazia())
        cout << "Lista vazia" << endl;
    else
        cout << "Lista não vazia" << endl;

    if(l.existe(10))
        cout << "\nO elemento 10 existe na listaa" << endl;
    else
        cout << "\nO elemento 10 não existe na lista" << endl;

    l.remover_final();

    l.mostrar();

    cout << "Tamnho da lista: " << l.tamanho() << endl;

    return 0;
}

// SAIDA DO PROGRAMA 

/* A lista não possui elementos!
  
  O elemento 10 não existe na lista
  Imprimindo todos os elementos da lista
  50
  10
  20
  30
  40
  
  Lista não vazia
  
  O elemento 10 existe na listaa
  Imprimindo todos os elementos da lista
  50
  10
  20
  30
  
  Tamnho da lista: 4 
*/

