#include "Lista.hpp"
template<typename T>
class Pilha : private Lista<T>{
 public:
    explicit Pilha(int t) : Lista<T>(t) {}

    void empilha(T dado) {
        Lista<T>::adiciona(dado);
    }

    T desempilha() {
        return Lista<T>::retiraUltimo();
    }

    T topo() {
        return Lista<T>::consultaUltimo();
    }

    int getPosTopo() {
        return Lista<T>::getIndice();
    }

    void limparPilha() {
        Lista<T>::limpa();
    }

    bool PilhaVazia() {
        return Lista<T>::estaVazio();
    }

    bool PilhaCheia() {
        return Lista<T>::estaCheio();
    }
};

