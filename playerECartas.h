#include <iostream>
#include <iomanip>

class carta{
    public:
        std::string nomeCarta{};
        int attack{};
        int defense{};
        int spAttack{};
        int spDefense{};
        int speed{};
        int statsParaUso[5]{attack, defense, spAttack, spDefense, speed};
        //bool foiUsada{false};
        //bool tiradaDoDeck{false};

    void mostrarCarta(){
        std::cout << std::setfill(' ') << std::setw(18) << nomeCarta << std::endl;
        std::cout << std::setfill('-') << std::setw(30) << '\n';
        std::cout << "[" << 1 << "]" << "Attack: " << attack << std::endl;
        std::cout << "[" << 2 << "]" << "Defense: " << defense << std::endl;
        std::cout << "[" << 3 << "]" << "Special Attack: " << spAttack << std::endl;
        std::cout << "[" << 4 << "]" << "Special Defense: " << spDefense << std::endl;
        std::cout << "[" << 5 << "]" << "Speed: " << speed << std::endl;
    };
};

class player{
    public:
        carta mao[5]{};
        int pontuacaoRounds{0};
        int pontuacaoTurno{0};

    void mostrarMao(){
        for(int i = 0; i < 5; i++){
            std::cout << "[" << i+1 << "]" << mao[i].nomeCarta << std::endl;
        }
    };
};