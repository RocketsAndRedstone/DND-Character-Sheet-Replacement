// a text only version of a DND chareter sheet/ invintory sheet started on 05/29/2024

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

void spells();
void invintory();
void dice();

int main(){
    
    bool repeat = true;
    int choice;
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
    while (moreSpels == true){
    std::cout << "Do you want to (1) cast a spell or (2)add a spell?\n";
    std::cin >> doing;
    
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
    std::string dice;
    std::cout << "Enter what dice you are rolling, ex d20, d10, d6:\n";
    std::cin >> dice;
    

    std::cout << time(NULL);
}