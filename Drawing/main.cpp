//====================================
// Kobe Bracey						 
// 3/29/19							 
// Programming Assignment #6: Drawing
//====================================

#include <iostream>
#include <fstream>
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace std;
using namespace sf;

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 500; 

	fstream binaryFile;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing"); 
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr(Color::Transparent, ShapeEnum::NOTHING);
	SettingsUI settingsUI(&settingsMgr); 
	ShapeMgr shapeMgr; 
	DrawingUI drawingUI(Vector2f(200, 50)); 

	binaryFile.open("shapes.bin", ios::in | ios::binary);
	if (binaryFile)
	{
		settingsMgr.readData(binaryFile);
		shapeMgr.restoreData(binaryFile);
	}

	binaryFile.close();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				binaryFile.open("shapes.bin", ios::out | ios::binary);
				settingsMgr.writeData(binaryFile);
				shapeMgr.saveData(binaryFile);
				binaryFile.close();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos, &shapeMgr);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

				if (drawingUI.isMouseInCanvas(mousePos))
				{
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}

		window.clear();

		settingsUI.draw(window);

		drawingUI.draw(window, &shapeMgr);

		window.display();
	}

	return 0;
}