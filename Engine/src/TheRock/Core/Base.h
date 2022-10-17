#pragma once

#include <memory>
//#include "Ref.h"  TODO: Make a ref system

namespace RockEngine
{
	void InitializeCore();
	void ShutdownCore();
}

#ifndef RE_PLATFORM_WINDOWS
#error TheRock only supports Windows!
#endif

// __VA_ARGS__ expansion to get past MSVC "bug"
#define RE_EXPAND_VARGS(x) x

// bits shift
#define BIT(x) (1 << x)

// Lambda function to bind events
#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) \
{ \
	return this->fn(std::forward<decltype(args)>(args)...); \
}

// ZeroMemory function
//#ifndef ZeroMemory
//	#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))
//#endif

#include "Assert.h" 

// Pointer wrappers
namespace RockEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	// unsigned char
	using byte = uint8_t;
	// unsigned int
	using u32 = uint32_t;
	// unsigned long long
	using u64 = uint64_t;
	// int
	using i32 = int32_t;

}