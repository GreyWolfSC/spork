#pragma once

#include <gccore.h>

/// <summary>
/// X11 color values
/// </summary>
namespace colors
{
	static constexpr GXColor AliceBlue = (GXColor) { 0xF0, 0xF8, 0xFF, 0xFF };
	static constexpr GXColor AntiqueWhite = (GXColor) { 0xFA, 0xEB, 0xD7, 0xFF };
	static constexpr GXColor Aqua = (GXColor) { 0x00, 0xFF, 0xFF, 0xFF };
	static constexpr GXColor Aquamarine = (GXColor) { 0x7F, 0xFF, 0xD4, 0xFF };
	static constexpr GXColor Azure = (GXColor) { 0xF0, 0xFF, 0xFF, 0xFF };
	static constexpr GXColor Beige = (GXColor) { 0xF5, 0xF5, 0xDC, 0xFF };
	static constexpr GXColor Bisque = (GXColor) { 0xFF, 0xE4, 0xC4, 0xFF };
	static constexpr GXColor Black = (GXColor) { 0x00, 0x00, 0x00, 0xFF };
	static constexpr GXColor BlanchedAlmond = (GXColor) { 0xFF, 0xEB, 0xCD, 0xFF };
	static constexpr GXColor Blue = (GXColor) { 0x00, 0x00, 0xFF, 0xFF };
	static constexpr GXColor BlueViolet = (GXColor) { 0x8A, 0x2B, 0xE2, 0xFF };
	static constexpr GXColor Brown = (GXColor) { 0xA5, 0x2A, 0x2A, 0xFF };
	static constexpr GXColor BurlyWood = (GXColor) { 0xDE, 0xB8, 0x87, 0xFF };
	static constexpr GXColor CadetBlue = (GXColor) { 0x5F, 0x9E, 0xA0, 0xFF };
	static constexpr GXColor Chartreuse = (GXColor) { 0x7F, 0xFF, 0x00, 0xFF };
	static constexpr GXColor Chocolate = (GXColor) { 0xD2, 0x69, 0x1E, 0xFF };
	static constexpr GXColor Coral = (GXColor) { 0xFF, 0x7F, 0x50, 0xFF };
	static constexpr GXColor CornflowerBlue = (GXColor) { 0x64, 0x95, 0xED, 0xFF };
	static constexpr GXColor Cornsilk = (GXColor) { 0xFF, 0xF8, 0xDC, 0xFF };
	static constexpr GXColor Crimson = (GXColor) { 0xDC, 0x14, 0x3C, 0xFF };
	static constexpr GXColor Cyan = (GXColor) { 0x00, 0xFF, 0xFF, 0xFF };
	static constexpr GXColor DarkBlue = (GXColor) { 0x00, 0x00, 0x8B, 0xFF };
	static constexpr GXColor DarkCyan = (GXColor) { 0x00, 0x8B, 0x8B, 0xFF };
	static constexpr GXColor DarkGoldenrod = (GXColor) { 0xB8, 0x86, 0x0B, 0xFF };
	static constexpr GXColor DarkGray = (GXColor) { 0xA9, 0xA9, 0xA9, 0xFF };
	static constexpr GXColor DarkGreen = (GXColor) { 0x00, 0x64, 0x00, 0xFF };
	static constexpr GXColor DarkKhaki = (GXColor) { 0xBD, 0xB7, 0x6B, 0xFF };
	static constexpr GXColor DarkMagenta = (GXColor) { 0x8B, 0x00, 0x8B, 0xFF };
	static constexpr GXColor DarkOliveGreen = (GXColor) { 0x55, 0x6B, 0x2F, 0xFF };
	static constexpr GXColor DarkOrange = (GXColor) { 0xFF, 0x8C, 0x00, 0xFF };
	static constexpr GXColor DarkOrchid = (GXColor) { 0x99, 0x32, 0xCC, 0xFF };
	static constexpr GXColor DarkRed = (GXColor) { 0x8B, 0x00, 0x00, 0xFF };
	static constexpr GXColor DarkSalmon = (GXColor) { 0xE9, 0x96, 0x7A, 0xFF };
	static constexpr GXColor DarkSeaGreen = (GXColor) { 0x8F, 0xBC, 0x8F, 0xFF };
	static constexpr GXColor DarkSlateBlue = (GXColor) { 0x48, 0x3D, 0x8B, 0xFF };
	static constexpr GXColor DarkSlateGray = (GXColor) { 0x2F, 0x4F, 0x4F, 0xFF };
	static constexpr GXColor DarkTurquoise = (GXColor) { 0x00, 0xCE, 0xD1, 0xFF };
	static constexpr GXColor DarkViolet = (GXColor) { 0x94, 0x00, 0xD3, 0xFF };
	static constexpr GXColor DeepPink = (GXColor) { 0xFF, 0x14, 0x93, 0xFF };
	static constexpr GXColor DeepSkyBlue = (GXColor) { 0x00, 0xBF, 0xFF, 0xFF };
	static constexpr GXColor DimGray = (GXColor) { 0x69, 0x69, 0x69, 0xFF };
	static constexpr GXColor DodgerBlue = (GXColor) { 0x1E, 0x90, 0xFF, 0xFF };
	static constexpr GXColor Firebrick = (GXColor) { 0xB2, 0x22, 0x22, 0xFF };
	static constexpr GXColor FloralWhite = (GXColor) { 0xFF, 0xFA, 0xF0, 0xFF };
	static constexpr GXColor ForestGreen = (GXColor) { 0x22, 0x8B, 0x22, 0xFF };
	static constexpr GXColor Fuchsia = (GXColor) { 0xFF, 0x00, 0xFF, 0xFF };
	static constexpr GXColor Gainsboro = (GXColor) { 0xDC, 0xDC, 0xDC, 0xFF };
	static constexpr GXColor GhostWhite = (GXColor) { 0xF8, 0xF8, 0xFF, 0xFF };
	static constexpr GXColor Gold = (GXColor) { 0xFF, 0xD7, 0x00, 0xFF };
	static constexpr GXColor Goldenrod = (GXColor) { 0xDA, 0xA5, 0x20, 0xFF };
	static constexpr GXColor Gray = (GXColor) { 0x80, 0x80, 0x80, 0xFF };
	static constexpr GXColor Green = (GXColor) { 0x00, 0x80, 0x00, 0xFF };
	static constexpr GXColor GreenYellow = (GXColor) { 0xAD, 0xFF, 0x2F, 0xFF };
	static constexpr GXColor Honeydew = (GXColor) { 0xF0, 0xFF, 0xF0, 0xFF };
	static constexpr GXColor HotPink = (GXColor) { 0xFF, 0x69, 0xB4, 0xFF };
	static constexpr GXColor IndianRed = (GXColor) { 0xCD, 0x5C, 0x5C, 0xFF };
	static constexpr GXColor Indigo = (GXColor) { 0x4B, 0x00, 0x82, 0xFF };
	static constexpr GXColor Ivory = (GXColor) { 0xFF, 0xFF, 0xF0, 0xFF };
	static constexpr GXColor Khaki = (GXColor) { 0xF0, 0xE6, 0x8C, 0xFF };
	static constexpr GXColor Lavender = (GXColor) { 0xE6, 0xE6, 0xFA, 0xFF };
	static constexpr GXColor LavenderBlush = (GXColor) { 0xFF, 0xF0, 0xF5, 0xFF };
	static constexpr GXColor LawnGreen = (GXColor) { 0x7C, 0xFC, 0x00, 0xFF };
	static constexpr GXColor LemonChiffon = (GXColor) { 0xFF, 0xFA, 0xCD, 0xFF };
	static constexpr GXColor LightBlue = (GXColor) { 0xAD, 0xD8, 0xE6, 0xFF };
	static constexpr GXColor LightCoral = (GXColor) { 0xF0, 0x80, 0x80, 0xFF };
	static constexpr GXColor LightCyan = (GXColor) { 0xE0, 0xFF, 0xFF, 0xFF };
	static constexpr GXColor LightGoldenrodYellow = (GXColor) { 0xFA, 0xFA, 0xD2, 0xFF };
	static constexpr GXColor LightGray = (GXColor) { 0xD3, 0xD3, 0xD3, 0xFF };
	static constexpr GXColor LightGreen = (GXColor) { 0x90, 0xEE, 0x90, 0xFF };
	static constexpr GXColor LightPink = (GXColor) { 0xFF, 0xB6, 0xC1, 0xFF };
	static constexpr GXColor LightSalmon = (GXColor) { 0xFF, 0xA0, 0x7A, 0xFF };
	static constexpr GXColor LightSeaGreen = (GXColor) { 0x20, 0xB2, 0xAA, 0xFF };
	static constexpr GXColor LightSkyBlue = (GXColor) { 0x87, 0xCE, 0xFA, 0xFF };
	static constexpr GXColor LightSlateGray = (GXColor) { 0x77, 0x88, 0x99, 0xFF };
	static constexpr GXColor LightSteelBlue = (GXColor) { 0xB0, 0xC4, 0xDE, 0xFF };
	static constexpr GXColor LightYellow = (GXColor) { 0xFF, 0xFF, 0xE0, 0xFF };
	static constexpr GXColor Lime = (GXColor) { 0x00, 0xFF, 0x00, 0xFF };
	static constexpr GXColor LimeGreen = (GXColor) { 0x32, 0xCD, 0x32, 0xFF };
	static constexpr GXColor Linen = (GXColor) { 0xFA, 0xF0, 0xE6, 0xFF };
	static constexpr GXColor Magenta = (GXColor) { 0xFF, 0x00, 0xFF, 0xFF };
	static constexpr GXColor Maroon = (GXColor) { 0x80, 0x00, 0x00, 0xFF };
	static constexpr GXColor MediumAquamarine = (GXColor) { 0x66, 0xCD, 0xAA, 0xFF };
	static constexpr GXColor MediumBlue = (GXColor) { 0x00, 0x00, 0xCD, 0xFF };
	static constexpr GXColor MediumOrchid = (GXColor) { 0xBA, 0x55, 0xD3, 0xFF };
	static constexpr GXColor MediumPurple = (GXColor) { 0x93, 0x70, 0xDB, 0xFF };
	static constexpr GXColor MediumSeaGreen = (GXColor) { 0x3C, 0xB3, 0x71, 0xFF };
	static constexpr GXColor MediumSlateBlue = (GXColor) { 0x7B, 0x68, 0xEE, 0xFF };
	static constexpr GXColor MediumSpringGreen = (GXColor) { 0x00, 0xFA, 0x9A, 0xFF };
	static constexpr GXColor MediumTurquoise = (GXColor) { 0x48, 0xD1, 0xCC, 0xFF };
	static constexpr GXColor MediumVioletRed = (GXColor) { 0xC7, 0x15, 0x85, 0xFF };
	static constexpr GXColor MidnightBlue = (GXColor) { 0x19, 0x19, 0x70, 0xFF };
	static constexpr GXColor MintCream = (GXColor) { 0xF5, 0xFF, 0xFA, 0xFF };
	static constexpr GXColor MistyRose = (GXColor) { 0xFF, 0xE4, 0xE1, 0xFF };
	static constexpr GXColor Moccasin = (GXColor) { 0xFF, 0xE4, 0xB5, 0xFF };
	static constexpr GXColor NavajoWhite = (GXColor) { 0xFF, 0xDE, 0xAD, 0xFF };
	static constexpr GXColor Navy = (GXColor) { 0x00, 0x00, 0x80, 0xFF };
	static constexpr GXColor OldLace = (GXColor) { 0xFD, 0xF5, 0xE6, 0xFF };
	static constexpr GXColor Olive = (GXColor) { 0x80, 0x80, 0x00, 0xFF };
	static constexpr GXColor OliveDrab = (GXColor) { 0x6B, 0x8E, 0x23, 0xFF };
	static constexpr GXColor Orange = (GXColor) { 0xFF, 0xA5, 0x00, 0xFF };
	static constexpr GXColor OrangeRed = (GXColor) { 0xFF, 0x45, 0x00, 0xFF };
	static constexpr GXColor Orchid = (GXColor) { 0xDA, 0x70, 0xD6, 0xFF };
	static constexpr GXColor PaleGoldenrod = (GXColor) { 0xEE, 0xE8, 0xAA, 0xFF };
	static constexpr GXColor PaleGreen = (GXColor) { 0x98, 0xFB, 0x98, 0xFF };
	static constexpr GXColor PaleTurquoise = (GXColor) { 0xAF, 0xEE, 0xEE, 0xFF };
	static constexpr GXColor PaleVioletRed = (GXColor) { 0xDB, 0x70, 0x93, 0xFF };
	static constexpr GXColor PapayaWhip = (GXColor) { 0xFF, 0xEF, 0xD5, 0xFF };
	static constexpr GXColor PeachPuff = (GXColor) { 0xFF, 0xDA, 0xB9, 0xFF };
	static constexpr GXColor Peru = (GXColor) { 0xCD, 0x85, 0x3F, 0xFF };
	static constexpr GXColor Pink = (GXColor) { 0xFF, 0xC0, 0xCB, 0xFF };
	static constexpr GXColor Plum = (GXColor) { 0xDD, 0xA0, 0xDD, 0xFF };
	static constexpr GXColor PowderBlue = (GXColor) { 0xB0, 0xE0, 0xE6, 0xFF };
	static constexpr GXColor Purple = (GXColor) { 0x80, 0x00, 0x80, 0xFF };
	static constexpr GXColor Red = (GXColor) { 0xFF, 0x00, 0x00, 0xFF };
	static constexpr GXColor RosyBrown = (GXColor) { 0xBC, 0x8F, 0x8F, 0xFF };
	static constexpr GXColor RoyalBlue = (GXColor) { 0x41, 0x69, 0xE1, 0xFF };
	static constexpr GXColor SaddleBrown = (GXColor) { 0x8B, 0x45, 0x13, 0xFF };
	static constexpr GXColor Salmon = (GXColor) { 0xFA, 0x80, 0x72, 0xFF };
	static constexpr GXColor SandyBrown = (GXColor) { 0xF4, 0xA4, 0x60, 0xFF };
	static constexpr GXColor SeaGreen = (GXColor) { 0x2E, 0x8B, 0x57, 0xFF };
	static constexpr GXColor SeaShell = (GXColor) { 0xFF, 0xF5, 0xEE, 0xFF };
	static constexpr GXColor Sienna = (GXColor) { 0xA0, 0x52, 0x2D, 0xFF };
	static constexpr GXColor Silver = (GXColor) { 0xC0, 0xC0, 0xC0, 0xFF };
	static constexpr GXColor SkyBlue = (GXColor) { 0x87, 0xCE, 0xEB, 0xFF };
	static constexpr GXColor SlateBlue = (GXColor) { 0x6A, 0x5A, 0xCD, 0xFF };
	static constexpr GXColor SlateGray = (GXColor) { 0x70, 0x80, 0x90, 0xFF };
	static constexpr GXColor Snow = (GXColor) { 0xFF, 0xFA, 0xFA, 0xFF };
	static constexpr GXColor SpringGreen = (GXColor) { 0x00, 0xFF, 0x7F, 0xFF };
	static constexpr GXColor SteelBlue = (GXColor) { 0x46, 0x82, 0xB4, 0xFF };
	static constexpr GXColor Tan = (GXColor) { 0xD2, 0xB4, 0x8C, 0xFF };
	static constexpr GXColor Teal = (GXColor) { 0x00, 0x80, 0x80, 0xFF };
	static constexpr GXColor Thistle = (GXColor) { 0xD8, 0xBF, 0xD8, 0xFF };
	static constexpr GXColor Tomato = (GXColor) { 0xFF, 0x63, 0x47, 0xFF };
	static constexpr GXColor Transparent = (GXColor) { 0xFF, 0xFF, 0xFF, 0x00 };
	static constexpr GXColor Turquoise = (GXColor) { 0x40, 0xE0, 0xD0, 0xFF };
	static constexpr GXColor Violet = (GXColor) { 0xEE, 0x82, 0xEE, 0xFF };
	static constexpr GXColor Wheat = (GXColor) { 0xF5, 0xDE, 0xB3, 0xFF };
	static constexpr GXColor White = (GXColor) { 0xFF, 0xFF, 0xFF, 0xFF };
	static constexpr GXColor WhiteSmoke = (GXColor) { 0xF5, 0xF5, 0xF5, 0xFF };
	static constexpr GXColor Yellow = (GXColor) { 0xFF, 0xFF, 0x00, 0xFF };
	static constexpr GXColor YellowGreen = (GXColor) { 0x9A, 0xCD, 0x32, 0xFF };
};
