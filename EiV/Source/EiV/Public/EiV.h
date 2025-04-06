// Copyright 2025, Galacticc Games. All rights reserved.

/* Licensed under MIT license. See LICENSE for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 6th April 2025
*/

#pragma once

#include "Modules/ModuleManager.h"

class FEiVModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
