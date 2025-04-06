// Copyright 2025, Galacticc Games. All rights reserved.

/* Licensed under MIT license. See LICENSE for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 6th April 2025
*/

using UnrealBuildTool;

public class EiV : ModuleRules
{
	public EiV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "Eigen" });
			
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Eigen" });

        AddEngineThirdPartyPrivateStaticDependencies(Target, "Eigen");
        PublicDefinitions.Add("EIGEN_IGNORE_UNREACHABLE_CODE_WARNING=1");
    }
}
