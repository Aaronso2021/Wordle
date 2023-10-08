#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

int main (){
    vector <string> word;
    string guess;
    string feedback = "XXXXX";
    bool isWord = false;
    int seed = 0;
    srand(time(0));

    ifstream file;
    file.open("words.txt");
    string data;

    while (!file.eof()){
        getline(file, data);
        word.push_back(data);
    }
    
    string wordle;
    wordle = word.at(rand()%12972);
    //Word from word list is randomly selected
    for (int h = 1; h < 7; ++h){
    cout << "Turn:" << h << endl;
    cin >> guess; //Gives you 6 tries

        if (guess == wordle){
            cout << "You win! The wordle was: " << wordle << endl;
            return 0;
        }
        //closes game if you get the correct word
        while (isWord == false){
            for (int p = 0; p < word.size(); ++p){
                if (guess == word.at(p)){
                    isWord = true;
                    break;
                }
            }
            //checks if the word is a real word
            cout << "Please enter a valid word." << endl; 
        cin >> guess;
    }
    feedback = "XXXXX";
        for (int i = 0; i < wordle.size(); ++i){
            for (int j = 0; j < guess.size(); ++j){ 
                if (wordle[i] == guess[i]){
                feedback[i] = '$';
                }
                else if (wordle[i] == guess[j] && i != j && feedback[i] != '%'){
                feedback[j] = '%';
                //checks if letters are present but in the incorrect place
                }
            }
        }
    //Checks guess for correct + incorect letters
    cout << feedback << endl;
}
    cout << "The wordle was: " << wordle << endl;
    return 0;
}
