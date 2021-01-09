/*******************************************
 * Author: Nick Marozick
 * Date: 10/3/17
 * Description: Ant Header File
 * *******************************************/

#ifndef ANT.HPP
#define ANT.HPP
#include <string> 
#include <iostream>
#include <cstdlib>
#include <sstream>

class Ant 
{

	private: 

	int boardSteps; 
	std::string **arr2D; 
	std::string lastSquareColor= " "; 
	std::string nextSquareColor= " "; 
	std::string direction = "north"; 
	int antXLocation; 
	int antYLocation;
	int nextSquareX; 
	int nextSquareY; 
	int lastSquareX=0; 
	int lastSquareY=0; 
	int steps;
	int rows;
	int columns;
	
	
	public: 
	
	Ant(); 
	void menuStart();
	void menuEnd();  
	void play(); //loops a full play cycle	
	void menuStepCount(); // determines amount of steps
	void menuBoardSize(); // creates board rows & columns
	void menuStartLocation(); // determines starting spot for ant
	void boardCreate(std::string**, int, int); //rows, columns from Menu
	void antCompass();//determines ant direction
	void antLocation();//projects ants forward move
	void preAntChange();
	void boardChange(int, int, int, int); //makes all live board changes
	void postAntChange(); 
	void boardPrint(); 
	void gameOver();
											  										};
											  										#endif 
