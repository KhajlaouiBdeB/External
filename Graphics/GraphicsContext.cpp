#include "Graphics/GraphicsContext.h"

#include <cassert>

#include "raylib.h"
#include "raygui.h"

namespace Graphics
{
    using namespace Common;

    static GraphicsContext g_instance;

    GraphicsContext& GraphicsContext::Instance()
    {
        return g_instance;
    }

    GraphicsContext::GraphicsContext()
        : m_PenColor(colors[black]),
          m_PenThickness(1.0f),
          m_BrushColor(colors[black]),
          m_bBrushHollow(false),
          m_TextColor(colors[black]),
          m_bDrawing(false)
    {
    }

    static Color ToRaylibColor(GfxColor c)
    {
        return Color{c.r, c.g, c.b, c.a};
    }

    static Rectangle ToRaylibRect(const Rect2D& r)
    {
        return Rectangle{(float)r.x, (float)r.y, (float)r.w, (float)r.h};
    }

    void GraphicsContext::GuiPanel(Rect2D bounds, const char* text)
    {
        ::GuiPanel(ToRaylibRect(bounds), text);
    }

    void GraphicsContext::GuiLabel(Rect2D bounds, const char* text)
    {
        ::GuiLabel(ToRaylibRect(bounds), text);
    }

    bool GraphicsContext::GuiButton(Rect2D bounds, const char* text)
    {
        return ::GuiButton(ToRaylibRect(bounds), text) != 0;
    }

    void GraphicsContext::GuiCheckBox(Rect2D bounds, const char* text, bool* checked)
    {
        ::GuiCheckBox(ToRaylibRect(bounds), text, checked);
    }

    void GraphicsContext::GuiListView(Rect2D bounds, const char* text, int* scrollIndex, int* active)
    {
        ::GuiListView(ToRaylibRect(bounds), text, scrollIndex, active);
    }

    void GraphicsContext::BlackPen()
    {
        m_PenColor = colors[black];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::WhitePen()
    {
        m_PenColor = colors[white];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::RedPen()
    {
        m_PenColor = colors[red];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::GreenPen()
    {
        m_PenColor = colors[green];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::BluePen()
    {
        m_PenColor = colors[blue];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::GreyPen()
    {
        m_PenColor = colors[grey];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::PinkPen()
    {
        m_PenColor = colors[pink];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::YellowPen()
    {
        m_PenColor = colors[yellow];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::OrangePen()
    {
        m_PenColor = colors[orange];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::PurplePen()
    {
        m_PenColor = colors[purple];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::BrownPen()
    {
        m_PenColor = colors[brown];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::DarkGreenPen()
    {
        m_PenColor = colors[dark_green];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::LightBluePen()
    {
        m_PenColor = colors[light_blue];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::LightGreyPen()
    {
        m_PenColor = colors[light_grey];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::LightPinkPen()
    {
        m_PenColor = colors[light_pink];
        m_PenThickness = 1.0f;
    }

    void GraphicsContext::ThickBlackPen()
    {
        m_PenColor = colors[black];
        m_PenThickness = 2.0f;
    }

    void GraphicsContext::ThickWhitePen()
    {
        m_PenColor = colors[white];
        m_PenThickness = 2.0f;
    }

    void GraphicsContext::ThickRedPen()
    {
        m_PenColor = colors[red];
        m_PenThickness = 2.0f;
    }

    void GraphicsContext::ThickGreenPen()
    {
        m_PenColor = colors[green];
        m_PenThickness = 2.0f;
    }

    void GraphicsContext::ThickBluePen()
    {
        m_PenColor = colors[blue];
        m_PenThickness = 2.0f;
    }

    void GraphicsContext::BlackBrush()
    {
        m_BrushColor = colors[black];
        m_bBrushHollow = false;
    }

    void GraphicsContext::WhiteBrush()
    {
        m_BrushColor = colors[white];
        m_bBrushHollow = false;
    }

    void GraphicsContext::HollowBrush()
    {
        m_bBrushHollow = true;
    }

    void GraphicsContext::GreenBrush()
    {
        m_BrushColor = colors[green];
        m_bBrushHollow = false;
    }

    void GraphicsContext::RedBrush()
    {
        m_BrushColor = colors[red];
        m_bBrushHollow = false;
    }

    void GraphicsContext::BlueBrush()
    {
        m_BrushColor = colors[blue];
        m_bBrushHollow = false;
    }

    void GraphicsContext::GreyBrush()
    {
        m_BrushColor = colors[grey];
        m_bBrushHollow = false;
    }

    void GraphicsContext::BrownBrush()
    {
        m_BrushColor = colors[brown];
        m_bBrushHollow = false;
    }

    void GraphicsContext::YellowBrush()
    {
        m_BrushColor = colors[yellow];
        m_bBrushHollow = false;
    }

    void GraphicsContext::LightBlueBrush()
    {
        m_BrushColor = colors[light_blue];
        m_bBrushHollow = false;
    }

    void GraphicsContext::DarkGreenBrush()
    {
        m_BrushColor = colors[dark_green];
        m_bBrushHollow = false;
    }

    void GraphicsContext::OrangeBrush()
    {
        m_BrushColor = colors[orange];
        m_bBrushHollow = false;
    }

    //--------------------------- Window lifecycle

    void GraphicsContext::InitWindow(int width, int height, const char* title)
    {
        ::InitWindow(width, height, title);
    }

    void GraphicsContext::CloseWindow()
    {
        ::CloseWindow();
    }

    void GraphicsContext::SetTargetFPS(int fps)
    {
        ::SetTargetFPS(fps);
    }

    bool GraphicsContext::WindowShouldClose()
    {
        return ::WindowShouldClose();
    }

    int GraphicsContext::GetScreenHeight()
    {
        return ::GetScreenHeight();
    }

    void GraphicsContext::StartDrawing()
    {
        assert(!m_bDrawing);

        m_bDrawing = true;

        BeginDrawing();

        BlackPen();
        BlackBrush();
        m_TextColor = colors[black];
    }

    void GraphicsContext::ClearBackground(GfxColor color)
    {
        ::ClearBackground(ToRaylibColor(color));
    }

    void GraphicsContext::StopDrawing()
    {
        assert(m_bDrawing);

        m_bDrawing = false;

        EndDrawing();
    }

    //---------------------------Text

    void GraphicsContext::TextAtPos(int x, int y, const std::string& s)
    {
        DrawText(s.c_str(), x, y, 10, ToRaylibColor(m_TextColor));
    }

    void GraphicsContext::TextAtPos(double x, double y, const std::string& s)
    {
        DrawText(s.c_str(), (int)x, (int)y, 10, ToRaylibColor(m_TextColor));
    }

    void GraphicsContext::TextAtPos(Vector2D pos, const std::string& s)
    {
        DrawText(s.c_str(), (int)pos.x, (int)pos.y, 10, ToRaylibColor(m_TextColor));
    }

    void GraphicsContext::TextColor(int color)
    {
        assert(color < NumColors);
        m_TextColor = colors[color];
    }

    void GraphicsContext::TextColor(int r, int g, int b)
    {
        m_TextColor = GfxColor{(unsigned char)r, (unsigned char)g, (unsigned char)b, 255};
    }

    //----------------------------pixels
    void GraphicsContext::DrawDot(Vector2D pos, GfxColor color)
    {
        DrawPixel((int)pos.x, (int)pos.y, ToRaylibColor(color));
    }

    void GraphicsContext::DrawDot(int x, int y, GfxColor color)
    {
        DrawPixel(x, y, ToRaylibColor(color));
    }

    //-------------------------Line Drawing

    void GraphicsContext::Line(Vector2D from, Vector2D to)
    {
        DrawLineEx(Vector2{(float)from.x, (float)from.y}, Vector2{(float)to.x, (float)to.y}, m_PenThickness, ToRaylibColor(m_PenColor));
    }

    void GraphicsContext::Line(int a, int b, int x, int y)
    {
        DrawLineEx(Vector2{(float)a, (float)b}, Vector2{(float)x, (float)y}, m_PenThickness, ToRaylibColor(m_PenColor));
    }

    void GraphicsContext::Line(double a, double b, double x, double y)
    {
        DrawLineEx(Vector2{(float)a, (float)b}, Vector2{(float)x, (float)y}, m_PenThickness, ToRaylibColor(m_PenColor));
    }

    void GraphicsContext::PolyLine(const std::vector<Vector2D>& points)
    {
        // make sure we have at least 2 points
        if (points.size() < 2)
            return;

        for (unsigned int p = 1; p < points.size(); ++p)
        {
            Line(points[p - 1], points[p]);
        }
    }

    void GraphicsContext::LineWithArrow(Vector2D from, Vector2D to, double size)
    {
        Vector2D norm = Vec2DNormalize(to - from);

        // calculate where the arrow is attached
        Vector2D CrossingPoint = to - (norm * size);

        // calculate the two extra points required to make the arrowhead
        Vector2D ArrowPoint1 = CrossingPoint + (norm.Perp() * 0.4f * size);
        Vector2D ArrowPoint2 = CrossingPoint - (norm.Perp() * 0.4f * size);

        // draw the line
        Line(from, CrossingPoint);

        // draw the arrowhead (filled with the currently selected brush)
        DrawTriangle(Vector2{(float)ArrowPoint1.x, (float)ArrowPoint1.y},
                     Vector2{(float)to.x, (float)to.y},
                     Vector2{(float)ArrowPoint2.x, (float)ArrowPoint2.y},
                     ToRaylibColor(m_bBrushHollow ? m_PenColor : m_BrushColor));
    }

    void GraphicsContext::Cross(Vector2D pos, int diameter)
    {
        Line((int)pos.x - diameter, (int)pos.y - diameter, (int)pos.x + diameter, (int)pos.y + diameter);
        Line((int)pos.x - diameter, (int)pos.y + diameter, (int)pos.x + diameter, (int)pos.y - diameter);
    }

    //---------------------Geometry drawing methods

    void GraphicsContext::Rect(int left, int top, int right, int bot)
    {
        if (!m_bBrushHollow)
        {
            DrawRectangle(left, top, right - left, bot - top, ToRaylibColor(m_BrushColor));
        }
        DrawRectangleLinesEx(Rectangle{(float)left, (float)top, (float)(right - left), (float)(bot - top)}, m_PenThickness, ToRaylibColor(m_PenColor));
    }

    void GraphicsContext::Rect(double left, double top, double right, double bot)
    {
        Rect((int)left, (int)top, (int)right, (int)bot);
    }

    void GraphicsContext::ClosedShape(const std::vector<Vector2D>& points)
    {
        if (points.empty())
            return;

        if (!m_bBrushHollow && points.size() >= 3)
        {
            std::vector<Vector2> fan(points.size());
            for (size_t p = 0; p < points.size(); ++p)
            {
                fan[p] = Vector2{(float)points[p].x, (float)points[p].y};
            }
            DrawTriangleFan(fan.data(), (int)fan.size(), ToRaylibColor(m_BrushColor));
        }

        for (unsigned int p = 1; p < points.size(); ++p)
        {
            Line(points[p - 1], points[p]);
        }

        Line(points[points.size() - 1], points[0]);
    }

    void GraphicsContext::Circle(Vector2D pos, double radius)
    {
        Circle((int)pos.x, (int)pos.y, radius);
    }

    void GraphicsContext::Circle(double x, double y, double radius)
    {
        Circle((int)x, (int)y, radius);
    }

    void GraphicsContext::Circle(int x, int y, double radius)
    {
        if (!m_bBrushHollow)
        {
            DrawCircle(x, y, (float)radius, ToRaylibColor(m_BrushColor));
        }
        DrawCircleLines(x, y, (float)radius, ToRaylibColor(m_PenColor));
    }

    void GraphicsContext::SetPenColor(int color)
    {
        assert(color < NumColors);

        switch (color)
        {
        case black:
            BlackPen();
            return;

        case white:
            WhitePen();
            return;
        case red:
            RedPen();
            return;
        case green:
            GreenPen();
            return;
        case blue:
            BluePen();
            return;
        case pink:
            PinkPen();
            return;
        case grey:
            GreyPen();
            return;
        case yellow:
            YellowPen();
            return;
        case orange:
            OrangePen();
            return;
        case purple:
            PurplePen();
            return;
        case brown:
            BrownPen();
            return;
        case light_blue:
            LightBluePen();
            return;
        case light_grey:
            LightGreyPen();
            return;
        case light_pink:
            LightPinkPen();
            return;
        } // end switch
    }
} // namespace Graphics