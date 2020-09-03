/**
 * \file Component.h
 *
 * \author Jonathon  Harkness
 *
 * Derived Polygon Class to manipulate our Machine Components
 */

#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Polygon.h"

class CActualMachine;


/**
 *	\brief Components Hold the shared functionality of
 *		Shapes SnowBlowers Motors Pulleys. 
 *		They can be added to Actual Machine objects
 */
class CComponent : public CPolygon
{
public:
	CComponent();
	virtual ~CComponent();

	/** \brief Copy constructor disabled */
	CComponent(const CComponent&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CComponent&) = delete;

	void SetPosition(int x, int y);

	void SetActualMachine(CActualMachine *machine);

	void SetXandY(int x, int y);

	int GetX();

	int GetY();

	virtual void SetTime(int frame);

	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
private:
	/// Component Position Set by the Factory
	Gdiplus::Point mPos;

	/// True X Location of our component
	int mX = 0;

	/// True Y Location of our component
	int mY = 0;
	/// The actor using this drawable
	CActualMachine* mAcutalMachine = nullptr;

	/// Our Current Frame
	int mFrame = 0;

};

