#pragma once
#include <SFML/Graphics.hpp>
#include "SettingsMgr.h"
#include <iostream>
using namespace std;
using namespace sf;

class SettingsUI // The UI for the settings
{
private:
	CircleShape redBtn; // Red button
	CircleShape greenBtn; // Green button
	CircleShape blueBtn; // Blue button
	CircleShape circleBtn; // Circle buttton
	RectangleShape squareBtn; // Square button
	SettingsMgr *sMgr; // Settings
public:


	// default constructor
	SettingsUI(SettingsMgr *mgr)
	{
		sMgr = mgr;

		Vector2f pos(80, 60);
		redBtn.setPosition(pos);
		redBtn.setRadius(25);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);

		Vector2f pos2(80, 130);
		greenBtn.setPosition(pos2);
		greenBtn.setRadius(25);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		Vector2f pos3(80, 200);
		blueBtn.setPosition(pos3);
		blueBtn.setRadius(25);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);

		Vector2f ciPos(80, 305);
		circleBtn.setPosition(ciPos);
		circleBtn.setRadius(25);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		Vector2f sqPos(83, 375);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(45, 45));
	}

	// Changes settings for what the mouse selects
	void handleMouseUp(Vector2f mouse, ShapeMgr *mgr)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Red);
		}

		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Green);
		}

		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Blue);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentShape(CIRCLE);
		}

		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentShape(SQUARE);
		}
	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	// Draws the button selection and creates text for shapes/colors
	void draw(RenderWindow& win)
	{
		Font font; // Font for text
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text color("Selected Color", font, 25); // Selected color
		color.setPosition(30, 15);

		Text shape("Selected Shape", font, 25); // Selected shape
		shape.setPosition(30, 260);

		RectangleShape line; // Line between the settings and canvas
		Vector2f linePos(250, 0);
		line.setPosition(linePos);
		line.setOutlineColor(Color::White);
		line.setOutlineThickness(2);
		line.setSize(Vector2f(0, 600));
		line.setFillColor(Color::White);

		if (sMgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else
		{
			redBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}
		else
		{
			greenBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else
		{
			blueBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else
		{
			circleBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}
		else
		{
			squareBtn.setFillColor(Color::Transparent);
		}

		win.draw(color);
		win.draw(shape);
		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(blueBtn);
		win.draw(circleBtn);
		win.draw(squareBtn);
		win.draw(line);
	}
};