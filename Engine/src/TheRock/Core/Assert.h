#pragma once

#ifdef RE_DEBUG
#define RE_ENABLE_ASSERTS
#endif // RE_DEBUG

#ifdef RE_PLATFORM_WINDOWS
#if RE_DYNAMIC_LINK
#ifdef RE_BUILD_DLL
#define RE_API __declspec(dllexport)
#else
#define RE_API __declspec(dllimport)
#endif
#else
#define RE_API
#endif

#else
#error TheRock only supports Windows!
#endif

#ifdef RE_ENABLE_ASSERTS

#define RE_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { RE_ERROR("Assertion Failed!"); __debugbreak(); } }
#define RE_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { RE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define RE_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro

#define RE_ASSERT(...) RE_ASSERT_RESOLVE(__VA_ARGS__, RE_ASSERT_MESSAGE, RE_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#define RE_CORE_ASSERT(...) RE_ASSERT_RESOLVE(__VA_ARGS__, RE_ASSERT_MESSAGE, RE_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#else
#define RE_ASSERT(...)
#define RE_CORE_ASSERT(...)
#endif
