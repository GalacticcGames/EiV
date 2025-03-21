# EiV - Quick Linear Algebra and Matrix Access
## Unreal Engine Tools & Plugins - Engine Tools
Fab Listing: [Fab - EiV](https://www.fab.com/listings/b37b7133-7653-4e47-9d4a-f625e99738dc)

![EiV Image](EiVThumb.png)

## What is EiV?

EiV is a **C++ and Blueprint Library** for [Unreal Engine](https://www.unrealengine.com/) that is powered by the [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library. Eigen is a **free**, third party **linear algebra library** for C++ that comes **built-in**🔧 to Unreal Engine. This plugin is meant to **save you the hassle** of trying to **include** Eigen in your own projects, to help the conversion between Unreal Engine and Eigen types be a bit smoother, and to provide an **easy interface**💻 to **Eigen functionality in [Blueprints](https://dev.epicgames.com/documentation/en-us/unreal-engine/blueprints-visual-scripting-in-unreal-engine)!** 

## Why EiV?

EiV is designed to be a *time-saver*⌚ when it comes to using linear algebra and Eigen in Unreal Engine. The include pattern it offers will *save you all of the issues* that come with including a third party library in Unreal Engine. EiV's macro-based include pattern makes sure that you *only need to include the main header* file to have access to *all of the code you need* in any C++ file. It also helps those that don't want to use C++ to still have linear algebra in blueprints! EiV also offers an *ever-growing*⬆️*suite of functions* for Blueprints to use linear algebra! If some part of the blueprint functionality looks incomplete, it will likely be added soon, since it takes a very long time to convert all of Eigen's functionality into Blueprints. You can go check out the EiV **public GitHub repo (you are already here)** to see what progress is being made, make suggestions, and maybe even get some updates before Fab!

## Features:
* **80+ Blueprint Functions** and counting - EiV has **growing blueprint support** for linear algebra - *something you won't find anywhere else!*
* **Dynamically-sized Real** and **Complex** valued matrices for blueprints!
* **250+ C++ typedefs** to make directly using Eigen types just a bit easier and to save you writing 'Eigen::' before everything
* **70+ C++ helper functions** to help with converting back and forth between Unreal Engine and Eigen types
* <ins>All code is public on GitHub</ins> - check out what is being updated and even suggest new functions to add!

## Support, Tutorials, and Documentation:

◿ For questions, feedback, and product support don't hesitate to contact us. You are also welcome to join our Discord community, [The Galaxy](https://discord.gg/usmH9mZGVe).
> The Galaxy is a community that is for interacting with us and others that use our products and support us. *You can join even if you haven't
purchased our products.* You can look at questions and written reviews from community members on a variety of topics relating to
what we do. We hope to see you there!

◿ TODO can be found on YouTube and cover everything from basic setup to making advanced systems with EiV

◿ Detailed documentation and the changelog is available below if you want to read more about EiV

## Documentation:

### Getting Started:

To begin using EiV, first either download the plugin from Fab or from the GitHub repository and build it from source. EiV is engineered in Unreal Engine 5.1 to ensure it is compatible with versions 5.1 and above. Once you have EiV in your engine's plugin directory *(Engine / Plugins / Marketplace /)*, open the project you want to use it in and enable the plugin. It should be under the programming category. You may need to restart Unreal Engine for changes to take effect. Then you should be good to go to start using Eigen through EiV in C++ and Blueprints. More specific instructions for each are in the below sections.

| Unreal Engine Version | EiV Compatible |
| --------------------- | -------------- |
| 4.27 and below        | ❌            |
| --------------------- | -------------- |
| 5.0                   | ❌            |
| --------------------- | -------------- |
| 5.1                   | ⚠️ Built From Source |
| --------------------- | -------------- |
| 5.2                   | ⚠️ Built From Source |
| --------------------- | -------------- |
| 5.3                   | ✅ Available on Fab |
| --------------------- | -------------- |
| 5.4                   | ✅ Available on Fab |
| --------------------- | -------------- |
| 5.5                   | ✅ Available on Fab |

> [!NOTE]
> If you experience any errors on restarting or building just after EiV is activated (particularly relating to expecting to find a type declared in a module rules), See the [C++ section](#C++:) of the documentation for some tips on resolving that.

### Blueprints:

Using EiV in Blueprints is quite simple. It is just implemented as a Blueprint Function Library and should be accessible from the context menu by searching for 'EiV' (It will appear as 'Ei V' because of the way the engine parses text). 

> [!IMPORTANT]
> Not all EiV blueprint types do something as of now. We are working on adding and improving blueprint implementations over time, since Eigen is a large library to turn into blueprint functions.

Most EiV types are accessed via converter nodes. These nodes take what will be converted to the other type on one end and then swap that input type to the output. For example, the node below has a Matrix input and an Eigen Matrix input. Both of these inputs are reflected as outputs. When a normal matrix is input to this converter, the converter outputs the converted type from the Out Eigen Matrix pin. The pattern follows for an Eigen Matrix input - it is output from the Out Matrix pin. **Inputs do not directly carry through this node.** If a input pin is unconnected, that is no problem for EiV and it will just output the conversion of the empty type (often being 0 or some null matrix for blank inputs).

Once you have an Eigen/EiV type in your blueprint, you can use the EiV functiosn for those types. These functions are more or less a 1:1 mapping to the actual Eigen functions, so checking out the [Eigen documentation](https://eigen.tuxfamily.org/dox/) should help you understand how they work if you are unfamiliar.

### C++:



<!-- MARKDOWN THEME -->
# $\textsf{\color{#f5750e}{f5750e}}$

## $\textsf{\color{#f48522}{f48522}}$

### $\textsf{\color{#326a95}{326a95}}$

#### $\textsf{\color{#18afd3}{18afd3}}$

##### $\textsf{\color{#5ec3d5}{5ec3d5}}$
