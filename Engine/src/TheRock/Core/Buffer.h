#pragma once

#include "TheRock/Core/Base.h"

namespace RockEngine
{
	struct Buffer
	{
		byte* Data;
		u32 Size;

		Buffer()
			: Data(nullptr), Size(0)
		{

		}

		Buffer(byte* data, u32 size)
			: Data(data), Size(size)
		{

		}

		void Allocate(u32 size)
		{
			delete[] Data;
			Data = nullptr;

			if (size == 0)
				return;

			Size = size;
			Data = new byte[size];
		}

		void ZeroInitialize()
		{
			if (Data)
				memset(Data, 0, Size);
		}

		void Write(void* data, u32 size, u32 offset = 0)
		{
			RE_CORE_ASSERT(offset + size <= Size, "Buffer overflow!");
			memcpy(Data + offset, data, size);
		}

		static Buffer Copy(void* data, uint32_t size)
		{
			Buffer buffer;
			buffer.Allocate(size);
			memcpy(buffer.Data, data, size);
			return buffer;
		}

		operator bool() const
		{
			return Data;
		}

		byte& operator[](u32 index)
		{
			return Data[index];
		}

		byte operator[](u32 index) const
		{
			return Data[index];
		}

		template<typename T>
		T* As()
		{
			return (T*)Data;
		}

		inline u32 GetSize() const { return Size; }
	};
}