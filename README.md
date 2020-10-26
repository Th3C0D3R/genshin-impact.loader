<p align="center">

  <a href="https://github.com/dhulkifl/genshin-impact.loader">
    <img width="256" heigth="256" src="https://i.imgur.com/qrAlSjd.png" alt="💉"/>
  </a>  

  <h1 align="center">Genshin Impact - Loader</h1>

  <p align="center">
    <a href="https://hits.seeyoufarm.com/api/count/graph/dailyhits.svg?url=https://github.com/dhulkifl/genshin-impact.loader">
      <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fdhulkifl%2Fgenshin-impact.loader&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true" alt="repository hits">
    </a>
    <a href="https://github.com/dhulkifl/genshin-impact.loader/releases">
      <img src="https://img.shields.io/github/downloads/dhulkifl/genshin-impact.loader/total?style=flat-square" alt="downloads"/>
    </a>
    <a href="https://github.com/dhulkifl/genshin-impact.loader/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/dhulkifl/genshin-impact.loader?style=flat-square" alt="contributors"/>
    </a>
    <a href="https://github.com/dhulkifl/genshin-impact.loader/watchers">
      <img src="https://img.shields.io/github/watchers/dhulkifl/genshin-impact.loader?style=flat-square" alt="watchers"/>
    </a>
    <a href="https://github.com/dhulkifl/genshin-impact.loader/stargazers">
      <img src="https://img.shields.io/github/stars/dhulkifl/genshin-impact.loader?style=flat-square" alt="stars"/>
    </a>
    <a href="https://github.com/dhulkifl/genshin-impact.loader/network/members">
      <img src="https://img.shields.io/github/forks/dhulkifl/genshin-impact.loader?style=flat-square" alt="forks"/>
    </a>
  </p>

  <p align="center">
    Easily inject into miHoYo's Genshin Impact
  </p>
</p>

<!--  -->

## Notice

Copyright (c) 2020, https://github.com/dhulkifl
All rights reserved.

This repository is protected by copyright, but is able to be obtained from any reproduction, storage in a retrieval system, or transmission in any form or by any means, electronic, mechanical, photocopying, recording, or likewise as the contents of this repository are openly accessible online. Source code contained within this repository is licensed under the [BSD 3-Clause License (Revised)](https://tldrlegal.com/license/bsd-3-clause-license-(revised)). See the [LICENSE](./LICENSE) file for details.

<!--  -->

## About

[Injecting via kernelmode with Capcom's exploitable driver](https://github.com/veselysps/Genshin-Bypass) is cool but is a risk to the end user. Instead, lets keep things in the usermode *for now* as it makes it easier to manage for everybody. The payloads in this loader will be loaded after the game's "anti-cheat" driver is installed. To load before security features can be setup use [genshin-impact.preloader](https://github.com/dhulkifl/genshin-impact.preloader/) instead. I can't promise that this loader will go undetected. It will try to hide itself and other injected dlls as best as it can. More features may be added at a later date.

## Showcase

## Installation / Uninstallation

Just run the exe, find and select your ```GenshinImpact.exe``` and install. To uninstall, just run the exe, find and select your ```GenshinImpact.exe``` and uninstall. 

## Configuration

DLL files can be added into your game's extra folder, for example: ```'DRIVE:\Games\miHoYo\Genshin Impact Game\extra\'```. They will be loaded automatically. If you uninstall the files within ```'\extra\'``` and the ```'\extra\'``` directory itself will be deleted.

## Troubleshooting

+ Stop the Driver
    ```
    sc query mhyprot2
    sc stop mhyprot2
    sc delete mhyprot2
    sc query mhyprotect
    sc stop mhyprotect
    sc delete mhyprotect
    ```

+ Cache Cleaning
    + Delete the contents in your Local AppData folder, for example: ```C:\Users\Alice\AppData\Local\Temp\```
        + This will remove the temp copied ```mhyprot2.sys``` and any unity / browser / misc contents
    + Delete the contents in your LocalLow AppData folder, for example: ```C:\Users\Alice\AppData\LocalLow\miHoYo\```
        + This will remove the browser cache

+ Uninstall the Loader
    + There might be an a issue with the loader stub. You can check the output logs of the stub itself with DebugView

## Environment Requirements

### Minimum

+ Windows x64 Operating System (XP -> 10)
+ .NET Frameworks 4.0 (CLR/VC++)

### Tested

+ Windows 10 x64 v1809

## Building

### Requirements

+ Visual Studio 2015 (C++)
+ .NET Frameworks 4.0 (CLR/VC++)

### Steps

1) Compile crypt
2) Compile stub
3) Run ```crypt.exe stub.dll > stub.h```
4) Place ```stub.h``` into ```\source\loader\```
5) Compile loader

<!--  -->

## Feedback

I welcome your constructive input - both negative and positive. I will continue to try to provide updates when able. At some point you may find errors, inconsistencies, or methods that could be improved, or are missing altogether. Your feedback is critical to help improve future revisions.

The best way to reach out is by opening a new issue in this repository:

https://github.com/dhulkifl/genshin-impact.loader/issues

Please be sure to refer to what your situation is when giving feedback and if possible link the topic in question.

Many thanks.

<!--  -->

<p align="center">
  <a href="https://github.com/dhulkifl">
    <img width="64" heigth="64" src="https://avatars3.githubusercontent.com/u/73345443" alt="dhulkifl"/>
  </a>  
</p>

<!--  -->