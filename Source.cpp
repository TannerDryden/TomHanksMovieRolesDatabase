// Name: Tanner Dryden
// Description: this program utilizes a search tree class and a tom hanks
//				movie role class to sort and output all of tom hanks movies,
//				release dates, and roles. It also searches for movie(s) in the database.
#include "BSTree.h"
#include "TomHanksMovieRoles.h"
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{	
	// instatiating search tree and tomHanksMovieRole objects
	BinSearchTree<string, TomHanksMovieRoles> tree;
	ifstream inFile;
	TomHanksMovieRoles tomHanksRole;
	
	// open file
	inFile.open("C:\\Users\\Tanner\\source\\repos\\BinarySearchTree\\TomHanksMovieRoles.txt");

	// checking open file failure
	if(!inFile){
		cout << "Unable to open file" << endl;
		exit(1); // terminate with error
	}

	// reads file and parses the data into a binary search tree
	do 
	{
 		inFile >> tomHanksRole;
		tree.insert(tomHanksRole.getMovieTitle(), tomHanksRole);
	} while (!inFile.eof());

	// close file
	inFile.close();

	// testing find function
	bool isSplashFound = tree.find("Splash", tomHanksRole);
	if (isSplashFound == true)
	{
		cout << "Splash is in the database" << endl;
	}
	bool isToyStory99Found = tree.find("Toy Story 99", tomHanksRole);
	if (isToyStory99Found == false)
	{
		cout << "Toy Story 99 is not in the database" << endl << endl;
	}

	// outputing the database to the console
	cout << tree;
}