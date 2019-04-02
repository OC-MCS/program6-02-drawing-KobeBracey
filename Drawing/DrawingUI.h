#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeMgr.h"
#include <iostream>
using namespace std;
using namespace sf;

class DrawingUI // Draws shapes and colors
{
private:
	RectangleShape canvas; // The canvas to draw on
public:

	// Positions
	DrawingUI(Vector2f p)
	{
		p;
	}

	// draw - Draws onto the canvas
	// win is the window to draw on
	// mgr is the shape manager
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		Vector2f canvasPos(257, 0);
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Black);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(542, 597));
		canvas.setFillColor(Color::Black);
		win.draw(canvas);

		for (unsigned int i = 0; i < mgr->getShapes().size(); i++)
		{
			mgr->getShapes()[i]->draw(win);
		}
	}


	// isMouseInCanvas - checks mouse position if it's in the canvas
	// mousePos is the mouse position
	// returns true or false if mouse in canvas
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inCanvas;

		if (canvas.getGlobalBounds().contains(mousePos))
		{
			inCanvas = true;
		}
		else
		{
			inCanvas = false;
		}

		return inCanvas;
	}
};