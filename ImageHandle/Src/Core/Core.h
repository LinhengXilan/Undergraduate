/**
 * @file Core/Core.h
 * @author LinhengXilan
 * @version 0.0.0.2
 * @date 2026-1-8
 */

#ifndef CORE_CORE_H
#define CORE_CORE_H

#ifndef BUILD_DLL
#define DLL __declspec(dllimport)
#else
#define DLL __declspec(dllexport)
#endif

namespace ImageHandle
{

	template<typename T>
	using Object = std::unique_ptr<T>;

	template<typename T, typename... Args>
	constexpr Object<T> CreateObject(Args&&... args);

	template<typename T>
	using ObjectRef = std::shared_ptr<T>;

	template<typename T, typename... Args>
	constexpr ObjectRef<T> CreateObjectRef(Args&&... args);

}

#include <Core/Core.inl>

#endif