#pragma once

namespace hh::needle {
    struct ViewportSetting {
        int unk1;
        int unk2;
        int renderResX;
        int renderResY;
        int unk3;
        float unk4;
    
        ViewportSetting(int width, int height);
    };
}
