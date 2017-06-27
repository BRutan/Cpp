------------------------------------------------------------------------------------------------------------------------------------
## Folder description:
------------------------------------------------------------------------------------------------------------------------------------
Contains following examples of usage (using header and source files contained in Files sub-folder):

- OptionsAndGeneratorExampleUsage.cpp: Example usage of derived AmericanPerpetualOption, EuropeanOption classes and MeshGenerator class
that describe behavior of stock options (price, greeks, finite difference method approximation) and generate large number of iterates  that give further insight to how option behavior changes with respect to chosen variables (stock price, strike price, time, risk free rate, cost of carry, implied volatility).

- MonteCarloExampleUsage.cpp: Example of pricing options via a Monte Carlo object that takes the average discounted price of the underlying using randomly generated paths with the Euler-Maruyama scheme.

- ExcelCOMExampleUsage.cpp: Example usage of automated output of C++ computations to Excel via Microsoft's COM library.

------------------------------------------------------------------------------------------------------------------------------------
* Compilation Instructions:  

  **Note: Boost 1.64.0 is required to compile all files. It can be downloaded at http://www.boost.org/users/download/.**
  
  * Visual Studio:
    - Create new Visual C++ -> General -> Empty Project.
    - Add all header and source files in File sub-folder to the project (via right click \<Project Name\> -> Add -> Existing Item in the         Solution Explorer window).
    - Add ONE of the desired test files (in Options super-folder) to the project.
    - Implement Boost libraries via navigating to Project -> Properties -> VC++ Directories and adding '\<Your Path>\boost_1_64_0'               absolute filepath to the 'Include Directories' area.
    - Click Build -> Build Solution (CTRL-SHIFT-B) then click Debug -> Start Debugging (F5) to run the solution.
