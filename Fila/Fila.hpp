#include "Lista.hpp"
template<typename T>
class Fila : private Lista<T> {
 public:
    explicit Fila(int tam) : Lista<T>(tam) {}
    void inclui(T dado) {
        Lista<T>::adiciona(dado);
    }
    T retira() {
        return Lista<T>::retiraPrimeiro();
    }
    T ultimo() {
        return Lista<T>::consultaUltimo();
    }
    int getUltimo() {
        return Lista<T>::getIndice();
    }
    bool filaCheia() {
        return Lista<T>::estaCheio();
    }
    bool filaVazia() {
        return Lista<T>::estaVazio();
    }
    void inicializaFila() {
        Lista<T>::limpa();
    }
};


