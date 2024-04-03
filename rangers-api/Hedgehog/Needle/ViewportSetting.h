#pragma once

namespace hh::needle {
    struct ViewportSetting {
        int unk1;
        int unk2;
        int width;
        int height;
        int unk3;
        float unk4;
    
        ViewportSetting(int width, int height);
    };
}
