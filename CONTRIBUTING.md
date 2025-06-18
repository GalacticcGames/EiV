## How to Contribute To EiV

You can help build the EiV plugin by either submiting any Issues you have found with it here in the GitHub repo or by submitting Pull 
Requests to the repo with changes or new features you would like to see.

### Issues

When you submit an Issue it will be added to the milestone towards the next EiV update. We will then work on resolving this issue and 
mark it complete once it is solved on the development branch. You can also help us out by submitting your own Pull Requests that resolve 
the issue that we will review and add to the development branch.

### Pull Requests

When you create a Pull Request with some modifications you would like made, we will review the changes in this request and test them 
out on the development branch. When creating changes for EiV, make sure to follow [Unreal Engine Coding Standards](https://dev.epicgames.com/documentation/en-us/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine)
and that your code you create matches the patterns already found in the file. For example, if you are adding new Blueprint Functions 
that require a new EiV blueprint struct, please place the new struct along with all of the others in the `EiVBPLibrary.h` file and 
not to have it placed somewhere that requires a scavenger hunt. Also, if creating new EiV typedefs, please make sure to group them 
logically and that you space them out like shown already in the source file to help make them a bit more readable (*yes, we know it 
is hard to read in the first place, but anything helps*). Lastly, if creating typedefs that have a consistent pattern involved, try 
and make a macro for them like `MAKE_COMMON_TYPEDEFS` in `EiVLibrary.h` to reduce visual bloat, and make sure to undefine the macro 
once you are done using it.

> [!Tip]
> Any Pull Requests you make are going to be implemented on the development branch and not directly on the main branch. When creating
> modifications, make sure you have the latest version of the development branch on your fork to make sure you don't accidentally make
> a redundant Pull Request for something we just added or fixed in the latest development iterations on the development branch.
