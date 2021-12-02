# ELEC2645 - CW2
This is my personal section for my coursework for university. It involves calculating the fourier transform for any cartesian equation for any amount of terms. These can then be saved and automatically displayed on a Desmos Graph.
## How to Run
### Linux
1. Clone the repository using `git clone https://gitlab.com/Rory652/2645-cw2.git`
2. Navigate to the repositories folder in the terminal
3. Run `cmake .`
4. Run `cmake --build .`
5. Run the program with `./cw2` (Linux) - use the command line argument `test` to run the tests.
The output of the program will be called `output.html` and will be stored in the same file as the executable. If you equation uses any of sin, cos, etc. the Desmos graph won't display immediately, just use the arrow keys to move through the graph text on the left and it should show up just fine.
## Features
- Enter any equation using the accepted operations
- Choose any range of integration
- Calculate any number of fourier terms
- Save the results and view on a Desmos interactable graph
