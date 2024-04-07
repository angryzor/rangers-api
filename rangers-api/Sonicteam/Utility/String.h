#pragma once

namespace csl::ut {
    class String : public csl::ut::MoveArray32<char> {
    public:
        String(csl::fnd::IAllocator* pAllocator) : csl::ut::MoveArray32<char>{ pAllocator } {}

        void reserve(uint32_t len) {
            csl::ut::MoveArray32<char>::reserve(len + 1);
            m_capacity = len;
        }

        char* c_str() {
            return m_pBuffer;
        }

        void copyFrom(const char* str, size_t len, size_t srcOffset, size_t dstOffset);
    };
}
