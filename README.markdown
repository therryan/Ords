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

Currently, Ords supports two ways of interaction: the interactive mode and the argument-interface.
To open the interactive mode, just open the application: `ords`. To see the supported commands, type `help`.
To see what arguments there are, type `ords --help`.

### Paths and Settings

Ords stores its data in the data folder. All the files end in ".ords". By default it's `~/ords/`.
To change that, edit the `datapath` directive in the `~/.ords.conf` file.

## Other files

### LICENSE

Contains the GPLv3 license.

### CHANGELOG

Contains an easily understandable version history of the main features.

### DEVELOPER

Has information about the inner workings of the application for people who are interested in that kind of stuff.

## Authors

Teemu Vasama <therryan1@gmail.com>