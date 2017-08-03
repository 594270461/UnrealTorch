// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UEWrappedSol2.h"    // unique_ptr and forward declarations do not seem to play with UBT..

#include <memory>

#include "UthLuaState.generated.h"




/**
 * 
 */
UCLASS( Category = "UnrealTorch|Lua", meta = (DisplayName = "Lua State") )
class UNREALTORCH_API UUthLuaState : public UObject
{
	GENERATED_BODY()

public:

	/** Constructs a new UthLuaState object, creating a new Lua state and initializing it.
	 *
	 * A new sol::state is created.
	 *
	 * All Lua standard libraries are opened.
	 *
	 * A global variable 'uth' is created with the following structure:
	 *   uth                                  The main table for all UnrealTorch data
	 *     .ue                                Data from UE
	 *       .UE_LOG( verbosity, message )    Write log entries to UE log
	 *       .ELogVerbosity                   Verbosity level enumeration for UE_LOG()
	 *       .BuildShippingOrTest             True if UE is running in Shipping or Test configuration
	 *       .FPaths                          UE path information
	 *         .GameLogDir                    Log directory path from FPaths::GameLogDir()
	 *
	 * The package.path variable is set to include the following locations, in this order:
	 *   1. UnrealTorch's own Lua files: <pluginroot>/Source/UnrealTorch/Private/lua/?.lua
	 *   2. Torch's Lua files: <pluginroot>/Source/ThirdParty/Torch/WindowsTorch/lua/?.lua and
	 *      <pluginroot>/Source/ThirdParty/Torch/WindowsTorch/lua/?/init.lua
	 *   3. Project level Lua files: <root>/Content/Lua/?.lua and <root>/Content/Lua/?/init.lua
	 * The package.cpath variable is set to include the following locations, in this order:
	 *   1. Torch DLLs: <pluginroot>/Source/ThirdParty/Torch/WindowsTorch/bin/?.dll
	 *   2. Project level DLLs: <root>/Content/Lua/bin/?.dll
	 */
	UUthLuaState();

	/** No-op. */
	virtual ~UUthLuaState();

	/** Checks whether the object is in a valid, usable state. */
	bool isValid();



	/** Sol-wrapped Lua state instance */
	std::unique_ptr<sol::state> lua;

};
