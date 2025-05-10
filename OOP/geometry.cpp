#include <iostream>
#include <iomanip>
#include <cmath>
#include "geometry.hpp"
using namespace std;

namespace GM
{
	const double PI = 3.141592653589793;

	void GeometryCalculator::clearScreen() const
	{
		cout << string(50, '\n') << endl;
	}

	void GeometryCalculator::printMenu() const
	{
		cout << "==============================" << endl;
		cout << "  Geometry Area Calculator" << endl;
		cout << "==============================" << endl;
		cout << "1. Circle" << endl;
		cout << "2. Rectangle" << endl;
		cout << "3. Triangle" << endl;
		cout << "0. Exit" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter your choice: " << endl;
	}

	void GeometryCalculator::run()
	{
		int choice = -1;
		Shape* shape = nullptr;

		while (true)
		{
			clearScreen();
			printMenu();
			cin >> choice;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input. Please enter a number." << endl;
				cout << "Press Enter to continue..." << endl;
				cin.ignore();
				cin.get();
				continue;
			}

			switch (choice)
			{
			case 0:
				cout << "Thank you for using the calculator!" << endl;
				return;
			case 1:
				shape = new Circle();
				break;
			case 2:
				shape = new Rectangle();
				break;
			case 3:
				shape = new Triangle();
				break;
			default:
				cout << "Invalid choice." << endl;
				cout << "Press Enter to continue..." << endl;
				cin.ignore();
				cin.get();
				continue;
			}

			shape->input();
			shape->display();
			delete shape;
			shape = nullptr;

			cout << "Press Enter to continue..." << endl;
			cin.ignore();
			cin.get();
		}
	}

	// --- Circle ---
	void Circle::input()
	{
		cout << "Enter radius: " << endl;
		cin >> radius;
	}

	double Circle::area() const
	{
		return PI * radius * radius;
	}

	void Circle::display() const
	{
		cout << fixed << setprecision(2);
		cout << "[ Circle ]" << endl;
		cout << "Radius: " << radius << endl;
		cout << "Area: " << area() << endl;
	}

	// --- Rectangle ---
	void Rectangle::input()
	{
		cout << "Enter width: " << endl;
		cin >> width;
		cout << "Enter height: " << endl;
		cin >> height;
	}

	double Rectangle::area() const
	{
		return width * height;
	}

	void Rectangle::display() const
	{
		cout << fixed << setprecision(2);
		cout << "[ Rectangle ]" << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
		cout << "Area: " << area() << endl;
	}

	// --- Triangle ---
	void Triangle::input()
	{
		cout << "Enter base: " << endl;
		cin >> base;
		cout << "Enter height: " << endl;
		cin >> height;
	}

	double Triangle::area() const
	{
		return 0.5 * base * height;
	}

	void Triangle::display() const
	{
		cout << fixed << setprecision(2);
		cout << "[ Triangle ]" << endl;
		cout << "Base: " << base << endl;
		cout << "Height: " << height << endl;
		cout << "Area: " << area() << endl;
	}
}
