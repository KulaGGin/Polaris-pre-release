#include "Modules/ModuleInterface.h"

#include "AssetsActionsRegistrator.h"

#define LOCTEXT_NAMESPACE "PolarisEditor"

class FPolarisGameEditor : public IModuleInterface {
public:
	virtual void StartupModule() override {
		UAssetsActionsRegistrator::RegisterAllTypeActions();
	}

	virtual void ShutdownModule() override {
		UAssetsActionsRegistrator::UnregisterAllTypeActions();
	}
};

IMPLEMENT_MODULE(FPolarisGameEditor, PolarisEditor);

#undef LOCTEXT_NAMESPACE