#include "../Vetor/Vetor.hpp"
template<typename T>
class Pilha : private Vetor<T>{
 private:

 public:
        Pilha(int t) : Vetor<T>(t) {}

        void empilha(T dado) {
            Vetor<T>::adiciona(dado);
        }
        
        T desempilha() {
            return Vetor<T>::retiraUltimo();
        }

        T topo() {
            return Vetor<T>::consultaUltimo();
        }

        int getPosTopo() {
            return Vetor<T>::getIndice();
        }

        void limparPilha() {
            Vetor<T>::limpa();
        }

        bool PilhaVazia() {
            return Vetor<T>::estaVazio();
        }

        bool PilhaCheia() {
            return Vetor<T>::estaCheio();
        }
};

