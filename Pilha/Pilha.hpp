template<typename T>
class Pilha {
 private:
        int posicaoTopo, tamanho;
        T *pilha;

 public:
        Pilha() {
            posicaoTopo = -1;
            tamanho = 0;
        }
        Pilha<T>(int t) {
            pilha = new T[t];
            posicaoTopo = -1;
            tamanho = t;
        }
        void empilha(T dado) {
            if (PilhaCheia()) throw "Pilha cheia";
            pilha[++posicaoTopo] = dado;
        }
        T desempilha() {
            if (PilhaVazia()) throw "Pilha vazia";
            posicaoTopo--;
            return pilha[posicaoTopo + 1];
        }
        T topo() {
            return pilha[posicaoTopo];
        }
        int getPosTopo() {
            if (PilhaVazia()) throw "Pilha vazia";
            return posicaoTopo;
        }
        void limparPilha() {
            posicaoTopo = -1;
        }
        bool PilhaVazia() {
            if (posicaoTopo < 0) return true;
            return false;
        }
        bool PilhaCheia() {
            if (posicaoTopo >= (tamanho - 1)) return true;
            return false;
        }
};

