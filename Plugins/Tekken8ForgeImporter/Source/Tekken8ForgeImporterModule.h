#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class TEKKEN8FORGEIMPORTER_API FTekken8ForgeImporterModule : public IModuleInterface {
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	/**
	 * Do stuff after engine is initialized.
	 */
	void OnPostEngineInit();

private:
	/** OnPostEngineInit delegate handler. */
	FDelegateHandle OnPostEngineInitDelegateHandle;
};
