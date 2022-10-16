#pragma once

namespace RockEngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define RE_KEY_SPACE           ::RockEngine::Key::Space
#define RE_KEY_APOSTROPHE      ::RockEngine::Key::Apostrophe    /* ' */
#define RE_KEY_COMMA           ::RockEngine::Key::Comma         /* , */
#define RE_KEY_MINUS           ::RockEngine::Key::Minus         /* - */
#define RE_KEY_PERIOD          ::RockEngine::Key::Period        /* . */
#define RE_KEY_SLASH           ::RockEngine::Key::Slash         /* / */
#define RE_KEY_0               ::RockEngine::Key::D0
#define RE_KEY_1               ::RockEngine::Key::D1
#define RE_KEY_2               ::RockEngine::Key::D2
#define RE_KEY_3               ::RockEngine::Key::D3
#define RE_KEY_4               ::RockEngine::Key::D4
#define RE_KEY_5               ::RockEngine::Key::D5
#define RE_KEY_6               ::RockEngine::Key::D6
#define RE_KEY_7               ::RockEngine::Key::D7
#define RE_KEY_8               ::RockEngine::Key::D8
#define RE_KEY_9               ::RockEngine::Key::D9
#define RE_KEY_SEMICOLON       ::RockEngine::Key::Semicolon     /* ; */
#define RE_KEY_EQUAL           ::RockEngine::Key::Equal         /* = */
#define RE_KEY_A               ::RockEngine::Key::A
#define RE_KEY_B               ::RockEngine::Key::B
#define RE_KEY_C               ::RockEngine::Key::C
#define RE_KEY_D               ::RockEngine::Key::D
#define RE_KEY_E               ::RockEngine::Key::E
#define RE_KEY_F               ::RockEngine::Key::F
#define RE_KEY_G               ::RockEngine::Key::G
#define RE_KEY_H               ::RockEngine::Key::H
#define RE_KEY_I               ::RockEngine::Key::I
#define RE_KEY_J               ::RockEngine::Key::J
#define RE_KEY_K               ::RockEngine::Key::K
#define RE_KEY_L               ::RockEngine::Key::L
#define RE_KEY_M               ::RockEngine::Key::M
#define RE_KEY_N               ::RockEngine::Key::N
#define RE_KEY_O               ::RockEngine::Key::O
#define RE_KEY_P               ::RockEngine::Key::P
#define RE_KEY_Q               ::RockEngine::Key::Q
#define RE_KEY_R               ::RockEngine::Key::R
#define RE_KEY_S               ::RockEngine::Key::S
#define RE_KEY_T               ::RockEngine::Key::T
#define RE_KEY_U               ::RockEngine::Key::U
#define RE_KEY_V               ::RockEngine::Key::V
#define RE_KEY_W               ::RockEngine::Key::W
#define RE_KEY_X               ::RockEngine::Key::X
#define RE_KEY_Y               ::RockEngine::Key::Y
#define RE_KEY_Z               ::RockEngine::Key::Z
#define RE_KEY_LEFT_BRACKET    ::RockEngine::Key::LeftBracket   /* [ */
#define RE_KEY_BACKSLASH       ::RockEngine::Key::Backslash     /* \ */
#define RE_KEY_RIGHT_BRACKET   ::RockEngine::Key::RightBracket  /* ] */
#define RE_KEY_GRAVE_ACCENT    ::RockEngine::Key::GraveAccent   /* ` */
#define RE_KEY_WORLD_1         ::RockEngine::Key::World1        /* non-US #1 */
#define RE_KEY_WORLD_2         ::RockEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define RE_KEY_ESCAPE          ::RockEngine::Key::Escape
#define RE_KEY_ENTER           ::RockEngine::Key::Enter
#define RE_KEY_TAB             ::RockEngine::Key::Tab
#define RE_KEY_BACKSPACE       ::RockEngine::Key::Backspace
#define RE_KEY_INSERT          ::RockEngine::Key::Insert
#define RE_KEY_DELETE          ::RockEngine::Key::Delete
#define RE_KEY_RIGHT           ::RockEngine::Key::Right
#define RE_KEY_LEFT            ::RockEngine::Key::Left
#define RE_KEY_DOWN            ::RockEngine::Key::Down
#define RE_KEY_UP              ::RockEngine::Key::Up
#define RE_KEY_PAGE_UP         ::RockEngine::Key::PageUp
#define RE_KEY_PAGE_DOWN       ::RockEngine::Key::PageDown
#define RE_KEY_HOME            ::RockEngine::Key::Home
#define RE_KEY_END             ::RockEngine::Key::End
#define RE_KEY_CAPS_LOCK       ::RockEngine::Key::CapsLock
#define RE_KEY_SCROLL_LOCK     ::RockEngine::Key::ScrollLock
#define RE_KEY_NUM_LOCK        ::RockEngine::Key::NumLock
#define RE_KEY_PRINT_SCREEN    ::RockEngine::Key::PrintScreen
#define RE_KEY_PAUSE           ::RockEngine::Key::Pause
#define RE_KEY_F1              ::RockEngine::Key::F1
#define RE_KEY_F2              ::RockEngine::Key::F2
#define RE_KEY_F3              ::RockEngine::Key::F3
#define RE_KEY_F4              ::RockEngine::Key::F4
#define RE_KEY_F5              ::RockEngine::Key::F5
#define RE_KEY_F6              ::RockEngine::Key::F6
#define RE_KEY_F7              ::RockEngine::Key::F7
#define RE_KEY_F8              ::RockEngine::Key::F8
#define RE_KEY_F9              ::RockEngine::Key::F9
#define RE_KEY_F10             ::RockEngine::Key::F10
#define RE_KEY_F11             ::RockEngine::Key::F11
#define RE_KEY_F12             ::RockEngine::Key::F12
#define RE_KEY_F13             ::RockEngine::Key::F13
#define RE_KEY_F14             ::RockEngine::Key::F14
#define RE_KEY_F15             ::RockEngine::Key::F15
#define RE_KEY_F16             ::RockEngine::Key::F16
#define RE_KEY_F17             ::RockEngine::Key::F17
#define RE_KEY_F18             ::RockEngine::Key::F18
#define RE_KEY_F19             ::RockEngine::Key::F19
#define RE_KEY_F20             ::RockEngine::Key::F20
#define RE_KEY_F21             ::RockEngine::Key::F21
#define RE_KEY_F22             ::RockEngine::Key::F22
#define RE_KEY_F23             ::RockEngine::Key::F23
#define RE_KEY_F24             ::RockEngine::Key::F24
#define RE_KEY_F25             ::RockEngine::Key::F25

/* Keypad */
#define RE_KEY_KP_0            ::RockEngine::Key::KP0
#define RE_KEY_KP_1            ::RockEngine::Key::KP1
#define RE_KEY_KP_2            ::RockEngine::Key::KP2
#define RE_KEY_KP_3            ::RockEngine::Key::KP3
#define RE_KEY_KP_4            ::RockEngine::Key::KP4
#define RE_KEY_KP_5            ::RockEngine::Key::KP5
#define RE_KEY_KP_6            ::RockEngine::Key::KP6
#define RE_KEY_KP_7            ::RockEngine::Key::KP7
#define RE_KEY_KP_8            ::RockEngine::Key::KP8
#define RE_KEY_KP_9            ::RockEngine::Key::KP9
#define RE_KEY_KP_DECIMAL      ::RockEngine::Key::KPDecimal
#define RE_KEY_KP_DIVIDE       ::RockEngine::Key::KPDivide
#define RE_KEY_KP_MULTIPLY     ::RockEngine::Key::KPMultiply
#define RE_KEY_KP_SUBTRACT     ::RockEngine::Key::KPSubtract
#define RE_KEY_KP_ADD          ::RockEngine::Key::KPAdd
#define RE_KEY_KP_ENTER        ::RockEngine::Key::KPEnter
#define RE_KEY_KP_EQUAL        ::RockEngine::Key::KPEqual

#define RE_KEY_LEFT_SHIFT      ::RockEngine::Key::LeftShift
#define RE_KEY_LEFT_CONTROL    ::RockEngine::Key::LeftControl
#define RE_KEY_LEFT_ALT        ::RockEngine::Key::LeftAlt
#define RE_KEY_LEFT_SUPER      ::RockEngine::Key::LeftSuper
#define RE_KEY_RIGHT_SHIFT     ::RockEngine::Key::RightShift
#define RE_KEY_RIGHT_CONTROL   ::RockEngine::Key::RightControl
#define RE_KEY_RIGHT_ALT       ::RockEngine::Key::RightAlt
#define RE_KEY_RIGHT_SUPER     ::RockEngine::Key::RightSuper
#define RE_KEY_MENU            ::RockEngine::Key::Menu

// Mouse (TODO: move into separate file probably)
#define RE_MOUSE_BUTTON_LEFT    0
#define RE_MOUSE_BUTTON_RIGHT   1
#define RE_MOUSE_BUTTON_MIDDLE  2
