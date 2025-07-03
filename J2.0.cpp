#include <iostream>
using namespace std;

int main() {
    const int MAX_JOGADORES = 5;
    const int MIN_JOGADORES = 2;

    int numJogadores;
    string jogadores[MAX_JOGADORES];
    int numeroSecreto;
    int palpite;
    int inicio = 1, fim = 100;
    bool acertou = false;

    
    do {
        cout << "Informe a quantidade de jogadores (entre 2 e 5): ";
        cin >> numJogadores;
    } while (numJogadores < MIN_JOGADORES || numJogadores > MAX_JOGADORES);

    
    for (int i = 0; i < numJogadores; i++) {
        cout << "Digite o nome do jogador " << i + 1 << ": ";
        cin >> jogadores[i];
    }

    
    do {
        cout << jogadores[0] << ", escolha um número secreto entre 1 e 100: ";
        cin >> numeroSecreto;
    } while (numeroSecreto < 1 || numeroSecreto > 100);

    
    cout << string(50, '\n');

     while (!acertou) {
        for (int i = 1; i < numJogadores; i++) {
            cout << jogadores[i] << ", digite um palpite entre " << inicio << " e " << fim << ": ";
            cin >> palpite;

     if (palpite < inicio || palpite > fim) {
                cout << "Palpite inválido! Tente dentro do intervalo." << endl << endl;
                continue;
            }

           if (palpite == numeroSecreto) {
                cout << jogadores[i] << ", você acertou... mas perdeu! 😂" << endl;
                acertou = true;
                break;
            } else if (palpite > numeroSecreto) {
                fim = palpite - 1;
                cout << "O número secreto é menor!" << endl;
            } else {
                inicio = palpite + 1;
                cout << "O número secreto é maior!" << endl;
            }

            cout << "Novo intervalo: " << inicio << " a " << fim << endl << endl;
        }
    }

    return 0;
}
