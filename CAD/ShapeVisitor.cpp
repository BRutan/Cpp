/* ShapeVisitor.cpp
Description:
	*Class derived from boost::static_visitor<void> for moving derived Shape clases (Circle, Line, Point).
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

#include<boost/variant.hpp>
#include"Circle.hpp"
#include"Line.hpp"
#include"Point.hpp"
#include"ShapeVisitor.hpp"

namespace Containers
{
	////////////////////////////
	// Constructors/Destructor: 
	////////////////////////////
	ShapeVisitor::ShapeVisitor() : m_dx(0), m_dy(0)													/* Default Constructor. */
	{

	}
	ShapeVisitor::ShapeVisitor(double dx_in, double dy_in) : m_dx(dx_in), m_dy(dy_in)				/* Overloaded Constructor. Set m_dx and m_dy. */
	{
		
	}
	ShapeVisitor::ShapeVisitor(const ShapeVisitor &sv_in) : m_dx(sv_in.m_dx), m_dy(sv_in.m_dy)		/* Copy Constructor. */
	{

	}
	ShapeVisitor::~ShapeVisitor()						/* Destructor. */
	{

	}
	////////////////////////////
	// Accessors: 
	////////////////////////////
	double ShapeVisitor::DX() const						/* Get m_dx. */
	{
		return m_dx;
	}
	double ShapeVisitor::DY() const						/* Get m_dy. */
	{
		return m_dy;
	}
	////////////////////////////
	// Mutators: 
	////////////////////////////
	void ShapeVisitor::DX(double dx_in)					/* Set m_dx. */
	{
		m_dx = dx_in;
	}
	void ShapeVisitor::DY(double dy_in)					/* Set m_dy. */
	{
		m_dy = dy_in;
	}
	////////////////////////////
	// Overloaded Operators: 
	////////////////////////////
	ShapeVisitor& ShapeVisitor::operator=(const ShapeVisitor& sv_in) /* Assignment operator. */
	{
		// Preclude self-assignment:
		if (this != &sv_in)
		{
			m_dx = sv_in.m_dx;
			m_dy = sv_in.m_dy;
		}
		return *this;
	}
	// Overloaded Visitor operators:
	void ShapeVisitor::operator () (BenRutan::CAD::Circle& circ_in)	 /* Visitor specialization for Circle class. */
	{
		// Increment X and Y coordinate in CenterPoint by m_dx and m_dy respectively:
		double xCpy = circ_in.CenterPoint().X();
		double yCpy = circ_in.CenterPoint().Y();
		circ_in.CenterPoint(BenRutan::CAD::Point(xCpy + m_dx, yCpy + m_dy));
	}
	void ShapeVisitor::operator () (BenRutan::CAD::Line& line_in)	 /* Visitor specialization for Line class. */
	{
		// Increment X and Y coordinate in each of Line's Point objects by m_dx and m_dy respectively:
		double xCpy = line_in.P1().X();
		double yCpy = line_in.P1().Y();
		line_in.P1(BenRutan::CAD::Point(xCpy + m_dx, yCpy + m_dy));
		xCpy = line_in.P2().X();
		yCpy = line_in.P2().Y();
		line_in.P2(BenRutan::CAD::Point(xCpy + m_dx, yCpy + m_dy));
	}
	void ShapeVisitor::operator () (BenRutan::CAD::Point& point_in)	 /* Point specialization for Point class. */
	{
		// Increment X and Y coordinate in Point object by m_dx and m_dy respectively:
		point_in.X(point_in.X() + m_dx);
		point_in.Y(point_in.Y() + m_dy);
	}
};