#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct ShapeData // Keeps track of shape data
{
	int colorNumber; // Shape color
	Vector2f pos; // Shape position
	ShapeEnum sH; // Shape selected
};

class DrawingShape // Draws shapes
{
private:
	Vector2f location; // Shape location
	Color color; // Shape color
	ShapeEnum shape; // Shape selected
	ShapeData shapeData; // Shape Data
public:

	// Constructor for shape data
	DrawingShape(Vector2f loc, Color col, ShapeEnum sH)
	{
		location = loc;
		color = col;
		shape = sH;

		shapeData.colorNumber = col.toInteger();
		shapeData.pos = loc;
		shapeData.sH = sH;
	}

	virtual void draw(RenderWindow &win) = 0;

	// Gets shape gata
	ShapeData getShapeData()
	{
		return shapeData; // returns shape data.
	}
};

class Circle : public DrawingShape // Draws circles
{
private:
	CircleShape circle;
public:

	// Sets circle size
	Circle(Vector2f loc, Color col, ShapeEnum sH) : DrawingShape(loc, col, sH)
	{
		circle.setPosition(loc);
		circle.setRadius(5);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(col);
		circle.setFillColor(col);
	}

	// Draws the circle
	void draw(RenderWindow &win)
	{
		win.draw(circle);
	}
};

class Square : public DrawingShape // Draws squares
{
private:
	RectangleShape square;
public:

	// Sets square size info
	Square(Vector2f loc, Color col, ShapeEnum sH) : DrawingShape(loc, col, sH)
	{
		square.setPosition(loc);
		square.setOutlineColor(col);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(8, 8));
		square.setFillColor(col);
	}

	// Draws the square
	void draw(RenderWindow &win)
	{
		win.draw(square);
	}
};