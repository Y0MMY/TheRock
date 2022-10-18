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
		{}

		Buffer(byte* data, u32 size)
			: Data(data), Size(size)
		{}

		void Allocate(u32 size)
		{
			delete[] Data;
			Data = nullptr;

			if (!size)
				return;

			Data = new byte[size];
			Size = size;
		}

		void ZeroInitialize()
		{
			if (Data)
				memset(Data, 0, Size);
		}

		template<typename T>
		T& Read(uint32_t offset = 0)
		{
			return *(T*)(Data + offset);
		}


		void Write(void* data, u32 size, u32 offset = 0)
		{
			RE_ASSERT(offset + size <= Size, "Buffer overflow!");
			memcpy(Data + offset, data, size);
		}

		static Buffer Copy(void* data, u32 size)
		{
			Buffer buffer;
			buffer.Allocate(size);
			memcpy(buffer.Data, data, size);
			return buffer;
		}

		operator bool() const {
			return Data;
		}

		byte& operator[](int index)
		{
			return Data[index];
		}

		byte& operator[](int index) const
		{
			return Data[index];
		}

		template <typename T>
		T* As()
		{
			return (T*)Data;
		}

		inline u32 GetSize() const { return Size; }
	};
}