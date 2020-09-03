/**
 * \file Component.cpp
 *
 * \author Jonathon  Harkness
 */

#include "pch.h"
#include "Component.h"
#include "ActualMachine.h"

using namespace Gdiplus;


/**
 * Constructor
 */
CComponent::CComponent()
{
}


/**
 * Destructor
 */
CComponent::~CComponent()
{
}


/**
 * \brief Sets the position from the factory to mPos
 * \param x the X Position of the component
 * \param y the Y position of the component
 */
void CComponent::SetPosition(int x, int y)
{
	mPos.X = x;
	mPos.Y = y;
}


/**
 * \brief Sets the Actual Machine the component corresponds to
 * \param machine Pointer to ActualMachine adding the component
 */
void CComponent::SetActualMachine(CActualMachine *machine)
{
	mAcutalMachine = machine;
}


/**
 * \brief Sets the true location of the component
 * \param x mPos.X+draw x
 * \param y mPos.Y+draw y
 */
void CComponent::SetXandY(int x, int y)
{
	mX = x;
	mY = y;
}


/**
 * \brief Gets X
 * \returns mX
 */
int CComponent::GetX()
{
	return mX;
}


/**
 * \brief Gets Y
 * \returns mY
 */
int CComponent::GetY()
{
	return mY;
}


/**
 * Sets the current frame of our Machine
 * \param frame Current machine frame
 */
void CComponent::SetTime(int frame)
{
	mFrame = frame;
}


/**
 * \brief Draws our Component through Polygon, Sets the True X and Y
 * \param graphics component graphics
 * \param x X Location of component
 * \param y Y Location of component
 */
void CComponent::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	SetXandY(mPos.X + x, mPos.Y + y);
	DrawPolygon(graphics, mPos.X + x, mPos.Y + y);
}
