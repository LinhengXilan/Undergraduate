/**
 * @file Core/Core.inl
 * @author LinhengXilan
 * @version 0.0.0.2
 * @date 2026-1-8
 */

#ifndef CORE_CORE_INL
#define CORE_CORE_INL

#include <Core/Core.h>

namespace ImageHandle
{
	template<typename T, typename... Args>
	constexpr Object<T> CreateObject(Args&&... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	constexpr ObjectRef<T> CreateObjectRef(Args&&... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#endif