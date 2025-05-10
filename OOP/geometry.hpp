#pragma once
#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

namespace GM
{
	class Shape
	{
	public:
		virtual void input() = 0;
		virtual double area() const = 0;
		virtual void display() const = 0;
		virtual ~Shape() = default;
	};

	class Circle : public Shape
	{
	private:
		double radius;
	public:
		void input() override;
		double area() const override;
		void display() const override;
	};

	class Rectangle : public Shape
	{
	private:
		double width, height;
	public:
		void input() override;
		double area() const override;
		void display() const override;
	};

	class Triangle : public Shape
	{
	private:
		double base, height;
	public:
		void input() override;
		double area() const override;
		void display() const override;
	};

	class GeometryCalculator
	{
	public:
		void run();
	private:
		void printMenu() const;
		void clearScreen() const;
	};
}

#endif // GEOMETRY_HPP
#pragma once
