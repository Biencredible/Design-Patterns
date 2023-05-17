#pragma once
#include "Widget.h"
#include <vector>

class Frame :
    public Widget
{
    std::vector<Widget*> m_Children{};
public:

    void Paint() override;
    void SetVisibility(bool visibility) override;
    void Add(Widget* pWidget) override;
    void Remove(Widget* pWidget) override;
    Widget* GetFrame() override { return this; }
    ~Frame();
};

