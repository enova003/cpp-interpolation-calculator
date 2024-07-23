# Requirements

  - GNU g++ compiler (11.4.0 or higher recommended)
  - GNU Make

# Compilation

The code can be compiled using the provided makefile; simply type the command `make`.

After compiling the program, the executable file will appear; 
this file will be named "parseTemps".

# Execution

The program, must be run with an input filename as 
the first command line argument. The program will **not** 
prompt the user for a filename.

The program can be executed as follows:
    `./parseTemps input/input_file_name`

where "input_file_name" is replaced by a .txt input file.

# Output

The program outputs data both to the terminal and to .txt files.

If given the command:
  `./parseTemps input/sample-input.txt`

where "sample-input.txt" contained:
```
    61.0 63.0 50.0 58.0
    80.0 81.0 68.0 77.0
    62.0 63.0 52.0 60.0
    83.0 82.0 70.0 79.0
    68.0 69.0 58.0 65.0
```
The following data would be printed to the terminal:
```
    (0, [61, 63, 50, 58])
    (30, [80, 81, 68, 77])
    (60, [62, 63, 52, 60])
    (90, [83, 82, 70, 79])
    (120, [68, 69, 58, 65])
```
Where, 
- The first column represents the time in seconds
- The second column represents the specs of Core 0
- The third column represents the specs of Core 1
- The fourth column represents the specs of Core 2
- The fifth column represents the specs of Core 3

______________________________________________________

The program will output four .txt files;
the files will appear in the directory containing the main 
program, `parseTemps`. These files will appear in the following format:
  - core_00_interpolation_file.txt
  - core_01_interpolation_file.txt
  - core_02_interpolation_file.txt
  - core_03_interpolation_file.txt

These files contain the piecewise linear interpolation data and the 
least squares approximation data for the provided .txt argument file.


If given the command:
  `./parseTemps input/sample-input.txt`

where sample-input.txt contained the following data:
```
    61.0 63.0 50.0 58.0
    80.0 81.0 68.0 77.0
    62.0 63.0 52.0 60.0
    83.0 82.0 70.0 79.0
    68.0 69.0 58.0 65.0
```
- core_00_interpolation_file.txt would appear as follows:
```
    0 <= x <=    30 ; y =    61 +   0.633333 x ; interpolation
   30 <= x <=    60 ; y =    98 +       -0.6 x ; interpolation
   60 <= x <=    90 ; y =    20 +        0.7 x ; interpolation
   90 <= x <=   120 ; y =   128 +       -0.5 x ; interpolation
    0 <= x <=   120 ; y =  67.4 +  0.0566667 x ; least-squares
```

- core_01_interpolation_file.txt would appear as follows:
```
    0 <= x <=    30 ; y =    63 +        0.6 x ; interpolation
   30 <= x <=    60 ; y =    99 +       -0.6 x ; interpolation
   60 <= x <=    90 ; y =    25 +   0.633333 x ; interpolation
   90 <= x <=   120 ; y =   121 +  -0.433333 x ; interpolation
    0 <= x <=   120 ; y =    69 +  0.0433333 x ; least-squares
```
- core_02_interpolation_file.txt would appear as follows: 
```
    0 <= x <=    30 ; y =    50 +        0.6 x ; interpolation
   30 <= x <=    60 ; y =    84 +  -0.533333 x ; interpolation
   60 <= x <=    90 ; y =    16 +        0.6 x ; interpolation
   90 <= x <=   120 ; y =   106 +       -0.4 x ; interpolation
    0 <= x <=   120 ; y =    56 +       0.06 x ; least-squares
```
- core_03_interpolation_file.txt would appear as follows:
```
    0 <= x <=    30 ; y =    58 +   0.633333 x ; interpolation
   30 <= x <=    60 ; y =    94 +  -0.566667 x ; interpolation
   60 <= x <=    90 ; y =    22 +   0.633333 x ; interpolation
   90 <= x <=   120 ; y =   121 +  -0.466667 x ; interpolation
    0 <= x <=   120 ; y =  64.6 +  0.0533333 x ; least-squares
```
# Important Notes

Whenever the command `make clean` is run, all .txt files will be deleted

If you run the program multiple times with different input files 
(for example, first with .`/parseTemps input/sample-input.txt` and 
then with `./parseTemps input/sensors-2018.12.26.txt`), the piecewise 
linear interpolation data and least squares approximation data from 
the second input file will override (replace) the data stored in the 
.txt files from the first input file.
