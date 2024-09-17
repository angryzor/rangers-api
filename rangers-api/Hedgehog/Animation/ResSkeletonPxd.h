#pragma once

namespace hh::anim {
    class ResSkeletonPxd : public ResSkeleton {
    public:
        uint64_t unk101;
        uint64_t unk102;
        csl::ut::MoveArray<void*> unk103;
        uint64_t unk104;
        csl::ut::PointerMap<void*, void*> unk105;
        uint64_t unk106;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;
        virtual uint64_t UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
        virtual uint64_t UnkFunc14() override;
        virtual uint64_t UnkFunc15() override;
        virtual uint64_t UnkFunc16() override;
        virtual uint64_t UnkFunc17() override;
        virtual uint64_t UnkFunc18() override;
    };
}
