/********************************************************
 * Author: Nick Marozick
 * Date: 10/8/17
 * Description: Ant Class Implementation File
 * *****************************************************/

#include "ant.hpp"
#include <iostream> 
#include <string>
#include <cstdlib>
#include <sstream>
using std::cout; 
using std::cin; 
using std::endl; 

/***********************************************************
 * Ant::Ant()- Ant Default Constructor
 * *******************************************************/

Ant::Ant()
{
	steps = 3;
	rows = 3;
	columns = 3;
	antYLocation = 1;
	antXLocation = 1;
}


/**********************************************************************************
 * void Ant::menuStart
 * ********************************************************************************/


void Ant::menuStart()
{
std::string stringInput= ""; 
int value= 0;

do
{
std::cout << "Langston's Ant" << "\n";
std::cout << "Enter 1 to Start:" <<  "\n";
std::cout << "Enter 2 to Quit:" << "\n"; 

getline(cin, stringInput); 
std::stringstream input(stringInput); 
input >> value;
} while ((value != 1) && (value!=2)) ;

if (value==1)
{
Ant antboardStart;

antboardStart.play(); 
} 

}

/*******************************************************************************
 * void Ant::menuBoardSize()- asks user for size of the board, both columns and rows
 * ********************************************************************************/

void Ant::menuBoardSize()

{

int r; //for rows
int c; //for columns
std::string rowInput= "";
std::string columnInput= ""; 

			
	do
	{
	std::cout << "What should be the size of the board? " << "\n"; 
	std::cout << "Enter int value between 3 and 80 for rows: " << "\n";
	std::getline(cin, rowInput);
	std::stringstream rowValue(rowInput);
	rowValue >> r;  
	} while (r<3 || r>80);  // youtube;
	
																						rows = r;
	
	std::cout << "rows: " << rows << "\n"; 
																						do
	{
	std::cout << "Input int value between 3 and 80 for columns: " << "\n";
	std::getline(cin, columnInput);
	std::stringstream columnValue(columnInput);
	columnValue >> c; 
	}  while (c<3 || c>80); 
																						columns = c;

	std::cout << "columns: " << columns << "\n"; 

}	


/**************************************************************
 * void Ant::play()
 * ***********************************************************/

void Ant::play() 
{
	
	menuBoardSize(); 

	arr2D = new std::string*[rows];//per tutorial 
	for (int i=0; i <rows; i++)
	{	arr2D[i]= new std::string [columns];} 

	menuStepCount();

	menuStartLocation(); 

	boardCreate(arr2D, rows, columns);
	
	for (boardSteps= 0; boardSteps<steps; boardSteps++)
	{  
 	antCompass(); 
	
	antLocation(); 

	preAntChange(); 

	boardChange(lastSquareX, lastSquareY, nextSquareX, nextSquareY); 

	postAntChange(); 

	boardPrint();
 	}

	menuEnd(); 
		
}
																					/****************************************************************
void Ant::menuStepCount()- asks user for how many steps the ant
should move
***************************************************************/
																					void Ant::menuStepCount()
{
std::string stepInput; 																			int s; 

	do
	{																					std::cout << "How many steps for the ant?" << "\n";
	std::getline(cin, stepInput);
	std::stringstream input (stepInput);
	input >> s; 
	}  while (s<1);
																						steps = s;

	std::cout << "steps: " << steps << "\n"; 
}

																					/***************************************************************************
void Ant::menuStartLocation()- prompts the user for a start location by
user choice or random start 																		***************************************************************************/
																					void Ant::menuStartLocation()
{
int answer;
std::string userAnswer;
std::string userRow;
std::string userColumn;
int aSColumn; 
int aSRow; 
	
	
	do 
	{
	std::cout << "Extra Credit: Would you like a random start location for the ant?" << "\n";
																						std::cout << "Enter 1 for Yes" << "\n";
																						std::cout << "Enter 2 for No" << "\n";
																						std::getline(cin, userAnswer);
	std::stringstream uA (userAnswer);
	uA >> answer; 	 
	} 
	while (answer != 1 && answer != 2);
																						
	if (answer == 1)
	{
		antYLocation = rand() % rows + 1;
		antXLocation = rand() % columns + 1;
	}
																							if (answer == 2)
		{
		
		do
		{
		std::cout << "Enter ant starting x value (column) location: " << "\n"; 
	
		std::getline(cin, userColumn); 
		std::stringstream uC (userColumn);  
		uC >> aSColumn;
		}  while (aSColumn<0 || (aSColumn>(columns-1)));
 		
		antXLocation= aSColumn; 


		do
		{
		std::cout << "Enter ant starting y value (row) location: " << "\n";
																							std::getline(cin, userRow);
		std::stringstream uR (userRow); 
		uR >> aSRow; 
		}  while (aSRow<0 || (aSRow>(rows-1))); 
	
		antYLocation= aSRow;  
		
	}

std::cout << "antXLocation: " << antXLocation << "\n"; 
std::cout << "antYLocation: " << antYLocation << "\n"; 

}
																					/************************************************************************
* void Ant::boardCreate- takes the user inputted rows and columns for 
* the dynamic 2D array and builds out the board
*************************************************************************/
																					void Ant::boardCreate(std::string **arr2D, int r, int c) // array, rows, and column
{

	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
		{
		arr2D[i][j] = " "; 
		}
	}
}
	
/****************************************************************************
void Ant::antCompass()- based on the landing square, determines the ants
next direction	
****************************************************************************/

void Ant::antCompass()
{
																					std::string newDirection; //shouldn't need from values set initially = north;

std::cout << "initial direction: " << direction << "\n"; //testing 
																						if (direction == "north" && nextSquareColor == " ")
	{
	newDirection = "east";
	}
																						if (direction == "north" && nextSquareColor == "#")
	{
	newDirection = "west";
	}
	
	if (direction == "east" && nextSquareColor == " ")
	{
	newDirection = "south";
	}
	if (direction == "east" && nextSquareColor == "#")
	{
	newDirection = "north";
	}

	if (direction == "south" && nextSquareColor == " ")
	{
	newDirection = "west";
	}
																						if (direction == "south" && nextSquareColor == "#")
	{
	newDirection = "east";
	}

	if (direction == "west" && nextSquareColor == " ")
	{
	newDirection = "north";
	}

	if (direction == "west" && nextSquareColor == "#")
	{
	newDirection = "south";
	}
								
	direction = newDirection; 

}

/********************************************************************
void Ant::antLocation()- notes the current ant location and projects
the next square it will take
*********************************************************************/
																	                     		void Ant::antLocation()
{
																	                     			if (direction == "north")
	{	
	nextSquareY = antYLocation-1;
	}																																                     								if (direction == "east")
	{
	nextSquareX = antXLocation+1;
	}
							                     													if (direction == "south")
	{
	nextSquareY = antYLocation+1;
	}
		                     																		if (direction == "west")
	{
	nextSquareX = antXLocation-1;
	}
	
	
	if (nextSquareY < 0)
	{
	nextSquareY = 2;
	}


	if (nextSquareY > rows)
	{
	nextSquareY = rows - 2;
	}
	

	if (nextSquareX < 0)
	{
	nextSquareX = 2;
	}

	if (nextSquareX > columns)
	{
	nextSquareX = columns - 2;
	}
		
}

/*******************************************************************************
void Ant::preAntChange()- gets the next square color and stories it, which is 
used to determine ant's next direction. It also logs the ant's current square, 
prior to the move so that the square color can be changed in next function once 
the ant has moved
********************************************************************************/
																					void Ant::preAntChange() 

{
																					if (arr2D[nextSquareY][nextSquareX] == " ")
{
nextSquareColor = " ";
}
																					if (arr2D[nextSquareY][nextSquareX] == "#")
{																					nextSquareColor = "#";
}	   
																					lastSquareX = antXLocation;
lastSquareY = antYLocation; 
}

/*****************************************************************
* void Ant::boardChange() - updates/changes the board values
******************************************************************/
																					void Ant::boardChange(int lastSquareX, int lastSquareY, int nextSquareX, int nextSquareY) 
{			
	
	std::cout << "last Square X: " << lastSquareX << "\n"; 

	std::cout << "last Square Y: " << lastSquareY << "\n"; 

	arr2D[nextSquareY][nextSquareX]="*"; 

	antXLocation= nextSquareX; //just added

	antYLocation= nextSquareY; //just added

    
	if (boardSteps>0 && lastSquareColor == " ")
	{
	arr2D[lastSquareY][lastSquareX] = "#";
	}
	
	if (boardSteps>0 && lastSquareColor == "#")
	{
	arr2D[lastSquareY][lastSquareX] = " "; 
	}
	
	std::cout << "X Location: " << nextSquareX << "\n"; 

	std::cout << "Y Location: " << nextSquareY << "\n";  	
}	

/***************************************************************************************
void Ant::postAntChange()- The ant has moved to a new position. Stores the string value 
(color) of the square so that it can be changed once the ant moves again
*****************************************************************************************/
																					void Ant::postAntChange()
{
	lastSquareColor = nextSquareColor; //
}
																					/***********************************************************************
void Ant::boardPrint(&columns) - prints the board after every ant move
***********************************************************************/
																					void Ant::boardPrint() //might need board 
{
	for (int h = 0; h < columns; h++)
	{
	std::cout << "--";
	}
																						std::cout << "\n";
																						for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{	if (j==(columns-1)) 
			{std::cout << "\n";}
			std::cout << arr2D[i][j];}
	}
				
	std::cout << "\n";
																						for (int k = 0; k < columns; k++)
	{
	std::cout << "--";
	}
	
	std::cout << "\n";
}
	 
/************************************************************************
 * void menuEnd(); 
 * *********************************************************************/

void Ant::menuEnd()
{
std::string stringInput= ""; 
int value= 0;

do
{
std::cout << "Langston's Ant" << "\n";
std::cout << "Enter 1 to Play Again:" <<  "\n";
std::cout << "Enter 2 to Quit:" << "\n"; 

getline(cin, stringInput); 
std::stringstream input(stringInput); 
input >> value;
} while ((value != 1) && (value!=2)) ;

if (value==1)
{
Ant antboardStart;

antboardStart.play(); 
} 

}

/*************************************************************************
void Ant::gameOver()- clears the board memory and pulls up menu option to quit
or play again
**************************************************************************/
																					void Ant::gameOver()
{
	for (int i = 0; i<rows; i++)
	{
	delete[] arr2D[i];
	}
																						delete[] arr2D;

	**arr2D=nullptr; 
}

