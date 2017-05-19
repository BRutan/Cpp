/* ShapeVisitor.hpp
Description:
	*Class derived from boost::static_visitor<void> for moving/changing coordinates of derived Shape clases (Circle, Line, Point).
State Variables:
	*double m_dx, m_dy: Change in x and y direction respectively.
Class Methods:
	// Constructors/Destructor:
	ShapeVisitor(): Default constructor.
	ShapeVisitor(double, double): Overloaded constructor. Set m_dx and m_dy.
	ShapeVisitor(const ShapeVisitor&): Copy constructor.
	~ShapeVisitor(): Destructor.
	// Accessors:
	double DX() const: Return m_dx.
	double DY() const: Return m_dy.
	// Mutators:
	void DX(double): Set m_dx.
	void DY(double): Set m_dy.
*/
#ifndef SHAPEVISITOR_HPP
#define SHAPEVISITOR_HPP

#include<boost\variant.hpp>
#include<iostream>
#include"Circle.hpp"
#include"Line.hpp"
#include"Point.hpp"

namespace Containers
{
	class ShapeVisitor : public boost::static_visitor<void>
	{
	private:
		////////////////////////////
		// State Variables: 
		////////////////////////////
		double m_dx, m_dy;
	public:
		////////////////////////////
		// Constructors/Destructor: 
		////////////////////////////
		ShapeVisitor();								/* Default Constructor. */
		ShapeVisitor(double, double);				/* Overloaded Constructor: set m_dx and m_dy. */
		ShapeVisitor(const ShapeVisitor&);			/* Copy Constructor. */
		virtual ~ShapeVisitor();					/* Destructor. */
		////////////////////////////
		// Accessors: 
		////////////////////////////
		double DX() const;							/* Get m_dx. */				
		double DY() const;							/* Get m_dy. */
		////////////////////////////
		// Mutators: 
		////////////////////////////
		void DX(double);							/* Set m_dx. */
		void DY(double);							/* Set m_dy. */
		////////////////////////////
		// Overloaded Operators: 
		////////////////////////////
		ShapeVisitor& operator=(const ShapeVisitor&);	/* Assignment operator. */
		// Overloaded Visitor operators:
		void operator () (BenRutan::CAD::Circle&);		/* Visitor specialization for Circle class. */
		void operator () (BenRutan::CAD::Line&);		/* Visitor specialization for Line class. */
		void operator () (BenRutan::CAD::Point&);		/* Visitor specialization for Point class. */
	};
}

#endif