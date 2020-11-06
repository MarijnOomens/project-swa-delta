#pragma once
#ifdef _DEBUG
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport) 
#endif
#elif NDEBUG
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport) 
#endif
#else
#define ENGINE_API
#endif