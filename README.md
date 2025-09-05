# <a href="https://mjmcguffin.github.io/MuqcsCraft/">MuqcsCraft</a>

MuqcsCraft is a web-based graphical simulator and visualizer for quantum circuits, built on top of the <a href="https://github.com/MJMcGuffin/muqcs.js">muqcs</a> library.

![Example 1](/doc/screenshot-teaser.png)

![Example 2](/doc/screenshot-W4.png)

![Example 3](/doc/screenshot-grover.png)

## Companion Video

A video will be made to demonstrate MuqcsCraft's functionality.

## Companion Paper

An academic paper about MuqcsCraft has been drafted and will be uploaded soon to arxiv.

## Building the code

The build process is simple but idiosyncratic.
The developer is not an expert on modern web development tools, and so invented a way to build the code that works well with his computing environment.

The util/ folder contains a Makefile to build two utilities:
(1) a "quoter" written in C, which takes the contents of a file and outputs it as a quoted string, escaping characters as necessary,
and
(2) an "includer" written in perl, that can be used as a very simple text preprocessor to include the contents of one file in another, similar to #include statements in C code, by using SIMPLE_INCLUDE statements.

The icons/ folder contains image files in png format, and a Makefile that converts the png files to a base64 plain text encoding that is then quoted.

The root folder contains a Makefile that includes the muqcs.js and icon files into the .html.source file and outputs the final .html file.
Search for SIMPLE_INCLUDE inside the .html.source file.

So the .html.source file is the one that a programmer would normally edit to modify functionality before running make to build the .html file.

Search for "web analytics" inside the .html.source file to see how visits are logged without tracking personal information.

The doc/ folder contains some diagrams that could be useful to understand the layout code.

