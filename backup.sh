#!/bin/bash
tar -cvf "ords-$(date +%F).tar" --exclude=".*" src/ data/ ords/ info/