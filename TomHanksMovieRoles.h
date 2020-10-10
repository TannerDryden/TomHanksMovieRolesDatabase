// Name: Tanner Dryden
// Description: This Class creates a database of tom hanks movie roles

#pragma once
#include <iostream>
#include <string>
using namespace std;

class TomHanksMovieRoles
{
private:
	// Atrributes
	string movieTitle;
	int releaseDate;
	string role;

public:

	// Constructors
	TomHanksMovieRoles()
	{
		setMovieTitle("no title stored");
		setReleaseDate(NULL);
		setRole("no role stored");
	}

	TomHanksMovieRoles(string newMovieTitle, int newReleaseDate, string newRole)
	{
		setMovieTitle(newMovieTitle);
		setReleaseDate(newReleaseDate);
		setRole(newRole);
	}

	// Accessors 
	string getMovieTitle() const
	{
		return movieTitle;
	}
	int getReleaseDate() const
	{
		return releaseDate;
	}
	string getRole() const
	{
		return role;
	}

	// Mutators
	void setMovieTitle(string newMovieTitle)
	{
		movieTitle = newMovieTitle;
	}
	void setReleaseDate(int newReleaseDate)
	{
		releaseDate = newReleaseDate;
	}
	void setRole(string newRole)
	{
		role = newRole;
	}

	// Operator overloads
	friend istream& operator >>(istream& inStream, TomHanksMovieRoles &tomHanksRole)
	{
		string inputLine;
		const char tab(9);

		getline(inStream, inputLine, tab); // try to read a title
		if(!inStream.eof()) // if the read is successful
		{
			tomHanksRole.setMovieTitle(inputLine); // store the title
			getline(inStream, inputLine, tab); // read the release year
			tomHanksRole.setReleaseDate(stoi(inputLine)); // convert to int and store
			getline(inStream, inputLine); // read the role
			tomHanksRole.setRole(inputLine); // store the role
		}
		return inStream;
	}

	friend ostream& operator <<(ostream& outStream, const TomHanksMovieRoles& tomHanksRole)
	{
		outStream << tomHanksRole.getMovieTitle() << " " << tomHanksRole.getReleaseDate() <<
			" " << tomHanksRole.getRole() << endl;
		return outStream;
	}
};