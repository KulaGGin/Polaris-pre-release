using UnrealBuildTool;

public class Tekken8ForgeImporter : ModuleRules {
	public Tekken8ForgeImporter(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.Add("Tekken8ForgeImporter");

		PublicDependencyModuleNames.AddRange(new[] {
			"Core",
			"InputCore"
		});


		PrivateDependencyModuleNames.AddRange(new[] {
			"Polaris",
			"UnrealEd",
			"Engine",
			"Core",
			"CoreUObject",
			"UMG",
            "Blutility",
            "LevelSequence",
            "Json",
            "JsonUtilities"
        });
	}
}