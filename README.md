# Console Games

Console games are a set of small, simple games that you can play on your Windows or Linux console.

## Installation and Running

### Linux

1. **Clone the repository**:
    ```sh
    git clone https://github.com/hionjk/simple-games-c
    cd simple-games-c
    ```

2. **Run make**:
    ```
    make
    ```

3. **Run the game**:
    ```
    ./game
    ```

### Windows

1. **Clone the repository**:
    - Open Command Prompt (cmd) or PowerShell and run:
    ```sh
    git clone https://github.com/hionjk/simple-games-c
    cd simple-games-c
    ```

2. **Install MinGW (Minimalist GNU for Windows)**:
    - Download and install MinGW from [MinGW website](https://osdn.net/projects/mingw/releases/).
    - Add the `bin` directory of your MinGW installation to your system's PATH.

3. **Compile the game**:
    - Open PowerShell and run:
    ```
    gcc main.c games/* utils/* game
    ```

4. **Run the game**:
    ```
    game.exe
    ```

### Additional Information
- Make sure you have `gcc` installed. On Linux, you can install it using your package manager (e.g., `sudo apt-get install gcc` on Debian-based distributions). On Windows, you can install `gcc` as part of MinGW.
