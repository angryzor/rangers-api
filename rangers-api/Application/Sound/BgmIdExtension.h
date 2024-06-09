#pragma once

namespace app::snd {
    class BgmIdExtension : public SoundDirectorExtension {
    public:
        static constexpr const char* name = "BgmId";

        void SetBgmId(unsigned int id, bool autoRemoveRequest);
    };
}