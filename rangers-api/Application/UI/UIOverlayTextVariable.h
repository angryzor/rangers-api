#pragma once

namespace app::ui {
    struct OverlayTextVariable {
        csl::ut::String id;
        csl::ut::String value;
        bool translated;

        void SetTranslatedValue(const char* id, const char* valueId);
        void SetUntranslatedValue(const char* id, const char* value);
    };

    struct OverlayTextVariableCollection {
        csl::ut::MoveArray<OverlayTextVariable> variables;

        OverlayTextVariable* Add(csl::fnd::IAllocator** allocator);
    };
}
