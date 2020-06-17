<h1>Bite Programming Language</h1>

<p>Bite is an assembly style programming language that compiles textfile input into C++. The original version of Bite used was designed to use flex and bison for lexical analysis and parsing; however, the goto style execution required for assembly programming languages was nearly impossible to implement. This lead to the development of a more hands-on approach to the problem. To parse the input of the textfile, Bite first uses a tokenizer to separate all words within the file and stores them in a two-dimensional vector of strings. These strings are then sent to the programizer class to build the program object. The programizer compares blueprints of possible instruction names and argument types to the input tokens and returns a Line object. This entity can later be used to execute the member functions of the program class, and in turn, execute the program.</p>

<img src="https://svgshare.com/i/M6z.svg">

<h2>Usage</h2>
<p>To use Bite: ethier clone the repository or access it here https://repl.it/@JaceCallihoo/Bite-Programming-Language#bite.txt at repl.it. From there, modify the bite.txt file to run your assembly code</p>

<h2>Author</h2>
<p>Jace Callihoo - https://jacecallihoo.com/</p>

<h2>Licence</h2>
<p>This project is licensed under the MIT License - see the LICENSE.md file for details</p>
