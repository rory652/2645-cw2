# ELEC2645 - CW2
This is my personal section for my coursework for university. It involves calculating the fourier transform for any cartesian equation for any amount of terms. These can then be saved and automatically displayed on a Desmos Graph.
## How to Run
This program requires at least CMake 3.10 (the version that comes with Repl) to be able to run it.
### Linux
1. Clone the repository using `git clone https://gitlab.com/Rory652/2645-cw2.git`
2. Navigate to the repositories folder in the terminal
3. Run `cmake .`
4. Run `cmake --build .`
5. Run the program with `./cw2` (Linux) - use the command line argument `test` to run the tests.
### Repl
1. Create a new repl and import from `github.com/rory652/2645-cw2`
2. Set language to C++ and set the run command to `cd build && cmake ../ && cmake --build . && ./cw2`
3. Tests can be ran by going to the shell and running `cd build; ./cw2 test`
4. You may have to download the output file to your computer and run it from there to see the output properly

The output of the program will be called `output.html` and will be stored in the same file as the executable. If you equation uses any of sin, cos, etc. the Desmos graph won't display immediately, just use the arrow keys to move through the graph text on the left and it should show up just fine.
## Features
- Enter any equation using the accepted operations
- Choose any range of integration
- Calculate any number of fourier terms
- Save the results and view on a Desmos interactable graph
