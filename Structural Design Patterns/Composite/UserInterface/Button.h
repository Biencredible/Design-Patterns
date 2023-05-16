#pragma once
#include "Widget.h"
class Button :
    public Widget
{
public:
    void Paint() override;
    void SetVisibility(bool visibility) override;
    void Add(Widget* pWidget) override;
    void Remove(Widget* pWidget) override;
};

