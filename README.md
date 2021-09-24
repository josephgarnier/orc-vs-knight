<div align="center">
<figure>
  <img src="https://i.imgur.com/mBIbXGW.png" alt="Orc vs Knight" width="50%"/>
</figure>

# Orc-vs-Knight
</div>
<p align="center">
<strong>A turn-based mini game developed for a job interview.</strong>
</p>

<p align="center">
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="CrCC BY-NC-SA 4.0" src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-brightgreen.svg"/></a> <img alt="plateform-windows-linux-mac" src="https://img.shields.io/badge/platform-windows%20%7C%20linux%20%7C%20mac-lightgrey.svg"/> <img alt="languages-cmake-c++" src="https://img.shields.io/badge/languages-CMake%20%7C%20C%2B%2B-blue.svg"/> <img alt="goal-progress-100" src="https://img.shields.io/badge/goal%20progress-100%25-orange.svg"/>
</p>

Here is a turn-based mini game developed in a few days to show to recruiters my skills in C++. It is written in **modern C++ 17** and in using **modern CMake**, with a particular focus on good practices. This game is crossplaform and works on Windows, Linux and MacOS.

## ✨ Features

A mini-game that opposes an orc against an knight controlled by an AI in a turn-based battle. The player can only set the way the game moves to the next round: automatically or manually after pressing a key.

## ⚓ Requirements

To contribue to this game, you will need at least the following (install guides are provided on the respective websites):

- **C++ compiler** - e.g [GCC](https://gcc.gnu.org/), [Clang C++](https://clang.llvm.org/cxx_status.html) or [Visual Studio](https://visualstudio.microsoft.com).
- **CMake v3.20+** - can be found [here](https://cmake.org/).
- **SFML v2.5.1+** - can be found [here](https://www.sfml-dev.org/index.php).

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

Create a Console project in Visual Studio 2017 or 2019 that will run a small, simple simulation game of battle between two units (knight vs. orc). You are free to use external libraries of your choice if you feel you need them, as long as the project you will provide at the end can run without the need to install any other software. You must give us a zip file containing a local git repo. This should contain on the master branch the Visual solution that we will just have to compile and run to test your program.

Here is a description of the rules to respect. If some of the them are not clear to you or are not precise enough, you are free to make choices as long as you specify them in your return email.

Characteristics of the knight:

- He has 20 life points and a 50 point shield.
- He has a sword that allows him to do 5 points of damage per turn.
- He has a "charge" ability that allows him to do double the damage this turn. This ability can only be used every 3 turns. It has a 60% chance of success. If it doesn't succeed, you will have to wait the 3 turns mentioned above to try it again.
- The damage taken by the knight is first inflicted on the shield and when the shield has no more points, the unit loses life points.

Orc Characteristics:

- He has 60 points of life but has no shield.
- He has an axe that allows him to do 8 points of damage per turn.
- He has a "stun" ability that allows him to stun the enemy for one turn. A stunned enemy cannot do any damage this turn. This ability can only be used every 5 turns. It has a 20% chance of success. If it does not succeed, you must wait the 5 turns mentioned above to try it again.

Here is the flow of the game:

- A game turn consists of 2 successive elements: launching special abilities, then combat between units.
- There are as many game turns as necessary for one side to win the game.
- A side wins the game when the opponent unit has been killed.
- For the combat between 2 units, each unit inflicts directly the damage to the enemy unit (taking into account the possible effects of the abilities).

Additional constraints:

- In order to check that your program is working properly, it would be nice to be able to follow the evolution of the game by displaying the information of each unit at each turn.
- The program must be well structured so that it is easy to add new classes and/or new characteristics.

Bonus:

- To make the game more "dynamic", it might be nice to be able to make choices before the game starts/during the game. You are free to make a proposal(s) and implement it.

## ⚙️ Usage and commands

According to this project has been developped from this [other template project](https://github.com/josephgarnier/cpp-starter-project-cmake), you can find all the commands you will need by clicking [here](https://github.com/josephgarnier/cpp-starter-project-cmake#%EF%B8%8F-usage-and-commands).

## 📂 Folder structure overview

According to this project has been developped from this [other template project](https://github.com/josephgarnier/cpp-starter-project-cmake), you can find a description of the folder structure by clicking [here](https://github.com/josephgarnier/cpp-starter-project-cmake#-folder-structure-overview).

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
