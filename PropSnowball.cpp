/**
 * \file PropSnowball.cpp
 *
 * \author Jonathon  Harkness
 *
 * Class for Constructing Snowball Prop
 */

#include "pch.h"
#include "PropSnowball.h"
#include "Timeline.h"
#include "Actor.h"

/// Ratio to convert Radians to Degrees
const double RtoD = 57.295779513;

using namespace Gdiplus;


/**
 * Constructor
 * \param name Name of the drawable
 * \param filename Image filename
 */
CPropSnowball::CPropSnowball(const std::wstring& name, const std::wstring& filename) : CImageDrawable(name, filename)
{
}


/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CPropSnowball::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Draws the head top
 * \param graphics The graphics object we are drawing on
 */
void CPropSnowball::Draw(Gdiplus::Graphics* graphics)
{
    CImageDrawable::Draw(graphics);


}

/** Set keyframe based on current status */
void CPropSnowball::SetKeyframe()
{
    CDrawable::SetKeyframe();
    mChannel.SetKeyframe(GetPosition());
}

/** Get current channel from animation system */
void CPropSnowball::GetKeyframe()
{
    CDrawable::GetKeyframe();
    if (mChannel.IsValid())
    {
        SetPosition(mChannel.GetPoint());
    }
}
/** Add the channels for this drawable to a timeline
 * \param timeline The timeline class.
 */
void CPropSnowball::SetTimeline(CTimeline* timeline)
{
    CDrawable::SetTimeline(timeline);
    timeline->AddChannel(&mChannel);
}

/**
 * \brief Set the actor. This is where we set the channel name
 * \param actor Actor to set
 */
void CPropSnowball::SetActor(CActor* actor)
{
    CImageDrawable::SetActor(actor);

    // Set the channel name
    mChannel.SetName(actor->GetName() + L":" + GetName() + L":position");

}
