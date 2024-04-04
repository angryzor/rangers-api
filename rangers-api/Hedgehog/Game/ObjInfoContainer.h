#pragma once

namespace hh::game {
    class ObjInfoContainer : public GameService {
    public:
        csl::ut::StringMap<ObjInfo*> objInfosByName;
        csl::ut::MoveArray<ObjInfo*> objInfos;

        ObjInfo* GetInfo(const char* name);
        void Initialize();
        void Finalize();
        bool Unk1();
        void LoadRequestAll();
        bool Register(const char* name, ObjInfo* objInfo);
        bool Unregister(const char* name);

        GAMESERVICE_CLASS_DECLARATION(ObjInfoContainer)
    };
}
