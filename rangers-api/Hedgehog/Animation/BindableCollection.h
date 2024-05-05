#pragma once

namespace hh::anim {
    class BindableCollection {
        float collectionFloat;
        csl::ut::LinkList<Bindable> items;
    };
}