# Security Policy

## Supported Versions

All updates to EiV will be engineered from Unreal Engine 5.1 to ensure forward compatibility such that the current versions supported shall always be supported. However, you should be careful as Unreal Engine versions
supported are not always available on Fab (the latest three versions will always be). If the version you are looking for is not on Fab, you can build from source using the code here, but make sure you understand the 
process otherwise the plugin may not work as intended.

| Version | Supported          |
| ------- | ------------------ |
| 5.5.x   | :white_check_mark: |
| 5.4.x   | :white_check_mark: |
| 5.3.x   | :white_check_mark: |
| 5.2.x   | :white_check_mark: |
| 5.1.x   | :white_check_mark: |
| 5.0.x   | :x:                |
| < 4.27.x| :x:                |

## Reporting a Vulnerability

As with any code that allows for you to do your own memory management, there naturally comes potential for security vulnerabilities. When working mostly within Unreal C++, much of that danger is restrained thanks to UObjects.
However, this library allows you to access non-Unreal Engine C++ and thus expects you to understand more about safe coding practices in C++. While the Eigen version that comes with Unreal Engine handles much of its own internal memory management through Unreal's memory allocation system, if you allocate memory for and maintain pointers to Eigen structures it is solely on you to handle them. We recommend using techniques such as [smart pointers](https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170) to help reduce issues within your program. For those that want to look more in-depth at security best practices in C++ please see the [SEI CERT C++ Coding Standard](https://wiki.sei.cmu.edu/confluence/display/cplusplus/2+Rules) (it is not fully complete but it gives a very good idea of what to work towards for safe, effective C++).

There may natrually be vulnerabilities in the code of this product too and if you happen to find any, please either notify us here on GitHub or go and submit a possible bug report on our [Discord Community](https://discord.gg/usmH9mZGVe).
