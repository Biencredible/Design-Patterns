#pragma once
class Widget
{
protected:
    bool m_IsVisible{ true };
public:
    virtual void Paint() = 0;
    virtual void SetVisibility(bool visibility) = 0;
    virtual void Add(Widget* pWidget) = 0;
    virtual void Remove(Widget* pWidget) = 0;
    virtual ~Widget() = default;
};

