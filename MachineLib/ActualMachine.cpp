/**
 * \file ActualMachine.cpp
 *
 * \author Jonathon  Harkness
 */

#include "pch.h"
#include "ActualMachine.h"
#include "MachineOwner.h"



/**
 * \brief Constructor
 * \param machine our Machine object 
 */
CActualMachine::CActualMachine(const int &machine)
{

}


/**
 * Destructor
 */
CActualMachine::~CActualMachine()
{
}


/**
 * \brief Sets the current time for our Machine's components and motors
 * \param time as double
 */
void CActualMachine::SetTime(double time)
{
	for (auto motor : mMotor)
	{
		if (motor != nullptr)
		{
			motor->SetTime(time);
		}
		for (auto components : mComponentsInOrder)
		{
			components->SetTime(int(time));
		}
	}
}


/**
 * \brief Adds a Component to our Machine
 * \param component The component we are adding to our machine
 */
void CActualMachine::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponentsInOrder.push_back(component);
	component->SetActualMachine(this);
}


/**
 * \brief Draws our Machine at x, y
 * \param graphics provides the graphics for our machine
 * \param x X Location for Machine
 * \param y Y Location for Machine
 */
void CActualMachine::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	for (auto components : mComponentsInOrder)
	{
		components->Draw(graphics, x, y);
	}
}


/**
 * \brief adds a motor to our machine
 * \param motor Motor being added to our machine
 */
void CActualMachine::SetMotor(std::shared_ptr<CMotor> motor)
{
	mMotor.push_back(motor);
}
