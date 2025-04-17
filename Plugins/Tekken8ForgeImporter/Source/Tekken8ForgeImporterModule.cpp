#include "Tekken8ForgeImporterModule.h"

IMPLEMENT_MODULE(FTekken8ForgeImporterModule, FTekken8ForgeImporter)

void FTekken8ForgeImporterModule::StartupModule() {
	// Add OnPostEngineInit delegate.
	OnPostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddRaw(this, &FTekken8ForgeImporterModule::OnPostEngineInit);
}

void FTekken8ForgeImporterModule::ShutdownModule() {
	// Remove OnPostEngineInit delegate
	FCoreDelegates::OnPostEngineInit.Remove(OnPostEngineInitDelegateHandle);
}

void FTekken8ForgeImporterModule::OnPostEngineInit() {
	// Do post engine stuff here
}
