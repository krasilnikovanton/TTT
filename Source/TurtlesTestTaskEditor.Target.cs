// Turtles Test Task. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TurtlesTestTaskEditorTarget : TargetRules
{
	public TurtlesTestTaskEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TurtlesTestTask" } );
	}
}
