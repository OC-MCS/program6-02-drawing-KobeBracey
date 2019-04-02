#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <vector>
using namespace std;
using namespace sf;

class ShapeMgr // Maintains current shapes and colors.
{
private:
	vector<DrawingShape*> shapes; // Stores shapes and colors.
public:

	// Adds shapes
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (color != Color::White)
		{
			if (whichShape == CIRCLE)
			{
				Circle *circle; // circle
				circle = new Circle(pos, color, whichShape);
				shapes.push_back(circle);
			}

			if (whichShape == SQUARE)
			{
				Square *square; // Square
				square = new Square(pos, color, whichShape);
				shapes.push_back(square);
			}
		}
	}

	// Clears shape data
	void clearShapes(ShapeMgr *mgr)
	{
		mgr->shapes.clear();
	}

	// Gets shape data
	vector<DrawingShape*> getShapes()
	{
		return shapes; // Returns shapes data.
	}

	// Saves data to binary file
	void saveData(fstream &binaryFile)
	{
		ShapeData saved; // Shapes Data.

		for (unsigned int i = 0; i < shapes.size(); i++)
		{
			saved = shapes[i]->getShapeData();
			binaryFile.write(reinterpret_cast<char*>(&saved), sizeof(saved));
		}
	}

	// Restores data when reloaded
	void restoreData(fstream &binaryFile)
	{
		ShapeData restore; // Shapes data

		while (binaryFile.read(reinterpret_cast<char*>(&restore), sizeof(restore)))
		{
			addShape(restore.pos, restore.sH, Color(restore.colorNumber));
		}
	}
};