#pragma once

namespace hh::anim {
    class BindableCollection {
        uint32_t unk1;
        csl::ut::LinkList<Bindable> items;
    };
}