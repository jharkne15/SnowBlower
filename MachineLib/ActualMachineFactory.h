/**
 * \file ActualMachineFactory.h
 *
 * \author Jonathon
 *
 * Actual Machine factory class. Creates Actual Machine objects
 */

#pragma once

#include <memory>

class CActualMachine;



/**
 * Abstract class for our Machine1(and2) factories
 */
class CActualMachineFactory
{
public:
    virtual ~CActualMachineFactory();

    /// \brief abstract function for Creating a Machine
    /// \returns 0
    virtual std::shared_ptr<CActualMachine> CreateMachine() = 0;
protected:
    CActualMachineFactory();
};

