// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Sol2 : ModuleRules
{
	public Sol2(TargetInfo Target)
	{
		Type = ModuleType.External;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
	}
}
