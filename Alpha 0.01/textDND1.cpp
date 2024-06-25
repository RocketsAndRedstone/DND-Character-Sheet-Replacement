// a text only version of a DND chareter sheet/ invintory sheet started on 05/29/2024
// New name: HereDND

#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <time.h>



void spells();
void invintory();
void dice();

int main(){
    bool repeat = true;
    int choice;
    // the main loop to select any of the available options allowing for mutiple uses of each option
    while ( repeat == true){
        std::cout << "Select the number from the following list:\n 1: acsess spell list\n 2: acsess invintory\n 3: roll a dice\n 4: end\n";
        std::cin >> choice;
        if (choice == 1){
            spells();
        }
        else if (choice == 2){
            invintory();
        }
        else if (choice == 3){
            dice();
        }
        else if (choice == 4){
            repeat = false;
        }
    }

    return 0;
}


void spells(){
    int doing;
    bool moreSpels = true;
    //selects the option wanted by the user
    while (moreSpels == true){
    std::cout << "Do you want to (1) cast a spell or (2)add a spell?\n";
    std::cin >> doing;
    //opens up the spell list for the player to select from. Displays the spells and their level as well as the advailable spell slots(needs to be implemented)
    if (doing == 1){
        std::string spellOutput;
        std::ifstream readSpells("Spells.txt");
        while (getline (readSpells , spellOutput)){
            std::cout << spellOutput << "\n";
        }

        std::cout << "Selsect the spell to be cast:\t";

        readSpells.close();
        
    }

    else if (doing == 2){
        //alows for the adition of spells to the spell list for homebrew spells and spells for older editions of the game
        std::string level, spellName, fullSpell;
        std::ofstream addSpells("Spells.txt", std::ios::in | std::ios::out | std::ios::ate);
        std::cout << "Enter the spell's level, enter 0 for a cantrip:\n";
        std::cin >> level;
        std::cout << "Enter the name of the spell:\n";
        std::cin.ignore();
        std::getline(std::cin, spellName);
        fullSpell = level + spellName + "," + "\n";
        addSpells << fullSpell;
        addSpells.close();
    }
    char response;
    std::cout << "go to main selsection screen? y or n:\t";
    std::cin >> response;
    if (response == 'y' | response == 'Y'){
        moreSpels = false;
    }
   
    }
    
    std::cout << "Casting spells\n";
}

void invintory(){
    std::cout << "messing around with stuf\n";
}

void dice(){
    //a built in dice roller for damage and other rolls
    
    std::string dice;
    int numOfRolls, diceresult;
    std::cout << "Enter what dice you are rolling, ex d20, d10, d6:\n";
    std::cin >> dice;
    std::cout << "How many times do you want to roll the " << dice << "?\n";
    std::cin >> numOfRolls;
    dice.erase(0,1);
    int diceTrue = stoi(dice);
    srand(time(NULL));
    for (int i = 0; i < numOfRolls; i++){
        diceresult = (rand() % diceTrue + 1);
        std::cout << diceresult << "\n";
    }
    

   // std::cout << time(NULL);
}