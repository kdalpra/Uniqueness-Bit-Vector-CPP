
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

bool is_all_lowercase(const string &s) {
	int temp = 0;
	int total = s.length();

	for(string::size_type i = s.length(); i > 0; --i){ //iterates over the string

		if(islower(s.at(i-1))){ //adds to the integer for every lower case letter found
			temp++;
		}
		else{
			temp += 0; //does not add to the integer if the letter is not lower case
		}
	}

	if(temp == total){ //if the amount of lower case letters found is equal to the amount of letters in the string, then they were all lower case
		return true;
	}
	else{
		return false;
	}
}

bool all_unique_letters(const string &s) {

	unsigned long int vector = 0; //32 bits needed
	unsigned long int setter = 0; //not used for storage

	for(string::size_type i = 0; i < s.size(); i++){ //iterates over the string
		setter = 1 << (s[i] - s[0]); //setter becomes the number 1 bit shifted left by the ith index's letter minus the first letter (in ASCII numbers)
		if((setter & vector) != 0){ //if the bitwise and operation of the setter and the vector does not equal zero, then there was a 1 in the same position in setter and vector, meaning there was a duplicate
			return false;
		}
		else{
			vector = vector | setter; //if we keep looping, then it stores the bitwise or operation of vector and setter into the vector unsigned int
		}
	}
	return true;
}

int main(int argc, char * const argv[]) {

	istringstream iss;
	string s;

	if(argc != 2){ // throws an error if there aren't exactly 2 arguments in the command line
		cerr << "Usage: " <<argv[0] <<" <string>" <<endl;
		return 1;
	}
	else{
		iss.str(argv[1]);
		iss >> s;
		if(is_all_lowercase(s) == false){ //throws an error if the string isn't only lower case letters
			cerr << "Error: String must contain only lowercase letters."<<endl;
			return 1;
		}
		else{
			if(all_unique_letters(s) == false){ //states that there was a duplicate letter found
				cout << "Duplicate letters found."<<endl;
				return 0;
			}
			else if(all_unique_letters(s) == true){ //states that every letter is unique
				cout << "All letters are unique." <<endl;
				return 0;
			}
		}
	}

}
