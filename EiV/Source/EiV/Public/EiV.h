// Copyright 2025, Galacticc Games. All rights reserved.

/* Licensed under MIT license. See License.txt for full license text.
*
*        Created: 20th March 2025
*  Last Modified: 20th March 2025
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
