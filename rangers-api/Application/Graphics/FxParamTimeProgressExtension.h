#pragma once

namespace app::gfx {
    class FxParamTimeProgressExtension
        : public FxParamExtension
        , public hh::game::GameManagerListener
        , public evt::EventPlayerListener {
        game::TimeService* timeService;
        evt::EventPlayer* eventPlayer;
        app::rfl::TimeProgressNeedleFxParam timeProgressNeedleFxParam;
        app::rfl::FxAtmosphereParameter atmosphereParameter;
        uint16_t unk1;
        
    public:
        FxParamTimeProgressExtension(csl::fnd::IAllocator* allocator);
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void UnkFunc2() override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
    };
}
