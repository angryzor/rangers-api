#pragma once

namespace hh::fnd {
    class ManagedResource;
    class ReloaderListener {
    public:
        virtual ~ReloaderListener() = default;
        virtual void UnknownThingReloadedCallback(void* thing) {}
        virtual void ResourceReloadedCallback(ManagedResource* resource) {}
    };
}
