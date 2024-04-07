#pragma once

namespace app::level {
	class StageInfo : public hh::game::GameService, public app::fnd::AppResourceManagerListener
	{
	public:
		csl::ut::MoveArray<hh::fnd::Reference<StageData>> stages;
		csl::ut::MoveArray<void*> unk1;

        GAMESERVICE_CLASS_DECLARATION(StageInfo)
	};
}
