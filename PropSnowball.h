/**
 * \file PropSnowball.h
 *
 * \author Jonathon  Harkness
 *
 * Class to Display Snowball object
 */


#pragma once
#include "ImageDrawable.h"
#include "AnimChannelPoint.h"

using namespace std;
using namespace Gdiplus;


/**
 * \brief Implements Snowballs, which have unique functionality compared
 * to HeadTop and existing Drawables
 */
class CPropSnowball :
	public CImageDrawable
{
public:

    /// Constructor
    CPropSnowball(const std::wstring& name, const std::wstring& filename);

    /// Overrides IsMovable in CDrawable, makes head movable
    /// \returns true
    virtual bool IsMovable() override { return true; }

    /// Draws Snowball at a reduced image size, overrides CDrawable
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /// Transform a point from a location on the bitmap to a location on the screen.
    Gdiplus::Point TransformPoint(Gdiplus::Point p);

    virtual void SetActor(CActor* actor) override;
    virtual void SetTimeline(CTimeline* timeline) override;
    virtual void SetKeyframe() override;
    virtual void GetKeyframe() override;

private:

    /// HeadTop's Channel
    CAnimChannelPoint mChannel;
};

