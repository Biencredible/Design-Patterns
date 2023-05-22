#pragma once
class Widget
{
    Widget* m_pParent{};
protected:
    bool m_IsVisible{ true };
public:
    void SetParent(Widget *p)
    {
        m_pParent = p;
    }
    Widget* GetParent() { return m_pParent; }
    virtual void Paint() = 0;
    virtual void SetVisibility(bool visibility) = 0;
    virtual void Add(Widget* pWidget) = 0;
    virtual void Remove(Widget* pWidget) = 0;
    virtual ~Widget() = default;
    virtual Widget* GetFrame() { return nullptr; }
};

