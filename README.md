# X11 Tutorial

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)

This project is for an X11 tutorial. We will build an application with 8 colors in a palette to pick from, and clicking a color will change the color of a rectagle and display that color's name on a label.

## Branches

Each part of the tutorial will have its own branch, with the final project being in the main branch. Make sure to check out the branch corresponding to the step of the tutorial you are on.

## Contents (WIP, subject to change):
Branch names and their use:

- `part-0` - basic setup and Hello World
- `part-1` - add rectangles and label
- `part-2` - add events to the rectangles and label
- `part-3` - change the main rectangle on events

## Concept image

![Concept Image](/documentation/concept.png?raw=true "Concept Image")
## License

[GLPv3](https://www.gnu.org/licenses/gpl-3.0.en.html)


## Run Locally

1. Install the X11 development libraries

    Fedora and EPEL:
    ```bash
    sudo dnf install libX11-devel #Fedora
    ```

    Ubuntu, Debian, and derivatives:
    ```bash
    sudo apt install libX11-devel #Fedora
    ```

    OpenSUSE:
    ```bash
    sudo zypper install xorg-x11-devel
    ```

2. Clone the project

```bash
  git clone git@github.com:jpenn84/x11-tutorial.git
```

3. Follow the tutorial (WIP, coming soon)
