# Ords

Git page: http://github.org/therryan/Ords

## What is Ords?

Ords is a program for training the vocabulary.
It is distributed under the terms and conditions of the Gnu General Public License, version 3. See LICENSE for details.

## Installation

To install, just go to the folder and `make`.
Then copy the resulting binary to the place that you want.
`make install` moves the binary by default to `~`. `make install "LOCATION=/usr/bin"` will install the application there.

## Usage

Currently, Ords supports to ways of interaction: the interactive mode and the argument-interface.
To open the interactive mode, just open the application. To see the supported commands, type `help`
To see what arguments there are, type `ords --help`.

### Paths and Settings

Ords currently stores its data in the data folder. All the files end in ".ords".
Settings are under development. In the future the location of the data folder can be moved.

## Authors

Teemu Vasama
	<therryan1@gmail.com>