#include "AccelAdapter.h"

bool AccelAdapter::Up()
{
    return accel.GetHorizontalAxis() > 0;
}

bool AccelAdapter::Down()
{
    return accel.GetHorizontalAxis() < 0;
}

bool AccelAdapter::Left()
{
    return accel.GetHorizontalAxis() < 0;

}

bool AccelAdapter::Right()
{
    return accel.GetHorizontalAxis() > 0;
}
