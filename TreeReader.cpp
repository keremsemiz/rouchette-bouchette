#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void openFile(ifstream&, string);
void processFile(ifstream&);

int main() {
	// 1. open the file
	ifstream inFile;
	openFile(inFile, "possibility.txt");
	
	// 2. process the file
	processFile(inFile);
	
	// 3. close the file
	inFile.close();

	return 0;
}

void processFile(ifstream& inFile) {
	string line, word;
	istringstream iss;
    char valueAttackP = 'A',valueDefenseP = 'D',valueAttackC = 'a',valueDefenseC = 'd',valueHealC = 'h';
    int playerLife=3,playerShield=3,computerLife=3,computerShield=3;
	int Win,Loss,count;
	double probability,totalprobability;
	
	
	while (!inFile.eof()) {
		// read line by line from the file
		getline(inFile, line);
		if (inFile.good()) {
			//cout << line << endl;
			// read word by word from the line
			iss.clear(); // clear out state
			iss.str(line);
			while (iss.good()) {
				iss >> word;
				//cout << word << endl;
				// read char by char from the word
				//for (char c : word) {
					//cout << c << endl;
				//}
                playerLife=3,playerShield=3,computerLife=3,computerShield=3,count+=1,probability=1;
				for (int i = 0; i < word.length(); i++) {
                    //Player Attack
                    if(word[i]==valueAttackP){
						probability *=0.67;
                        if(computerShield>0){
                            computerShield -=1;
                        }else if (computerLife>0){
                            computerLife-=1;
                        }
                    }else if(word[i]==valueDefenseP){
						probability *=0.32;
                        if(playerShield<3){
                            playerShield +=1;
                        }
                    }else if(word[i]==valueAttackC){
                        if(playerShield>0){
                            playerShield -=1;
                        }else if (playerLife>0){
                            playerLife-=1;
                        }
                    }else if(word[i]==valueDefenseC){
                        if(computerShield<3){
                            computerShield +=1;
                        }
                    }else if(word[i]==valueHealC){
                        if(computerLife<3){
                            computerLife +=1;
                        }
                    }else{
                        cout<<"Error :"<<word[i];
                    }
                    if (computerLife == 0){
						totalprobability =probability+totalprobability;
                        Win +=1;
                        break;
                    }
					if (playerLife == 0){
                        Loss +=1;
                        break;
                    }
				}
			}	
		}
	}
    cout<<"\nWin :"<<Win<<"\nLoss :"<<count-Win<<"\nCount :"<<count<<"\nProbability :"<<totalprobability/Win;
}

void openFile(ifstream& inFile, string fname) {
	inFile.open(fname);
	if (inFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
