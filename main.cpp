#include <iostream>
#include <cstdlib>
#include <limits>
#include "playerECartas.h"
#include <iomanip>

int oponenteIA(carta cartaAtual);
void avancaTela(bool limpaTela = true, bool inputAvanca = true);
void embaralharDeck(carta (&deckParaEmbaralhar)[35]);

//Load cards
carta deck[] = {
    {"Charizard", 84, 78, 109, 85, 100},
    {"Blastoise", 83, 100, 85, 105, 78},
    {"Venusaur", 82, 83, 100, 100, 80},
    {"Dracovish", 90, 100, 70, 80, 75},
    {"Gigalith", 135, 130, 60, 80, 25},
    {"Arcanine", 110, 80, 100, 80, 95},
    {"Zoroark", 105, 60, 120, 60, 105},
    {"Delphox", 69, 72, 114, 100, 104},
    {"Greninja", 95, 67, 103, 71, 122},
    {"Pikachu", 70, 65, 95, 75, 120},
    {"Mewtwo", 130, 120, 170, 130, 150},
    {"Umbreon", 65, 110, 60, 130, 65},
    {"Beartic", 130, 80, 70, 80, 50},
    {"Snorlax", 110, 65, 65, 110, 30},
    {"Sceptile", 85, 65, 105, 85, 120},
    {"Dragonite", 134, 95, 100, 100, 80},
    {"Garchomp", 130, 95, 80, 85, 102},
    {"Machamp", 130, 80, 65, 85, 55},
    {"Typhlosion", 84, 78, 109, 85, 100},
    {"Luxray", 120, 79, 95, 79, 70},
    {"Blaziken", 120, 70, 110, 70, 100},
    {"Eevee", 55, 50, 45, 65, 55},
    {"Jolteon", 65, 60, 110, 95, 130},
    {"Flygon", 100, 80, 85, 80, 100},
    {"Lapras", 85, 90, 85, 95, 60},
    {"Gyarados", 125, 79, 60, 100, 81},
    {"Torterra", 109, 105, 75, 85, 56},
    {"Infernape", 104, 71, 104, 71, 108},
    {"Empoleon", 86, 88, 111, 101, 60},
    {"Mew", 100, 100, 100, 100, 100},
    {"Florges", 65, 68, 112, 154, 75},
    {"Sylveon", 65, 65, 110, 130, 60},
    {"Hawlucha", 92, 75, 74, 63, 118},
    {"Pidgeott", 80, 75, 70, 70, 101},
    {"Serperior", 75, 95, 75, 95, 113}
};

player jogador;
player oponente;
//int randomCard{}; didnt work :C
//int i{0};
int n{0};
int atributoEscolhido{0};
//int aiCardChoice{0}; Redundant
int atributoAUsar{0};
int menuChoice{0};
std::string statusNomes[5]{
    "Attack",
    "Defense",
    "Special Attack",
    "Special Defense",
    "Speed"
};

int main(){

    while(true){ //Main game loop

        while(true){ //Main menu loop
            std::cout << std::setfill(' ') << std::setw(18) << "TRUNFO" << std::endl;;
            std::cout << std::setfill('-') << std::setw(30) << "\n";
            std::cout << "[" << 1 << "]" << " PLAY" << std::endl;
            std::cout << "[" << 2 << "]" << " HOW TO PLAY" << std::endl;
            std::cout << "[" << 3 << "]" << " QUIT" << std::endl;
            std::cout << "Choose an Option: ";

            if(std::cin >> menuChoice){
                if(menuChoice >= 1 && menuChoice <= 3){
                    break;

                }else{
                    std::cout << "Please input a valid option" << std::endl;
                }
            }else{
                std::cout << "Please input a valid option" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            avancaTela(true,false);
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //Clears input buffer        
        avancaTela(true,false);

        switch (menuChoice){
            case 3: //End Program
                std::cout << "Closing game" << std::endl;
                return 0;
                break;

            case 2:
                std::cout << std::setfill(' ') << std::setw(16) << "RULES" << std::endl;
                std::cout << std::setfill('-') << std::setw(30) << "\n";
                
                std::cout << "Trunfo is a very simple card game" << std::endl;

                avancaTela();

                std::cout << "Both, you and your opponent, are given 5 cards at the beginning of the round!" << std::endl;
                std::cout << "The cards are randomly chosen from a deck filled with 35 cards" << std::endl;
                std::cout << "which will be shuffled at the beginning of each round" << std::endl; 

                avancaTela();

                std::cout << "Each card will have a bunch of different stats\n" << std::endl;
                deck[7].mostrarCarta();

                avancaTela();

                std::cout << "Each turn, players will pull a card from their hand \nwithout showing it to the other." << std::endl;
                std::cout << "After both picked a card, one will choose a stat from it!" << std::endl;
                std::cout << "Each turn, players will alternate who gets to pick the stat\n" << std::endl;
                deck[7].mostrarCarta();

                std::cout << "\nPlayer 1 has choosen the " << statusNomes[2] << " Stat!" << std::endl;
                
                avancaTela();

                std::cout << "Then, players will reveal and compare the chosen stat of their cards\n" << std::endl;
                std::cout << "Player 1's Card" << std::endl;
                deck[7].mostrarCarta();

                std::cout << "\nPlayer 2's Card" <<std::endl;
                deck[5].mostrarCarta();

                std::cout << "\nThe one with the highest stat wins!" << std::endl;

                avancaTela();

                std::cout << "Games will be composed of 3 rounds, each with 5 turns." << std::endl;
                std::cout << "The first player to win 3 turns wins the round" << std::endl;
                std::cout << "and the first player to win 2 rounds wins the game!" << std::endl;
                std::cout << "And that is it! Now you are ready to play Trunfo!" << std::endl;

                avancaTela();

                break;

            case 1:
                int roundCount{0};
                for(;;){
                    roundCount += 1;
                    embaralharDeck(deck);

                    jogador.pontuacaoTurno = 0;
                    oponente.pontuacaoTurno = 0;
                    //i = 0;

                    for(int i = 0; i < 5; i++){
                        jogador.mao[i] = deck[i];
                        oponente.mao[i] = deck[i+5];
                        //deck[i].tiradaDoDeck = true;   
                    }
                    
                    std::cout << "ROUND " << roundCount << std::endl;

                    for(int j = 0; j < 5; j++){
                        if(j % 2 == 0){ //Player goes first

                            for(;;){

                                std::cout << "\nIT IS YOUR TURN!" << std::endl;
                                avancaTela();

                                jogador.mao[j].mostrarCarta();
                                std::cout << "Choose a stat: ";

                                if(std::cin >> atributoEscolhido){ //Input Validation
                                    if(1 <= atributoEscolhido && atributoEscolhido <= 5){
                                        atributoAUsar = atributoEscolhido - 1;
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                        break;

                                    }
                                    std::cout << "Choose a valid option" << std::endl;

                                }else{
                                    std::cout << "Choose a valid option" << std::endl;
                                    std::cin.clear(); //Ignores error condition
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Cleans Input Buffer
                                }

                                avancaTela(true,false);
                            }

                            std::cout << "\nOpponent's card" << std::endl;
                            oponente.mao[j].mostrarCarta();

                            //avancaTela();

                        }else{ //Oponent goes first

                            std::cout << "IT IS THE OPPONENTS'S TURN!" << std::endl;
                            atributoAUsar = oponenteIA(oponente.mao[j]);
                            std::cout << "The opponent chose the " << statusNomes[atributoAUsar] << " stat!" << std::endl;
                            
                            avancaTela();

                            oponente.mao[j].mostrarCarta();
                            std::cout << "\nYour current card\n" << std::endl;
                            jogador.mao[j].mostrarCarta();

                            //avancaTela();
                        }

                        avancaTela();

                        std::cout << statusNomes[atributoAUsar] << " of your card: " << jogador.mao[j].statsParaUso[atributoAUsar] << std::endl;
                        std::cout << statusNomes[atributoAUsar] << " of the opponent card: " << oponente.mao[j].statsParaUso[atributoAUsar] << std::endl;


                        if(jogador.mao[j].statsParaUso[atributoAUsar] > oponente.mao[j].statsParaUso[atributoAUsar]){ //Player won the turn
                            jogador.pontuacaoTurno++;
                            std::cout << "You won this turn!" << std::endl; 

                        }else if(jogador.mao[j].statsParaUso[atributoAUsar] < oponente.mao[j].statsParaUso[atributoAUsar]){ //Player lost the turn
                            oponente.pontuacaoTurno++;
                            std::cout << "The opponent won this turn!" << std::endl; 
    
                        }else{ //Turn has tied
                            std::cout << "This Turn is a Tie!";
                        }

                        std::cout << '\n' << std::setfill(' ') << std::setw(17) << "TURN SCORE" << "\n";
                        std::cout << std::setfill('-') << std::setw(30) << "\n";
                        std::cout << "You: " << jogador.pontuacaoTurno << "    X    "; 
                        std::cout << "Opponent: " << oponente.pontuacaoTurno << '\n' << "\n";

                        //avancaTela();

                        if(jogador.pontuacaoTurno >= 3){ //Player has won the round
                            std::cout << "You won this Round!" << std::endl;
                            jogador.pontuacaoRounds++;
                            avancaTela();
                            break;
                        }
                        else if(oponente.pontuacaoTurno >= 3){ //Player has lost the round
                            std::cout << "The opponent won this Round!" << std::endl;
                            oponente.pontuacaoRounds++;
                            avancaTela();
                            break;

                        }else if(j == 4){ //This is to treat games with ties

                            if(jogador.pontuacaoTurno > oponente.pontuacaoTurno){ //Player won the round with ties
                                std::cout << "You won this Round!" << std::endl;
                                jogador.pontuacaoRounds++;

                            }else if(jogador.pontuacaoTurno < oponente.pontuacaoTurno){ //Opponent won the round with ties
                                std::cout << "The opponent won this Round!" << std::endl;
                                oponente.pontuacaoRounds++;

                            }else{ //The game ended in a tie
                                std::cout << "This Round is a Tie!" << std::endl;
                            }

                            avancaTela();

                        }else{
                            avancaTela();
                        }

                    }

                    if((jogador.pontuacaoRounds >=2) || (oponente.pontuacaoRounds >=2)){ //Checks if someone has already won
                        break;
                    }
                }

                avancaTela(true,false);

                if(jogador.pontuacaoRounds > oponente.pontuacaoRounds){ //Player won the game
                    std::cout << "Congratulations! You have won the game!" << std::endl;

                }else{//Player lost the game
                    std::cout << "It seems you have lost! Better luck next time!" << std::endl;
                }
                
                std::cout << '\n' << std::setw(7) << "Final Score (Rounds Won)";
                std::cout << std::setfill('-') << std::setw(30) << std::endl;
                std::cout << "\nYou: " << jogador.pontuacaoRounds << "   X   " << "Opponent: " << oponente.pontuacaoRounds << std::endl;

                avancaTela();
                
                //std::cout << "Program end" << std::endl; //Debug
                break;

        }
    }
}

int oponenteIA(carta cartaAtual){ //Definição da função da IA
    //srand((unsigned)time(0)); Redundant
    int aiAction{rand() % 100};
    int highestOption{0};

    //aiAction = 19; //Debug

    if(aiAction <= 29){ //30% chance do choose a random stat
        return rand() % 5;

    }else{ //70% to look for the highest card stat
        for(int i = 0; i < 5; i++){
            if(cartaAtual.statsParaUso[highestOption] <= cartaAtual.statsParaUso[i]){
                highestOption = i;
            }
        }
    }

    return highestOption;

}

void avancaTela(bool limpaTela, bool inputAvanca){
    //char garbage{}; //Horrible

    if(inputAvanca){
        std::cout << "\nPress ENTER to proceed" << std::endl;

        //std::cin >> garbage; //A true crime against programming
        std::cin.sync();
        std::cin.get();

        //std::cin.clear();

    }

    if(limpaTela){
        std::cout << "\033c"; //Clears terminal
    }
}

void embaralharDeck(carta (&deckParaEmbaralhar) [35]){

    srand((unsigned)(time(NULL))); //Sets a seed based on the current system clock
    carta deckEmbaralhado[35];
    int p{0};
    int auxp{0};
    int m{0};

    for(int j = 0; j < 5; j++){

        if(j % 2 == 0){ //Shuffles the deck foward
            p = rand() % 35;
            auxp = p;

            while(p < 35){
                deckEmbaralhado[m] = deckParaEmbaralhar[p];
                p++;
                m++;
            }

            p = auxp - 1;

            while(p > -1){
                deckEmbaralhado[m] = deckParaEmbaralhar[p];
                p--;
                m++;
            }

            m = 0;

            for(int j = 0; j < 35; j++){
                deckParaEmbaralhar[j] = deckEmbaralhado[j];
            }

        }else{ //Shuffles the deck backwards
            m = 34;
            p = rand() % 35;
            auxp = p;

            while(p < 35){
                deckEmbaralhado[m] = deckParaEmbaralhar[p];
                p++;
                m--;
            }

            p = auxp - 1;

            while(p > -1){
                deckEmbaralhado[m] = deckParaEmbaralhar[p];
                p--;
                m--;
            }

            m = 0;

            for(int j = 0; j < 35; j++){
                deckParaEmbaralhar[j] = deckEmbaralhado[j];
            //    std::cout << deckParaEmbaralhar[j].nomeCarta << std::endl; //Debug
            }

            //avancaTela(); //Debug
        }
    }


}