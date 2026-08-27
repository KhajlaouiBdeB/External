#ifndef GRAPHICS_CONTEXT_H
#define GRAPHICS_CONTEXT_H
//------------------------------------------------------------------------
//
//  Name:   GraphicsContext.h
//
//  Desc:   A singleton class that mimics the old GDI-based drawing helper
//          but is backed entirely by raylib. Call each method using the
//          #define for gfx. eg gfx.Line(10, 20, 300, 300)
//          gfx.StartDrawing()/StopDrawing() wrap raylib's own
//          BeginDrawing()/EndDrawing() for the whole frame - call them
//          once per frame, before/after everything else is drawn.
//
//          Kept free of raylib.h on purpose - GfxColor is our own POD,
//          converted to/from raylib's Color only inside GraphicsContext.cpp,
//          so nothing that merely calls gfx.* needs to see raylib types.
//------------------------------------------------------------------------
#include <string>
#include <vector>

#include "2D/Vector2D.h"
#include "2D/Rect2D.h"

//------------------------------- define some colors
namespace Common
{
    struct GfxColor
    {
        unsigned char r = 0, g = 0, b = 0, a = 255;
    };

    const int NumColors = 15;

    const GfxColor colors[NumColors] =
        {
            GfxColor{255, 0, 0, 255},     // red
            GfxColor{0, 0, 255, 255},     // blue
            GfxColor{0, 255, 0, 255},     // green
            GfxColor{0, 0, 0, 255},       // black
            GfxColor{255, 200, 200, 255}, // pink
            GfxColor{200, 200, 200, 255}, // grey
            GfxColor{255, 255, 0, 255},   // yellow
            GfxColor{255, 170, 0, 255},   // orange
            GfxColor{255, 0, 170, 255},   // purple
            GfxColor{133, 90, 0, 255},    // brown
            GfxColor{255, 255, 255, 255}, // white
            GfxColor{0, 100, 0, 255},     // dark green
            GfxColor{0, 255, 255, 255},   // light blue
            GfxColor{200, 200, 200, 255}, // light grey
            GfxColor{255, 230, 230, 255}  // light pink
    };

    // Convenience constants for callers that need a color raylib itself would
    // have handed them (e.g. WHITE/BLANK) without depending on raylib.h.
    const GfxColor GfxWhite{255, 255, 255, 255};
    const GfxColor GfxBlank{0, 0, 0, 0};

    // make life easier on the fingers
#define gfx Common::GraphicsContext::Instance()

    class GraphicsContext
    {
        GraphicsContext(const GraphicsContext&) = delete;
        GraphicsContext& operator=(const GraphicsContext&) = delete;

      public:
        int NumPenColors() const
        {
            return NumColors;
        }

        // enumerate some colors
        enum ColorIndex
        {
            red,
            blue,
            green,
            black,
            pink,
            grey,
            yellow,
            orange,
            purple,
            brown,
            white,
            dark_green,
            light_blue,
            light_grey,
            light_pink,
            hollow
        };

      private:
        // current pen (outline) state
        GfxColor m_PenColor;
        float m_PenThickness;

        // current brush (fill) state
        GfxColor m_BrushColor;
        bool m_bBrushHollow;

        // current text color
        GfxColor m_TextColor;

        bool m_bDrawing;

      public:
        static GraphicsContext& Instance();
        GraphicsContext();

        ~GraphicsContext()
        {
        }

        void BlackPen();
        void WhitePen();
        void RedPen();
        void GreenPen();
        void BluePen();
        void GreyPen();
        void PinkPen();
        void YellowPen();
        void OrangePen();
        void PurplePen();
        void BrownPen();

        void DarkGreenPen();
        void LightBluePen();
        void LightGreyPen();
        void LightPinkPen();

        void ThickBlackPen();
        void ThickWhitePen();
        void ThickRedPen();
        void ThickGreenPen();
        void ThickBluePen();

        void BlackBrush();
        void WhiteBrush();
        void HollowBrush();
        void GreenBrush();
        void RedBrush();
        void BlueBrush();
        void GreyBrush();
        void BrownBrush();
        void YellowBrush();
        void LightBlueBrush();
        void DarkGreenBrush();
        void OrangeBrush();

        //--------------------------- Window lifecycle

        // wraps raylib's InitWindow()
        void InitWindow(int width, int height, const char* title);

        // wraps raylib's CloseWindow()
        void CloseWindow();

        // wraps raylib's SetTargetFPS()
        void SetTargetFPS(int fps);

        // wraps raylib's WindowShouldClose()
        bool WindowShouldClose();

        // wraps raylib's GetScreenHeight()
        int GetScreenHeight();

        //--------------------------- raygui widgets
        // Implemented in GraphicsContext.cpp so raygui.h stays out of this header.
        // Rect2D (not raylib's Rectangle) keeps raylib/raygui types from leaking to callers.
        void GuiPanel(Rect2D bounds, const char* text);
        void GuiLabel(Rect2D bounds, const char* text);
        bool GuiButton(Rect2D bounds, const char* text);
        void GuiCheckBox(Rect2D bounds, const char* text, bool* checked);
        void GuiListView(Rect2D bounds, const char* text, int* scrollIndex, int* active);

        // ALWAYS call this once, before drawing anything else in the frame.
        // Wraps raylib's BeginDrawing().
        void StartDrawing();

        // clears the frame to the given color. Wraps raylib's ClearBackground().
        void ClearBackground(GfxColor color);

        // ALWAYS call this once, after everything else in the frame has been
        // drawn. Wraps raylib's EndDrawing().
        void StopDrawing();

        //---------------------------Text

        void TextAtPos(int x, int y, const std::string& s);

        void TextAtPos(double x, double y, const std::string& s);

        void TextAtPos(Vector2D pos, const std::string& s);

        // raylib always draws text with a transparent background, so these are no-ops
        // kept for API compatibility with the old GDI-backed version
        void TransparentText()
        {
        }

        void OpaqueText()
        {
        }

        void TextColor(int color);
        void TextColor(int r, int g, int b);

        //----------------------------pixels
        void DrawDot(Vector2D pos, GfxColor color);

        void DrawDot(int x, int y, GfxColor color);

        //-------------------------Line Drawing

        void Line(Vector2D from, Vector2D to);

        void Line(int a, int b, int x, int y);

        void Line(double a, double b, double x, double y);

        void PolyLine(const std::vector<Vector2D>& points);

        void LineWithArrow(Vector2D from, Vector2D to, double size);

        void Cross(Vector2D pos, int diameter);

        //---------------------Geometry drawing methods

        void Rect(int left, int top, int right, int bot);

        void Rect(double left, double top, double right, double bot);

        void ClosedShape(const std::vector<Vector2D>& points);

        void Circle(Vector2D pos, double radius);

        void Circle(double x, double y, double radius);

        void Circle(int x, int y, double radius);

        void SetPenColor(int color);
    };

} // namespace Common

#endif