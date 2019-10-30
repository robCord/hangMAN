#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

int main ()
{
	// Display Title of the program to the user
	cout << "Keyword simulation decryption training program" << endl;
	// Ask the recruit to log in using their name
	cout << "Please enter your name" << endl;
	
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name;
	cin >> name;
	// Display an overview of what Keywords II is to the recruit 
	cout << "Welcome " << name << ", this program is designed to enhance your keyword decryption skills in a time efficient manor" << "\n";
	// Display directions to the recruit on how to use Keywords
	cout << "You are given a word to solve, please enter a single letters to input your guess\n";
	cout << "You are given three guesses, should the word remain unsolved, you will fail the current simulation\n";
	


	// Create a collection of 10 words you had written down manually
	// set the words into a list along with corresponding hints
	enum fields { WORD, HINT, NUM_FIELDS };
	//number of code words to use in options for user to solve
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"work"},
		{"runner"},
		{"tired"},
		{"persistent"},
		{"chain"},
		{"comfort"},
		{"jogging"},
		{"bread"},
		{"bullet"},
		{"black"},
	};
	
	// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;
	
	// Display the simulation # is starting to the recruit. 
MainLoop:
	cout << "current simulation: " << simulations << endl;
	srand(static_cast<unsigned int>(time(0)));

	int failedRounds = 0;
	
	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	for (int i = 0; i < 3; i++)
	{
		int choice = rand() % NUM_WORDS;
		string theWord = WORDS[choice][WORD];
		//maximum number of tries before failing 
		int incorrectGuesses = 3;

		//keeps track of individual letters 
		string guessedLetters;
		//keeps track of the word entirely
		string guess;

		for (int j = 0; j < theWord.length(); j++)
		{
			//sets a place holder for letters 
			guess += '_';
		}
		
		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while (incorrectGuesses > 0 && guess != theWord)
		{
			//     Tell recruit how many incorrect guesses he or she has left
			cout << "Guesses remaining " << incorrectGuesses << endl;
			//     Show recruit the letters he or she has guessed
			cout << "Your guessed letters " << guessedLetters << endl;
			//     Show player how much of the secret word he or she has guessed
			cout << "Word so far " << guess << endl;
			//     Get recruit's next guess
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "enter your next letters" << endl;
			char letter;
			cin >> letter;
			//     While recruit has entered a letter that he or she has already guessed
			while (guessedLetters.find(letter) != string::npos)
			{
				//          Get recruit ’s guess
				cout << "you already guessed that. Please enter a new character. ";
				cin >> letter;
			}

			//     Add the new guess to the group of used letters
			guessedLetters += letter;
			
			//     If the guess is in the secret word
			if (theWord.find(letter) != string::npos)
			{
				//          Tell the recruit the guess is correct
				cout << "You have entered a correct letter" << endl;
				
				//          Update the word guessed so far with the new letter
				for (int j = 0; j < theWord.length(); j++)
				{
					if (theWord[j] == letter)
					{
						//sets the area with the corresponding letter
						guess[j] = letter;
					}
				}
			}
			//     Otherwise
			else
			{
				//          Tell the recruit the guess is incorrect
				cout << " Your guess was incorrect" << endl;
				//          Increment the number of incorrect guesses the recruit has made
				incorrectGuesses--;
			}
		}

		if (incorrectGuesses <= 0)
		{
			// alerts user to failing and proceeds to the next word
			cout << "You failed this round. The answer was " << theWord << endl;
			cout << "Moving to next round." << "\n\n";
			//adds to rounds 
			failedRounds++;
		}
		else
		{
			cout << "You have passed this round, the keyword was \n" << theWord << "\n\n";
		}
	}
	
	// If the recruit has made too many incorrect guesses
	if (failedRounds == 3)
	{
	//     Tell the recruit that he or she has failed the Keywords II course.
		cout << "You have failed this simulation " << endl;
	}
	// Otherwise
	else
	{
		//     Congratulate the recruit on guessing the secret words
		cout << "You have passed this simulation" << endl;
	}
	// Ask the recruit if they would like to run the simulation again
	cout << "would you like to run another simulation? (y/n)" << endl;
	char answer;
	cin >> answer;
	
	// If the recruit wants to run the simulation again
	if (answer == 'y' || answer == 'Y')
	{
		//     Increment the number of simulations ran counter
		simulations++;
		//     Move program execution back up to // Display the simulation # is starting to the recruit.
		goto MainLoop;
	}
	// Otherwise 
	else
	{
		//     Display End of Simulations to the recruit
		cout << "end of simulation " << endl;
		//     Pause the Simulation with press any key to continue
		system(("pause"));
	}
	return 0;
}