/**
 * \file ActualMachine.h
 *
 * \author Jonathon  Harkness
 *
 * A Class to Build our Actual Machine
 */

#pragma once

#include <memory>
#include <vector>
#include <string>
#include "Component.h"
#include "Motor.h"

class CMachineOwner;


/**
 * This class houses all of our machine components
 * and their functionality with CMachine.
 * A Machine can have any many components as it likes
 */
class CActualMachine
{
public:
	CActualMachine(const int &machine);
	virtual ~CActualMachine();

	/** \brief Copy constructor disabled */
	CActualMachine(const CActualMachine&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActualMachine&) = delete;


	void SetTime(double time);

	void AddComponent(std::shared_ptr<CComponent> component);

	void Draw(Gdiplus::Graphics* graphics, int x, int y);

	void SetMotor(std::shared_ptr<CMotor> motor);

private:

	/// The components in drawing order
	std::vector<std::shared_ptr<CComponent>> mComponentsInOrder;

	/// Motors for the Machine
	std::vector<std::shared_ptr<CMotor>> mMotor;
};

