<div align="center">
<figure>
  <img src="https://i.imgur.com/7moLJxE.png" alt="C++ and CMake" width="50%"/>
</figure>

# Orc-vs-Knight
</div>
<p align="center">
<strong>A little game developed for a job interview.</strong>
</p>

<p align="center">
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="CrCC BY-NC-SA 4.0" src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-brightgreen.svg"/></a> <img alt="plateform-windows-linux-mac" src="https://img.shields.io/badge/platform-windows%20%7C%20linux%20%7C%20mac-lightgrey.svg"/> <img alt="languages-cmake-c++" src="https://img.shields.io/badge/languages-CMake%20%7C%20C%2B%2B-blue.svg"/>
</p>

Here is a mini game developed as part of a job application. It is written in **modern C++ 17** and in using **modern CMake**, with a particular focus on good practices. This game is crossplaform and works on Windows, Linux and MacOS.

## ✨ Features

A great mini game for a great job.

## ⚓ Requirements

To contribue to this game, you will need at least the following (install guides are provided on the respective websites):

- **C++ compiler** - e.g [GCC](https://gcc.gnu.org/), [Clang C++](https://clang.llvm.org/cxx_status.html) or [Visual Studio](https://visualstudio.microsoft.com).
- **CMake v3.20+** - can be found [here](https://cmake.org/).

The following dependencies are **optional** because they will be **automatically downloaded** by CMake if they can't be found:

- [Doxygen](http://www.doxygen.nl/) (used when `ENABLE_TEST_MODULE` option is set to `on`);
- [GTest](https://github.com/google/googletest) (used when `ENABLE_DOC_MODULE` option is set to `on`).

## 🚀 Getting started

1. **Get the project** from this repository either by [downloading it](https://github.com/josephgarnier/orc-vs-knight/archive/refs/heads/master.zip) or by [cloning](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository) it directly with the command :

    ```bash
    git clone https://github.com/josephgarnier/orc-vs-knight.git --recursive
    cd orc-vs-knight
    ```

2. **Edit the basic settings.** Open the file `cmake/project/StandardOptions.txt` and edit the settings in following instructions from [here](https://github.com/josephgarnier/cpp-starter-project-cmake#-setting-up-the-generator-modules).

3. **Let's go to dev your amazing game.** Open the project in your favorite IDE, try to compile then write your files.

## 💫 Specifications

Créer un projet Console sous Visual Studio 2017 ou 2019 qui fera tourner un petit jeu de simulation simple de bataille entre deux unités (chevalier contre orc). Vous êtes libre d'utiliser des librairies externes de votre choix si vous estimez en avoir besoin, à condition que le projet que vous allez fournir à la fin puisse se lancer sans avoir besoin d'installer un autre logiciel. Vous devez nous rendre un fichier zip contenant un repo git local. Celui-ci devra contenir sur la branche master la solution Visual que nous aurons juste à compiler et lancer pour tester votre programme.

Voici une description des règles à respecter. Si certaines règles ne vous semblent pas claires ou qu'il manque de précisions, vous êtes libre de faire des choix à condition de nous les préciser dans votre mail de retour.

Caractéristiques du chevalier :

- Il dispose de 20 points de vie et d'un bouclier de 50 points.
- Il dispose d'une épée lui permettant de faire 5 points de dégâts par tour.
- Il dispose d'une capacité "charge" lui permettant de faire le double de dégâts ce tour-ci. Cette capacité ne peut être utilisée que tous les 3 tours de jeu. Elle a 60% de chance de réussir. Si elle ne réussit pas, il faudra attendre les 3 tours mentionnés ci-dessus pour la tenter de nouveau.
- Les dégâts pris par le chevalier sont d'abord infligés au bouclier et lorsque le bouclier n'a plus de points, l'unité perd des points de vie.

Caractéristiques de l'orc :

- L'orc dispose de 60 points de vie mais n'a pas de bouclier.
- Il dispose d'une hache lui permettant de faire 8 points de dégâts par tour.
- Il dispose d'une capacité "stun" lui permettant d'étourdir l'ennemi pendant un tour. Un ennemi étourdi ne pourra pas faire de dégât ce tour-ci. Cette capacité ne peut être utilisée que tous les 5 tours de jeu. Elle a 20% de chance de réussir. Si elle ne réussit pas, il faudra attendre les 5 tours mentionnés ci-dessus pour la tenter de nouveau.

Voici le déroulement de la partie :

- Un tour de jeu est constitué de 2 éléments successifs : lancement de capacités spéciales, puis combat entre les unités.
- Il y a autant de tour de jeu que nécessaire pour que l'un des côté gagne la partie.
- Un côté gagne la partie quand l'unité adverse a été tuée.
- Pour le combat entre 2 unités, chaque unité inflige directement les dégâts à l'unité ennemie (en prenant en compte les éventuels effets des capacités).

Contraintes supplémentaires :

- Afin de vérifier que votre programme fonctionne normalement, il serait appréciable de pouvoir suivre l'évolution de la partie en affichant notamment les informations de chaque unité à chaque tour de jeu.
- Il faut que le programme soit correctement architecturé pour qu'il soit facile d'ajouter de nouvelles classes et/ou de nouvelles caractéristiques.

Bonus :
- Pour rendre le jeu plus "dynamique", il pourrait être sympa de pouvoir faire des choix avant le lancement de la partie/pendant la partie. Vous êtes libre de faire une/des propositions et de les implémenter.

## ⚙️ Usage and commands

According to this project has been developped from this [other project](https://github.com/josephgarnier/cpp-starter-project-cmake), it provide several scripts and commands to generate the *Build Lifecycle* and execute each build phase with their targets. If you are a VS Code user, they have all been written in `.vscode/tasks.json` and can be launched from the [command palette](https://code.visualstudio.com/docs/editor/tasks), otherwise you can use a command prompt. All the following instructions have to be executed from the root of the project. They are listed in the order of execution of a complete and classic sequence of build phases.

Commands to **clean the *Build Lifecycle*** (these scripts clean `build/`, `doc/` and `bin/`):

```bash
# clean the Build Lifecycle (on Linux/MacOS)
./clean-cmake.sh

# clean the Build Lifecycle (on Windows)
clean-cmake.bat
```

Commands to **generate the *Build Lifecycle*** (these scripts call the `cmake` command):

```bash
# generate the Build Lifecycle (on Linux/MacOS)
./run-cmake.sh

# generate the Build Lifecycle (on Windows)
run-cmake.bat

# a useful command for listing what targets has been generated
cmake --build build/ --target help

# a useful command for listing variables in the cache and their descriptions
cmake -LAH build/
```

Commands to **clean and generate the *Build Lifecycle***:

```bash
# clean and generate the Build Lifecycle (on Linux/MacOS)
./clean-cmake.sh && sleep 3s && echo \"\" && ./run-cmake.sh

# clean and generate the Build Lifecycle (on Windows)
clean-cmake.bat && timeout /t 3 > NUL && echo. && run-cmake.bat
```

Commands to **execute the `uninstall` build phase** of the *Build Lifecycle* (only available if the *Export Generator Module* has been activated):

```bash
# run the uninstall target (on Linux/MacOS)
sudo cmake --build build/ --target uninstall

# run the uninstall target (on Windows)
cmake --build build/ --target uninstall
```

Commands to **execute the `clean` build phase** of the *Build Lifecycle*:

```bash
# run the clean target
cmake --build build/ --target clean
```

Commands to **execute the `compile` build phase** of the *Build Lifecycle*:

```bash
# build all binary targets (except for tests)
cmake --build build/ --target all

# build all binary targets in verbose mode (except for tests)
cmake --build build/ --target all --verbose

# execute the `compile` phase after the `clean` phase
cmake --build build/ --target all --clean-first

# execute the `compile` phase after the `clean` phase in verbose
cmake --build build/ --target all --clean-first --verbose
```

Commands to **execute the `test` build phase** of the *Build Lifecycle* (only available if the *Test Generator Module* has been activated):

```bash
# build the test binary target and execute the tests binary executable
cmake --build build/ --target orc-vs-knight_test && ../bin/orc-vs-knight_test
```

Commands to **execute the `doc` build phase** of the *Build Lifecycle* (only available if the *Doc Generator Module* has been activated):

```bash
# run the doc target
cmake --build build/ --target doc
```

Commands to **execute the `install` build phase** of the *Build Lifecycle* (only available if the *Export Generator Module* has been activated):

```bash
# run the install target (on Linux/MacOS)
sudo cmake --build build/ --target install

# run the install target (on Windows)
cmake --build build/ --target install
```

Commands to **execute the `package` build phase** of the *Build Lifecycle* (only available if the *Package Generator Module* has been activated):

```bash
# run the package and package_source targets (on Linux/MacOS)
cmake --build build/ --target package package_source && sleep 3s && rm -rfv bin/_CPack_Packages

# run the package and package_source targets (on Windows)
cmake --build build/ --target package package_source && timeout /t 3 > NUL && del /a /f /s /q bin/_CPack_Packages

# run the package target (on Linux/MacOS)
cmake --build build/ --target package && sleep 3s && rm -rfv bin/_CPack_Packages

# run the package target (on Windows)
cmake --build build/ --target package && timeout /t 3 > NUL && del /a /f /s /q bin/_CPack_Packages

# run the package_source target (on Linux/MacOS)
cmake --build build/ --target package_source && sleep 3s && rm -rfv bin/_CPack_Packages

# run the package_source target (on Windows)
cmake --build build/ --target package_source && timeout /t 3 > NUL && del /a /f /s /q bin/_CPack_Packages

# a useful command for debugging during the package configuration step (on Linux/MacOS)
cpack --debug --verbose --config build/CPackConfig.cmake && sleep 3s && rm -rfv bin/_CPack_Packages

# a useful command for debugging during the package configuration step (on Windows)
cpack --debug --verbose --config build/CPackConfig.cmake && timeout /t 3 > NUL && del /a /f /s /q bin/_CPack_Packages
```

Use the following commands to **execute the binaries built** as executable:

```bash
# execute the main binary executable (on Linux/MacOS)
./bin/orc-vs-knight

# execute the main binary executable (on Windows)
bin/orc-vs-knight
```

## 📂 Folder structure overview

This project has been set up with a specific file/folder structure in mind. The following describes some important features of this setup:

| **Directory and File** | **What belongs here** |
|------------------------|-----------------------|
| `.vscode/tasks.json` | Specific VS Code tasks configured to compile, clean, build, etc. |
| `assets/` | Contains images, musics, maps and all resources needed for a game or a simulation project. |
| `bin/` | Any libs that get compiled by the project and the output executables go here, also if you pack your project, the generated files go here. |
| `build/` | Contains the CMake build-tree. |
| `cmake/helpers/` | Contains some scripts and all generator modules used to generate the *Build Lifecycle*. |
| `cmake/modules/` | Contains custom CMake modules. |
| `cmake/project/` | Setting files for configuring the generator modules. |
| `cmake/toolchains/` | Contains toolchain files for compilers.
| `config/` | Contains configuration files used by the C++ project. |
| `doc/` | Contains code documentation generated by [Doxygen](http://www.doxygen.org). |
| `include/` | All necessary third-party header files (.h) and public header files (.h) of the project. |
| `lib/` | Any libaries needed in the project. |
| `resources/` | Contains images, musics, maps and all resources needed for the project (e.g for graphical user interfaces). |
| `src/` | Source files (.cpp) and private/public header files (.h) of the project. |
| `tests/` | Source files (.cpp) and header files (.h) for the unit testing framework [GTest](https://github.com/google/googletest). |
| `clean-cmake.bat` | Utility script for Windows to remove all generated files in `build/`, `bin/` and `doc/`. |
| `clean-cmake.sh` | Utility script for Linux/MacOS to remove all generated files in `build/`, `bin/` and `doc/` directories. |
| `CMakeLists.txt` | Main `CMakelists.txt` file of the project. |
| `LICENSE.md` | License file for project (needs to be edited). |
| `README.md` | Readme file for project (needs to be edited). |
| `run-cmake.bat` | Utility script for Windows to generate the *Build Lifecycle*. |
| `run-cmake.sh` | Utility script for Linux/MacOS to generate the *Build Lifecycle*. |

## 🤝 Contributing

1. Fork the repo and create your feature branch from master.
2. Create a topic branch - `git checkout -b my_branch`.
3. Push to your branch - `git push origin my_branch`.
4. Create a Pull Request from your branch.

## 👥 Credits

This project is maintained and developed by [Joseph Garnier](https://www.joseph-garnier.com/).

## ©️ License

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Licence Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

This work is licensed under the terms of a <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0</a>.  See the [LICENSE.md](LICENSE.md) file for details.

## 🍻 Acknowledgments

This project was inspired by [SFML Blueprints](https://github.com/Krozark/SFML-book) and [SFML Game Development](https://github.com/SFML/SFML-Game-Development-Book).
