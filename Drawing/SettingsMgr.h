#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE, NOTHING }; // Shape choices

class SettingsMgr // Keeps the current settings
{
private:
	Color color; // Color
	ShapeEnum shape; // Shape
public:

	// Starting shape and color
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		color = startingColor;
		shape = startingShape;
	}

	// Gets current color
	Color getCurColor()
	{
		return color; // Returns colors
	}

	// Gets current shape
	ShapeEnum getCurShape()
	{
		return shape; // Returns shapes.
	}

	// Sets the current color
	void setCurrentColor(Color setColor)
	{
		color = setColor;
	}


	// Sets the current shape
	void setCurrentShape(ShapeEnum setShape)
	{
		shape = setShape;
	}

	// Writes data into the binary file
	void writeData(fstream &binaryFile)
	{
		int colors = color.toInteger();
		binaryFile.write(reinterpret_cast<char*>(&colors), sizeof(colors));
		binaryFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}

	// Reads data into the binary file
	void readData(fstream &binaryFile)
	{
		int colors;
		binaryFile.read(reinterpret_cast<char*>(&colors), sizeof(colors));
		binaryFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));
		color = Color(colors);
	}
};