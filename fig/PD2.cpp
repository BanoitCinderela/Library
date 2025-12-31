  cout << "f(0) = " << anterior << ", f(1) = " << atual << endl;
        
        for (int i = 2; i <= n; i++) {
            long long proximo = anterior + atual;
            cout << "f(" << i << ") = " << anterior << " + " << atual 
                 << " = " << proximo << endl;
            anterior = atual;
            atual = proximo;
        }
        return atual;
    }
    static void compararPerformance(int n) {
        cout << "=== COMPARACAO DE PERFORMANCE PARA F(" << n << ") ===" << endl;
        
        // Teste memoizacao
        auto inicio = high_resolution_clock::now();
        unordered_map<int, long long> memo;
        long long resultMemo = fibMemoizado(n, memo);
        auto fim = high_resolution_clock::now();
        auto tempoMemo = duration_cast<microseconds>(fim - inicio);
        
        cout << "Memoizacao: " << resultMemo << " (tempo: " 
             << tempoMemo.count() << " microssegundos)" << endl;
        
        // Teste tabulacao
        inicio = high_resolution_clock::now();
        long long resultTab = fibTabulacao(n);
        fim = high_resolution_clock::now();
        auto tempoTab = duration_cast<microseconds>(fim - inicio);
        
        cout << "Tabulacao: " << resultTab << " (tempo: " 
             << tempoTab.count() << " microssegundos)" << endl;
        
        // Teste otimizado
        inicio = high_resolution_clock::now();
        long long resultOtim = fibOtimizado(n);
        fim = high_resolution_clock::now();
        auto tempoOtim = duration_cast<microseconds>(fim - inicio);
        
        cout << "Otimizado: " << resultOtim << " (tempo: " 
             << tempoOtim.count() << " microssegundos)" << endl;
    }
};
int main() {
    int n = 10;
    
    cout << "=== FIBONACCI COM PROGRAMACAO DINAMICA ===" << endl;
    // Demonstrar diferenca entre abordagens
    Fibonacci::compararPerformance(n);
    
    cout << "\n=== DETALHES DA CONSTRUCAO ===" << endl;
    cout << "Fibonacci(" << n << ") = " << Fibonacci::fibTabulacao(n) << endl;
    return 0;
}