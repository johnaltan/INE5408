#include "../Vetor/Vetor.hpp"
template<typename T>
class Fila : private Vetor<T> {
 private:

 public:
	Fila(int tam) : Vetor<T>(tam) {}
	void inclui(T dado) {
        Vetor<T>::adiciona(dado);
    }
	T retira() {
        return Vetor<T>::retiraPrimeiro();
    }
	T ultimo() {
        return Vetor<T>::consultaUltimo();
    }
	int getUltimo() {
        return Vetor<T>::getIndice();
    }
	bool filaCheia() {
        return Vetor<T>::estaCheio();
    }
	bool filaVazia() {
        return Vetor<T>::estaVazio();
    }
	void inicializaFila() {
        Vetor<T>::limpa(); 
    }
};


