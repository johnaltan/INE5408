template<typename T>
class Vetor{
 private:
    T *vetor;
    int indice, tamanho;

 public:
    Vetor() {
        indice = -1;
        tamanho = 0;
    }

    explicit Vetor(int t) {
        tamanho = t;
        indice = -1;
        vetor = new T[tamanho];
    }

    int getIndice() {
        if (estaVazio()) throw "Vetor vazio";
        return indice;
    }

    void adiciona(T elemento) {
        if (estaCheio()) throw "Vetor cheio";
        vetor[++indice] = elemento;
    }

    T acessa(int ind, bool consulta) {
        if ((ind < 0) || (ind > indice)) throw "Indice fora dos limites";
        if (!consulta) indice--;
        T dado = vetor[ind];
        int i = ind;
        for (; i < (indice + 1); i++) vetor[i] = vetor[i + 1];
        return dado;
    }

    T retiraUltimo() {
        return acessa(indice, false);
    }

    T retiraPrimeiro() {
        return acessa(0, false);
    }

    T consultaUltimo() {
        return acessa(indice, true);
    }

    T consultaPrimeiro() {
        return acessa(0, true);
    }

    void limpa() {
        indice = -1;
    }

    bool estaVazio() {
        if (indice < 0) return true;
        return false;
    }
    bool estaCheio() {
        if (indice >= (tamanho - 1)) return true;
        return false;
    }
};

